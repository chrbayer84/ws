//==============================================================================
// rtty_gfft.hpp:
//
// FFT library ported from fldigi (Dave Freese, W1HKJ / John Green)
//
// This file is part of WSJT-X.
//==============================================================================

#ifndef RTTY_GFFT_HPP
#define RTTY_GFFT_HPP

#include <cmath>
#include <complex>

template <typename FFT_TYPE>
class rtty_gfft {
#define RTTY_FFT_RECIPLN2  1.442695040888963407359924681001892137426 // 1.0/log(2) 

#define RTTY_LOG2(a) (RTTY_FFT_RECIPLN2*std::log(a))		// floating point logarithm base 2
#define RTTY_POW2(m) ((unsigned int) 1 << (m))	// integer power of 2 for m<32

#define RTTY_MCACHE  (11 - (sizeof(FFT_TYPE) / 8))

#define RTTY_FFT_PI      3.141592653589793238462643383279502884197	// pi
#define RTTY_FFT_ROOT2   1.414213562373095048801688724209698078569	// sqrt(2)
#define RTTY_FFT_COSPID8 0.9238795325112867561281831893967882868224	// cos(pi/8)
#define RTTY_FFT_SINPID8 0.3826834323650897717284599840303988667613	// sin(pi/8)

private:
	int			FFT_size;
	int			FFT_N;
	FFT_TYPE	*FFT_table_1[32];
	short int	*FFT_table_2[32];

	FFT_TYPE	*Utbl;
	short		*BRLow;

	void fftInit();
	int ConvertFFTSize(int);

	void riffts1(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, short *BRLow);
	void ifrstage(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl);
	void rifft8pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void rifft4pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void rifft2pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void rifft1pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void rffts1(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, short *BRLow);
	void frstage(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl);
	void rfft8pt(FFT_TYPE *ioptr);
	void rfft4pt(FFT_TYPE *ioptr);
	void rfft2pt(FFT_TYPE *ioptr);
	void rfft1pt(FFT_TYPE *ioptr);
	void iffts1(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, short *BRLow);
	void ifftrecurs(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, int Ustride,
					 int NDiffU, int StageCnt);
	void ibfstages(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, int Ustride,
					int NDiffU, int StageCnt);
	void ibfR4(FFT_TYPE *ioptr, int M, int NDiffU);
	void ibfR2(FFT_TYPE *ioptr, int M, int NDiffU);
	void ifft8pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void ifft4pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void ifft2pt(FFT_TYPE *ioptr, FFT_TYPE scale);
	void scbitrevR2(FFT_TYPE *ioptr, int M, short *BRLow, FFT_TYPE scale);
	void ffts1(FFT_TYPE *ioptr, int M, FFT_TYPE *Utbl, short *BRLow);
	void fftrecurs(FFT_TYPE *ioptr, int M,
				FFT_TYPE *Utbl, int Ustride, int NDiffU,
				int StageCnt);
	void bfstages(FFT_TYPE *ioptr, int M,
				FFT_TYPE *Utbl, int Ustride,
				int NDiffU, int StageCnt);
	void bfR4(FFT_TYPE *ioptr, int M, int NDiffU);
	void bfR2(FFT_TYPE *ioptr, int M, int NDiffU);
	void fft8pt(FFT_TYPE *ioptr);
	void fft4pt(FFT_TYPE *ioptr);
	void fft2pt(FFT_TYPE *ioptr);
	void bitrevR2(FFT_TYPE *ioptr, int M, short *BRLow);
	void fftBRInit(int M, short *BRLow);
	void fftCosInit(int M, FFT_TYPE *Utbl);
	
public:
	explicit rtty_gfft(int M = 8192) {
		if (M < 16) M = 16;
		if (M > 268435456) M = 268435456;
		FFT_size = M;
		fftInit();
	}
	~rtty_gfft() {
		for (int i = 0; i < 32; i++) {
			if (FFT_table_1[i] != 0) delete [] FFT_table_1[i];
			if (FFT_table_2[i] != 0) delete [] FFT_table_2[i];
		}
	}

	void ComplexFFT(std::complex<FFT_TYPE> *buf);
	void InverseComplexFFT(std::complex<FFT_TYPE> *buf);
	void RealFFT(std::complex<FFT_TYPE> *buf);
	void InverseRealFFT(std::complex<FFT_TYPE> *buf);
	FFT_TYPE GetInverseComplexFFTScale();
	FFT_TYPE GetInverseRealFFTScale();
};

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fftCosInit(int M, FFT_TYPE *uTbl)
{
	int i;
	FFT_TYPE *uptr = uTbl;
	int length = RTTY_POW2(M)/4;
	double twoPi = 8.0 * std::atan(1.0);
	double angle = twoPi / (double) RTTY_POW2(M);

	for (i = 0; i <= length; i++)
		*uptr++ = std::cos(i * angle);
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fftBRInit(int M, short *bRLow)
{
	int i, j;
	int length = RTTY_POW2(M/2);
	int rev;
	int mask;
	int limit = M/2;

	for (i = 0; i < length; i++) {
		rev = 0;
		mask = 1;
		for (j = 0; j < limit; j++) {
			rev <<= 1;
			if (i & mask) rev |= 1;
			mask <<= 1;
		}
		*bRLow++ = rev;
	}
}

template <typename FFT_TYPE>
int rtty_gfft<FFT_TYPE>::ConvertFFTSize(int M)
{
	int n = 1;
	FFT_N = 0;
	while (n < M) {
		n <<= 1;
		FFT_N++;
	}
	FFT_size = n;
	return FFT_N;
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fftInit()
{
	int i;
	for (i = 0; i < 32; i++) {
		FFT_table_1[i] = 0;
		FFT_table_2[i] = 0;
	}
	int M = ConvertFFTSize(FFT_size);
	Utbl = FFT_table_1[M] = new FFT_TYPE[RTTY_POW2(M)/4 + 1];
	fftCosInit(M, Utbl);
	BRLow = FFT_table_2[M] = new short int[RTTY_POW2(M/2)];
	fftBRInit(M, BRLow);
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::bitrevR2(FFT_TYPE *ioptr, int M, short *bRLow)
{
	int i, j;
	int length = RTTY_POW2(M/2);
	int halfLength = length >> 1;
	FFT_TYPE *i1 = ioptr;
	FFT_TYPE *i2;
	FFT_TYPE tempr, tempi;
	int rev;

	for (i = 0; i < length; i++) {
		rev = bRLow[i];
		if (i < rev) {
			i2 = ioptr + (rev * length * 2);
			for (j = 0; j < length; j++) {
				tempr = i1[0];
				tempi = i1[1];
				i1[0] = i2[0];
				i1[1] = i2[1];
				i2[0] = tempr;
				i2[1] = tempi;
				i1 += 2;
				i2 += 2;
			}
		} else {
			i1 += length * 2;
		}
	}

	i1 = ioptr;
	for (i = 0; i < length; i++) {
		for (j = 0; j < halfLength; j++) {
			rev = bRLow[j];
			if (j < rev) {
				i2 = i1 + (rev * 2);
				tempr = i1[j*2];
				tempi = i1[j*2 + 1];
				i1[j*2] = i2[0];
				i1[j*2 + 1] = i2[1];
				i2[0] = tempr;
				i2[1] = tempi;
			}
		}
		i1 += length * 2;
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fft2pt(FFT_TYPE *ioptr)
{
	FFT_TYPE r0 = ioptr[0];
	FFT_TYPE i0 = ioptr[1];
	FFT_TYPE r1 = ioptr[2];
	FFT_TYPE i1 = ioptr[3];

	ioptr[0] = r0 + r1;
	ioptr[1] = i0 + i1;
	ioptr[2] = r0 - r1;
	ioptr[3] = i0 - i1;
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fft4pt(FFT_TYPE *ioptr)
{
	FFT_TYPE r0 = ioptr[0] + ioptr[4];
	FFT_TYPE i0 = ioptr[1] + ioptr[5];
	FFT_TYPE r1 = ioptr[0] - ioptr[4];
	FFT_TYPE i1 = ioptr[1] - ioptr[5];
	FFT_TYPE r2 = ioptr[2] + ioptr[6];
	FFT_TYPE i2 = ioptr[3] + ioptr[7];
	FFT_TYPE r3 = ioptr[2] - ioptr[6];
	FFT_TYPE i3 = ioptr[3] - ioptr[7];

	ioptr[0] = r0 + r2;
	ioptr[1] = i0 + i2;
	ioptr[4] = r0 - r2;
	ioptr[5] = i0 - i2;
	ioptr[2] = r1 + i3;
	ioptr[3] = i1 - r3;
	ioptr[6] = r1 - i3;
	ioptr[7] = i1 + r3;
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::fft8pt(FFT_TYPE *ioptr)
{
	FFT_TYPE r0 = ioptr[0];
	FFT_TYPE i0 = ioptr[1];
	FFT_TYPE r1 = ioptr[2];
	FFT_TYPE i1 = ioptr[3];
	FFT_TYPE r2 = ioptr[4];
	FFT_TYPE i2 = ioptr[5];
	FFT_TYPE r3 = ioptr[6];
	FFT_TYPE i3 = ioptr[7];
	FFT_TYPE r4 = ioptr[8];
	FFT_TYPE i4 = ioptr[9];
	FFT_TYPE r5 = ioptr[10];
	FFT_TYPE i5 = ioptr[11];
	FFT_TYPE r6 = ioptr[12];
	FFT_TYPE i6 = ioptr[13];
	FFT_TYPE r7 = ioptr[14];
	FFT_TYPE i7 = ioptr[15];

	FFT_TYPE t0r = r0 + r4;
	FFT_TYPE t0i = i0 + i4;
	FFT_TYPE t4r = r0 - r4;
	FFT_TYPE t4i = i0 - i4;
	FFT_TYPE t1r = r1 + r5;
	FFT_TYPE t1i = i1 + i5;
	FFT_TYPE t5r = r1 - r5;
	FFT_TYPE t5i = i1 - i5;
	FFT_TYPE t2r = r2 + r6;
	FFT_TYPE t2i = i2 + i6;
	FFT_TYPE t6r = r2 - r6;
	FFT_TYPE t6i = i2 - i6;
	FFT_TYPE t3r = r3 + r7;
	FFT_TYPE t3i = i3 + i7;
	FFT_TYPE t7r = r3 - r7;
	FFT_TYPE t7i = i3 - i7;

	FFT_TYPE u0r = t0r + t2r;
	FFT_TYPE u0i = t0i + t2i;
	FFT_TYPE u2r = t0r - t2r;
	FFT_TYPE u2i = t0i - t2i;
	FFT_TYPE u1r = t1r + t3r;
	FFT_TYPE u1i = t1i + t3i;
	FFT_TYPE u3r = t1r - t3r;
	FFT_TYPE u3i = t1i - t3i;

	ioptr[0] = u0r + u1r;
	ioptr[1] = u0i + u1i;
	ioptr[8] = u0r - u1r;
	ioptr[9] = u0i - u1i;
	ioptr[4] = u2r + u3i;
	ioptr[5] = u2i - u3r;
	ioptr[12] = u2r - u3i;
	ioptr[13] = u2i + u3r;

	FFT_TYPE c1 = (FFT_TYPE)RTTY_FFT_COSPID8;
	FFT_TYPE s1 = (FFT_TYPE)RTTY_FFT_SINPID8;
	(void)c1;
	(void)s1;
	FFT_TYPE v5r = (t5r - t5i) * (FFT_TYPE)0.7071067811865475;
	FFT_TYPE v5i = (t5r + t5i) * (FFT_TYPE)0.7071067811865475;
	FFT_TYPE v7r = (t7r + t7i) * (FFT_TYPE)0.7071067811865475;
	FFT_TYPE v7i = (-t7r + t7i) * (FFT_TYPE)0.7071067811865475;

	FFT_TYPE w4r = t4r + t6i;
	FFT_TYPE w4i = t4i - t6r;
	FFT_TYPE w6r = t4r - t6i;
	FFT_TYPE w6i = t4i + t6r;

	ioptr[2] = w4r + v5r;
	ioptr[3] = w4i + v5i;
	ioptr[10] = w4r - v5r;
	ioptr[11] = w4i - v5i;
	ioptr[6] = w6r + v7i;
	ioptr[7] = w6i - v7r;
	ioptr[14] = w6r - v7i;
	ioptr[15] = w6i + v7r;
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::bfR2(FFT_TYPE *ioptr, int M, int NDiffU)
{
	int N = RTTY_POW2(M);
	int halfN = N >> 1;
	FFT_TYPE *i1 = ioptr;
	FFT_TYPE *i2 = ioptr + halfN * 2;
	FFT_TYPE tempr, tempi;

	for (int i = 0; i < halfN; i++) {
		tempr = *i1 - *i2;
		tempi = *(i1+1) - *(i2+1);
		*i1 = *i1 + *i2;
		*(i1+1) = *(i1+1) + *(i2+1);
		*i2 = tempr;
		*(i2+1) = tempi;
		i1 += 2;
		i2 += 2;
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::bfR4(FFT_TYPE *ioptr, int M, int NDiffU)
{
	int N = RTTY_POW2(M);
	int quarterN = N >> 2;
	FFT_TYPE *i0 = ioptr;
	FFT_TYPE *i1 = ioptr + quarterN * 2;
	FFT_TYPE *i2 = ioptr + quarterN * 4;
	FFT_TYPE *i3 = ioptr + quarterN * 6;
	FFT_TYPE r0, i_0, r1, i_1, r2, i_2, r3, i_3;
	FFT_TYPE t0r, t0i, t1r, t1i, t2r, t2i, t3r, t3i;

	for (int i = 0; i < quarterN; i++) {
		r0 = *i0; i_0 = *(i0+1);
		r1 = *i1; i_1 = *(i1+1);
		r2 = *i2; i_2 = *(i2+1);
		r3 = *i3; i_3 = *(i3+1);

		t0r = r0 + r2; t0i = i_0 + i_2;
		t1r = r0 - r2; t1i = i_0 - i_2;
		t2r = r1 + r3; t2i = i_1 + i_3;
		t3r = r1 - r3; t3i = i_1 - i_3;

		*i0 = t0r + t2r; *(i0+1) = t0i + t2i;
		*i2 = t0r - t2r; *(i2+1) = t0i - t2i;
		*i1 = t1r + t3i; *(i1+1) = t1i - t3r;
		*i3 = t1r - t3i; *(i3+1) = t1i + t3r;

		i0 += 2; i1 += 2; i2 += 2; i3 += 2;
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::bfstages(FFT_TYPE *ioptr, int M, FFT_TYPE *uTbl,
								   int Ustride, int NDiffU, int StageCnt)
{
	int N = RTTY_POW2(M);
	int halfN = N >> 1;
	FFT_TYPE *i1, *i2;
	FFT_TYPE tempr, tempi, wr, wi;
	int uIdx;

	for (int stage = 0; stage < StageCnt; stage++) {
		int step = halfN >> stage;
		for (int group = 0; group < (1 << stage); group++) {
			i1 = ioptr + group * step * 4;
			i2 = i1 + step * 2;
			for (int j = 0; j < step; j++) {
				uIdx = j * Ustride * (1 << stage);
				wr = uTbl[uIdx];
				wi = -uTbl[NDiffU - uIdx];
				tempr = i2[0] * wr - i2[1] * wi;
				tempi = i2[0] * wi + i2[1] * wr;
				i2[0] = i1[0] - tempr;
				i2[1] = i1[1] - tempi;
				i1[0] = i1[0] + tempr;
				i1[1] = i1[1] + tempi;
				i1 += 2;
				i2 += 2;
			}
		}
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::ffts1(FFT_TYPE *ioptr, int M, FFT_TYPE *uTbl, short *bRLow)
{
	int N = RTTY_POW2(M);
	int NDiffU = N / 4;

	if (M <= 3) {
		bitrevR2(ioptr, M, bRLow);
		if (M == 1) fft2pt(ioptr);
		else if (M == 2) fft4pt(ioptr);
		else if (M == 3) fft8pt(ioptr);
		return;
	}

	bfstages(ioptr, M, uTbl, 1, NDiffU, M - 3);
	bitrevR2(ioptr, M, bRLow);
	for (int i = 0; i < N; i += 8) {
		fft8pt(ioptr + i * 2);
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::ComplexFFT(std::complex<FFT_TYPE> *buf)
{
	ffts1(reinterpret_cast<FFT_TYPE*>(buf), FFT_N, Utbl, BRLow);
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::InverseComplexFFT(std::complex<FFT_TYPE> *buf)
{
	int N = RTTY_POW2(FFT_N);
	FFT_TYPE *ioptr = reinterpret_cast<FFT_TYPE*>(buf);
	for (int i = 0; i < N; i++) {
		ioptr[2*i + 1] = -ioptr[2*i + 1];
	}
	ffts1(ioptr, FFT_N, Utbl, BRLow);
	FFT_TYPE scale = (FFT_TYPE)(1.0 / (double)N);
	for (int i = 0; i < N; i++) {
		ioptr[2*i] *= scale;
		ioptr[2*i + 1] = -ioptr[2*i + 1] * scale;
	}
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::RealFFT(std::complex<FFT_TYPE> *buf)
{
	ComplexFFT(buf);
}

template <typename FFT_TYPE>
void rtty_gfft<FFT_TYPE>::InverseRealFFT(std::complex<FFT_TYPE> *buf)
{
	InverseComplexFFT(buf);
}

template <typename FFT_TYPE>
FFT_TYPE rtty_gfft<FFT_TYPE>::GetInverseComplexFFTScale()
{
	return (FFT_TYPE)(1.0 / (double)RTTY_POW2(FFT_N));
}

template <typename FFT_TYPE>
FFT_TYPE rtty_gfft<FFT_TYPE>::GetInverseRealFFTScale()
{
	return (FFT_TYPE)(1.0 / (double)RTTY_POW2(FFT_N));
}

#endif // RTTY_GFFT_HPP
