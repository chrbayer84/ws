/********************************************************************************
** Form generated from reading UI file 'Configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgets/CheckableItemComboBox.hpp"
#include "widgets/DecodeHighlightingListView.hpp"
#include "widgets/LazyFillComboBox.hpp"

QT_BEGIN_NAMESPACE

class Ui_configuration_dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *configuration_tabs;
    QWidget *general_tab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *station_group_box;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_14;
    QFormLayout *formLayout_3;
    QLabel *callsign_label;
    QLineEdit *callsign_line_edit;
    QFormLayout *formLayout_12;
    QLabel *grid_label;
    QLineEdit *grid_line_edit;
    QCheckBox *use_dynamic_grid;
    QFormLayout *formLayout_2;
    QLabel *label_12;
    QComboBox *region_combo_box;
    QFormLayout *formLayout_13;
    QLabel *label_5;
    QComboBox *type_2_msg_gen_combo_box;
    QFrame *line_5;
    QGroupBox *display_group_box;
    QGridLayout *gridLayout_4;
    QCheckBox *DXCC_check_box;
    QCheckBox *decodes_from_top_check_box;
    QPushButton *decoded_text_font_push_button;
    QPushButton *font_push_button;
    QCheckBox *TX_messages_check_box;
    QCheckBox *ppfx_check_box;
    QCheckBox *insert_blank_check_box;
    QCheckBox *show_country_names_check_box;
    QCheckBox *miles_check_box;
    QCheckBox *cb_detailed_blank_line;
    QHBoxLayout *DXCallGrid_Layout;
    QCheckBox *cbHighlightDXcall;
    QCheckBox *cbHighlightDXgrid;
    QCheckBox *cbHighlightRogers;
    QFrame *line_7;
    QGroupBox *behaviour_group_box;
    QGridLayout *gridLayout_8;
    QCheckBox *monitor_last_used_check_box;
    QCheckBox *auto_astro_check_box;
    QCheckBox *force_call_1st_check_box;
    QHBoxLayout *TxWatchdog_Layout;
    QCheckBox *tune_watchdog_check_box;
    QSpinBox *tune_watchdog_spin_box;
    QSpacerItem *horizontalSpacer;
    QLabel *label_10;
    QSpinBox *tx_watchdog_spin_box;
    QCheckBox *monitor_off_check_box;
    QCheckBox *enable_VHF_features_check_box;
    QCheckBox *progress_bar_check_box;
    QCheckBox *decode_at_52s_check_box;
    QCheckBox *repeat_Tx_check_box;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QSpinBox *CW_id_interval_spin_box;
    QCheckBox *quick_call_check_box;
    QCheckBox *single_decode_check_box;
    QCheckBox *kHz_without_k_check_box;
    QCheckBox *CW_id_after_73_check_box;
    QCheckBox *disable_TX_on_73_check_box;
    QCheckBox *alternate_bindings_check_box;
    QCheckBox *tx_QSY_check_box;
    QFrame *line_2;
    QGroupBox *additional_features_box;
    QGridLayout *gridLayout_17;
    QSpinBox *align_spin_box;
    QCheckBox *cb_showDistance;
    QCheckBox *cb_showAzimuth;
    QSpinBox *align_spin_box2;
    QCheckBox *cb_Align;
    QCheckBox *cbEraseBandActivity;
    QCheckBox *Map_Grid_to_State;
    QCheckBox *cbClearDXgrid;
    QCheckBox *cbClearDXcall;
    QCheckBox *band_hopping_every_minute_check_box;
    QCheckBox *alternate_erase_button_check_box;
    QCheckBox *cbRxToTxAfterQSO;
    QCheckBox *cbErase_when_mode_changed;
    QCheckBox *enable_Wait_features_check_box;
    QWidget *radio_tab;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_13;
    QGroupBox *split_operation_group_box;
    QGridLayout *gridLayout_12;
    QRadioButton *split_emulate_radio_button;
    QRadioButton *split_rig_radio_button;
    QRadioButton *split_none_radio_button;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *mode_group_box;
    QGridLayout *gridLayout_10;
    QRadioButton *mode_USB_radio_button;
    QRadioButton *mode_none_radio_button;
    QRadioButton *mode_data_radio_button;
    QFrame *line_4;
    QFrame *line_3;
    QGroupBox *CAT_control_group_box;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *CAT_port_label;
    QComboBox *CAT_port_combo_box;
    QGroupBox *CAT_serial_port_parameters_group_box;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_5;
    QLabel *CAT_baud_label;
    QComboBox *CAT_serial_baud_combo_box;
    QGroupBox *CAT_data_bits_group_box;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *CAT_default_bit_radio_button;
    QRadioButton *CAT_7_bit_radio_button;
    QRadioButton *CAT_8_bit_radio_button;
    QGroupBox *CAT_stop_bits_group_box;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *CAT_default_stop_bit_radio_button;
    QRadioButton *CAT_one_stop_bit_radio_button;
    QRadioButton *CAT_two_stop_bit_radio_button;
    QGroupBox *CAT_handshake_group_box;
    QGridLayout *gridLayout_11;
    QRadioButton *CAT_handshake_default_radio_button;
    QRadioButton *CAT_handshake_none_radio_button;
    QRadioButton *CAT_handshake_xon_radio_button;
    QRadioButton *CAT_handshake_hardware_radio_button;
    QGroupBox *CAT_control_lines_group_box;
    QHBoxLayout *horizontalLayout_8;
    QFormLayout *formLayout_8;
    QComboBox *force_DTR_combo_box;
    QLabel *force_DTR_label;
    QFormLayout *formLayout_9;
    QLabel *force_RTS_label;
    QComboBox *force_RTS_combo_box;
    QFrame *line;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *test_CAT_push_button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *test_PTT_push_button;
    QFrame *line_6;
    QGroupBox *PTT_method_group_box;
    QGridLayout *gridLayout_2;
    QRadioButton *PTT_VOX_radio_button;
    QRadioButton *PTT_DTR_radio_button;
    QRadioButton *PTT_CAT_radio_button;
    QRadioButton *PTT_RTS_radio_button;
    QFormLayout *formLayout_4;
    QLabel *PTT_port_label;
    QComboBox *PTT_port_combo_box;
    QCheckBox *tx_inhibit_check_box;
    QGroupBox *hamlib_groupBox;
    QGridLayout *gridLayout_24;
    QRadioButton *rbHamlib32;
    QPushButton *revert_update_button;
    QPushButton *hamlib_download_button;
    QGridLayout *hamlib_version_gridLayout;
    QLabel *in_use_text;
    QLabel *in_use;
    QLabel *backed_up_text;
    QLabel *backed_up;
    QRadioButton *rbHamlib64;
    QHBoxLayout *horizontalLayout_7;
    QLabel *rig_label;
    QComboBox *rig_combo_box;
    QLabel *CAT_poll_interval_label;
    QSpinBox *CAT_poll_interval_spin_box;
    QSpacerItem *verticalSpacer_7;
    QGroupBox *rig_data_group_box;
    QGridLayout *gridLayout_25;
    QCheckBox *PWR_and_SWR_check_box;
    QSpacerItem *verticalSpacer;
    QCheckBox *check_SWR_check_box;
    QCheckBox *highlight_ALC1_check_box;
    QCheckBox *highlight_ALC2_check_box;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *TX_audio_source_group_box;
    QGridLayout *gridLayout_7;
    QRadioButton *TX_source_data_radio_button;
    QRadioButton *TX_source_mic_radio_button;
    QWidget *audio_tab;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *soundcard_group_box;
    QGridLayout *gridLayout_6;
    QLabel *sound_input_label;
    QLabel *sound_output_label;
    QComboBox *sound_output_channel_combo_box;
    QComboBox *sound_input_channel_combo_box;
    LazyFillComboBox *sound_input_combo_box;
    LazyFillComboBox *sound_output_combo_box;
    QPushButton *refresh_push_button;
    QHBoxLayout *sound_settings_layout;
    QCheckBox *tci_audio_check_box;
    QSpinBox *TCI_spin_box;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *cbSortAlphabetically;
    QCheckBox *cbHideCARD;
    QGroupBox *save_path_group_box;
    QHBoxLayout *horizontalLayout_5;
    QLabel *save_path_label;
    QLineEdit *save_path_display_label;
    QPushButton *save_path_select_push_button;
    QGroupBox *azel_path_group_box;
    QGridLayout *gridLayout_27;
    QHBoxLayout *AzEl_Layout;
    QLabel *azel_path_label;
    QLineEdit *azel_path_display_label;
    QPushButton *azel_path_select_push_button;
    QCheckBox *checkBoxAzElExtraLines;
    QGroupBox *split_operation_group_box_2;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBoxPwrBandTxMemory;
    QCheckBox *checkBoxPwrBandTuneMemory;
    QSpacerItem *verticalSpacer_3;
    QWidget *tx_macros_tab;
    QGridLayout *gridLayout;
    QPushButton *add_macro_push_button;
    QLineEdit *add_macro_line_edit;
    QPushButton *delete_macro_push_button;
    QListView *macros_list_view;
    QWidget *reporting_tab;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *logging_group_box;
    QGridLayout *gridLayout_14;
    QCheckBox *prompt_to_log_check_box;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *cbLogDialFrequency;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *cbAutoLog;
    QCheckBox *cbContestingOnly;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *logfileLayout;
    QLabel *logpath_label;
    QLineEdit *logpath_lineEdit;
    QPushButton *logpath_select_pushButton;
    QCheckBox *cbZZ00;
    QCheckBox *cbLog4digitGrids;
    QLabel *label_13;
    QLineEdit *opCallEntry;
    QCheckBox *report_in_comments_check_box;
    QCheckBox *log_as_RTTY_check_box;
    QCheckBox *specOp_in_comments_check_box;
    QFrame *line_8;
    QGroupBox *network_group_box;
    QGridLayout *gridLayout_29;
    QCheckBox *psk_reporter_check_box;
    QCheckBox *psk_reporter_tcpip_check_box;
    QGroupBox *livecq_group_box;
    QGridLayout *gridLayout_livecq;
    QCheckBox *livecq_check_box;
    QHBoxLayout *livecq_w3sz_layout;
    QCheckBox *livecq_official_check_box;
    QComboBox *livecq_w3sz_id_combo_box;
    QCheckBox *livecq_n6nu_check_box;
    QHBoxLayout *liveCQ_horizontalLayout;
    QCheckBox *livecq_custom_check_box;
    QLineEdit *livecq_other_url_line_edit;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_16;
    QFormLayout *formLayout_6;
    QLabel *udp_server_label;
    QLineEdit *udp_server_line_edit;
    QLabel *label_6;
    QSpinBox *udp_server_port_spin_box;
    QLabel *udp_interfaces_label;
    CheckableItemComboBox *udp_interfaces_combo_box;
    QLabel *udp_TTL_label;
    QSpinBox *udp_TTL_spin_box;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *accept_udp_requests_check_box;
    QCheckBox *udpWindowToFront;
    QCheckBox *udpWindowRestore;
    QCheckBox *udpWSJTXCompatibilityMode;
    QGroupBox *n1mm_group_box;
    QFormLayout *formLayout_15;
    QCheckBox *enable_n1mm_broadcast_check_box;
    QLabel *n1mm_server_name_label;
    QLineEdit *n1mm_server_name_line_edit;
    QLabel *n1mm_server_port_label;
    QSpinBox *n1mm_server_port_spin_box;
    QSpacerItem *verticalSpacer_4;
    QWidget *frequencies_tab;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *calibration_slope_ppm_spin_box;
    QFormLayout *formLayout_14;
    QLabel *label_7;
    QDoubleSpinBox *calibration_intercept_spin_box;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTableView *frequencies_table_view;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QTableView *stations_table_view;
    QWidget *colors_tab;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *reset_highlighting_to_defaults_push_button;
    QPushButton *reset_highlighting_to_defaults2_push_button;
    QPushButton *rescan_log_push_button;
    DecodeHighlightingListView *highlighting_list_view;
    QGridLayout *gridLayout_23;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *highlight_orange_check_box;
    QVBoxLayout *highlight_verticalLayout;
    QCheckBox *highlight_by_mode_check_box;
    QCheckBox *only_fields_check_box;
    QCheckBox *include_WAE_check_box;
    QCheckBox *highlight_73_check_box;
    QCheckBox *highlight_all_check_box;
    QLineEdit *highlight_orange_callsigns;
    QCheckBox *highlight_blue_check_box;
    QLineEdit *highlight_blue_callsigns;
    QGroupBox *groupBox_11;
    QFormLayout *formLayout_18;
    QLabel *label_15;
    QHBoxLayout *LotW_Layout;
    QLineEdit *LotW_CSV_URL_line_edit;
    QPushButton *LotW_CSV_fetch_push_button;
    QHBoxLayout *LotW_Layout_2;
    QSpinBox *LotW_days_since_upload_spin_box;
    QSpacerItem *horizontalSpacer_2;
    QLabel *LotW_CSV_status_label;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *downloads_groupBox;
    QGridLayout *gridLayout_21;
    QPushButton *CALL3_download_button;
    QLabel *CTY_file_label;
    QLabel *callsign_states_label;
    QLabel *CALL3_file_label;
    QPushButton *CALL3_EME_download_button;
    QPushButton *callsign_states_download_button;
    QPushButton *CTY_download_button;
    QWidget *advanced_tab;
    QGridLayout *gridLayout_9;
    QGroupBox *gbCloudlog;
    QGridLayout *gridLayout_22;
    QGridLayout *cloudlog_gridLayout;
    QLabel *api_url_label;
    QLabel *api_key_label;
    QLabel *station_id_label;
    QSpinBox *sbCloudlogStationID;
    QLineEdit *leCloudlogApiKey;
    QLineEdit *leCloudlogApiUrl;
    QPushButton *pbTestCloudlog;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout_10;
    QLabel *label_3;
    QDoubleSpinBox *sbDegrade;
    QLabel *label_9;
    QSpinBox *sbBandwidth;
    QLabel *label_11;
    QDoubleSpinBox *sbTxDelay;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *cbx2ToneSpacing;
    QCheckBox *cbx4ToneSpacing;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_16;
    QRadioButton *rbLowSidelobes;
    QRadioButton *rbMaxSensitivity;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_11;
    QLabel *label_2;
    QSpinBox *sbNtrials;
    QLabel *label_4;
    QSpinBox *sbAggressive;
    QCheckBox *cbTwoPass;
    QGroupBox *gbEQSL;
    QGridLayout *gridLayout_220;
    QGridLayout *eqsl_gridLayout;
    QLabel *eqsluser_label;
    QLabel *eqslpasswd_label;
    QLabel *eqslnick_label;
    QLineEdit *eqslnick_edit;
    QLineEdit *eqslpasswd_edit;
    QLineEdit *eqsluser_edit;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_26;
    QCheckBox *cbHighDPI;
    QCheckBox *cbLargerTabWidget;
    QGroupBox *gbSpecialOpActivity;
    QGridLayout *gridLayout_15;
    QRadioButton *rbARRL_Digi;
    QRadioButton *rbWW_DIGI;
    QCheckBox *cb_NCCC_Sprint;
    QHBoxLayout *horizontalLayout_17;
    QRadioButton *rbField_Day;
    QSpacerItem *horizontalSpacer_9;
    QFormLayout *formLayout_16;
    QLabel *labFD;
    QLineEdit *Field_Day_Exchange;
    QHBoxLayout *foxLayout_23;
    QRadioButton *rbHound;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *rbRTTY_Roundup;
    QSpacerItem *horizontalSpacer_10;
    QFormLayout *formLayout_17;
    QLabel *labRTTY;
    QLineEdit *RTTY_Exchange;
    QRadioButton *rbEU_VHF_Contest;
    QCheckBox *cbSuperFox;
    QHBoxLayout *OTP_Layout_2;
    QCheckBox *cbShowOTP;
    QSpacerItem *horizontalSpacer_18;
    QLabel *lblOTPUrl;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *OTPUrl;
    QRadioButton *rbNA_VHF_Contest;
    QRadioButton *rbFox;
    QHBoxLayout *OTP_Layout;
    QCheckBox *cbOTP;
    QSpacerItem *horizontalSpacer_11;
    QLabel *lblOTPSeed;
    QLineEdit *OTPSeed;
    QSpacerItem *horizontalSpacer_19;
    QLabel *lblOTPEvery;
    QSpinBox *sbOTPinterval;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_24;
    QCheckBox *cbContestName;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_25;
    QLabel *labCN;
    QLineEdit *Contest_Name;
    QRadioButton *rbQ65pileup;
    QSpacerItem *verticalSpacer_9;
    QWidget *alerts_tab;
    QGridLayout *gridLayout_20;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_25;
    QLabel *label_19;
    QLabel *label_21;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_24;
    QLabel *label_20;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_18;
    QCheckBox *cbMyCall;
    QCheckBox *cbUSState;
    QCheckBox *cbGrid;
    QCheckBox *cbQSYmessage;
    QCheckBox *cbWanted;
    QCheckBox *cbDXCCOB;
    QFrame *line_9;
    QCheckBox *cbContinentOB;
    QCheckBox *cbGridOB;
    QCheckBox *cbITUZ;
    QCheckBox *cbCQZ;
    QCheckBox *cbCQ;
    QCheckBox *cbDXCC;
    QCheckBox *cbDXcall;
    QCheckBox *cbContinent;
    QCheckBox *cbCQZOB;
    QCheckBox *cbITUZOB;
    QCheckBox *cbUSStateOB;
    QLabel *label_16;
    QHBoxLayout *voiceSelectLayout;
    QLabel *voicesLabel;
    QComboBox *voices_combo_box;
    QSpacerItem *voiceSpacer_1;
    QPushButton *pb_test_alerts;
    QSpacerItem *voiceSpacer_2;
    QLabel *label_17;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pbAlerts;
    QSpacerItem *horizontalSpacer_21;
    QWidget *filters_tab;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_19;
    QLineEdit *Blacklist10;
    QLineEdit *Whitelist3;
    QLineEdit *Blacklist5;
    QLabel *territory_label;
    QLabel *blacklist_label;
    QLineEdit *Blacklist11;
    QLineEdit *Blacklist3;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_10;
    QLineEdit *Pass2;
    QLineEdit *Whitelist11;
    QLineEdit *Blacklist8;
    QLineEdit *Whitelist7;
    QLineEdit *Blacklist1;
    QCheckBox *cbBlacklist;
    QLineEdit *Pass12;
    QLineEdit *Blacklist9;
    QLineEdit *Whitelist5;
    QLineEdit *Pass3;
    QCheckBox *cbWhitelist;
    QLineEdit *Whitelist1;
    QLineEdit *Whitelist12;
    QLineEdit *Territory1;
    QCheckBox *cb_filters_for_Wait_and_Pounce_only;
    QLineEdit *Territory4;
    QLineEdit *Pass9;
    QLineEdit *Whitelist10;
    QLineEdit *Pass10;
    QLineEdit *Blacklist7;
    QLineEdit *Whitelist4;
    QLineEdit *Pass6;
    QLineEdit *Pass4;
    QLineEdit *Blacklist12;
    QLineEdit *Whitelist9;
    QLineEdit *Blacklist2;
    QLineEdit *Pass8;
    QSpacerItem *verticalSpacer_12;
    QLineEdit *Whitelist2;
    QLineEdit *Blacklist6;
    QCheckBox *cbPass;
    QLineEdit *Pass1;
    QLineEdit *Pass7;
    QLabel *whitelist_label;
    QLineEdit *Pass5;
    QLineEdit *Whitelist8;
    QCheckBox *cb_filters_for_word2;
    QLineEdit *Pass11;
    QLineEdit *Blacklist4;
    QLabel *always_pass_label;
    QLineEdit *Territory2;
    QLineEdit *Territory3;
    QLineEdit *Whitelist6;
    QCheckBox *cb_twoDays;
    QDialogButtonBox *configuration_dialog_button_box;
    QButtonGroup *TX_mode_button_group;
    QButtonGroup *special_op_activity_button_group;
    QButtonGroup *split_mode_button_group;
    QButtonGroup *TX_audio_source_button_group;
    QButtonGroup *PTT_method_button_group;
    QButtonGroup *CAT_stop_bits_button_group;
    QButtonGroup *CAT_handshake_button_group;
    QButtonGroup *CAT_data_bits_button_group;

    void setupUi(QDialog *configuration_dialog)
    {
        if (configuration_dialog->objectName().isEmpty())
            configuration_dialog->setObjectName(QString::fromUtf8("configuration_dialog"));
        configuration_dialog->resize(826, 700);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(configuration_dialog->sizePolicy().hasHeightForWidth());
        configuration_dialog->setSizePolicy(sizePolicy);
        configuration_dialog->setMinimumSize(QSize(500, 400));
        verticalLayout_2 = new QVBoxLayout(configuration_dialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        scrollArea = new QScrollArea(configuration_dialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(490, 390));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 808, 683));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        configuration_tabs = new QTabWidget(scrollAreaWidgetContents_2);
        configuration_tabs->setObjectName(QString::fromUtf8("configuration_tabs"));
        general_tab = new QWidget();
        general_tab->setObjectName(QString::fromUtf8("general_tab"));
        verticalLayout_4 = new QVBoxLayout(general_tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        station_group_box = new QGroupBox(general_tab);
        station_group_box->setObjectName(QString::fromUtf8("station_group_box"));
        verticalLayout_12 = new QVBoxLayout(station_group_box);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        callsign_label = new QLabel(station_group_box);
        callsign_label->setObjectName(QString::fromUtf8("callsign_label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, callsign_label);

        callsign_line_edit = new QLineEdit(station_group_box);
        callsign_line_edit->setObjectName(QString::fromUtf8("callsign_line_edit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, callsign_line_edit);


        horizontalLayout_14->addLayout(formLayout_3);

        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        grid_label = new QLabel(station_group_box);
        grid_label->setObjectName(QString::fromUtf8("grid_label"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, grid_label);

        grid_line_edit = new QLineEdit(station_group_box);
        grid_line_edit->setObjectName(QString::fromUtf8("grid_line_edit"));

        formLayout_12->setWidget(0, QFormLayout::FieldRole, grid_line_edit);


        horizontalLayout_14->addLayout(formLayout_12);

        use_dynamic_grid = new QCheckBox(station_group_box);
        use_dynamic_grid->setObjectName(QString::fromUtf8("use_dynamic_grid"));

        horizontalLayout_14->addWidget(use_dynamic_grid);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_12 = new QLabel(station_group_box);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_12);

        region_combo_box = new QComboBox(station_group_box);
        region_combo_box->setObjectName(QString::fromUtf8("region_combo_box"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, region_combo_box);


        horizontalLayout_14->addLayout(formLayout_2);


        verticalLayout_12->addLayout(horizontalLayout_14);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QString::fromUtf8("formLayout_13"));
        label_5 = new QLabel(station_group_box);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_5);

        type_2_msg_gen_combo_box = new QComboBox(station_group_box);
        type_2_msg_gen_combo_box->addItem(QString());
        type_2_msg_gen_combo_box->addItem(QString());
        type_2_msg_gen_combo_box->addItem(QString());
        type_2_msg_gen_combo_box->setObjectName(QString::fromUtf8("type_2_msg_gen_combo_box"));
        type_2_msg_gen_combo_box->setEnabled(true);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, type_2_msg_gen_combo_box);


        verticalLayout_12->addLayout(formLayout_13);


        verticalLayout_4->addWidget(station_group_box);

        line_5 = new QFrame(general_tab);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        display_group_box = new QGroupBox(general_tab);
        display_group_box->setObjectName(QString::fromUtf8("display_group_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(display_group_box->sizePolicy().hasHeightForWidth());
        display_group_box->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(display_group_box);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        DXCC_check_box = new QCheckBox(display_group_box);
        DXCC_check_box->setObjectName(QString::fromUtf8("DXCC_check_box"));
        DXCC_check_box->setChecked(false);

        gridLayout_4->addWidget(DXCC_check_box, 5, 0, 1, 1);

        decodes_from_top_check_box = new QCheckBox(display_group_box);
        decodes_from_top_check_box->setObjectName(QString::fromUtf8("decodes_from_top_check_box"));

        gridLayout_4->addWidget(decodes_from_top_check_box, 0, 0, 1, 1);

        decoded_text_font_push_button = new QPushButton(display_group_box);
        decoded_text_font_push_button->setObjectName(QString::fromUtf8("decoded_text_font_push_button"));

        gridLayout_4->addWidget(decoded_text_font_push_button, 3, 2, 1, 1);

        font_push_button = new QPushButton(display_group_box);
        font_push_button->setObjectName(QString::fromUtf8("font_push_button"));

        gridLayout_4->addWidget(font_push_button, 2, 2, 1, 1);

        TX_messages_check_box = new QCheckBox(display_group_box);
        TX_messages_check_box->setObjectName(QString::fromUtf8("TX_messages_check_box"));

        gridLayout_4->addWidget(TX_messages_check_box, 3, 0, 1, 1);

        ppfx_check_box = new QCheckBox(display_group_box);
        ppfx_check_box->setObjectName(QString::fromUtf8("ppfx_check_box"));

        gridLayout_4->addWidget(ppfx_check_box, 5, 1, 1, 1);

        insert_blank_check_box = new QCheckBox(display_group_box);
        insert_blank_check_box->setObjectName(QString::fromUtf8("insert_blank_check_box"));

        gridLayout_4->addWidget(insert_blank_check_box, 0, 1, 1, 1);

        show_country_names_check_box = new QCheckBox(display_group_box);
        show_country_names_check_box->setObjectName(QString::fromUtf8("show_country_names_check_box"));

        gridLayout_4->addWidget(show_country_names_check_box, 5, 2, 1, 1);

        miles_check_box = new QCheckBox(display_group_box);
        miles_check_box->setObjectName(QString::fromUtf8("miles_check_box"));

        gridLayout_4->addWidget(miles_check_box, 2, 0, 1, 1);

        cb_detailed_blank_line = new QCheckBox(display_group_box);
        cb_detailed_blank_line->setObjectName(QString::fromUtf8("cb_detailed_blank_line"));

        gridLayout_4->addWidget(cb_detailed_blank_line, 0, 2, 1, 1);

        DXCallGrid_Layout = new QHBoxLayout();
        DXCallGrid_Layout->setObjectName(QString::fromUtf8("DXCallGrid_Layout"));
        cbHighlightDXcall = new QCheckBox(display_group_box);
        cbHighlightDXcall->setObjectName(QString::fromUtf8("cbHighlightDXcall"));

        DXCallGrid_Layout->addWidget(cbHighlightDXcall);

        cbHighlightDXgrid = new QCheckBox(display_group_box);
        cbHighlightDXgrid->setObjectName(QString::fromUtf8("cbHighlightDXgrid"));

        DXCallGrid_Layout->addWidget(cbHighlightDXgrid);


        gridLayout_4->addLayout(DXCallGrid_Layout, 2, 1, 1, 1);

        cbHighlightRogers = new QCheckBox(display_group_box);
        cbHighlightRogers->setObjectName(QString::fromUtf8("cbHighlightRogers"));

        gridLayout_4->addWidget(cbHighlightRogers, 3, 1, 1, 1);


        verticalLayout_4->addWidget(display_group_box);

        line_7 = new QFrame(general_tab);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_7);

        behaviour_group_box = new QGroupBox(general_tab);
        behaviour_group_box->setObjectName(QString::fromUtf8("behaviour_group_box"));
        sizePolicy2.setHeightForWidth(behaviour_group_box->sizePolicy().hasHeightForWidth());
        behaviour_group_box->setSizePolicy(sizePolicy2);
        gridLayout_8 = new QGridLayout(behaviour_group_box);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        monitor_last_used_check_box = new QCheckBox(behaviour_group_box);
        monitor_last_used_check_box->setObjectName(QString::fromUtf8("monitor_last_used_check_box"));

        gridLayout_8->addWidget(monitor_last_used_check_box, 1, 0, 1, 1);

        auto_astro_check_box = new QCheckBox(behaviour_group_box);
        auto_astro_check_box->setObjectName(QString::fromUtf8("auto_astro_check_box"));

        gridLayout_8->addWidget(auto_astro_check_box, 1, 2, 1, 2);

        force_call_1st_check_box = new QCheckBox(behaviour_group_box);
        force_call_1st_check_box->setObjectName(QString::fromUtf8("force_call_1st_check_box"));

        gridLayout_8->addWidget(force_call_1st_check_box, 6, 0, 1, 1);

        TxWatchdog_Layout = new QHBoxLayout();
        TxWatchdog_Layout->setObjectName(QString::fromUtf8("TxWatchdog_Layout"));
        tune_watchdog_check_box = new QCheckBox(behaviour_group_box);
        tune_watchdog_check_box->setObjectName(QString::fromUtf8("tune_watchdog_check_box"));

        TxWatchdog_Layout->addWidget(tune_watchdog_check_box);

        tune_watchdog_spin_box = new QSpinBox(behaviour_group_box);
        tune_watchdog_spin_box->setObjectName(QString::fromUtf8("tune_watchdog_spin_box"));
        tune_watchdog_spin_box->setMinimum(0);
        tune_watchdog_spin_box->setMaximum(300);
        tune_watchdog_spin_box->setValue(60);

        TxWatchdog_Layout->addWidget(tune_watchdog_spin_box);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TxWatchdog_Layout->addItem(horizontalSpacer);

        label_10 = new QLabel(behaviour_group_box);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        TxWatchdog_Layout->addWidget(label_10, 0, Qt::AlignRight);

        tx_watchdog_spin_box = new QSpinBox(behaviour_group_box);
        tx_watchdog_spin_box->setObjectName(QString::fromUtf8("tx_watchdog_spin_box"));
        tx_watchdog_spin_box->setValue(6);

        TxWatchdog_Layout->addWidget(tx_watchdog_spin_box);

        TxWatchdog_Layout->setStretch(1, 1);
        TxWatchdog_Layout->setStretch(2, 1);
        TxWatchdog_Layout->setStretch(4, 1);

        gridLayout_8->addLayout(TxWatchdog_Layout, 7, 1, 1, 3);

        monitor_off_check_box = new QCheckBox(behaviour_group_box);
        monitor_off_check_box->setObjectName(QString::fromUtf8("monitor_off_check_box"));
        monitor_off_check_box->setChecked(false);

        gridLayout_8->addWidget(monitor_off_check_box, 0, 0, 1, 1);

        enable_VHF_features_check_box = new QCheckBox(behaviour_group_box);
        enable_VHF_features_check_box->setObjectName(QString::fromUtf8("enable_VHF_features_check_box"));

        gridLayout_8->addWidget(enable_VHF_features_check_box, 0, 1, 1, 1);

        progress_bar_check_box = new QCheckBox(behaviour_group_box);
        progress_bar_check_box->setObjectName(QString::fromUtf8("progress_bar_check_box"));

        gridLayout_8->addWidget(progress_bar_check_box, 5, 2, 1, 2);

        decode_at_52s_check_box = new QCheckBox(behaviour_group_box);
        decode_at_52s_check_box->setObjectName(QString::fromUtf8("decode_at_52s_check_box"));

        gridLayout_8->addWidget(decode_at_52s_check_box, 4, 1, 1, 1);

        repeat_Tx_check_box = new QCheckBox(behaviour_group_box);
        repeat_Tx_check_box->setObjectName(QString::fromUtf8("repeat_Tx_check_box"));

        gridLayout_8->addWidget(repeat_Tx_check_box, 0, 2, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(behaviour_group_box);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(label, 0, Qt::AlignRight);

        CW_id_interval_spin_box = new QSpinBox(behaviour_group_box);
        CW_id_interval_spin_box->setObjectName(QString::fromUtf8("CW_id_interval_spin_box"));

        horizontalLayout_9->addWidget(CW_id_interval_spin_box);


        gridLayout_8->addLayout(horizontalLayout_9, 6, 3, 1, 1);

        quick_call_check_box = new QCheckBox(behaviour_group_box);
        quick_call_check_box->setObjectName(QString::fromUtf8("quick_call_check_box"));

        gridLayout_8->addWidget(quick_call_check_box, 4, 0, 1, 1);

        single_decode_check_box = new QCheckBox(behaviour_group_box);
        single_decode_check_box->setObjectName(QString::fromUtf8("single_decode_check_box"));

        gridLayout_8->addWidget(single_decode_check_box, 5, 1, 1, 1);

        kHz_without_k_check_box = new QCheckBox(behaviour_group_box);
        kHz_without_k_check_box->setObjectName(QString::fromUtf8("kHz_without_k_check_box"));

        gridLayout_8->addWidget(kHz_without_k_check_box, 4, 2, 1, 2);

        CW_id_after_73_check_box = new QCheckBox(behaviour_group_box);
        CW_id_after_73_check_box->setObjectName(QString::fromUtf8("CW_id_after_73_check_box"));

        gridLayout_8->addWidget(CW_id_after_73_check_box, 6, 2, 1, 1);

        disable_TX_on_73_check_box = new QCheckBox(behaviour_group_box);
        disable_TX_on_73_check_box->setObjectName(QString::fromUtf8("disable_TX_on_73_check_box"));

        gridLayout_8->addWidget(disable_TX_on_73_check_box, 5, 0, 1, 1);

        alternate_bindings_check_box = new QCheckBox(behaviour_group_box);
        alternate_bindings_check_box->setObjectName(QString::fromUtf8("alternate_bindings_check_box"));

        gridLayout_8->addWidget(alternate_bindings_check_box, 7, 0, 1, 1);

        tx_QSY_check_box = new QCheckBox(behaviour_group_box);
        tx_QSY_check_box->setObjectName(QString::fromUtf8("tx_QSY_check_box"));

        gridLayout_8->addWidget(tx_QSY_check_box, 1, 1, 1, 1);

        gridLayout_8->setColumnStretch(0, 2);

        verticalLayout_4->addWidget(behaviour_group_box);

        line_2 = new QFrame(general_tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        additional_features_box = new QGroupBox(general_tab);
        additional_features_box->setObjectName(QString::fromUtf8("additional_features_box"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(additional_features_box->sizePolicy().hasHeightForWidth());
        additional_features_box->setSizePolicy(sizePolicy4);
        gridLayout_17 = new QGridLayout(additional_features_box);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(-1, -1, -1, 9);
        align_spin_box = new QSpinBox(additional_features_box);
        align_spin_box->setObjectName(QString::fromUtf8("align_spin_box"));
        align_spin_box->setMinimum(-2);
        align_spin_box->setMaximum(10);
        align_spin_box->setValue(1);

        gridLayout_17->addWidget(align_spin_box, 5, 3, 1, 1);

        cb_showDistance = new QCheckBox(additional_features_box);
        cb_showDistance->setObjectName(QString::fromUtf8("cb_showDistance"));

        gridLayout_17->addWidget(cb_showDistance, 5, 0, 1, 1);

        cb_showAzimuth = new QCheckBox(additional_features_box);
        cb_showAzimuth->setObjectName(QString::fromUtf8("cb_showAzimuth"));

        gridLayout_17->addWidget(cb_showAzimuth, 5, 1, 1, 1);

        align_spin_box2 = new QSpinBox(additional_features_box);
        align_spin_box2->setObjectName(QString::fromUtf8("align_spin_box2"));
        align_spin_box2->setMinimum(-8);
        align_spin_box2->setMaximum(5);

        gridLayout_17->addWidget(align_spin_box2, 5, 4, 1, 1);

        cb_Align = new QCheckBox(additional_features_box);
        cb_Align->setObjectName(QString::fromUtf8("cb_Align"));

        gridLayout_17->addWidget(cb_Align, 5, 2, 1, 1);

        cbEraseBandActivity = new QCheckBox(additional_features_box);
        cbEraseBandActivity->setObjectName(QString::fromUtf8("cbEraseBandActivity"));

        gridLayout_17->addWidget(cbEraseBandActivity, 1, 1, 1, 1);

        Map_Grid_to_State = new QCheckBox(additional_features_box);
        Map_Grid_to_State->setObjectName(QString::fromUtf8("Map_Grid_to_State"));

        gridLayout_17->addWidget(Map_Grid_to_State, 1, 0, 1, 1);

        cbClearDXgrid = new QCheckBox(additional_features_box);
        cbClearDXgrid->setObjectName(QString::fromUtf8("cbClearDXgrid"));

        gridLayout_17->addWidget(cbClearDXgrid, 4, 1, 1, 1);

        cbClearDXcall = new QCheckBox(additional_features_box);
        cbClearDXcall->setObjectName(QString::fromUtf8("cbClearDXcall"));

        gridLayout_17->addWidget(cbClearDXcall, 4, 0, 1, 1);

        band_hopping_every_minute_check_box = new QCheckBox(additional_features_box);
        band_hopping_every_minute_check_box->setObjectName(QString::fromUtf8("band_hopping_every_minute_check_box"));

        gridLayout_17->addWidget(band_hopping_every_minute_check_box, 4, 2, 1, 1);

        alternate_erase_button_check_box = new QCheckBox(additional_features_box);
        alternate_erase_button_check_box->setObjectName(QString::fromUtf8("alternate_erase_button_check_box"));

        gridLayout_17->addWidget(alternate_erase_button_check_box, 1, 2, 1, 1);

        cbRxToTxAfterQSO = new QCheckBox(additional_features_box);
        cbRxToTxAfterQSO->setObjectName(QString::fromUtf8("cbRxToTxAfterQSO"));

        gridLayout_17->addWidget(cbRxToTxAfterQSO, 3, 2, 1, 3);

        cbErase_when_mode_changed = new QCheckBox(additional_features_box);
        cbErase_when_mode_changed->setObjectName(QString::fromUtf8("cbErase_when_mode_changed"));

        gridLayout_17->addWidget(cbErase_when_mode_changed, 3, 1, 1, 1);

        enable_Wait_features_check_box = new QCheckBox(additional_features_box);
        enable_Wait_features_check_box->setObjectName(QString::fromUtf8("enable_Wait_features_check_box"));

        gridLayout_17->addWidget(enable_Wait_features_check_box, 3, 0, 1, 1);

        gridLayout_17->setColumnStretch(0, 3);
        gridLayout_17->setColumnStretch(1, 3);
        gridLayout_17->setColumnStretch(2, 2);
        gridLayout_17->setColumnStretch(3, 1);
        gridLayout_17->setColumnStretch(4, 1);

        verticalLayout_4->addWidget(additional_features_box);

        configuration_tabs->addTab(general_tab, QString());
        radio_tab = new QWidget();
        radio_tab->setObjectName(QString::fromUtf8("radio_tab"));
        gridLayout_3 = new QGridLayout(radio_tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_13, 13, 2, 1, 1);

        split_operation_group_box = new QGroupBox(radio_tab);
        split_operation_group_box->setObjectName(QString::fromUtf8("split_operation_group_box"));
        gridLayout_12 = new QGridLayout(split_operation_group_box);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        split_emulate_radio_button = new QRadioButton(split_operation_group_box);
        split_mode_button_group = new QButtonGroup(configuration_dialog);
        split_mode_button_group->setObjectName(QString::fromUtf8("split_mode_button_group"));
        split_mode_button_group->addButton(split_emulate_radio_button);
        split_emulate_radio_button->setObjectName(QString::fromUtf8("split_emulate_radio_button"));
        split_emulate_radio_button->setChecked(true);

        gridLayout_12->addWidget(split_emulate_radio_button, 0, 2, 1, 1);

        split_rig_radio_button = new QRadioButton(split_operation_group_box);
        split_mode_button_group->addButton(split_rig_radio_button);
        split_rig_radio_button->setObjectName(QString::fromUtf8("split_rig_radio_button"));

        gridLayout_12->addWidget(split_rig_radio_button, 0, 1, 1, 1);

        split_none_radio_button = new QRadioButton(split_operation_group_box);
        split_mode_button_group->addButton(split_none_radio_button);
        split_none_radio_button->setObjectName(QString::fromUtf8("split_none_radio_button"));
        split_none_radio_button->setChecked(false);

        gridLayout_12->addWidget(split_none_radio_button, 0, 0, 1, 1);


        gridLayout_3->addWidget(split_operation_group_box, 8, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_3->addItem(verticalSpacer_5, 13, 0, 1, 1);

        mode_group_box = new QGroupBox(radio_tab);
        mode_group_box->setObjectName(QString::fromUtf8("mode_group_box"));
        gridLayout_10 = new QGridLayout(mode_group_box);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        mode_USB_radio_button = new QRadioButton(mode_group_box);
        TX_mode_button_group = new QButtonGroup(configuration_dialog);
        TX_mode_button_group->setObjectName(QString::fromUtf8("TX_mode_button_group"));
        TX_mode_button_group->addButton(mode_USB_radio_button);
        mode_USB_radio_button->setObjectName(QString::fromUtf8("mode_USB_radio_button"));
        mode_USB_radio_button->setChecked(true);

        gridLayout_10->addWidget(mode_USB_radio_button, 0, 1, 1, 1);

        mode_none_radio_button = new QRadioButton(mode_group_box);
        TX_mode_button_group->addButton(mode_none_radio_button);
        mode_none_radio_button->setObjectName(QString::fromUtf8("mode_none_radio_button"));

        gridLayout_10->addWidget(mode_none_radio_button, 0, 0, 1, 1);

        mode_data_radio_button = new QRadioButton(mode_group_box);
        TX_mode_button_group->addButton(mode_data_radio_button);
        mode_data_radio_button->setObjectName(QString::fromUtf8("mode_data_radio_button"));

        gridLayout_10->addWidget(mode_data_radio_button, 0, 2, 1, 1);


        gridLayout_3->addWidget(mode_group_box, 5, 2, 1, 1);

        line_4 = new QFrame(radio_tab);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_4, 4, 2, 1, 1);

        line_3 = new QFrame(radio_tab);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 2, 2, 1, 1);

        CAT_control_group_box = new QGroupBox(radio_tab);
        CAT_control_group_box->setObjectName(QString::fromUtf8("CAT_control_group_box"));
        sizePolicy3.setHeightForWidth(CAT_control_group_box->sizePolicy().hasHeightForWidth());
        CAT_control_group_box->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(CAT_control_group_box);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        CAT_port_label = new QLabel(CAT_control_group_box);
        CAT_port_label->setObjectName(QString::fromUtf8("CAT_port_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, CAT_port_label);

        CAT_port_combo_box = new QComboBox(CAT_control_group_box);
        CAT_port_combo_box->setObjectName(QString::fromUtf8("CAT_port_combo_box"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(CAT_port_combo_box->sizePolicy().hasHeightForWidth());
        CAT_port_combo_box->setSizePolicy(sizePolicy5);
        CAT_port_combo_box->setEditable(true);
        CAT_port_combo_box->setInsertPolicy(QComboBox::NoInsert);

        formLayout->setWidget(0, QFormLayout::FieldRole, CAT_port_combo_box);


        verticalLayout_3->addLayout(formLayout);

        CAT_serial_port_parameters_group_box = new QGroupBox(CAT_control_group_box);
        CAT_serial_port_parameters_group_box->setObjectName(QString::fromUtf8("CAT_serial_port_parameters_group_box"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(CAT_serial_port_parameters_group_box->sizePolicy().hasHeightForWidth());
        CAT_serial_port_parameters_group_box->setSizePolicy(sizePolicy6);
        verticalLayout = new QVBoxLayout(CAT_serial_port_parameters_group_box);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        CAT_baud_label = new QLabel(CAT_serial_port_parameters_group_box);
        CAT_baud_label->setObjectName(QString::fromUtf8("CAT_baud_label"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, CAT_baud_label);

        CAT_serial_baud_combo_box = new QComboBox(CAT_serial_port_parameters_group_box);
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->addItem(QString());
        CAT_serial_baud_combo_box->setObjectName(QString::fromUtf8("CAT_serial_baud_combo_box"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(CAT_serial_baud_combo_box->sizePolicy().hasHeightForWidth());
        CAT_serial_baud_combo_box->setSizePolicy(sizePolicy7);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, CAT_serial_baud_combo_box);


        verticalLayout->addLayout(formLayout_5);

        CAT_data_bits_group_box = new QGroupBox(CAT_serial_port_parameters_group_box);
        CAT_data_bits_group_box->setObjectName(QString::fromUtf8("CAT_data_bits_group_box"));
        horizontalLayout_4 = new QHBoxLayout(CAT_data_bits_group_box);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        CAT_default_bit_radio_button = new QRadioButton(CAT_data_bits_group_box);
        CAT_data_bits_button_group = new QButtonGroup(configuration_dialog);
        CAT_data_bits_button_group->setObjectName(QString::fromUtf8("CAT_data_bits_button_group"));
        CAT_data_bits_button_group->addButton(CAT_default_bit_radio_button);
        CAT_default_bit_radio_button->setObjectName(QString::fromUtf8("CAT_default_bit_radio_button"));
        CAT_default_bit_radio_button->setChecked(true);

        horizontalLayout_4->addWidget(CAT_default_bit_radio_button);

        CAT_7_bit_radio_button = new QRadioButton(CAT_data_bits_group_box);
        CAT_data_bits_button_group->addButton(CAT_7_bit_radio_button);
        CAT_7_bit_radio_button->setObjectName(QString::fromUtf8("CAT_7_bit_radio_button"));
        CAT_7_bit_radio_button->setAutoExclusive(true);

        horizontalLayout_4->addWidget(CAT_7_bit_radio_button);

        CAT_8_bit_radio_button = new QRadioButton(CAT_data_bits_group_box);
        CAT_data_bits_button_group->addButton(CAT_8_bit_radio_button);
        CAT_8_bit_radio_button->setObjectName(QString::fromUtf8("CAT_8_bit_radio_button"));
        CAT_8_bit_radio_button->setChecked(false);

        horizontalLayout_4->addWidget(CAT_8_bit_radio_button);


        verticalLayout->addWidget(CAT_data_bits_group_box);

        CAT_stop_bits_group_box = new QGroupBox(CAT_serial_port_parameters_group_box);
        CAT_stop_bits_group_box->setObjectName(QString::fromUtf8("CAT_stop_bits_group_box"));
        horizontalLayout_2 = new QHBoxLayout(CAT_stop_bits_group_box);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CAT_default_stop_bit_radio_button = new QRadioButton(CAT_stop_bits_group_box);
        CAT_stop_bits_button_group = new QButtonGroup(configuration_dialog);
        CAT_stop_bits_button_group->setObjectName(QString::fromUtf8("CAT_stop_bits_button_group"));
        CAT_stop_bits_button_group->addButton(CAT_default_stop_bit_radio_button);
        CAT_default_stop_bit_radio_button->setObjectName(QString::fromUtf8("CAT_default_stop_bit_radio_button"));
        CAT_default_stop_bit_radio_button->setChecked(true);

        horizontalLayout_2->addWidget(CAT_default_stop_bit_radio_button);

        CAT_one_stop_bit_radio_button = new QRadioButton(CAT_stop_bits_group_box);
        CAT_stop_bits_button_group->addButton(CAT_one_stop_bit_radio_button);
        CAT_one_stop_bit_radio_button->setObjectName(QString::fromUtf8("CAT_one_stop_bit_radio_button"));

        horizontalLayout_2->addWidget(CAT_one_stop_bit_radio_button);

        CAT_two_stop_bit_radio_button = new QRadioButton(CAT_stop_bits_group_box);
        CAT_stop_bits_button_group->addButton(CAT_two_stop_bit_radio_button);
        CAT_two_stop_bit_radio_button->setObjectName(QString::fromUtf8("CAT_two_stop_bit_radio_button"));
        CAT_two_stop_bit_radio_button->setChecked(false);

        horizontalLayout_2->addWidget(CAT_two_stop_bit_radio_button);


        verticalLayout->addWidget(CAT_stop_bits_group_box);

        CAT_handshake_group_box = new QGroupBox(CAT_serial_port_parameters_group_box);
        CAT_handshake_group_box->setObjectName(QString::fromUtf8("CAT_handshake_group_box"));
        gridLayout_11 = new QGridLayout(CAT_handshake_group_box);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        CAT_handshake_default_radio_button = new QRadioButton(CAT_handshake_group_box);
        CAT_handshake_button_group = new QButtonGroup(configuration_dialog);
        CAT_handshake_button_group->setObjectName(QString::fromUtf8("CAT_handshake_button_group"));
        CAT_handshake_button_group->addButton(CAT_handshake_default_radio_button);
        CAT_handshake_default_radio_button->setObjectName(QString::fromUtf8("CAT_handshake_default_radio_button"));
        CAT_handshake_default_radio_button->setChecked(true);

        gridLayout_11->addWidget(CAT_handshake_default_radio_button, 0, 0, 1, 1);

        CAT_handshake_none_radio_button = new QRadioButton(CAT_handshake_group_box);
        CAT_handshake_button_group->addButton(CAT_handshake_none_radio_button);
        CAT_handshake_none_radio_button->setObjectName(QString::fromUtf8("CAT_handshake_none_radio_button"));
        CAT_handshake_none_radio_button->setChecked(false);

        gridLayout_11->addWidget(CAT_handshake_none_radio_button, 0, 1, 1, 1);

        CAT_handshake_xon_radio_button = new QRadioButton(CAT_handshake_group_box);
        CAT_handshake_button_group->addButton(CAT_handshake_xon_radio_button);
        CAT_handshake_xon_radio_button->setObjectName(QString::fromUtf8("CAT_handshake_xon_radio_button"));

        gridLayout_11->addWidget(CAT_handshake_xon_radio_button, 1, 0, 1, 1);

        CAT_handshake_hardware_radio_button = new QRadioButton(CAT_handshake_group_box);
        CAT_handshake_button_group->addButton(CAT_handshake_hardware_radio_button);
        CAT_handshake_hardware_radio_button->setObjectName(QString::fromUtf8("CAT_handshake_hardware_radio_button"));

        gridLayout_11->addWidget(CAT_handshake_hardware_radio_button, 1, 1, 1, 1);


        verticalLayout->addWidget(CAT_handshake_group_box);

        CAT_control_lines_group_box = new QGroupBox(CAT_serial_port_parameters_group_box);
        CAT_control_lines_group_box->setObjectName(QString::fromUtf8("CAT_control_lines_group_box"));
        CAT_control_lines_group_box->setChecked(false);
        horizontalLayout_8 = new QHBoxLayout(CAT_control_lines_group_box);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        force_DTR_combo_box = new QComboBox(CAT_control_lines_group_box);
        force_DTR_combo_box->addItem(QString());
        force_DTR_combo_box->addItem(QString());
        force_DTR_combo_box->addItem(QString());
        force_DTR_combo_box->setObjectName(QString::fromUtf8("force_DTR_combo_box"));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, force_DTR_combo_box);

        force_DTR_label = new QLabel(CAT_control_lines_group_box);
        force_DTR_label->setObjectName(QString::fromUtf8("force_DTR_label"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, force_DTR_label);


        horizontalLayout_8->addLayout(formLayout_8);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        force_RTS_label = new QLabel(CAT_control_lines_group_box);
        force_RTS_label->setObjectName(QString::fromUtf8("force_RTS_label"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, force_RTS_label);

        force_RTS_combo_box = new QComboBox(CAT_control_lines_group_box);
        force_RTS_combo_box->addItem(QString());
        force_RTS_combo_box->addItem(QString());
        force_RTS_combo_box->addItem(QString());
        force_RTS_combo_box->setObjectName(QString::fromUtf8("force_RTS_combo_box"));

        formLayout_9->setWidget(0, QFormLayout::FieldRole, force_RTS_combo_box);


        horizontalLayout_8->addLayout(formLayout_9);


        verticalLayout->addWidget(CAT_control_lines_group_box);


        verticalLayout_3->addWidget(CAT_serial_port_parameters_group_box);


        gridLayout_3->addWidget(CAT_control_group_box, 1, 0, 11, 1);

        line = new QFrame(radio_tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 13, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        test_CAT_push_button = new QPushButton(radio_tab);
        test_CAT_push_button->setObjectName(QString::fromUtf8("test_CAT_push_button"));

        horizontalLayout_11->addWidget(test_CAT_push_button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        test_PTT_push_button = new QPushButton(radio_tab);
        test_PTT_push_button->setObjectName(QString::fromUtf8("test_PTT_push_button"));
        test_PTT_push_button->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"	background-color: red;\n"
"	border-style	: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        test_PTT_push_button->setCheckable(true);

        horizontalLayout_11->addWidget(test_PTT_push_button);


        gridLayout_3->addLayout(horizontalLayout_11, 10, 2, 1, 1);

        line_6 = new QFrame(radio_tab);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_6, 6, 2, 1, 1);

        PTT_method_group_box = new QGroupBox(radio_tab);
        PTT_method_group_box->setObjectName(QString::fromUtf8("PTT_method_group_box"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(PTT_method_group_box->sizePolicy().hasHeightForWidth());
        PTT_method_group_box->setSizePolicy(sizePolicy8);
        gridLayout_2 = new QGridLayout(PTT_method_group_box);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        PTT_VOX_radio_button = new QRadioButton(PTT_method_group_box);
        PTT_method_button_group = new QButtonGroup(configuration_dialog);
        PTT_method_button_group->setObjectName(QString::fromUtf8("PTT_method_button_group"));
        PTT_method_button_group->addButton(PTT_VOX_radio_button);
        PTT_VOX_radio_button->setObjectName(QString::fromUtf8("PTT_VOX_radio_button"));

        gridLayout_2->addWidget(PTT_VOX_radio_button, 0, 0, 1, 1);

        PTT_DTR_radio_button = new QRadioButton(PTT_method_group_box);
        PTT_method_button_group->addButton(PTT_DTR_radio_button);
        PTT_DTR_radio_button->setObjectName(QString::fromUtf8("PTT_DTR_radio_button"));
        PTT_DTR_radio_button->setChecked(true);

        gridLayout_2->addWidget(PTT_DTR_radio_button, 0, 1, 1, 1);

        PTT_CAT_radio_button = new QRadioButton(PTT_method_group_box);
        PTT_method_button_group->addButton(PTT_CAT_radio_button);
        PTT_CAT_radio_button->setObjectName(QString::fromUtf8("PTT_CAT_radio_button"));

        gridLayout_2->addWidget(PTT_CAT_radio_button, 1, 0, 1, 1);

        PTT_RTS_radio_button = new QRadioButton(PTT_method_group_box);
        PTT_method_button_group->addButton(PTT_RTS_radio_button);
        PTT_RTS_radio_button->setObjectName(QString::fromUtf8("PTT_RTS_radio_button"));

        gridLayout_2->addWidget(PTT_RTS_radio_button, 1, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        PTT_port_label = new QLabel(PTT_method_group_box);
        PTT_port_label->setObjectName(QString::fromUtf8("PTT_port_label"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, PTT_port_label);

        PTT_port_combo_box = new QComboBox(PTT_method_group_box);
        PTT_port_combo_box->setObjectName(QString::fromUtf8("PTT_port_combo_box"));
        sizePolicy5.setHeightForWidth(PTT_port_combo_box->sizePolicy().hasHeightForWidth());
        PTT_port_combo_box->setSizePolicy(sizePolicy5);
        PTT_port_combo_box->setEditable(true);
        PTT_port_combo_box->setInsertPolicy(QComboBox::NoInsert);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, PTT_port_combo_box);

        tx_inhibit_check_box = new QCheckBox(PTT_method_group_box);
        tx_inhibit_check_box->setObjectName(QString::fromUtf8("tx_inhibit_check_box"));

        formLayout_4->setWidget(1, QFormLayout::SpanningRole, tx_inhibit_check_box);


        gridLayout_2->addLayout(formLayout_4, 2, 0, 2, 2);


        gridLayout_3->addWidget(PTT_method_group_box, 1, 2, 1, 1);

        hamlib_groupBox = new QGroupBox(radio_tab);
        hamlib_groupBox->setObjectName(QString::fromUtf8("hamlib_groupBox"));
        gridLayout_24 = new QGridLayout(hamlib_groupBox);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        rbHamlib32 = new QRadioButton(hamlib_groupBox);
        rbHamlib32->setObjectName(QString::fromUtf8("rbHamlib32"));

        gridLayout_24->addWidget(rbHamlib32, 0, 1, 1, 1);

        revert_update_button = new QPushButton(hamlib_groupBox);
        revert_update_button->setObjectName(QString::fromUtf8("revert_update_button"));

        gridLayout_24->addWidget(revert_update_button, 0, 3, 1, 1);

        hamlib_download_button = new QPushButton(hamlib_groupBox);
        hamlib_download_button->setObjectName(QString::fromUtf8("hamlib_download_button"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(hamlib_download_button->sizePolicy().hasHeightForWidth());
        hamlib_download_button->setSizePolicy(sizePolicy9);

        gridLayout_24->addWidget(hamlib_download_button, 0, 2, 1, 1);

        hamlib_version_gridLayout = new QGridLayout();
        hamlib_version_gridLayout->setObjectName(QString::fromUtf8("hamlib_version_gridLayout"));
        in_use_text = new QLabel(hamlib_groupBox);
        in_use_text->setObjectName(QString::fromUtf8("in_use_text"));

        hamlib_version_gridLayout->addWidget(in_use_text, 0, 0, 1, 1);

        in_use = new QLabel(hamlib_groupBox);
        in_use->setObjectName(QString::fromUtf8("in_use"));
        in_use->setMinimumSize(QSize(0, 0));

        hamlib_version_gridLayout->addWidget(in_use, 0, 1, 1, 1);

        backed_up_text = new QLabel(hamlib_groupBox);
        backed_up_text->setObjectName(QString::fromUtf8("backed_up_text"));

        hamlib_version_gridLayout->addWidget(backed_up_text, 1, 0, 1, 1);

        backed_up = new QLabel(hamlib_groupBox);
        backed_up->setObjectName(QString::fromUtf8("backed_up"));

        hamlib_version_gridLayout->addWidget(backed_up, 1, 1, 1, 1);

        hamlib_version_gridLayout->setColumnStretch(1, 1);

        gridLayout_24->addLayout(hamlib_version_gridLayout, 1, 0, 1, 4);

        rbHamlib64 = new QRadioButton(hamlib_groupBox);
        rbHamlib64->setObjectName(QString::fromUtf8("rbHamlib64"));
        rbHamlib64->setChecked(true);

        gridLayout_24->addWidget(rbHamlib64, 0, 0, 1, 1);


        gridLayout_3->addWidget(hamlib_groupBox, 12, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rig_label = new QLabel(radio_tab);
        rig_label->setObjectName(QString::fromUtf8("rig_label"));

        horizontalLayout_7->addWidget(rig_label);

        rig_combo_box = new QComboBox(radio_tab);
        rig_combo_box->setObjectName(QString::fromUtf8("rig_combo_box"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(rig_combo_box->sizePolicy().hasHeightForWidth());
        rig_combo_box->setSizePolicy(sizePolicy10);

        horizontalLayout_7->addWidget(rig_combo_box);

        CAT_poll_interval_label = new QLabel(radio_tab);
        CAT_poll_interval_label->setObjectName(QString::fromUtf8("CAT_poll_interval_label"));

        horizontalLayout_7->addWidget(CAT_poll_interval_label);

        CAT_poll_interval_spin_box = new QSpinBox(radio_tab);
        CAT_poll_interval_spin_box->setObjectName(QString::fromUtf8("CAT_poll_interval_spin_box"));
        CAT_poll_interval_spin_box->setMinimum(1);

        horizontalLayout_7->addWidget(CAT_poll_interval_spin_box);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 3);

        verticalSpacer_7 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 11, 2, 1, 1);

        rig_data_group_box = new QGroupBox(radio_tab);
        rig_data_group_box->setObjectName(QString::fromUtf8("rig_data_group_box"));
        sizePolicy3.setHeightForWidth(rig_data_group_box->sizePolicy().hasHeightForWidth());
        rig_data_group_box->setSizePolicy(sizePolicy3);
        rig_data_group_box->setMinimumSize(QSize(0, 0));
        rig_data_group_box->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_25 = new QGridLayout(rig_data_group_box);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        PWR_and_SWR_check_box = new QCheckBox(rig_data_group_box);
        PWR_and_SWR_check_box->setObjectName(QString::fromUtf8("PWR_and_SWR_check_box"));

        gridLayout_25->addWidget(PWR_and_SWR_check_box, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_25->addItem(verticalSpacer, 2, 0, 1, 1);

        check_SWR_check_box = new QCheckBox(rig_data_group_box);
        check_SWR_check_box->setObjectName(QString::fromUtf8("check_SWR_check_box"));

        gridLayout_25->addWidget(check_SWR_check_box, 0, 3, 1, 1);

        highlight_ALC1_check_box = new QCheckBox(rig_data_group_box);
        highlight_ALC1_check_box->setObjectName(QString::fromUtf8("highlight_ALC1_check_box"));

        gridLayout_25->addWidget(highlight_ALC1_check_box, 1, 0, 1, 1);

        highlight_ALC2_check_box = new QCheckBox(rig_data_group_box);
        highlight_ALC2_check_box->setObjectName(QString::fromUtf8("highlight_ALC2_check_box"));

        gridLayout_25->addWidget(highlight_ALC2_check_box, 1, 3, 1, 1);


        gridLayout_3->addWidget(rig_data_group_box, 12, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 9, 2, 1, 1);

        TX_audio_source_group_box = new QGroupBox(radio_tab);
        TX_audio_source_group_box->setObjectName(QString::fromUtf8("TX_audio_source_group_box"));
        gridLayout_7 = new QGridLayout(TX_audio_source_group_box);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        TX_source_data_radio_button = new QRadioButton(TX_audio_source_group_box);
        TX_audio_source_button_group = new QButtonGroup(configuration_dialog);
        TX_audio_source_button_group->setObjectName(QString::fromUtf8("TX_audio_source_button_group"));
        TX_audio_source_button_group->addButton(TX_source_data_radio_button);
        TX_source_data_radio_button->setObjectName(QString::fromUtf8("TX_source_data_radio_button"));

        gridLayout_7->addWidget(TX_source_data_radio_button, 0, 0, 1, 1);

        TX_source_mic_radio_button = new QRadioButton(TX_audio_source_group_box);
        TX_audio_source_button_group->addButton(TX_source_mic_radio_button);
        TX_source_mic_radio_button->setObjectName(QString::fromUtf8("TX_source_mic_radio_button"));
        TX_source_mic_radio_button->setChecked(true);

        gridLayout_7->addWidget(TX_source_mic_radio_button, 0, 1, 1, 1);


        gridLayout_3->addWidget(TX_audio_source_group_box, 3, 2, 1, 1);

        configuration_tabs->addTab(radio_tab, QString());
        audio_tab = new QWidget();
        audio_tab->setObjectName(QString::fromUtf8("audio_tab"));
        verticalLayout_9 = new QVBoxLayout(audio_tab);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        soundcard_group_box = new QGroupBox(audio_tab);
        soundcard_group_box->setObjectName(QString::fromUtf8("soundcard_group_box"));
        gridLayout_6 = new QGridLayout(soundcard_group_box);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        sound_input_label = new QLabel(soundcard_group_box);
        sound_input_label->setObjectName(QString::fromUtf8("sound_input_label"));

        gridLayout_6->addWidget(sound_input_label, 1, 0, 1, 1);

        sound_output_label = new QLabel(soundcard_group_box);
        sound_output_label->setObjectName(QString::fromUtf8("sound_output_label"));

        gridLayout_6->addWidget(sound_output_label, 2, 0, 1, 1);

        sound_output_channel_combo_box = new QComboBox(soundcard_group_box);
        sound_output_channel_combo_box->addItem(QString());
        sound_output_channel_combo_box->addItem(QString());
        sound_output_channel_combo_box->addItem(QString());
        sound_output_channel_combo_box->addItem(QString());
        sound_output_channel_combo_box->setObjectName(QString::fromUtf8("sound_output_channel_combo_box"));

        gridLayout_6->addWidget(sound_output_channel_combo_box, 2, 4, 1, 1);

        sound_input_channel_combo_box = new QComboBox(soundcard_group_box);
        sound_input_channel_combo_box->addItem(QString());
        sound_input_channel_combo_box->addItem(QString());
        sound_input_channel_combo_box->addItem(QString());
        sound_input_channel_combo_box->addItem(QString());
        sound_input_channel_combo_box->setObjectName(QString::fromUtf8("sound_input_channel_combo_box"));

        gridLayout_6->addWidget(sound_input_channel_combo_box, 1, 4, 1, 1);

        sound_input_combo_box = new LazyFillComboBox(soundcard_group_box);
        sound_input_combo_box->setObjectName(QString::fromUtf8("sound_input_combo_box"));
        sizePolicy10.setHeightForWidth(sound_input_combo_box->sizePolicy().hasHeightForWidth());
        sound_input_combo_box->setSizePolicy(sizePolicy10);

        gridLayout_6->addWidget(sound_input_combo_box, 1, 1, 1, 3);

        sound_output_combo_box = new LazyFillComboBox(soundcard_group_box);
        sound_output_combo_box->setObjectName(QString::fromUtf8("sound_output_combo_box"));
        sizePolicy10.setHeightForWidth(sound_output_combo_box->sizePolicy().hasHeightForWidth());
        sound_output_combo_box->setSizePolicy(sizePolicy10);

        gridLayout_6->addWidget(sound_output_combo_box, 2, 1, 1, 3);

        refresh_push_button = new QPushButton(soundcard_group_box);
        refresh_push_button->setObjectName(QString::fromUtf8("refresh_push_button"));

        gridLayout_6->addWidget(refresh_push_button, 3, 0, 1, 1);

        sound_settings_layout = new QHBoxLayout();
        sound_settings_layout->setObjectName(QString::fromUtf8("sound_settings_layout"));
        tci_audio_check_box = new QCheckBox(soundcard_group_box);
        tci_audio_check_box->setObjectName(QString::fromUtf8("tci_audio_check_box"));

        sound_settings_layout->addWidget(tci_audio_check_box);

        TCI_spin_box = new QSpinBox(soundcard_group_box);
        TCI_spin_box->setObjectName(QString::fromUtf8("TCI_spin_box"));
        TCI_spin_box->setAlignment(Qt::AlignCenter);
        TCI_spin_box->setMinimum(-50);
        TCI_spin_box->setMaximum(0);
        TCI_spin_box->setSingleStep(5);

        sound_settings_layout->addWidget(TCI_spin_box);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        sound_settings_layout->addItem(horizontalSpacer_7);

        cbSortAlphabetically = new QCheckBox(soundcard_group_box);
        cbSortAlphabetically->setObjectName(QString::fromUtf8("cbSortAlphabetically"));

        sound_settings_layout->addWidget(cbSortAlphabetically, 0, Qt::AlignHCenter);

        cbHideCARD = new QCheckBox(soundcard_group_box);
        cbHideCARD->setObjectName(QString::fromUtf8("cbHideCARD"));

        sound_settings_layout->addWidget(cbHideCARD);


        gridLayout_6->addLayout(sound_settings_layout, 3, 1, 1, 4);


        verticalLayout_9->addWidget(soundcard_group_box);

        save_path_group_box = new QGroupBox(audio_tab);
        save_path_group_box->setObjectName(QString::fromUtf8("save_path_group_box"));
        horizontalLayout_5 = new QHBoxLayout(save_path_group_box);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        save_path_label = new QLabel(save_path_group_box);
        save_path_label->setObjectName(QString::fromUtf8("save_path_label"));

        horizontalLayout_5->addWidget(save_path_label);

        save_path_display_label = new QLineEdit(save_path_group_box);
        save_path_display_label->setObjectName(QString::fromUtf8("save_path_display_label"));
        save_path_display_label->setCursor(QCursor(Qt::ArrowCursor));
        save_path_display_label->setMouseTracking(false);
        save_path_display_label->setAcceptDrops(false);
        save_path_display_label->setReadOnly(true);

        horizontalLayout_5->addWidget(save_path_display_label);

        save_path_select_push_button = new QPushButton(save_path_group_box);
        save_path_select_push_button->setObjectName(QString::fromUtf8("save_path_select_push_button"));

        horizontalLayout_5->addWidget(save_path_select_push_button);


        verticalLayout_9->addWidget(save_path_group_box);

        azel_path_group_box = new QGroupBox(audio_tab);
        azel_path_group_box->setObjectName(QString::fromUtf8("azel_path_group_box"));
        gridLayout_27 = new QGridLayout(azel_path_group_box);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        AzEl_Layout = new QHBoxLayout();
        AzEl_Layout->setSpacing(6);
        AzEl_Layout->setObjectName(QString::fromUtf8("AzEl_Layout"));
        azel_path_label = new QLabel(azel_path_group_box);
        azel_path_label->setObjectName(QString::fromUtf8("azel_path_label"));

        AzEl_Layout->addWidget(azel_path_label);

        azel_path_display_label = new QLineEdit(azel_path_group_box);
        azel_path_display_label->setObjectName(QString::fromUtf8("azel_path_display_label"));
        azel_path_display_label->setCursor(QCursor(Qt::ArrowCursor));
        azel_path_display_label->setMouseTracking(false);
        azel_path_display_label->setAcceptDrops(false);
        azel_path_display_label->setReadOnly(true);

        AzEl_Layout->addWidget(azel_path_display_label);

        azel_path_select_push_button = new QPushButton(azel_path_group_box);
        azel_path_select_push_button->setObjectName(QString::fromUtf8("azel_path_select_push_button"));

        AzEl_Layout->addWidget(azel_path_select_push_button);


        gridLayout_27->addLayout(AzEl_Layout, 0, 0, 1, 4);

        checkBoxAzElExtraLines = new QCheckBox(azel_path_group_box);
        checkBoxAzElExtraLines->setObjectName(QString::fromUtf8("checkBoxAzElExtraLines"));

        gridLayout_27->addWidget(checkBoxAzElExtraLines, 2, 0, 1, 1);


        verticalLayout_9->addWidget(azel_path_group_box);

        split_operation_group_box_2 = new QGroupBox(audio_tab);
        split_operation_group_box_2->setObjectName(QString::fromUtf8("split_operation_group_box_2"));
        horizontalLayout_13 = new QHBoxLayout(split_operation_group_box_2);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        checkBoxPwrBandTxMemory = new QCheckBox(split_operation_group_box_2);
        checkBoxPwrBandTxMemory->setObjectName(QString::fromUtf8("checkBoxPwrBandTxMemory"));

        horizontalLayout_13->addWidget(checkBoxPwrBandTxMemory);

        checkBoxPwrBandTuneMemory = new QCheckBox(split_operation_group_box_2);
        checkBoxPwrBandTuneMemory->setObjectName(QString::fromUtf8("checkBoxPwrBandTuneMemory"));

        horizontalLayout_13->addWidget(checkBoxPwrBandTuneMemory);


        verticalLayout_9->addWidget(split_operation_group_box_2);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        configuration_tabs->addTab(audio_tab, QString());
        tx_macros_tab = new QWidget();
        tx_macros_tab->setObjectName(QString::fromUtf8("tx_macros_tab"));
        gridLayout = new QGridLayout(tx_macros_tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        add_macro_push_button = new QPushButton(tx_macros_tab);
        add_macro_push_button->setObjectName(QString::fromUtf8("add_macro_push_button"));

        gridLayout->addWidget(add_macro_push_button, 0, 1, 1, 1);

        add_macro_line_edit = new QLineEdit(tx_macros_tab);
        add_macro_line_edit->setObjectName(QString::fromUtf8("add_macro_line_edit"));

        gridLayout->addWidget(add_macro_line_edit, 0, 0, 1, 1);

        delete_macro_push_button = new QPushButton(tx_macros_tab);
        delete_macro_push_button->setObjectName(QString::fromUtf8("delete_macro_push_button"));

        gridLayout->addWidget(delete_macro_push_button, 0, 2, 1, 1);

        macros_list_view = new QListView(tx_macros_tab);
        macros_list_view->setObjectName(QString::fromUtf8("macros_list_view"));
        macros_list_view->setContextMenuPolicy(Qt::ActionsContextMenu);
        macros_list_view->setStyleSheet(QString::fromUtf8("QListView {\n"
"    show-decoration-selected: 1; /* make the selection span the entire width of the view */\n"
"}\n"
"\n"
"// QListView::item:alternate {\n"
"//     background: #EEEEEE;\n"
"// }\n"
"\n"
"QListView::item:selected {\n"
"    border: 1px solid #6a6ea9;\n"
"}\n"
"\n"
"QListView::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"}"));
        macros_list_view->setDragDropMode(QAbstractItemView::InternalMove);
        macros_list_view->setDefaultDropAction(Qt::MoveAction);
        macros_list_view->setAlternatingRowColors(true);
        macros_list_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        macros_list_view->setUniformItemSizes(true);

        gridLayout->addWidget(macros_list_view, 1, 0, 1, 3);

        configuration_tabs->addTab(tx_macros_tab, QString());
        reporting_tab = new QWidget();
        reporting_tab->setObjectName(QString::fromUtf8("reporting_tab"));
        verticalLayout_5 = new QVBoxLayout(reporting_tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        logging_group_box = new QGroupBox(reporting_tab);
        logging_group_box->setObjectName(QString::fromUtf8("logging_group_box"));
        gridLayout_14 = new QGridLayout(logging_group_box);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        prompt_to_log_check_box = new QCheckBox(logging_group_box);
        prompt_to_log_check_box->setObjectName(QString::fromUtf8("prompt_to_log_check_box"));

        gridLayout_14->addWidget(prompt_to_log_check_box, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_6, 1, 1, 1, 1);

        cbLogDialFrequency = new QCheckBox(logging_group_box);
        cbLogDialFrequency->setObjectName(QString::fromUtf8("cbLogDialFrequency"));

        gridLayout_14->addWidget(cbLogDialFrequency, 6, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        cbAutoLog = new QCheckBox(logging_group_box);
        cbAutoLog->setObjectName(QString::fromUtf8("cbAutoLog"));

        horizontalLayout_12->addWidget(cbAutoLog);

        cbContestingOnly = new QCheckBox(logging_group_box);
        cbContestingOnly->setObjectName(QString::fromUtf8("cbContestingOnly"));

        horizontalLayout_12->addWidget(cbContestingOnly);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);


        gridLayout_14->addLayout(horizontalLayout_12, 3, 0, 1, 1);

        logfileLayout = new QHBoxLayout();
        logfileLayout->setObjectName(QString::fromUtf8("logfileLayout"));
        logpath_label = new QLabel(logging_group_box);
        logpath_label->setObjectName(QString::fromUtf8("logpath_label"));

        logfileLayout->addWidget(logpath_label);

        logpath_lineEdit = new QLineEdit(logging_group_box);
        logpath_lineEdit->setObjectName(QString::fromUtf8("logpath_lineEdit"));

        logfileLayout->addWidget(logpath_lineEdit);

        logpath_select_pushButton = new QPushButton(logging_group_box);
        logpath_select_pushButton->setObjectName(QString::fromUtf8("logpath_select_pushButton"));

        logfileLayout->addWidget(logpath_select_pushButton);


        gridLayout_14->addLayout(logfileLayout, 0, 0, 1, 4);

        cbZZ00 = new QCheckBox(logging_group_box);
        cbZZ00->setObjectName(QString::fromUtf8("cbZZ00"));

        gridLayout_14->addWidget(cbZZ00, 3, 1, 1, 1);

        cbLog4digitGrids = new QCheckBox(logging_group_box);
        cbLog4digitGrids->setObjectName(QString::fromUtf8("cbLog4digitGrids"));

        gridLayout_14->addWidget(cbLog4digitGrids, 3, 2, 1, 2);

        label_13 = new QLabel(logging_group_box);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_14->addWidget(label_13, 1, 2, 1, 1);

        opCallEntry = new QLineEdit(logging_group_box);
        opCallEntry->setObjectName(QString::fromUtf8("opCallEntry"));

        gridLayout_14->addWidget(opCallEntry, 1, 3, 1, 1);

        report_in_comments_check_box = new QCheckBox(logging_group_box);
        report_in_comments_check_box->setObjectName(QString::fromUtf8("report_in_comments_check_box"));

        gridLayout_14->addWidget(report_in_comments_check_box, 8, 0, 1, 1);

        log_as_RTTY_check_box = new QCheckBox(logging_group_box);
        log_as_RTTY_check_box->setObjectName(QString::fromUtf8("log_as_RTTY_check_box"));

        gridLayout_14->addWidget(log_as_RTTY_check_box, 6, 1, 1, 1);

        specOp_in_comments_check_box = new QCheckBox(logging_group_box);
        specOp_in_comments_check_box->setObjectName(QString::fromUtf8("specOp_in_comments_check_box"));

        gridLayout_14->addWidget(specOp_in_comments_check_box, 8, 1, 1, 3);


        verticalLayout_5->addWidget(logging_group_box);

        line_8 = new QFrame(reporting_tab);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_8);

        network_group_box = new QGroupBox(reporting_tab);
        network_group_box->setObjectName(QString::fromUtf8("network_group_box"));
        gridLayout_29 = new QGridLayout(network_group_box);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        psk_reporter_check_box = new QCheckBox(network_group_box);
        psk_reporter_check_box->setObjectName(QString::fromUtf8("psk_reporter_check_box"));

        gridLayout_29->addWidget(psk_reporter_check_box, 0, 0, 1, 1);

        psk_reporter_tcpip_check_box = new QCheckBox(network_group_box);
        psk_reporter_tcpip_check_box->setObjectName(QString::fromUtf8("psk_reporter_tcpip_check_box"));

        gridLayout_29->addWidget(psk_reporter_tcpip_check_box, 0, 1, 1, 1);


        verticalLayout_5->addWidget(network_group_box);

        livecq_group_box = new QGroupBox(reporting_tab);
        livecq_group_box->setObjectName(QString::fromUtf8("livecq_group_box"));
        gridLayout_livecq = new QGridLayout(livecq_group_box);
        gridLayout_livecq->setObjectName(QString::fromUtf8("gridLayout_livecq"));
        livecq_check_box = new QCheckBox(livecq_group_box);
        livecq_check_box->setObjectName(QString::fromUtf8("livecq_check_box"));

        gridLayout_livecq->addWidget(livecq_check_box, 0, 0, 1, 1);

        livecq_w3sz_layout = new QHBoxLayout();
        livecq_w3sz_layout->setObjectName(QString::fromUtf8("livecq_w3sz_layout"));
        livecq_official_check_box = new QCheckBox(livecq_group_box);
        livecq_official_check_box->setObjectName(QString::fromUtf8("livecq_official_check_box"));

        livecq_w3sz_layout->addWidget(livecq_official_check_box);

        livecq_w3sz_id_combo_box = new QComboBox(livecq_group_box);
        livecq_w3sz_id_combo_box->addItem(QString());
        livecq_w3sz_id_combo_box->addItem(QString());
        livecq_w3sz_id_combo_box->setObjectName(QString::fromUtf8("livecq_w3sz_id_combo_box"));

        livecq_w3sz_layout->addWidget(livecq_w3sz_id_combo_box);


        gridLayout_livecq->addLayout(livecq_w3sz_layout, 0, 1, 1, 1);

        livecq_n6nu_check_box = new QCheckBox(livecq_group_box);
        livecq_n6nu_check_box->setObjectName(QString::fromUtf8("livecq_n6nu_check_box"));
        livecq_n6nu_check_box->setChecked(false);

        gridLayout_livecq->addWidget(livecq_n6nu_check_box, 0, 2, 1, 1);

        liveCQ_horizontalLayout = new QHBoxLayout();
        liveCQ_horizontalLayout->setObjectName(QString::fromUtf8("liveCQ_horizontalLayout"));
        livecq_custom_check_box = new QCheckBox(livecq_group_box);
        livecq_custom_check_box->setObjectName(QString::fromUtf8("livecq_custom_check_box"));
        livecq_custom_check_box->setEnabled(true);
        livecq_custom_check_box->setChecked(false);

        liveCQ_horizontalLayout->addWidget(livecq_custom_check_box);

        livecq_other_url_line_edit = new QLineEdit(livecq_group_box);
        livecq_other_url_line_edit->setObjectName(QString::fromUtf8("livecq_other_url_line_edit"));

        liveCQ_horizontalLayout->addWidget(livecq_other_url_line_edit);

        liveCQ_horizontalLayout->setStretch(0, 1);
        liveCQ_horizontalLayout->setStretch(1, 5);

        gridLayout_livecq->addLayout(liveCQ_horizontalLayout, 1, 0, 1, 3);


        verticalLayout_5->addWidget(livecq_group_box);

        groupBox_4 = new QGroupBox(reporting_tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_16 = new QGridLayout(groupBox_4);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        udp_server_label = new QLabel(groupBox_4);
        udp_server_label->setObjectName(QString::fromUtf8("udp_server_label"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, udp_server_label);

        udp_server_line_edit = new QLineEdit(groupBox_4);
        udp_server_line_edit->setObjectName(QString::fromUtf8("udp_server_line_edit"));
        udp_server_line_edit->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, udp_server_line_edit);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_6);

        udp_server_port_spin_box = new QSpinBox(groupBox_4);
        udp_server_port_spin_box->setObjectName(QString::fromUtf8("udp_server_port_spin_box"));
        udp_server_port_spin_box->setMaximum(65534);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, udp_server_port_spin_box);

        udp_interfaces_label = new QLabel(groupBox_4);
        udp_interfaces_label->setObjectName(QString::fromUtf8("udp_interfaces_label"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, udp_interfaces_label);

        udp_interfaces_combo_box = new CheckableItemComboBox(groupBox_4);
        udp_interfaces_combo_box->setObjectName(QString::fromUtf8("udp_interfaces_combo_box"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, udp_interfaces_combo_box);

        udp_TTL_label = new QLabel(groupBox_4);
        udp_TTL_label->setObjectName(QString::fromUtf8("udp_TTL_label"));

        formLayout_6->setWidget(3, QFormLayout::LabelRole, udp_TTL_label);

        udp_TTL_spin_box = new QSpinBox(groupBox_4);
        udp_TTL_spin_box->setObjectName(QString::fromUtf8("udp_TTL_spin_box"));
        udp_TTL_spin_box->setMaximum(255);
        udp_TTL_spin_box->setValue(1);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, udp_TTL_spin_box);


        gridLayout_16->addLayout(formLayout_6, 0, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        accept_udp_requests_check_box = new QCheckBox(groupBox_4);
        accept_udp_requests_check_box->setObjectName(QString::fromUtf8("accept_udp_requests_check_box"));

        verticalLayout_11->addWidget(accept_udp_requests_check_box);

        udpWindowToFront = new QCheckBox(groupBox_4);
        udpWindowToFront->setObjectName(QString::fromUtf8("udpWindowToFront"));

        verticalLayout_11->addWidget(udpWindowToFront);

        udpWindowRestore = new QCheckBox(groupBox_4);
        udpWindowRestore->setObjectName(QString::fromUtf8("udpWindowRestore"));

        verticalLayout_11->addWidget(udpWindowRestore);

        udpWSJTXCompatibilityMode = new QCheckBox(groupBox_4);
        udpWSJTXCompatibilityMode->setObjectName(QString::fromUtf8("udpWSJTXCompatibilityMode"));

        verticalLayout_11->addWidget(udpWSJTXCompatibilityMode);


        gridLayout_16->addLayout(verticalLayout_11, 0, 1, 1, 1);


        verticalLayout_5->addWidget(groupBox_4);

        n1mm_group_box = new QGroupBox(reporting_tab);
        n1mm_group_box->setObjectName(QString::fromUtf8("n1mm_group_box"));
        formLayout_15 = new QFormLayout(n1mm_group_box);
        formLayout_15->setObjectName(QString::fromUtf8("formLayout_15"));
        enable_n1mm_broadcast_check_box = new QCheckBox(n1mm_group_box);
        enable_n1mm_broadcast_check_box->setObjectName(QString::fromUtf8("enable_n1mm_broadcast_check_box"));

        formLayout_15->setWidget(0, QFormLayout::SpanningRole, enable_n1mm_broadcast_check_box);

        n1mm_server_name_label = new QLabel(n1mm_group_box);
        n1mm_server_name_label->setObjectName(QString::fromUtf8("n1mm_server_name_label"));

        formLayout_15->setWidget(1, QFormLayout::LabelRole, n1mm_server_name_label);

        n1mm_server_name_line_edit = new QLineEdit(n1mm_group_box);
        n1mm_server_name_line_edit->setObjectName(QString::fromUtf8("n1mm_server_name_line_edit"));

        formLayout_15->setWidget(1, QFormLayout::FieldRole, n1mm_server_name_line_edit);

        n1mm_server_port_label = new QLabel(n1mm_group_box);
        n1mm_server_port_label->setObjectName(QString::fromUtf8("n1mm_server_port_label"));

        formLayout_15->setWidget(2, QFormLayout::LabelRole, n1mm_server_port_label);

        n1mm_server_port_spin_box = new QSpinBox(n1mm_group_box);
        n1mm_server_port_spin_box->setObjectName(QString::fromUtf8("n1mm_server_port_spin_box"));
        n1mm_server_port_spin_box->setMaximum(65534);

        formLayout_15->setWidget(2, QFormLayout::FieldRole, n1mm_server_port_spin_box);


        verticalLayout_5->addWidget(n1mm_group_box);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        configuration_tabs->addTab(reporting_tab, QString());
        frequencies_tab = new QWidget();
        frequencies_tab->setObjectName(QString::fromUtf8("frequencies_tab"));
        verticalLayout_10 = new QVBoxLayout(frequencies_tab);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_3 = new QGroupBox(frequencies_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_8);

        calibration_slope_ppm_spin_box = new QDoubleSpinBox(groupBox_3);
        calibration_slope_ppm_spin_box->setObjectName(QString::fromUtf8("calibration_slope_ppm_spin_box"));
        calibration_slope_ppm_spin_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        calibration_slope_ppm_spin_box->setDecimals(4);
        calibration_slope_ppm_spin_box->setMinimum(-999.999900000000025);
        calibration_slope_ppm_spin_box->setMaximum(999.999900000000025);
        calibration_slope_ppm_spin_box->setSingleStep(0.100000000000000);
        calibration_slope_ppm_spin_box->setValue(0.000000000000000);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, calibration_slope_ppm_spin_box);


        horizontalLayout_6->addLayout(formLayout_7);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QString::fromUtf8("formLayout_14"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_14->setWidget(0, QFormLayout::LabelRole, label_7);

        calibration_intercept_spin_box = new QDoubleSpinBox(groupBox_3);
        calibration_intercept_spin_box->setObjectName(QString::fromUtf8("calibration_intercept_spin_box"));
        calibration_intercept_spin_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        calibration_intercept_spin_box->setDecimals(2);
        calibration_intercept_spin_box->setMinimum(-99999.990000000005239);
        calibration_intercept_spin_box->setMaximum(99999.990000000005239);
        calibration_intercept_spin_box->setSingleStep(0.100000000000000);

        formLayout_14->setWidget(0, QFormLayout::FieldRole, calibration_intercept_spin_box);


        horizontalLayout_6->addLayout(formLayout_14);

        horizontalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox = new QGroupBox(frequencies_tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frequencies_table_view = new QTableView(groupBox);
        frequencies_table_view->setObjectName(QString::fromUtf8("frequencies_table_view"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(frequencies_table_view->sizePolicy().hasHeightForWidth());
        frequencies_table_view->setSizePolicy(sizePolicy11);
        frequencies_table_view->setContextMenuPolicy(Qt::ActionsContextMenu);
        frequencies_table_view->setDragDropMode(QAbstractItemView::DragOnly);
        frequencies_table_view->setAlternatingRowColors(true);
        frequencies_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
        frequencies_table_view->setSortingEnabled(true);
        frequencies_table_view->horizontalHeader()->setStretchLastSection(true);
        frequencies_table_view->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(frequencies_table_view);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frequencies_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stations_table_view = new QTableView(groupBox_2);
        stations_table_view->setObjectName(QString::fromUtf8("stations_table_view"));
        stations_table_view->setContextMenuPolicy(Qt::ActionsContextMenu);
        stations_table_view->setAcceptDrops(true);
        stations_table_view->setDragEnabled(true);
        stations_table_view->setDragDropOverwriteMode(true);
        stations_table_view->setDragDropMode(QAbstractItemView::DragDrop);
        stations_table_view->setDefaultDropAction(Qt::MoveAction);
        stations_table_view->setAlternatingRowColors(true);
        stations_table_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        stations_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
        stations_table_view->setSortingEnabled(true);
        stations_table_view->setWordWrap(true);
        stations_table_view->horizontalHeader()->setCascadingSectionResizes(true);
        stations_table_view->horizontalHeader()->setStretchLastSection(true);
        stations_table_view->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(stations_table_view);


        verticalLayout_10->addWidget(groupBox_2);

        configuration_tabs->addTab(frequencies_tab, QString());
        colors_tab = new QWidget();
        colors_tab->setObjectName(QString::fromUtf8("colors_tab"));
        verticalLayout_7 = new QVBoxLayout(colors_tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_12 = new QGroupBox(colors_tab);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(7);
        sizePolicy12.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy12);
        gridLayout_5 = new QGridLayout(groupBox_12);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        reset_highlighting_to_defaults_push_button = new QPushButton(groupBox_12);
        reset_highlighting_to_defaults_push_button->setObjectName(QString::fromUtf8("reset_highlighting_to_defaults_push_button"));

        horizontalLayout_20->addWidget(reset_highlighting_to_defaults_push_button);

        reset_highlighting_to_defaults2_push_button = new QPushButton(groupBox_12);
        reset_highlighting_to_defaults2_push_button->setObjectName(QString::fromUtf8("reset_highlighting_to_defaults2_push_button"));

        horizontalLayout_20->addWidget(reset_highlighting_to_defaults2_push_button);

        rescan_log_push_button = new QPushButton(groupBox_12);
        rescan_log_push_button->setObjectName(QString::fromUtf8("rescan_log_push_button"));

        horizontalLayout_20->addWidget(rescan_log_push_button);


        gridLayout_5->addLayout(horizontalLayout_20, 1, 0, 1, 2);

        highlighting_list_view = new DecodeHighlightingListView(groupBox_12);
        highlighting_list_view->setObjectName(QString::fromUtf8("highlighting_list_view"));
        sizePolicy8.setHeightForWidth(highlighting_list_view->sizePolicy().hasHeightForWidth());
        highlighting_list_view->setSizePolicy(sizePolicy8);
        highlighting_list_view->setContextMenuPolicy(Qt::ActionsContextMenu);
        highlighting_list_view->setAcceptDrops(true);
        highlighting_list_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        highlighting_list_view->setDragEnabled(true);
        highlighting_list_view->setDragDropMode(QAbstractItemView::InternalMove);
        highlighting_list_view->setDefaultDropAction(Qt::MoveAction);
        highlighting_list_view->setSelectionMode(QAbstractItemView::SingleSelection);
        highlighting_list_view->setResizeMode(QListView::Adjust);

        gridLayout_5->addWidget(highlighting_list_view, 0, 0, 1, 2);

        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_23->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        highlight_orange_check_box = new QCheckBox(groupBox_12);
        highlight_orange_check_box->setObjectName(QString::fromUtf8("highlight_orange_check_box"));

        gridLayout_23->addWidget(highlight_orange_check_box, 0, 3, 1, 1);

        highlight_verticalLayout = new QVBoxLayout();
        highlight_verticalLayout->setObjectName(QString::fromUtf8("highlight_verticalLayout"));
        highlight_by_mode_check_box = new QCheckBox(groupBox_12);
        highlight_by_mode_check_box->setObjectName(QString::fromUtf8("highlight_by_mode_check_box"));

        highlight_verticalLayout->addWidget(highlight_by_mode_check_box);

        only_fields_check_box = new QCheckBox(groupBox_12);
        only_fields_check_box->setObjectName(QString::fromUtf8("only_fields_check_box"));

        highlight_verticalLayout->addWidget(only_fields_check_box);

        include_WAE_check_box = new QCheckBox(groupBox_12);
        include_WAE_check_box->setObjectName(QString::fromUtf8("include_WAE_check_box"));

        highlight_verticalLayout->addWidget(include_WAE_check_box);

        highlight_73_check_box = new QCheckBox(groupBox_12);
        highlight_73_check_box->setObjectName(QString::fromUtf8("highlight_73_check_box"));

        highlight_verticalLayout->addWidget(highlight_73_check_box);

        highlight_all_check_box = new QCheckBox(groupBox_12);
        highlight_all_check_box->setObjectName(QString::fromUtf8("highlight_all_check_box"));

        highlight_verticalLayout->addWidget(highlight_all_check_box);


        gridLayout_23->addLayout(highlight_verticalLayout, 0, 1, 4, 1);

        highlight_orange_callsigns = new QLineEdit(groupBox_12);
        highlight_orange_callsigns->setObjectName(QString::fromUtf8("highlight_orange_callsigns"));

        gridLayout_23->addWidget(highlight_orange_callsigns, 1, 3, 1, 1);

        highlight_blue_check_box = new QCheckBox(groupBox_12);
        highlight_blue_check_box->setObjectName(QString::fromUtf8("highlight_blue_check_box"));

        gridLayout_23->addWidget(highlight_blue_check_box, 2, 3, 1, 1);

        highlight_blue_callsigns = new QLineEdit(groupBox_12);
        highlight_blue_callsigns->setObjectName(QString::fromUtf8("highlight_blue_callsigns"));

        gridLayout_23->addWidget(highlight_blue_callsigns, 3, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_23, 3, 0, 1, 2);


        verticalLayout_7->addWidget(groupBox_12);

        groupBox_11 = new QGroupBox(colors_tab);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        sizePolicy2.setHeightForWidth(groupBox_11->sizePolicy().hasHeightForWidth());
        groupBox_11->setSizePolicy(sizePolicy2);
        formLayout_18 = new QFormLayout(groupBox_11);
        formLayout_18->setObjectName(QString::fromUtf8("formLayout_18"));
        label_15 = new QLabel(groupBox_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_18->setWidget(1, QFormLayout::LabelRole, label_15);

        LotW_Layout = new QHBoxLayout();
        LotW_Layout->setObjectName(QString::fromUtf8("LotW_Layout"));
        LotW_CSV_URL_line_edit = new QLineEdit(groupBox_11);
        LotW_CSV_URL_line_edit->setObjectName(QString::fromUtf8("LotW_CSV_URL_line_edit"));

        LotW_Layout->addWidget(LotW_CSV_URL_line_edit);

        LotW_CSV_fetch_push_button = new QPushButton(groupBox_11);
        LotW_CSV_fetch_push_button->setObjectName(QString::fromUtf8("LotW_CSV_fetch_push_button"));

        LotW_Layout->addWidget(LotW_CSV_fetch_push_button);


        formLayout_18->setLayout(1, QFormLayout::FieldRole, LotW_Layout);

        LotW_Layout_2 = new QHBoxLayout();
        LotW_Layout_2->setObjectName(QString::fromUtf8("LotW_Layout_2"));
        LotW_days_since_upload_spin_box = new QSpinBox(groupBox_11);
        LotW_days_since_upload_spin_box->setObjectName(QString::fromUtf8("LotW_days_since_upload_spin_box"));
        LotW_days_since_upload_spin_box->setMinimum(0);
        LotW_days_since_upload_spin_box->setMaximum(9999);
        LotW_days_since_upload_spin_box->setValue(365);

        LotW_Layout_2->addWidget(LotW_days_since_upload_spin_box);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        LotW_Layout_2->addItem(horizontalSpacer_2);

        LotW_CSV_status_label = new QLabel(groupBox_11);
        LotW_CSV_status_label->setObjectName(QString::fromUtf8("LotW_CSV_status_label"));
        LotW_CSV_status_label->setMinimumSize(QSize(240, 0));

        LotW_Layout_2->addWidget(LotW_CSV_status_label);


        formLayout_18->setLayout(2, QFormLayout::FieldRole, LotW_Layout_2);

        label_14 = new QLabel(groupBox_11);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_18->setWidget(2, QFormLayout::LabelRole, label_14);


        verticalLayout_7->addWidget(groupBox_11);

        horizontalSpacer_8 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_8);

        downloads_groupBox = new QGroupBox(colors_tab);
        downloads_groupBox->setObjectName(QString::fromUtf8("downloads_groupBox"));
        sizePolicy2.setHeightForWidth(downloads_groupBox->sizePolicy().hasHeightForWidth());
        downloads_groupBox->setSizePolicy(sizePolicy2);
        gridLayout_21 = new QGridLayout(downloads_groupBox);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        CALL3_download_button = new QPushButton(downloads_groupBox);
        CALL3_download_button->setObjectName(QString::fromUtf8("CALL3_download_button"));

        gridLayout_21->addWidget(CALL3_download_button, 2, 1, 1, 1);

        CTY_file_label = new QLabel(downloads_groupBox);
        CTY_file_label->setObjectName(QString::fromUtf8("CTY_file_label"));

        gridLayout_21->addWidget(CTY_file_label, 0, 0, 1, 1);

        callsign_states_label = new QLabel(downloads_groupBox);
        callsign_states_label->setObjectName(QString::fromUtf8("callsign_states_label"));

        gridLayout_21->addWidget(callsign_states_label, 1, 0, 1, 1);

        CALL3_file_label = new QLabel(downloads_groupBox);
        CALL3_file_label->setObjectName(QString::fromUtf8("CALL3_file_label"));

        gridLayout_21->addWidget(CALL3_file_label, 2, 0, 1, 1);

        CALL3_EME_download_button = new QPushButton(downloads_groupBox);
        CALL3_EME_download_button->setObjectName(QString::fromUtf8("CALL3_EME_download_button"));

        gridLayout_21->addWidget(CALL3_EME_download_button, 2, 2, 1, 1);

        callsign_states_download_button = new QPushButton(downloads_groupBox);
        callsign_states_download_button->setObjectName(QString::fromUtf8("callsign_states_download_button"));

        gridLayout_21->addWidget(callsign_states_download_button, 1, 1, 1, 2);

        CTY_download_button = new QPushButton(downloads_groupBox);
        CTY_download_button->setObjectName(QString::fromUtf8("CTY_download_button"));

        gridLayout_21->addWidget(CTY_download_button, 0, 1, 1, 2);


        verticalLayout_7->addWidget(downloads_groupBox);

        configuration_tabs->addTab(colors_tab, QString());
        advanced_tab = new QWidget();
        advanced_tab->setObjectName(QString::fromUtf8("advanced_tab"));
        gridLayout_9 = new QGridLayout(advanced_tab);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gbCloudlog = new QGroupBox(advanced_tab);
        gbCloudlog->setObjectName(QString::fromUtf8("gbCloudlog"));
        QSizePolicy sizePolicy13(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(gbCloudlog->sizePolicy().hasHeightForWidth());
        gbCloudlog->setSizePolicy(sizePolicy13);
        gbCloudlog->setMinimumSize(QSize(0, 0));
        gbCloudlog->setCheckable(true);
        gbCloudlog->setChecked(false);
        gridLayout_22 = new QGridLayout(gbCloudlog);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        cloudlog_gridLayout = new QGridLayout();
        cloudlog_gridLayout->setObjectName(QString::fromUtf8("cloudlog_gridLayout"));
        api_url_label = new QLabel(gbCloudlog);
        api_url_label->setObjectName(QString::fromUtf8("api_url_label"));

        cloudlog_gridLayout->addWidget(api_url_label, 0, 0, 1, 1);

        api_key_label = new QLabel(gbCloudlog);
        api_key_label->setObjectName(QString::fromUtf8("api_key_label"));

        cloudlog_gridLayout->addWidget(api_key_label, 1, 0, 1, 1);

        station_id_label = new QLabel(gbCloudlog);
        station_id_label->setObjectName(QString::fromUtf8("station_id_label"));

        cloudlog_gridLayout->addWidget(station_id_label, 2, 0, 1, 1);

        sbCloudlogStationID = new QSpinBox(gbCloudlog);
        sbCloudlogStationID->setObjectName(QString::fromUtf8("sbCloudlogStationID"));
        sizePolicy9.setHeightForWidth(sbCloudlogStationID->sizePolicy().hasHeightForWidth());
        sbCloudlogStationID->setSizePolicy(sizePolicy9);
        sbCloudlogStationID->setMinimumSize(QSize(0, 0));
        sbCloudlogStationID->setMaximumSize(QSize(16777215, 16777215));
        sbCloudlogStationID->setMinimum(1);
        sbCloudlogStationID->setMaximum(999999);

        cloudlog_gridLayout->addWidget(sbCloudlogStationID, 2, 1, 1, 1);

        leCloudlogApiKey = new QLineEdit(gbCloudlog);
        leCloudlogApiKey->setObjectName(QString::fromUtf8("leCloudlogApiKey"));

        cloudlog_gridLayout->addWidget(leCloudlogApiKey, 1, 1, 1, 3);

        leCloudlogApiUrl = new QLineEdit(gbCloudlog);
        leCloudlogApiUrl->setObjectName(QString::fromUtf8("leCloudlogApiUrl"));

        cloudlog_gridLayout->addWidget(leCloudlogApiUrl, 0, 1, 1, 3);

        pbTestCloudlog = new QPushButton(gbCloudlog);
        pbTestCloudlog->setObjectName(QString::fromUtf8("pbTestCloudlog"));

        cloudlog_gridLayout->addWidget(pbTestCloudlog, 2, 3, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cloudlog_gridLayout->addItem(horizontalSpacer_13, 2, 2, 1, 1);


        gridLayout_22->addLayout(cloudlog_gridLayout, 0, 0, 1, 1);


        gridLayout_9->addWidget(gbCloudlog, 3, 0, 1, 1);

        groupBox_5 = new QGroupBox(advanced_tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        formLayout_10 = new QFormLayout(groupBox_5);
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_3);

        sbDegrade = new QDoubleSpinBox(groupBox_5);
        sbDegrade->setObjectName(QString::fromUtf8("sbDegrade"));
        sbDegrade->setDecimals(1);
        sbDegrade->setSingleStep(1.000000000000000);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, sbDegrade);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_10->setWidget(1, QFormLayout::LabelRole, label_9);

        sbBandwidth = new QSpinBox(groupBox_5);
        sbBandwidth->setObjectName(QString::fromUtf8("sbBandwidth"));
        sbBandwidth->setMaximum(6000);
        sbBandwidth->setSingleStep(100);
        sbBandwidth->setValue(2500);

        formLayout_10->setWidget(1, QFormLayout::FieldRole, sbBandwidth);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_10->setWidget(2, QFormLayout::LabelRole, label_11);

        sbTxDelay = new QDoubleSpinBox(groupBox_5);
        sbTxDelay->setObjectName(QString::fromUtf8("sbTxDelay"));
        sbTxDelay->setDecimals(1);
        sbTxDelay->setMinimum(0.000000000000000);
        sbTxDelay->setMaximum(0.500000000000000);
        sbTxDelay->setSingleStep(0.100000000000000);

        formLayout_10->setWidget(2, QFormLayout::FieldRole, sbTxDelay);

        groupBox_10 = new QGroupBox(groupBox_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 50));
        horizontalLayout_19 = new QHBoxLayout(groupBox_10);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        cbx2ToneSpacing = new QCheckBox(groupBox_10);
        cbx2ToneSpacing->setObjectName(QString::fromUtf8("cbx2ToneSpacing"));

        horizontalLayout_19->addWidget(cbx2ToneSpacing);

        cbx4ToneSpacing = new QCheckBox(groupBox_10);
        cbx4ToneSpacing->setObjectName(QString::fromUtf8("cbx4ToneSpacing"));
        cbx4ToneSpacing->setEnabled(true);

        horizontalLayout_19->addWidget(cbx4ToneSpacing);


        formLayout_10->setWidget(3, QFormLayout::SpanningRole, groupBox_10);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 50));
        horizontalLayout_16 = new QHBoxLayout(groupBox_7);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        rbLowSidelobes = new QRadioButton(groupBox_7);
        rbLowSidelobes->setObjectName(QString::fromUtf8("rbLowSidelobes"));
        rbLowSidelobes->setChecked(true);

        horizontalLayout_16->addWidget(rbLowSidelobes);

        rbMaxSensitivity = new QRadioButton(groupBox_7);
        rbMaxSensitivity->setObjectName(QString::fromUtf8("rbMaxSensitivity"));

        horizontalLayout_16->addWidget(rbMaxSensitivity);


        formLayout_10->setWidget(4, QFormLayout::SpanningRole, groupBox_7);


        gridLayout_9->addWidget(groupBox_5, 0, 1, 2, 1);

        groupBox_6 = new QGroupBox(advanced_tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        formLayout_11 = new QFormLayout(groupBox_6);
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_2);

        sbNtrials = new QSpinBox(groupBox_6);
        sbNtrials->setObjectName(QString::fromUtf8("sbNtrials"));
        sbNtrials->setMinimum(0);
        sbNtrials->setMaximum(12);
        sbNtrials->setValue(6);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, sbNtrials);

        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_11->setWidget(1, QFormLayout::LabelRole, label_4);

        sbAggressive = new QSpinBox(groupBox_6);
        sbAggressive->setObjectName(QString::fromUtf8("sbAggressive"));
        sbAggressive->setMaximum(10);

        formLayout_11->setWidget(1, QFormLayout::FieldRole, sbAggressive);

        cbTwoPass = new QCheckBox(groupBox_6);
        cbTwoPass->setObjectName(QString::fromUtf8("cbTwoPass"));
        cbTwoPass->setChecked(true);

        formLayout_11->setWidget(2, QFormLayout::LabelRole, cbTwoPass);


        gridLayout_9->addWidget(groupBox_6, 0, 0, 1, 1);

        gbEQSL = new QGroupBox(advanced_tab);
        gbEQSL->setObjectName(QString::fromUtf8("gbEQSL"));
        sizePolicy13.setHeightForWidth(gbEQSL->sizePolicy().hasHeightForWidth());
        gbEQSL->setSizePolicy(sizePolicy13);
        gbEQSL->setMinimumSize(QSize(0, 0));
        gbEQSL->setCheckable(true);
        gbEQSL->setChecked(false);
        gridLayout_220 = new QGridLayout(gbEQSL);
        gridLayout_220->setObjectName(QString::fromUtf8("gridLayout_220"));
        eqsl_gridLayout = new QGridLayout();
        eqsl_gridLayout->setObjectName(QString::fromUtf8("eqsl_gridLayout"));
        eqsluser_label = new QLabel(gbEQSL);
        eqsluser_label->setObjectName(QString::fromUtf8("eqsluser_label"));

        eqsl_gridLayout->addWidget(eqsluser_label, 0, 0, 1, 1);

        eqslpasswd_label = new QLabel(gbEQSL);
        eqslpasswd_label->setObjectName(QString::fromUtf8("eqslpasswd_label"));

        eqsl_gridLayout->addWidget(eqslpasswd_label, 1, 0, 1, 1);

        eqslnick_label = new QLabel(gbEQSL);
        eqslnick_label->setObjectName(QString::fromUtf8("eqslnick_label"));

        eqsl_gridLayout->addWidget(eqslnick_label, 2, 0, 1, 1);

        eqslnick_edit = new QLineEdit(gbEQSL);
        eqslnick_edit->setObjectName(QString::fromUtf8("eqslnick_edit"));

        eqsl_gridLayout->addWidget(eqslnick_edit, 2, 1, 1, 1);

        eqslpasswd_edit = new QLineEdit(gbEQSL);
        eqslpasswd_edit->setObjectName(QString::fromUtf8("eqslpasswd_edit"));

        eqsl_gridLayout->addWidget(eqslpasswd_edit, 1, 1, 1, 1);

        eqsluser_edit = new QLineEdit(gbEQSL);
        eqsluser_edit->setObjectName(QString::fromUtf8("eqsluser_edit"));

        eqsl_gridLayout->addWidget(eqsluser_edit, 0, 1, 1, 1);

        eqsl_gridLayout->setColumnStretch(1, 1);

        gridLayout_220->addLayout(eqsl_gridLayout, 0, 0, 1, 1);


        gridLayout_9->addWidget(gbEQSL, 3, 1, 1, 1);

        groupBox_8 = new QGroupBox(advanced_tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_26 = new QGridLayout(groupBox_8);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        cbHighDPI = new QCheckBox(groupBox_8);
        cbHighDPI->setObjectName(QString::fromUtf8("cbHighDPI"));

        gridLayout_26->addWidget(cbHighDPI, 0, 0, 1, 1);

        cbLargerTabWidget = new QCheckBox(groupBox_8);
        cbLargerTabWidget->setObjectName(QString::fromUtf8("cbLargerTabWidget"));

        gridLayout_26->addWidget(cbLargerTabWidget, 1, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_8, 1, 0, 1, 1);

        gbSpecialOpActivity = new QGroupBox(advanced_tab);
        gbSpecialOpActivity->setObjectName(QString::fromUtf8("gbSpecialOpActivity"));
        gbSpecialOpActivity->setCheckable(true);
        gbSpecialOpActivity->setChecked(false);
        gridLayout_15 = new QGridLayout(gbSpecialOpActivity);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        rbARRL_Digi = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group = new QButtonGroup(configuration_dialog);
        special_op_activity_button_group->setObjectName(QString::fromUtf8("special_op_activity_button_group"));
        special_op_activity_button_group->addButton(rbARRL_Digi);
        rbARRL_Digi->setObjectName(QString::fromUtf8("rbARRL_Digi"));

        gridLayout_15->addWidget(rbARRL_Digi, 4, 3, 1, 1);

        rbWW_DIGI = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbWW_DIGI);
        rbWW_DIGI->setObjectName(QString::fromUtf8("rbWW_DIGI"));
        rbWW_DIGI->setMinimumSize(QSize(0, 18));

        gridLayout_15->addWidget(rbWW_DIGI, 4, 0, 1, 1);

        cb_NCCC_Sprint = new QCheckBox(gbSpecialOpActivity);
        cb_NCCC_Sprint->setObjectName(QString::fromUtf8("cb_NCCC_Sprint"));

        gridLayout_15->addWidget(cb_NCCC_Sprint, 2, 1, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        rbField_Day = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbField_Day);
        rbField_Day->setObjectName(QString::fromUtf8("rbField_Day"));

        horizontalLayout_17->addWidget(rbField_Day);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_9);

        formLayout_16 = new QFormLayout();
        formLayout_16->setObjectName(QString::fromUtf8("formLayout_16"));
        labFD = new QLabel(gbSpecialOpActivity);
        labFD->setObjectName(QString::fromUtf8("labFD"));

        formLayout_16->setWidget(0, QFormLayout::LabelRole, labFD);

        Field_Day_Exchange = new QLineEdit(gbSpecialOpActivity);
        Field_Day_Exchange->setObjectName(QString::fromUtf8("Field_Day_Exchange"));
        Field_Day_Exchange->setMinimumSize(QSize(70, 0));
        Field_Day_Exchange->setAlignment(Qt::AlignCenter);

        formLayout_16->setWidget(0, QFormLayout::FieldRole, Field_Day_Exchange);


        horizontalLayout_17->addLayout(formLayout_16);

        horizontalLayout_17->setStretch(0, 2);
        horizontalLayout_17->setStretch(1, 1);
        horizontalLayout_17->setStretch(2, 1);

        gridLayout_15->addLayout(horizontalLayout_17, 2, 3, 1, 1);

        foxLayout_23 = new QHBoxLayout();
        foxLayout_23->setObjectName(QString::fromUtf8("foxLayout_23"));
        rbHound = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbHound);
        rbHound->setObjectName(QString::fromUtf8("rbHound"));
        rbHound->setChecked(true);

        foxLayout_23->addWidget(rbHound);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        foxLayout_23->addItem(horizontalSpacer_16);

        foxLayout_23->setStretch(1, 1);

        gridLayout_15->addLayout(foxLayout_23, 0, 3, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        rbRTTY_Roundup = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbRTTY_Roundup);
        rbRTTY_Roundup->setObjectName(QString::fromUtf8("rbRTTY_Roundup"));

        horizontalLayout_18->addWidget(rbRTTY_Roundup);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_10);

        formLayout_17 = new QFormLayout();
        formLayout_17->setObjectName(QString::fromUtf8("formLayout_17"));
        labRTTY = new QLabel(gbSpecialOpActivity);
        labRTTY->setObjectName(QString::fromUtf8("labRTTY"));

        formLayout_17->setWidget(0, QFormLayout::LabelRole, labRTTY);

        RTTY_Exchange = new QLineEdit(gbSpecialOpActivity);
        RTTY_Exchange->setObjectName(QString::fromUtf8("RTTY_Exchange"));
        RTTY_Exchange->setMinimumSize(QSize(70, 0));
        RTTY_Exchange->setAlignment(Qt::AlignCenter);

        formLayout_17->setWidget(0, QFormLayout::FieldRole, RTTY_Exchange);


        horizontalLayout_18->addLayout(formLayout_17);

        horizontalLayout_18->setStretch(0, 2);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 1);

        gridLayout_15->addLayout(horizontalLayout_18, 3, 3, 1, 1);

        rbEU_VHF_Contest = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbEU_VHF_Contest);
        rbEU_VHF_Contest->setObjectName(QString::fromUtf8("rbEU_VHF_Contest"));
        QSizePolicy sizePolicy14(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(rbEU_VHF_Contest->sizePolicy().hasHeightForWidth());
        rbEU_VHF_Contest->setSizePolicy(sizePolicy14);

        gridLayout_15->addWidget(rbEU_VHF_Contest, 3, 0, 1, 1);

        cbSuperFox = new QCheckBox(gbSpecialOpActivity);
        cbSuperFox->setObjectName(QString::fromUtf8("cbSuperFox"));

        gridLayout_15->addWidget(cbSuperFox, 0, 1, 1, 1);

        OTP_Layout_2 = new QHBoxLayout();
        OTP_Layout_2->setObjectName(QString::fromUtf8("OTP_Layout_2"));
        cbShowOTP = new QCheckBox(gbSpecialOpActivity);
        cbShowOTP->setObjectName(QString::fromUtf8("cbShowOTP"));
        cbShowOTP->setChecked(true);

        OTP_Layout_2->addWidget(cbShowOTP);

        horizontalSpacer_18 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        OTP_Layout_2->addItem(horizontalSpacer_18);

        lblOTPUrl = new QLabel(gbSpecialOpActivity);
        lblOTPUrl->setObjectName(QString::fromUtf8("lblOTPUrl"));

        OTP_Layout_2->addWidget(lblOTPUrl);

        horizontalSpacer_15 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        OTP_Layout_2->addItem(horizontalSpacer_15);

        OTPUrl = new QLineEdit(gbSpecialOpActivity);
        OTPUrl->setObjectName(QString::fromUtf8("OTPUrl"));
        OTPUrl->setMinimumSize(QSize(110, 0));

        OTP_Layout_2->addWidget(OTPUrl);

        OTP_Layout_2->setStretch(4, 1);

        gridLayout_15->addLayout(OTP_Layout_2, 1, 3, 1, 1);

        rbNA_VHF_Contest = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbNA_VHF_Contest);
        rbNA_VHF_Contest->setObjectName(QString::fromUtf8("rbNA_VHF_Contest"));
        sizePolicy14.setHeightForWidth(rbNA_VHF_Contest->sizePolicy().hasHeightForWidth());
        rbNA_VHF_Contest->setSizePolicy(sizePolicy14);

        gridLayout_15->addWidget(rbNA_VHF_Contest, 2, 0, 1, 1);

        rbFox = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbFox);
        rbFox->setObjectName(QString::fromUtf8("rbFox"));
        rbFox->setChecked(false);

        gridLayout_15->addWidget(rbFox, 0, 0, 1, 1);

        OTP_Layout = new QHBoxLayout();
        OTP_Layout->setObjectName(QString::fromUtf8("OTP_Layout"));
        cbOTP = new QCheckBox(gbSpecialOpActivity);
        cbOTP->setObjectName(QString::fromUtf8("cbOTP"));
        cbOTP->setEnabled(false);
        cbOTP->setChecked(true);

        OTP_Layout->addWidget(cbOTP);

        horizontalSpacer_11 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        OTP_Layout->addItem(horizontalSpacer_11);

        lblOTPSeed = new QLabel(gbSpecialOpActivity);
        lblOTPSeed->setObjectName(QString::fromUtf8("lblOTPSeed"));

        OTP_Layout->addWidget(lblOTPSeed);

        OTPSeed = new QLineEdit(gbSpecialOpActivity);
        OTPSeed->setObjectName(QString::fromUtf8("OTPSeed"));
        OTPSeed->setMinimumSize(QSize(110, 0));

        OTP_Layout->addWidget(OTPSeed);

        horizontalSpacer_19 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        OTP_Layout->addItem(horizontalSpacer_19);

        lblOTPEvery = new QLabel(gbSpecialOpActivity);
        lblOTPEvery->setObjectName(QString::fromUtf8("lblOTPEvery"));

        OTP_Layout->addWidget(lblOTPEvery);

        sbOTPinterval = new QSpinBox(gbSpecialOpActivity);
        sbOTPinterval->setObjectName(QString::fromUtf8("sbOTPinterval"));
        sbOTPinterval->setMaximum(20);
        sbOTPinterval->setValue(1);

        OTP_Layout->addWidget(sbOTPinterval);

        horizontalSpacer_17 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        OTP_Layout->addItem(horizontalSpacer_17);

        OTP_Layout->setStretch(3, 1);
        OTP_Layout->setStretch(7, 1);

        gridLayout_15->addLayout(OTP_Layout, 1, 0, 1, 3);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        cbContestName = new QCheckBox(gbSpecialOpActivity);
        cbContestName->setObjectName(QString::fromUtf8("cbContestName"));

        horizontalLayout_24->addWidget(cbContestName);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_12);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        labCN = new QLabel(gbSpecialOpActivity);
        labCN->setObjectName(QString::fromUtf8("labCN"));

        horizontalLayout_25->addWidget(labCN);

        Contest_Name = new QLineEdit(gbSpecialOpActivity);
        Contest_Name->setObjectName(QString::fromUtf8("Contest_Name"));
        Contest_Name->setMaximumSize(QSize(70, 16777215));
        Contest_Name->setMaxLength(4);
        Contest_Name->setCursorPosition(0);
        Contest_Name->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(Contest_Name);


        horizontalLayout_24->addLayout(horizontalLayout_25);


        gridLayout_15->addLayout(horizontalLayout_24, 5, 3, 1, 1);

        rbQ65pileup = new QRadioButton(gbSpecialOpActivity);
        special_op_activity_button_group->addButton(rbQ65pileup);
        rbQ65pileup->setObjectName(QString::fromUtf8("rbQ65pileup"));
        rbQ65pileup->setMinimumSize(QSize(0, 18));

        gridLayout_15->addWidget(rbQ65pileup, 5, 0, 1, 1);

        gridLayout_15->setColumnStretch(0, 1);

        gridLayout_9->addWidget(gbSpecialOpActivity, 2, 0, 1, 2);

        verticalSpacer_9 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_9, 4, 0, 1, 2);

        configuration_tabs->addTab(advanced_tab, QString());
        alerts_tab = new QWidget();
        alerts_tab->setObjectName(QString::fromUtf8("alerts_tab"));
        gridLayout_20 = new QGridLayout(alerts_tab);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_23 = new QLabel(alerts_tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_20->addWidget(label_23, 12, 0, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_20->addItem(verticalSpacer_11, 5, 0, 1, 1);

        label_25 = new QLabel(alerts_tab);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_20->addWidget(label_25, 11, 0, 1, 1);

        label_19 = new QLabel(alerts_tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_20->addWidget(label_19, 2, 0, 1, 1);

        label_21 = new QLabel(alerts_tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_20->addWidget(label_21, 4, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_20->addItem(verticalSpacer_8, 10, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_20->addItem(verticalSpacer_6, 7, 0, 1, 1);

        label_24 = new QLabel(alerts_tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_20->addWidget(label_24, 14, 0, 1, 1);

        label_20 = new QLabel(alerts_tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_20->addWidget(label_20, 3, 0, 1, 1);

        groupBox_9 = new QGroupBox(alerts_tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        sizePolicy2.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy2);
        gridLayout_18 = new QGridLayout(groupBox_9);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        cbMyCall = new QCheckBox(groupBox_9);
        cbMyCall->setObjectName(QString::fromUtf8("cbMyCall"));

        gridLayout_18->addWidget(cbMyCall, 10, 0, 1, 1);

        cbUSState = new QCheckBox(groupBox_9);
        cbUSState->setObjectName(QString::fromUtf8("cbUSState"));

        gridLayout_18->addWidget(cbUSState, 4, 0, 1, 1);

        cbGrid = new QCheckBox(groupBox_9);
        cbGrid->setObjectName(QString::fromUtf8("cbGrid"));

        gridLayout_18->addWidget(cbGrid, 5, 0, 1, 1);

        cbQSYmessage = new QCheckBox(groupBox_9);
        cbQSYmessage->setObjectName(QString::fromUtf8("cbQSYmessage"));

        gridLayout_18->addWidget(cbQSYmessage, 11, 1, 1, 1);

        cbWanted = new QCheckBox(groupBox_9);
        cbWanted->setObjectName(QString::fromUtf8("cbWanted"));

        gridLayout_18->addWidget(cbWanted, 10, 1, 1, 1);

        cbDXCCOB = new QCheckBox(groupBox_9);
        cbDXCCOB->setObjectName(QString::fromUtf8("cbDXCCOB"));

        gridLayout_18->addWidget(cbDXCCOB, 1, 1, 1, 1);

        line_9 = new QFrame(groupBox_9);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_18->addWidget(line_9, 9, 0, 1, 2);

        cbContinentOB = new QCheckBox(groupBox_9);
        cbContinentOB->setObjectName(QString::fromUtf8("cbContinentOB"));

        gridLayout_18->addWidget(cbContinentOB, 0, 1, 1, 1);

        cbGridOB = new QCheckBox(groupBox_9);
        cbGridOB->setObjectName(QString::fromUtf8("cbGridOB"));

        gridLayout_18->addWidget(cbGridOB, 5, 1, 1, 1);

        cbITUZ = new QCheckBox(groupBox_9);
        cbITUZ->setObjectName(QString::fromUtf8("cbITUZ"));

        gridLayout_18->addWidget(cbITUZ, 3, 0, 1, 1);

        cbCQZ = new QCheckBox(groupBox_9);
        cbCQZ->setObjectName(QString::fromUtf8("cbCQZ"));

        gridLayout_18->addWidget(cbCQZ, 2, 0, 1, 1);

        cbCQ = new QCheckBox(groupBox_9);
        cbCQ->setObjectName(QString::fromUtf8("cbCQ"));

        gridLayout_18->addWidget(cbCQ, 12, 0, 1, 1);

        cbDXCC = new QCheckBox(groupBox_9);
        cbDXCC->setObjectName(QString::fromUtf8("cbDXCC"));

        gridLayout_18->addWidget(cbDXCC, 1, 0, 1, 1);

        cbDXcall = new QCheckBox(groupBox_9);
        cbDXcall->setObjectName(QString::fromUtf8("cbDXcall"));

        gridLayout_18->addWidget(cbDXcall, 11, 0, 1, 1);

        cbContinent = new QCheckBox(groupBox_9);
        cbContinent->setObjectName(QString::fromUtf8("cbContinent"));

        gridLayout_18->addWidget(cbContinent, 0, 0, 1, 1);

        cbCQZOB = new QCheckBox(groupBox_9);
        cbCQZOB->setObjectName(QString::fromUtf8("cbCQZOB"));

        gridLayout_18->addWidget(cbCQZOB, 2, 1, 1, 1);

        cbITUZOB = new QCheckBox(groupBox_9);
        cbITUZOB->setObjectName(QString::fromUtf8("cbITUZOB"));

        gridLayout_18->addWidget(cbITUZOB, 3, 1, 1, 1);

        cbUSStateOB = new QCheckBox(groupBox_9);
        cbUSStateOB->setObjectName(QString::fromUtf8("cbUSStateOB"));

        gridLayout_18->addWidget(cbUSStateOB, 4, 1, 1, 1);


        gridLayout_20->addWidget(groupBox_9, 8, 0, 1, 1);

        label_16 = new QLabel(alerts_tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_20->addWidget(label_16, 0, 0, 1, 1);

        voiceSelectLayout = new QHBoxLayout();
        voiceSelectLayout->setObjectName(QString::fromUtf8("voiceSelectLayout"));
        voicesLabel = new QLabel(alerts_tab);
        voicesLabel->setObjectName(QString::fromUtf8("voicesLabel"));

        voiceSelectLayout->addWidget(voicesLabel);

        voices_combo_box = new QComboBox(alerts_tab);
        voices_combo_box->addItem(QString());
        voices_combo_box->setObjectName(QString::fromUtf8("voices_combo_box"));
        voices_combo_box->setCurrentText(QString::fromUtf8("default"));
        voices_combo_box->setMaxVisibleItems(15);

        voiceSelectLayout->addWidget(voices_combo_box);

        voiceSpacer_1 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        voiceSelectLayout->addItem(voiceSpacer_1);

        pb_test_alerts = new QPushButton(alerts_tab);
        pb_test_alerts->setObjectName(QString::fromUtf8("pb_test_alerts"));

        voiceSelectLayout->addWidget(pb_test_alerts);

        voiceSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        voiceSelectLayout->addItem(voiceSpacer_2);

        voiceSelectLayout->setStretch(0, 1);
        voiceSelectLayout->setStretch(1, 2);
        voiceSelectLayout->setStretch(2, 1);
        voiceSelectLayout->setStretch(3, 1);
        voiceSelectLayout->setStretch(4, 3);

        gridLayout_20->addLayout(voiceSelectLayout, 6, 0, 1, 1);

        label_17 = new QLabel(alerts_tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_20->addWidget(label_17, 1, 0, 1, 1);

        label_22 = new QLabel(alerts_tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_20->addWidget(label_22, 13, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_20 = new QSpacerItem(40, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_20);

        pbAlerts = new QPushButton(alerts_tab);
        pbAlerts->setObjectName(QString::fromUtf8("pbAlerts"));
        QSizePolicy sizePolicy15(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(pbAlerts->sizePolicy().hasHeightForWidth());
        pbAlerts->setSizePolicy(sizePolicy15);
        pbAlerts->setMinimumSize(QSize(0, 35));
        pbAlerts->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    color: #000000;\n"
"	background-color: #00ff00;\n"
"    border-style: outset;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"    border-color: black;\n"
"	min-width: 5em;\n"
"	padding: 3px;\n"
"}"));
        pbAlerts->setCheckable(true);

        horizontalLayout_21->addWidget(pbAlerts);

        horizontalSpacer_21 = new QSpacerItem(40, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_21);


        gridLayout_20->addLayout(horizontalLayout_21, 9, 0, 1, 1);

        configuration_tabs->addTab(alerts_tab, QString());
        filters_tab = new QWidget();
        filters_tab->setObjectName(QString::fromUtf8("filters_tab"));
        gridLayout_13 = new QGridLayout(filters_tab);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        Blacklist10 = new QLineEdit(filters_tab);
        Blacklist10->setObjectName(QString::fromUtf8("Blacklist10"));

        gridLayout_19->addWidget(Blacklist10, 7, 1, 1, 1);

        Whitelist3 = new QLineEdit(filters_tab);
        Whitelist3->setObjectName(QString::fromUtf8("Whitelist3"));

        gridLayout_19->addWidget(Whitelist3, 10, 2, 1, 1);

        Blacklist5 = new QLineEdit(filters_tab);
        Blacklist5->setObjectName(QString::fromUtf8("Blacklist5"));

        gridLayout_19->addWidget(Blacklist5, 6, 0, 1, 1);

        territory_label = new QLabel(filters_tab);
        territory_label->setObjectName(QString::fromUtf8("territory_label"));
        sizePolicy3.setHeightForWidth(territory_label->sizePolicy().hasHeightForWidth());
        territory_label->setSizePolicy(sizePolicy3);
        territory_label->setMinimumSize(QSize(0, 20));

        gridLayout_19->addWidget(territory_label, 1, 0, 1, 4, Qt::AlignBottom);

        blacklist_label = new QLabel(filters_tab);
        blacklist_label->setObjectName(QString::fromUtf8("blacklist_label"));

        gridLayout_19->addWidget(blacklist_label, 3, 0, 1, 4);

        Blacklist11 = new QLineEdit(filters_tab);
        Blacklist11->setObjectName(QString::fromUtf8("Blacklist11"));

        gridLayout_19->addWidget(Blacklist11, 7, 2, 1, 1);

        Blacklist3 = new QLineEdit(filters_tab);
        Blacklist3->setObjectName(QString::fromUtf8("Blacklist3"));

        gridLayout_19->addWidget(Blacklist3, 5, 2, 1, 1);

        label_18 = new QLabel(filters_tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy3.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy3);
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_19->addWidget(label_18, 0, 0, 1, 4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_19->addItem(verticalSpacer_10, 22, 0, 1, 1);

        Pass2 = new QLineEdit(filters_tab);
        Pass2->setObjectName(QString::fromUtf8("Pass2"));

        gridLayout_19->addWidget(Pass2, 15, 1, 1, 1);

        Whitelist11 = new QLineEdit(filters_tab);
        Whitelist11->setObjectName(QString::fromUtf8("Whitelist11"));

        gridLayout_19->addWidget(Whitelist11, 12, 2, 1, 1);

        Blacklist8 = new QLineEdit(filters_tab);
        Blacklist8->setObjectName(QString::fromUtf8("Blacklist8"));

        gridLayout_19->addWidget(Blacklist8, 6, 3, 1, 1);

        Whitelist7 = new QLineEdit(filters_tab);
        Whitelist7->setObjectName(QString::fromUtf8("Whitelist7"));

        gridLayout_19->addWidget(Whitelist7, 11, 2, 1, 1);

        Blacklist1 = new QLineEdit(filters_tab);
        Blacklist1->setObjectName(QString::fromUtf8("Blacklist1"));

        gridLayout_19->addWidget(Blacklist1, 5, 0, 1, 1);

        cbBlacklist = new QCheckBox(filters_tab);
        cbBlacklist->setObjectName(QString::fromUtf8("cbBlacklist"));

        gridLayout_19->addWidget(cbBlacklist, 4, 0, 1, 4);

        Pass12 = new QLineEdit(filters_tab);
        Pass12->setObjectName(QString::fromUtf8("Pass12"));

        gridLayout_19->addWidget(Pass12, 17, 3, 1, 1);

        Blacklist9 = new QLineEdit(filters_tab);
        Blacklist9->setObjectName(QString::fromUtf8("Blacklist9"));

        gridLayout_19->addWidget(Blacklist9, 7, 0, 1, 1);

        Whitelist5 = new QLineEdit(filters_tab);
        Whitelist5->setObjectName(QString::fromUtf8("Whitelist5"));

        gridLayout_19->addWidget(Whitelist5, 11, 0, 1, 1);

        Pass3 = new QLineEdit(filters_tab);
        Pass3->setObjectName(QString::fromUtf8("Pass3"));

        gridLayout_19->addWidget(Pass3, 15, 2, 1, 1);

        cbWhitelist = new QCheckBox(filters_tab);
        cbWhitelist->setObjectName(QString::fromUtf8("cbWhitelist"));

        gridLayout_19->addWidget(cbWhitelist, 9, 0, 1, 4);

        Whitelist1 = new QLineEdit(filters_tab);
        Whitelist1->setObjectName(QString::fromUtf8("Whitelist1"));

        gridLayout_19->addWidget(Whitelist1, 10, 0, 1, 1);

        Whitelist12 = new QLineEdit(filters_tab);
        Whitelist12->setObjectName(QString::fromUtf8("Whitelist12"));

        gridLayout_19->addWidget(Whitelist12, 12, 3, 1, 1);

        Territory1 = new QLineEdit(filters_tab);
        Territory1->setObjectName(QString::fromUtf8("Territory1"));

        gridLayout_19->addWidget(Territory1, 2, 0, 1, 1);

        cb_filters_for_Wait_and_Pounce_only = new QCheckBox(filters_tab);
        cb_filters_for_Wait_and_Pounce_only->setObjectName(QString::fromUtf8("cb_filters_for_Wait_and_Pounce_only"));

        gridLayout_19->addWidget(cb_filters_for_Wait_and_Pounce_only, 20, 0, 1, 4);

        Territory4 = new QLineEdit(filters_tab);
        Territory4->setObjectName(QString::fromUtf8("Territory4"));

        gridLayout_19->addWidget(Territory4, 2, 3, 1, 1);

        Pass9 = new QLineEdit(filters_tab);
        Pass9->setObjectName(QString::fromUtf8("Pass9"));

        gridLayout_19->addWidget(Pass9, 17, 0, 1, 1);

        Whitelist10 = new QLineEdit(filters_tab);
        Whitelist10->setObjectName(QString::fromUtf8("Whitelist10"));

        gridLayout_19->addWidget(Whitelist10, 12, 1, 1, 1);

        Pass10 = new QLineEdit(filters_tab);
        Pass10->setObjectName(QString::fromUtf8("Pass10"));

        gridLayout_19->addWidget(Pass10, 17, 1, 1, 1);

        Blacklist7 = new QLineEdit(filters_tab);
        Blacklist7->setObjectName(QString::fromUtf8("Blacklist7"));

        gridLayout_19->addWidget(Blacklist7, 6, 2, 1, 1);

        Whitelist4 = new QLineEdit(filters_tab);
        Whitelist4->setObjectName(QString::fromUtf8("Whitelist4"));

        gridLayout_19->addWidget(Whitelist4, 10, 3, 1, 1);

        Pass6 = new QLineEdit(filters_tab);
        Pass6->setObjectName(QString::fromUtf8("Pass6"));

        gridLayout_19->addWidget(Pass6, 16, 1, 1, 1);

        Pass4 = new QLineEdit(filters_tab);
        Pass4->setObjectName(QString::fromUtf8("Pass4"));

        gridLayout_19->addWidget(Pass4, 15, 3, 1, 1);

        Blacklist12 = new QLineEdit(filters_tab);
        Blacklist12->setObjectName(QString::fromUtf8("Blacklist12"));

        gridLayout_19->addWidget(Blacklist12, 7, 3, 1, 1);

        Whitelist9 = new QLineEdit(filters_tab);
        Whitelist9->setObjectName(QString::fromUtf8("Whitelist9"));

        gridLayout_19->addWidget(Whitelist9, 12, 0, 1, 1);

        Blacklist2 = new QLineEdit(filters_tab);
        Blacklist2->setObjectName(QString::fromUtf8("Blacklist2"));

        gridLayout_19->addWidget(Blacklist2, 5, 1, 1, 1);

        Pass8 = new QLineEdit(filters_tab);
        Pass8->setObjectName(QString::fromUtf8("Pass8"));

        gridLayout_19->addWidget(Pass8, 16, 3, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_19->addItem(verticalSpacer_12, 18, 0, 1, 1);

        Whitelist2 = new QLineEdit(filters_tab);
        Whitelist2->setObjectName(QString::fromUtf8("Whitelist2"));

        gridLayout_19->addWidget(Whitelist2, 10, 1, 1, 1);

        Blacklist6 = new QLineEdit(filters_tab);
        Blacklist6->setObjectName(QString::fromUtf8("Blacklist6"));

        gridLayout_19->addWidget(Blacklist6, 6, 1, 1, 1);

        cbPass = new QCheckBox(filters_tab);
        cbPass->setObjectName(QString::fromUtf8("cbPass"));

        gridLayout_19->addWidget(cbPass, 14, 0, 1, 4);

        Pass1 = new QLineEdit(filters_tab);
        Pass1->setObjectName(QString::fromUtf8("Pass1"));

        gridLayout_19->addWidget(Pass1, 15, 0, 1, 1);

        Pass7 = new QLineEdit(filters_tab);
        Pass7->setObjectName(QString::fromUtf8("Pass7"));

        gridLayout_19->addWidget(Pass7, 16, 2, 1, 1);

        whitelist_label = new QLabel(filters_tab);
        whitelist_label->setObjectName(QString::fromUtf8("whitelist_label"));
        sizePolicy3.setHeightForWidth(whitelist_label->sizePolicy().hasHeightForWidth());
        whitelist_label->setSizePolicy(sizePolicy3);
        whitelist_label->setMinimumSize(QSize(0, 20));

        gridLayout_19->addWidget(whitelist_label, 8, 0, 1, 4, Qt::AlignBottom);

        Pass5 = new QLineEdit(filters_tab);
        Pass5->setObjectName(QString::fromUtf8("Pass5"));

        gridLayout_19->addWidget(Pass5, 16, 0, 1, 1);

        Whitelist8 = new QLineEdit(filters_tab);
        Whitelist8->setObjectName(QString::fromUtf8("Whitelist8"));

        gridLayout_19->addWidget(Whitelist8, 11, 3, 1, 1);

        cb_filters_for_word2 = new QCheckBox(filters_tab);
        cb_filters_for_word2->setObjectName(QString::fromUtf8("cb_filters_for_word2"));

        gridLayout_19->addWidget(cb_filters_for_word2, 19, 0, 1, 4);

        Pass11 = new QLineEdit(filters_tab);
        Pass11->setObjectName(QString::fromUtf8("Pass11"));

        gridLayout_19->addWidget(Pass11, 17, 2, 1, 1);

        Blacklist4 = new QLineEdit(filters_tab);
        Blacklist4->setObjectName(QString::fromUtf8("Blacklist4"));

        gridLayout_19->addWidget(Blacklist4, 5, 3, 1, 1);

        always_pass_label = new QLabel(filters_tab);
        always_pass_label->setObjectName(QString::fromUtf8("always_pass_label"));
        always_pass_label->setMinimumSize(QSize(0, 20));

        gridLayout_19->addWidget(always_pass_label, 13, 0, 1, 4);

        Territory2 = new QLineEdit(filters_tab);
        Territory2->setObjectName(QString::fromUtf8("Territory2"));

        gridLayout_19->addWidget(Territory2, 2, 1, 1, 1);

        Territory3 = new QLineEdit(filters_tab);
        Territory3->setObjectName(QString::fromUtf8("Territory3"));

        gridLayout_19->addWidget(Territory3, 2, 2, 1, 1);

        Whitelist6 = new QLineEdit(filters_tab);
        Whitelist6->setObjectName(QString::fromUtf8("Whitelist6"));

        gridLayout_19->addWidget(Whitelist6, 11, 1, 1, 1);

        cb_twoDays = new QCheckBox(filters_tab);
        cb_twoDays->setObjectName(QString::fromUtf8("cb_twoDays"));

        gridLayout_19->addWidget(cb_twoDays, 21, 0, 1, 4);


        gridLayout_13->addLayout(gridLayout_19, 0, 0, 1, 1);

        configuration_tabs->addTab(filters_tab, QString());

        verticalLayout_6->addWidget(configuration_tabs);

        configuration_dialog_button_box = new QDialogButtonBox(scrollAreaWidgetContents_2);
        configuration_dialog_button_box->setObjectName(QString::fromUtf8("configuration_dialog_button_box"));
        configuration_dialog_button_box->setOrientation(Qt::Horizontal);
        configuration_dialog_button_box->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_6->addWidget(configuration_dialog_button_box);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea);

#if QT_CONFIG(shortcut)
        callsign_label->setBuddy(callsign_line_edit);
        grid_label->setBuddy(grid_line_edit);
        label_12->setBuddy(region_combo_box);
        label_5->setBuddy(type_2_msg_gen_combo_box);
        label_10->setBuddy(tx_watchdog_spin_box);
        label->setBuddy(CW_id_interval_spin_box);
        CAT_port_label->setBuddy(CAT_port_combo_box);
        CAT_baud_label->setBuddy(CAT_serial_baud_combo_box);
        force_DTR_label->setBuddy(force_DTR_combo_box);
        force_RTS_label->setBuddy(force_RTS_combo_box);
        PTT_port_label->setBuddy(PTT_port_combo_box);
        rig_label->setBuddy(rig_combo_box);
        CAT_poll_interval_label->setBuddy(CAT_poll_interval_spin_box);
        sound_input_label->setBuddy(sound_input_combo_box);
        sound_output_label->setBuddy(sound_output_combo_box);
        save_path_label->setBuddy(save_path_select_push_button);
        azel_path_label->setBuddy(azel_path_select_push_button);
        label_13->setBuddy(opCallEntry);
        udp_server_label->setBuddy(udp_server_line_edit);
        label_6->setBuddy(udp_server_port_spin_box);
        udp_interfaces_label->setBuddy(udp_interfaces_combo_box);
        udp_TTL_label->setBuddy(udp_TTL_spin_box);
        n1mm_server_name_label->setBuddy(n1mm_server_name_line_edit);
        n1mm_server_port_label->setBuddy(n1mm_server_port_spin_box);
        label_8->setBuddy(calibration_slope_ppm_spin_box);
        label_7->setBuddy(calibration_intercept_spin_box);
        label_15->setBuddy(LotW_CSV_URL_line_edit);
        label_14->setBuddy(LotW_days_since_upload_spin_box);
        label_3->setBuddy(sbDegrade);
        label_9->setBuddy(sbBandwidth);
        label_11->setBuddy(sbTxDelay);
        label_2->setBuddy(sbNtrials);
        label_4->setBuddy(sbAggressive);
        labFD->setBuddy(Field_Day_Exchange);
        labRTTY->setBuddy(RTTY_Exchange);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(callsign_line_edit, grid_line_edit);
        QWidget::setTabOrder(grid_line_edit, use_dynamic_grid);
        QWidget::setTabOrder(use_dynamic_grid, region_combo_box);
        QWidget::setTabOrder(region_combo_box, type_2_msg_gen_combo_box);
        QWidget::setTabOrder(type_2_msg_gen_combo_box, decodes_from_top_check_box);
        QWidget::setTabOrder(decodes_from_top_check_box, miles_check_box);
        QWidget::setTabOrder(miles_check_box, DXCC_check_box);
        QWidget::setTabOrder(DXCC_check_box, monitor_off_check_box);
        QWidget::setTabOrder(monitor_off_check_box, enable_VHF_features_check_box);
        QWidget::setTabOrder(enable_VHF_features_check_box, CW_id_interval_spin_box);
        QWidget::setTabOrder(CW_id_interval_spin_box, rig_combo_box);
        QWidget::setTabOrder(rig_combo_box, CAT_poll_interval_spin_box);
        QWidget::setTabOrder(CAT_poll_interval_spin_box, CAT_port_combo_box);
        QWidget::setTabOrder(CAT_port_combo_box, CAT_serial_baud_combo_box);
        QWidget::setTabOrder(CAT_serial_baud_combo_box, CAT_default_bit_radio_button);
        QWidget::setTabOrder(CAT_default_bit_radio_button, CAT_7_bit_radio_button);
        QWidget::setTabOrder(CAT_7_bit_radio_button, CAT_8_bit_radio_button);
        QWidget::setTabOrder(CAT_8_bit_radio_button, CAT_default_stop_bit_radio_button);
        QWidget::setTabOrder(CAT_default_stop_bit_radio_button, CAT_one_stop_bit_radio_button);
        QWidget::setTabOrder(CAT_one_stop_bit_radio_button, CAT_two_stop_bit_radio_button);
        QWidget::setTabOrder(CAT_two_stop_bit_radio_button, CAT_handshake_default_radio_button);
        QWidget::setTabOrder(CAT_handshake_default_radio_button, CAT_handshake_xon_radio_button);
        QWidget::setTabOrder(CAT_handshake_xon_radio_button, CAT_handshake_none_radio_button);
        QWidget::setTabOrder(CAT_handshake_none_radio_button, CAT_handshake_hardware_radio_button);
        QWidget::setTabOrder(CAT_handshake_hardware_radio_button, force_DTR_combo_box);
        QWidget::setTabOrder(force_DTR_combo_box, force_RTS_combo_box);
        QWidget::setTabOrder(force_RTS_combo_box, PTT_VOX_radio_button);
        QWidget::setTabOrder(PTT_VOX_radio_button, PTT_CAT_radio_button);
        QWidget::setTabOrder(PTT_CAT_radio_button, PTT_DTR_radio_button);
        QWidget::setTabOrder(PTT_DTR_radio_button, PTT_RTS_radio_button);
        QWidget::setTabOrder(PTT_RTS_radio_button, PTT_port_combo_box);
        QWidget::setTabOrder(PTT_port_combo_box, TX_source_data_radio_button);
        QWidget::setTabOrder(TX_source_data_radio_button, TX_source_mic_radio_button);
        QWidget::setTabOrder(TX_source_mic_radio_button, mode_none_radio_button);
        QWidget::setTabOrder(mode_none_radio_button, mode_USB_radio_button);
        QWidget::setTabOrder(mode_USB_radio_button, mode_data_radio_button);
        QWidget::setTabOrder(mode_data_radio_button, split_none_radio_button);
        QWidget::setTabOrder(split_none_radio_button, split_rig_radio_button);
        QWidget::setTabOrder(split_rig_radio_button, split_emulate_radio_button);
        QWidget::setTabOrder(split_emulate_radio_button, test_CAT_push_button);
        QWidget::setTabOrder(test_CAT_push_button, test_PTT_push_button);
        QWidget::setTabOrder(test_PTT_push_button, sound_input_combo_box);
        QWidget::setTabOrder(sound_input_combo_box, sound_input_channel_combo_box);
        QWidget::setTabOrder(sound_input_channel_combo_box, sound_output_combo_box);
        QWidget::setTabOrder(sound_output_combo_box, sound_output_channel_combo_box);
        QWidget::setTabOrder(sound_output_channel_combo_box, save_path_select_push_button);
        QWidget::setTabOrder(save_path_select_push_button, checkBoxPwrBandTxMemory);
        QWidget::setTabOrder(checkBoxPwrBandTxMemory, checkBoxPwrBandTuneMemory);
        QWidget::setTabOrder(checkBoxPwrBandTuneMemory, add_macro_line_edit);
        QWidget::setTabOrder(add_macro_line_edit, add_macro_push_button);
        QWidget::setTabOrder(add_macro_push_button, delete_macro_push_button);
        QWidget::setTabOrder(delete_macro_push_button, macros_list_view);
        QWidget::setTabOrder(macros_list_view, prompt_to_log_check_box);
        QWidget::setTabOrder(prompt_to_log_check_box, report_in_comments_check_box);
        QWidget::setTabOrder(report_in_comments_check_box, opCallEntry);
        QWidget::setTabOrder(opCallEntry, psk_reporter_check_box);
        QWidget::setTabOrder(psk_reporter_check_box, udp_server_line_edit);
        QWidget::setTabOrder(udp_server_line_edit, udp_server_port_spin_box);
        QWidget::setTabOrder(udp_server_port_spin_box, udp_interfaces_combo_box);
        QWidget::setTabOrder(udp_interfaces_combo_box, udp_TTL_spin_box);
        QWidget::setTabOrder(udp_TTL_spin_box, accept_udp_requests_check_box);
        QWidget::setTabOrder(accept_udp_requests_check_box, udpWindowToFront);
        QWidget::setTabOrder(udpWindowToFront, udpWindowRestore);
        QWidget::setTabOrder(udpWindowRestore, udpWSJTXCompatibilityMode);
        QWidget::setTabOrder(udpWSJTXCompatibilityMode, enable_n1mm_broadcast_check_box);
        QWidget::setTabOrder(enable_n1mm_broadcast_check_box, n1mm_server_name_line_edit);
        QWidget::setTabOrder(n1mm_server_name_line_edit, n1mm_server_port_spin_box);
        QWidget::setTabOrder(n1mm_server_port_spin_box, calibration_slope_ppm_spin_box);
        QWidget::setTabOrder(calibration_slope_ppm_spin_box, calibration_intercept_spin_box);
        QWidget::setTabOrder(calibration_intercept_spin_box, frequencies_table_view);
        QWidget::setTabOrder(frequencies_table_view, stations_table_view);
        QWidget::setTabOrder(stations_table_view, highlighting_list_view);
        QWidget::setTabOrder(highlighting_list_view, LotW_CSV_URL_line_edit);
        QWidget::setTabOrder(LotW_CSV_URL_line_edit, LotW_CSV_fetch_push_button);
        QWidget::setTabOrder(LotW_CSV_fetch_push_button, sbNtrials);
        QWidget::setTabOrder(sbNtrials, sbAggressive);
        QWidget::setTabOrder(sbAggressive, cbTwoPass);
        QWidget::setTabOrder(cbTwoPass, sbDegrade);
        QWidget::setTabOrder(sbDegrade, sbBandwidth);
        QWidget::setTabOrder(sbBandwidth, sbTxDelay);
        QWidget::setTabOrder(sbTxDelay, cbx2ToneSpacing);
        QWidget::setTabOrder(cbx2ToneSpacing, cbx4ToneSpacing);
        QWidget::setTabOrder(cbx4ToneSpacing, rbLowSidelobes);
        QWidget::setTabOrder(rbLowSidelobes, rbMaxSensitivity);
        QWidget::setTabOrder(rbMaxSensitivity, gbSpecialOpActivity);
        QWidget::setTabOrder(gbSpecialOpActivity, rbField_Day);
        QWidget::setTabOrder(rbField_Day, rbEU_VHF_Contest);
        QWidget::setTabOrder(rbEU_VHF_Contest, rbRTTY_Roundup);
        QWidget::setTabOrder(rbRTTY_Roundup, Field_Day_Exchange);
        QWidget::setTabOrder(Field_Day_Exchange, RTTY_Exchange);
        QWidget::setTabOrder(RTTY_Exchange, Territory1);
        QWidget::setTabOrder(Territory1, Territory2);
        QWidget::setTabOrder(Territory2, Territory3);
        QWidget::setTabOrder(Territory3, Territory4);
        QWidget::setTabOrder(Territory4, cbBlacklist);
        QWidget::setTabOrder(cbBlacklist, Blacklist1);
        QWidget::setTabOrder(Blacklist1, Blacklist2);
        QWidget::setTabOrder(Blacklist2, Blacklist3);
        QWidget::setTabOrder(Blacklist3, Blacklist4);
        QWidget::setTabOrder(Blacklist4, Blacklist5);
        QWidget::setTabOrder(Blacklist5, Blacklist6);
        QWidget::setTabOrder(Blacklist6, Blacklist7);
        QWidget::setTabOrder(Blacklist7, Blacklist8);
        QWidget::setTabOrder(Blacklist8, Blacklist9);
        QWidget::setTabOrder(Blacklist9, Blacklist10);
        QWidget::setTabOrder(Blacklist10, Blacklist11);
        QWidget::setTabOrder(Blacklist11, Blacklist12);
        QWidget::setTabOrder(Blacklist12, cbWhitelist);
        QWidget::setTabOrder(cbWhitelist, Whitelist1);
        QWidget::setTabOrder(Whitelist1, Whitelist2);
        QWidget::setTabOrder(Whitelist2, Whitelist3);
        QWidget::setTabOrder(Whitelist3, Whitelist4);
        QWidget::setTabOrder(Whitelist4, Whitelist5);
        QWidget::setTabOrder(Whitelist5, Whitelist6);
        QWidget::setTabOrder(Whitelist6, Whitelist7);
        QWidget::setTabOrder(Whitelist7, Whitelist8);
        QWidget::setTabOrder(Whitelist8, Whitelist9);
        QWidget::setTabOrder(Whitelist9, Whitelist10);
        QWidget::setTabOrder(Whitelist10, Whitelist11);
        QWidget::setTabOrder(Whitelist11, Whitelist12);
        QWidget::setTabOrder(Whitelist12, cbPass);
        QWidget::setTabOrder(cbPass, Pass1);
        QWidget::setTabOrder(Pass1, Pass2);
        QWidget::setTabOrder(Pass2, Pass3);
        QWidget::setTabOrder(Pass3, Pass4);
        QWidget::setTabOrder(Pass4, Pass5);
        QWidget::setTabOrder(Pass5, Pass6);
        QWidget::setTabOrder(Pass6, Pass7);
        QWidget::setTabOrder(Pass7, Pass8);
        QWidget::setTabOrder(Pass8, Pass9);
        QWidget::setTabOrder(Pass9, Pass10);
        QWidget::setTabOrder(Pass10, Pass11);
        QWidget::setTabOrder(Pass11, Pass12);
        QWidget::setTabOrder(Pass12, cb_filters_for_word2);
        QWidget::setTabOrder(cb_filters_for_word2, cb_filters_for_Wait_and_Pounce_only);

        retranslateUi(configuration_dialog);
        QObject::connect(configuration_dialog_button_box, SIGNAL(accepted()), configuration_dialog, SLOT(accept()));
        QObject::connect(configuration_dialog_button_box, SIGNAL(rejected()), configuration_dialog, SLOT(reject()));
        QObject::connect(add_macro_push_button, SIGNAL(clicked()), add_macro_line_edit, SLOT(setFocus()));
        QObject::connect(add_macro_line_edit, SIGNAL(returnPressed()), add_macro_push_button, SLOT(setFocus()));

        configuration_tabs->setCurrentIndex(0);
        type_2_msg_gen_combo_box->setCurrentIndex(1);
        CAT_serial_baud_combo_box->setCurrentIndex(0);
        PTT_port_combo_box->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(configuration_dialog);
    } // setupUi

    void retranslateUi(QDialog *configuration_dialog)
    {
        configuration_dialog->setWindowTitle(QCoreApplication::translate("configuration_dialog", "Settings", nullptr));
        station_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Station Details", nullptr));
        callsign_label->setText(QCoreApplication::translate("configuration_dialog", "My C&all:", nullptr));
#if QT_CONFIG(tooltip)
        callsign_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "Station callsign.", nullptr));
#endif // QT_CONFIG(tooltip)
        grid_label->setText(QCoreApplication::translate("configuration_dialog", "M&y Grid:", nullptr));
#if QT_CONFIG(tooltip)
        grid_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Maidenhead locator, preferably 6 characters.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        use_dynamic_grid->setToolTip(QCoreApplication::translate("configuration_dialog", "Check to allow grid changes from external programs", nullptr));
#endif // QT_CONFIG(tooltip)
        use_dynamic_grid->setText(QCoreApplication::translate("configuration_dialog", "AutoGrid", nullptr));
        label_12->setText(QCoreApplication::translate("configuration_dialog", "IARU Region:", nullptr));
#if QT_CONFIG(tooltip)
        region_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Select your IARU region.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("configuration_dialog", "Message generation for type 2 compound callsign holders:", nullptr));
        type_2_msg_gen_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "Full call in Tx1", nullptr));
        type_2_msg_gen_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "Full call in Tx3", nullptr));
        type_2_msg_gen_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "Full call in Tx5 only", nullptr));

#if QT_CONFIG(tooltip)
        type_2_msg_gen_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Type 2 compound callsigns are those with prefixes or suffixes not included in the allowed shortlist (See Help-&gt;Add-on prefixes and suffixes).</p><p>This option determines which generated messages should contain your full type 2 compound call sign rather than your base callsign. It only applies if you have a type 2 compound callsign.</p><p>This option controls the way the messages that are used to answer CQ calls are generated. Generated messages 6 (CQ) and 5 (73) will always contain your full callsign. The JT65 and JT9 protocols allow for some standard messages with your full call at the expense of another piece of information such as the DX call or your locator.</p><p>Choosing message 1 omits the DX callsign which may be an issue when replying to CQ calls. Choosing message 3 also omits the DX callsign and many versions of this and other software will not extract the report. Choosing neither means that your full callsign only goes in your message 5 (73) so your QSO partner may log the "
                        "wrong callsign.</p><p>None of these options are perfect, message 3 is usually best but be aware your QSO partner may not log the report you send them.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        display_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Display", nullptr));
#if QT_CONFIG(tooltip)
        DXCC_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Show if decoded stations are new DXCC entities or worked before.", nullptr));
#endif // QT_CONFIG(tooltip)
        DXCC_check_box->setText(QCoreApplication::translate("configuration_dialog", "Show &DXCC, grid, and worked-before status    ", nullptr));
#if QT_CONFIG(tooltip)
        decodes_from_top_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check to have decodes for a new period start at the top of the Band Activity window and not scroll off the top when the window is full.</p><p>This is to aid selecting decodes to double-click while decoding is still in progress. Use the Band Activity vertical scroll bar to reveal decodes past the bottom of the window.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        decodes_from_top_check_box->setText(QCoreApplication::translate("configuration_dialog", "Start new period decodes at top", nullptr));
#if QT_CONFIG(tooltip)
        decoded_text_font_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Set the font characteristics for the Band Activity and Rx Frequency areas.", nullptr));
#endif // QT_CONFIG(tooltip)
        decoded_text_font_push_button->setText(QCoreApplication::translate("configuration_dialog", "Decoded Text Font...", nullptr));
#if QT_CONFIG(tooltip)
        font_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Set the font characteristics for the application.", nullptr));
#endif // QT_CONFIG(tooltip)
        font_push_button->setText(QCoreApplication::translate("configuration_dialog", "Font...", nullptr));
#if QT_CONFIG(tooltip)
        TX_messages_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Show outgoing transmitted messages in the Rx frequency window.", nullptr));
#endif // QT_CONFIG(tooltip)
        TX_messages_check_box->setText(QCoreApplication::translate("configuration_dialog", "&Tx messages to Rx frequency window", nullptr));
        ppfx_check_box->setText(QCoreApplication::translate("configuration_dialog", "Show principal prefix instead of country name        ", nullptr));
#if QT_CONFIG(tooltip)
        insert_blank_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Include a separator line between periods in the band activity window.", nullptr));
#endif // QT_CONFIG(tooltip)
        insert_blank_check_box->setText(QCoreApplication::translate("configuration_dialog", "&Blank line between decoding periods", nullptr));
        show_country_names_check_box->setText(QCoreApplication::translate("configuration_dialog", "Show DXCC for all messages", nullptr));
#if QT_CONFIG(tooltip)
        miles_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Show distance to DX station in miles rather than kilometers.", nullptr));
#endif // QT_CONFIG(tooltip)
        miles_check_box->setText(QCoreApplication::translate("configuration_dialog", "Display dista&nce in miles", nullptr));
#if QT_CONFIG(tooltip)
        cb_detailed_blank_line->setToolTip(QCoreApplication::translate("configuration_dialog", "Show the separator line between periods with time stamp of the decode period.", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_detailed_blank_line->setText(QCoreApplication::translate("configuration_dialog", "Show blank line with time stamp", nullptr));
#if QT_CONFIG(tooltip)
        cbHighlightDXcall->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight DX Call in message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHighlightDXcall->setText(QCoreApplication::translate("configuration_dialog", "Highlight DX Call", nullptr));
#if QT_CONFIG(tooltip)
        cbHighlightDXgrid->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight DX Grid in message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHighlightDXgrid->setText(QCoreApplication::translate("configuration_dialog", "Highlight DX Grid", nullptr));
#if QT_CONFIG(tooltip)
        cbHighlightRogers->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight RRR/RR73/73 in messages for us.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHighlightRogers->setText(QCoreApplication::translate("configuration_dialog", "Highlight RRR/RR73/73 in messages for us", nullptr));
        behaviour_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Behavior", nullptr));
#if QT_CONFIG(tooltip)
        monitor_last_used_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check this if you wish to automatically return to the last monitored frequency when monitor is enabled, leave it unchecked if you wish to have the current rig frequency maintained.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        monitor_last_used_check_box->setText(QCoreApplication::translate("configuration_dialog", "Monitor returns to last used frequency", nullptr));
#if QT_CONFIG(tooltip)
        auto_astro_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Open the Astronomical Data window automatically when switching to Q65 or JT65 mode and Decode after EME delay is enabled, and close it when no longer needed.</p><p>Open the QSYMessage Creator automatically if the VHF Features are enabled and such QSY messages are applicable.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        auto_astro_check_box->setText(QCoreApplication::translate("configuration_dialog", "Auto-open/close Astronomical data window", nullptr));
        force_call_1st_check_box->setText(QCoreApplication::translate("configuration_dialog", "Calling CQ forces Call 1st", nullptr));
#if QT_CONFIG(tooltip)
        tune_watchdog_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Disable the Tune watchdog.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tune_watchdog_check_box->setText(QCoreApplication::translate("configuration_dialog", "Tune watchdog   ", nullptr));
#if QT_CONFIG(tooltip)
        tune_watchdog_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Number of seconds before Tune is aborted</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tune_watchdog_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " seconds", nullptr));
        label_10->setText(QCoreApplication::translate("configuration_dialog", "Tx watchdog: ", nullptr));
#if QT_CONFIG(tooltip)
        tx_watchdog_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Number of minutes before unattended transmissions are aborted</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tx_watchdog_spin_box->setSpecialValueText(QCoreApplication::translate("configuration_dialog", "Disabled", nullptr));
        tx_watchdog_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " minutes", nullptr));
        tx_watchdog_spin_box->setPrefix(QString());
#if QT_CONFIG(tooltip)
        monitor_off_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Don't start decoding until the monitor button is clicked.", nullptr));
#endif // QT_CONFIG(tooltip)
        monitor_off_check_box->setText(QCoreApplication::translate("configuration_dialog", "Mon&itor off at startup", nullptr));
        enable_VHF_features_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable VHF and submode features", nullptr));
#if QT_CONFIG(tooltip)
        progress_bar_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Turn the progress bar red while transmitting.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        progress_bar_check_box->setText(QCoreApplication::translate("configuration_dialog", "Turn progress bar red while transmitting", nullptr));
        decode_at_52s_check_box->setText(QCoreApplication::translate("configuration_dialog", "Decode after EME delay", nullptr));
#if QT_CONFIG(tooltip)
        repeat_Tx_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Tx until 73 is received when in MSK144 or Q65 mode. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        repeat_Tx_check_box->setText(QCoreApplication::translate("configuration_dialog", "MSK144/Q65: Tx until 73 is received", nullptr));
        label->setText(QCoreApplication::translate("configuration_dialog", "ID Inter&val:", nullptr));
#if QT_CONFIG(tooltip)
        CW_id_interval_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Send a CW ID periodically every few minutes.\n"
"This might be required under your countries licence regulations.\n"
"It will not interfere with other users as it is always sent in the\n"
"quiet period when decoding is done.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        quick_call_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Automatic transmission mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        quick_call_check_box->setText(QCoreApplication::translate("configuration_dialog", "Doubl&e-click on call sets Tx enable", nullptr));
        single_decode_check_box->setText(QCoreApplication::translate("configuration_dialog", "Single decode", nullptr));
#if QT_CONFIG(tooltip)
        kHz_without_k_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Allow kHz frequency offset entry without 'k' suffix.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        kHz_without_k_check_box->setText(QCoreApplication::translate("configuration_dialog", "kHz entry without k (restart required)", nullptr));
#if QT_CONFIG(tooltip)
        CW_id_after_73_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Send a CW ID after every 73 or free text message.", nullptr));
#endif // QT_CONFIG(tooltip)
        CW_id_after_73_check_box->setText(QCoreApplication::translate("configuration_dialog", "CW ID a&fter 73", nullptr));
#if QT_CONFIG(tooltip)
        disable_TX_on_73_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Turns off automatic transmissions after sending a 73 or any other free\n"
"text message.", nullptr));
#endif // QT_CONFIG(tooltip)
        disable_TX_on_73_check_box->setText(QCoreApplication::translate("configuration_dialog", "Di&sable Tx after sending 73", nullptr));
        alternate_bindings_check_box->setText(QCoreApplication::translate("configuration_dialog", "Alternate F1-F6 bindings", nullptr));
#if QT_CONFIG(tooltip)
        tx_QSY_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Some rigs are not able to process CAT commands while transmitting. This means that if you are operating in split mode you may have to uncheck this option.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tx_QSY_check_box->setText(QCoreApplication::translate("configuration_dialog", "Allow Tx frequency changes while transmitting", nullptr));
        additional_features_box->setTitle(QCoreApplication::translate("configuration_dialog", "Additional features", nullptr));
#if QT_CONFIG(tooltip)
        align_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Increase or decrease the space between message text and DXCC.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cb_showDistance->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>If a station sends locator, calculate and show the distance in Band Activity pane.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_showDistance->setText(QCoreApplication::translate("configuration_dialog", "Show distance in messages with grid", nullptr));
#if QT_CONFIG(tooltip)
        cb_showAzimuth->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>If a station sends a valid Maidenhead locator, calculate and show the great-circle azimuth in Band Activity pane.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_showAzimuth->setText(QCoreApplication::translate("configuration_dialog", "Show azimuth in messages with grid", nullptr));
#if QT_CONFIG(tooltip)
        align_spin_box2->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Increase or decrease the space between DXCC and distance/azimuth.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cb_Align->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Align the text for DXCC, distance and azimuth.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_Align->setText(QCoreApplication::translate("configuration_dialog", "Align DXCC/distance/azimuth", nullptr));
#if QT_CONFIG(tooltip)
        cbEraseBandActivity->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        cbEraseBandActivity->setText(QCoreApplication::translate("configuration_dialog", "Erase decodes after band change", nullptr));
        Map_Grid_to_State->setText(QCoreApplication::translate("configuration_dialog", "Show US States", nullptr));
        cbClearDXgrid->setText(QCoreApplication::translate("configuration_dialog", "Clear DX Grid after QSO", nullptr));
        cbClearDXcall->setText(QCoreApplication::translate("configuration_dialog", "Clear DX Call after QSO", nullptr));
        band_hopping_every_minute_check_box->setText(QCoreApplication::translate("configuration_dialog", "Band hopping every minute", nullptr));
        alternate_erase_button_check_box->setText(QCoreApplication::translate("configuration_dialog", "Alternate Erase button behavior", nullptr));
        cbRxToTxAfterQSO->setText(QCoreApplication::translate("configuration_dialog", "Set Rx frequency to Tx frequency after QSO", nullptr));
        cbErase_when_mode_changed->setText(QCoreApplication::translate("configuration_dialog", "Erase decodes after mode change", nullptr));
        enable_Wait_features_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable Wait features", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(general_tab), QCoreApplication::translate("configuration_dialog", "Genera&l", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(general_tab), QCoreApplication::translate("configuration_dialog", "General station details and settings.", nullptr));
#endif // QT_CONFIG(tooltip)
        split_operation_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Split Operation", nullptr));
#if QT_CONFIG(tooltip)
        split_emulate_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use only VFO A for split operation (the program temporarily changes the QRG of your rig during transmission).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        split_emulate_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Fake It", nullptr));
#if QT_CONFIG(tooltip)
        split_rig_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use VFO A+B for split operation (works with many rigs, but requires the use of both VFOs).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        split_rig_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Rig", nullptr));
#if QT_CONFIG(tooltip)
        split_none_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Don't use split (not recommended).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        split_none_radio_button->setText(QCoreApplication::translate("configuration_dialog", "None", nullptr));
#if QT_CONFIG(tooltip)
        mode_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Modulation mode selected on radio.", nullptr));
#endif // QT_CONFIG(tooltip)
        mode_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Mode", nullptr));
#if QT_CONFIG(tooltip)
        mode_USB_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>USB is usually the correct modulation mode,</p><p>unless the radio has a special data or packet mode setting</p><p>for AFSK operation.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        mode_USB_radio_button->setText(QCoreApplication::translate("configuration_dialog", "US&B", nullptr));
#if QT_CONFIG(tooltip)
        mode_none_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Don't allow the program to set the radio mode\n"
"(not recommended but use if the wrong mode\n"
"or bandwidth is selected).", nullptr));
#endif // QT_CONFIG(tooltip)
        mode_none_radio_button->setText(QCoreApplication::translate("configuration_dialog", "None", nullptr));
#if QT_CONFIG(tooltip)
        mode_data_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "If this is available then it is usually the correct mode for this program.", nullptr));
#endif // QT_CONFIG(tooltip)
        mode_data_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Data/P&kt", nullptr));
#if QT_CONFIG(tooltip)
        CAT_control_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Settings that control your CAT interface.", nullptr));
#endif // QT_CONFIG(tooltip)
        CAT_control_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "CAT Control", nullptr));
        CAT_port_label->setText(QCoreApplication::translate("configuration_dialog", "Port:", nullptr));
#if QT_CONFIG(tooltip)
        CAT_port_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Serial port used for CAT control.", nullptr));
#endif // QT_CONFIG(tooltip)
        CAT_port_combo_box->setCurrentText(QString());
#if QT_CONFIG(accessibility)
        CAT_serial_port_parameters_group_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Serial Port Parameters", nullptr));
#endif // QT_CONFIG(accessibility)
        CAT_serial_port_parameters_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Serial Port Parameters", nullptr));
        CAT_baud_label->setText(QCoreApplication::translate("configuration_dialog", "Baud Rate:", nullptr));
        CAT_serial_baud_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "1200", nullptr));
        CAT_serial_baud_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "2400", nullptr));
        CAT_serial_baud_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "4800", nullptr));
        CAT_serial_baud_combo_box->setItemText(3, QCoreApplication::translate("configuration_dialog", "9600", nullptr));
        CAT_serial_baud_combo_box->setItemText(4, QCoreApplication::translate("configuration_dialog", "19200", nullptr));
        CAT_serial_baud_combo_box->setItemText(5, QCoreApplication::translate("configuration_dialog", "38400", nullptr));
        CAT_serial_baud_combo_box->setItemText(6, QCoreApplication::translate("configuration_dialog", "57600", nullptr));
        CAT_serial_baud_combo_box->setItemText(7, QCoreApplication::translate("configuration_dialog", "115200", nullptr));

#if QT_CONFIG(tooltip)
        CAT_serial_baud_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Serial port data rate which must match the setting of your radio.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        CAT_data_bits_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Number of data bits used to communicate with your radio's CAT interface (usually eight).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        CAT_data_bits_group_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Data bits", nullptr));
#endif // QT_CONFIG(accessibility)
        CAT_data_bits_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Data Bits", nullptr));
        CAT_default_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "D&efault", nullptr));
        CAT_7_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Se&ven", nullptr));
        CAT_8_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "E&ight", nullptr));
#if QT_CONFIG(tooltip)
        CAT_stop_bits_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Number of stop bits used when communicating with your radio's CAT interface</p><p>(consult you radio's manual for details).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        CAT_stop_bits_group_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Stop bits", nullptr));
#endif // QT_CONFIG(accessibility)
        CAT_stop_bits_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Stop Bits", nullptr));
        CAT_default_stop_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Default", nullptr));
        CAT_one_stop_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "On&e", nullptr));
        CAT_two_stop_bit_radio_button->setText(QCoreApplication::translate("configuration_dialog", "T&wo", nullptr));
#if QT_CONFIG(tooltip)
        CAT_handshake_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Flow control protocol used between this computer and your radio's CAT interface (usually &quot;None&quot; but some require &quot;Hardware&quot;).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        CAT_handshake_group_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Handshake", nullptr));
#endif // QT_CONFIG(accessibility)
        CAT_handshake_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Handshake", nullptr));
        CAT_handshake_default_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Default", nullptr));
        CAT_handshake_none_radio_button->setText(QCoreApplication::translate("configuration_dialog", "&None", nullptr));
#if QT_CONFIG(tooltip)
        CAT_handshake_xon_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Software flow control (very rare on CAT interfaces).", nullptr));
#endif // QT_CONFIG(tooltip)
        CAT_handshake_xon_radio_button->setText(QCoreApplication::translate("configuration_dialog", "XON/XOFF", nullptr));
#if QT_CONFIG(tooltip)
        CAT_handshake_hardware_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Flow control using the RTS and CTS RS-232 control lines\n"
"not often used but some radios have it as an option and \n"
"a few, particularly some Kenwood rigs, require it).", nullptr));
#endif // QT_CONFIG(tooltip)
        CAT_handshake_hardware_radio_button->setText(QCoreApplication::translate("configuration_dialog", "&Hardware", nullptr));
#if QT_CONFIG(tooltip)
        CAT_control_lines_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Special control of CAT port control lines.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        CAT_control_lines_group_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Force Control Lines", nullptr));
#endif // QT_CONFIG(accessibility)
        CAT_control_lines_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Force Control Lines", nullptr));
        force_DTR_combo_box->setItemText(0, QString());
        force_DTR_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "High", nullptr));
        force_DTR_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "Low", nullptr));

        force_DTR_label->setText(QCoreApplication::translate("configuration_dialog", "DTR:", nullptr));
        force_RTS_label->setText(QCoreApplication::translate("configuration_dialog", "RTS:", nullptr));
        force_RTS_combo_box->setItemText(0, QString());
        force_RTS_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "High", nullptr));
        force_RTS_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "Low", nullptr));

#if QT_CONFIG(tooltip)
        test_CAT_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Attempt to connect to the radio with these settings.</p><p>The button will turn green if the connection is successful or red if there is a problem.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        test_CAT_push_button->setText(QCoreApplication::translate("configuration_dialog", "Test CAT", nullptr));
#if QT_CONFIG(tooltip)
        test_PTT_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Attempt to activate the transmitter.\n"
"Click again to deactivate. Normally no power should be\n"
"output since there is no audio being generated at this time.\n"
"Check that any Tx indication on your radio and/or your\n"
"radio interface behave as expected.", nullptr));
#endif // QT_CONFIG(tooltip)
        test_PTT_push_button->setText(QCoreApplication::translate("configuration_dialog", "Test PTT", nullptr));
#if QT_CONFIG(tooltip)
        PTT_method_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "How this program activates the PTT on your radio?", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_method_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "PTT Method", nullptr));
#if QT_CONFIG(tooltip)
        PTT_VOX_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>No PTT activation, instead the radio's automatic VOX is used to key the transmitter.</p><p>Use this if you have no radio interface hardware.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_VOX_radio_button->setText(QCoreApplication::translate("configuration_dialog", "VO&X", nullptr));
#if QT_CONFIG(tooltip)
        PTT_DTR_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use the RS-232 DTR control line to toggle your radio's PTT, requires hardware to interface the line.</p><p>Some commercial interface units also use this method.</p><p>The DTR control line of the CAT serial port may be used for this or a DTR control line on a different serial port may be used.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_DTR_radio_button->setText(QCoreApplication::translate("configuration_dialog", "&DTR", nullptr));
#if QT_CONFIG(tooltip)
        PTT_CAT_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Some radios support PTT via CAT commands,\n"
"use this option if your radio supports it and you have no\n"
"other hardware interface for PTT.", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_CAT_radio_button->setText(QCoreApplication::translate("configuration_dialog", "C&AT", nullptr));
#if QT_CONFIG(tooltip)
        PTT_RTS_radio_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use the RS-232 RTS control line to toggle your radio's PTT, requires hardware to interface the line.</p><p>Some commercial interface units also use this method.</p><p>The RTS control line of the CAT serial port may be used for this or a RTS control line on a different serial port may be used. Note that this option is not available on the CAT serial port when hardware flow control is used.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_RTS_radio_button->setText(QCoreApplication::translate("configuration_dialog", "R&TS", nullptr));
        PTT_port_label->setText(QCoreApplication::translate("configuration_dialog", "Port:", nullptr));
#if QT_CONFIG(tooltip)
        PTT_port_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Select the RS-232 serial port utilised for PTT control, this option is available when DTR or RTS is selected above as a transmit method.</p><p>This port can be the same one as the one used for CAT control.</p><p>For some interface types the special value CAT may be chosen, this is used for non-serial CAT interfaces that can control serial port control lines remotely (OmniRig for example).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PTT_port_combo_box->setCurrentText(QString());
#if QT_CONFIG(tooltip)
        tx_inhibit_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p><b>TX Inhibit</b> (RTS/DTR PTT only).</p><p>This <b>WS station</b> is the app, PC, network, radio, and antenna (may be a remote go-box). When enabled, listen for UDP from a KEY agent (default port 22372). The KEY agent <b>tells WS stations not to transmit</b> while a priority radio is keyed. Physical outcome: <code>assert PTT \342\207\224 want_tx and not hold</code>. Sequencing continues; only whether this station may assert PTT is filtered.</p><p>Default is off (stock PTT). Co-band multi-op stations that share a band with a priority radio should enable this and run a KEY agent.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tx_inhibit_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable TX &Inhibit", nullptr));
        hamlib_groupBox->setTitle(QCoreApplication::translate("configuration_dialog", "Update Hamlib", nullptr));
        rbHamlib32->setText(QCoreApplication::translate("configuration_dialog", "32-bit", nullptr));
#if QT_CONFIG(tooltip)
        revert_update_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Revert the last Hamlib update. </p><p>Note: This function is only available on Windows.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        revert_update_button->setText(QCoreApplication::translate("configuration_dialog", "Revert Update", nullptr));
#if QT_CONFIG(tooltip)
        hamlib_download_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Download the latest libhamlib-4.dll file from https://n0nb.users.sourceforge.net/. </p><p>Note: This function is only available on Windows.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        hamlib_download_button->setText(QCoreApplication::translate("configuration_dialog", "Update Hamlib", nullptr));
        in_use_text->setText(QCoreApplication::translate("configuration_dialog", "In use:", nullptr));
        in_use->setText(QString());
        backed_up_text->setText(QCoreApplication::translate("configuration_dialog", "Backed up:", nullptr));
        backed_up->setText(QString());
        rbHamlib64->setText(QCoreApplication::translate("configuration_dialog", "64-bit", nullptr));
        rig_label->setText(QCoreApplication::translate("configuration_dialog", "Rig:", nullptr));
        CAT_poll_interval_label->setText(QCoreApplication::translate("configuration_dialog", "Poll Interval:", nullptr));
#if QT_CONFIG(tooltip)
        CAT_poll_interval_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Interval to poll rig for status. Longer intervals will mean that changes to the rig will take longer to be detected.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        CAT_poll_interval_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " s", nullptr));
        rig_data_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Rig Data", nullptr));
#if QT_CONFIG(tooltip)
        PWR_and_SWR_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Read and display transmit PWR, SWR and ALC of your rig.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PWR_and_SWR_check_box->setText(QCoreApplication::translate("configuration_dialog", "Display PWR, SWR and ALC", nullptr));
#if QT_CONFIG(tooltip)
        check_SWR_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Stop transmitting immediately when SWR exceeds 2.5.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        check_SWR_check_box->setText(QCoreApplication::translate("configuration_dialog", "Halt Tx when SWR > 2.5", nullptr));
        highlight_ALC1_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight ALC > 50%", nullptr));
        highlight_ALC2_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight ALC > 90%", nullptr));
#if QT_CONFIG(tooltip)
        TX_audio_source_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Some radios can select the audio input using a CAT command,\n"
"this setting allows you to select which audio input will be used\n"
"(if it is available then generally the Rear/Data option is best).", nullptr));
#endif // QT_CONFIG(tooltip)
        TX_audio_source_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Transmit Audio Source", nullptr));
        TX_source_data_radio_button->setText(QCoreApplication::translate("configuration_dialog", "Rear&/Data", nullptr));
        TX_source_mic_radio_button->setText(QCoreApplication::translate("configuration_dialog", "&Front/Mic", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(radio_tab), QCoreApplication::translate("configuration_dialog", "&Radio", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(radio_tab), QCoreApplication::translate("configuration_dialog", "Radio interface configuration settings.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        soundcard_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Souncard", nullptr));
#endif // QT_CONFIG(tooltip)
        soundcard_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Soundcard", nullptr));
        sound_input_label->setText(QCoreApplication::translate("configuration_dialog", "&Input:", nullptr));
        sound_output_label->setText(QCoreApplication::translate("configuration_dialog", "Ou&tput:", nullptr));
        sound_output_channel_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "Mono", nullptr));
        sound_output_channel_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "Left", nullptr));
        sound_output_channel_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "Right", nullptr));
        sound_output_channel_combo_box->setItemText(3, QCoreApplication::translate("configuration_dialog", "Both", nullptr));

#if QT_CONFIG(tooltip)
        sound_output_channel_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Select the audio channel used for transmission.\n"
"Unless you have multiple radios connected on different\n"
"channels; then you will usually want to select mono or\n"
"both here.", nullptr));
#endif // QT_CONFIG(tooltip)
        sound_input_channel_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "Mono", nullptr));
        sound_input_channel_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "Left", nullptr));
        sound_input_channel_combo_box->setItemText(2, QCoreApplication::translate("configuration_dialog", "Right", nullptr));
        sound_input_channel_combo_box->setItemText(3, QCoreApplication::translate("configuration_dialog", "Both", nullptr));

#if QT_CONFIG(tooltip)
        sound_input_channel_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Select the channel to use for receiving.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sound_input_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Select the audio CODEC to use for receiving.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sound_output_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Select the audio CODEC to use for transmitting.\n"
"If this is your default device for system sounds then\n"
"ensure that all system sounds are disabled otherwise\n"
"you will broadcast any systems sounds generated during\n"
"transmitting periods.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        refresh_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Refresh audio device list.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        refresh_push_button->setText(QCoreApplication::translate("configuration_dialog", "Refresh", nullptr));
#if QT_CONFIG(tooltip)
        tci_audio_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use TCI Audio when available.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tci_audio_check_box->setText(QCoreApplication::translate("configuration_dialog", "Use TCI Audio (restart required)", nullptr));
#if QT_CONFIG(tooltip)
        TCI_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Rx audio level</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        TCI_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " dB", nullptr));
        TCI_spin_box->setPrefix(QCoreApplication::translate("configuration_dialog", "Rx ", nullptr));
#if QT_CONFIG(tooltip)
        cbSortAlphabetically->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Sort audio device names alphabetically.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSortAlphabetically->setText(QCoreApplication::translate("configuration_dialog", "Sort alphabetically", nullptr));
#if QT_CONFIG(tooltip)
        cbHideCARD->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Hide the usually unusable ALSA CARD subdevices on Linux.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHideCARD->setText(QCoreApplication::translate("configuration_dialog", "Hide ALSA CARD subdevices (Linux only)", nullptr));
#if QT_CONFIG(tooltip)
        save_path_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Save Directory", nullptr));
#endif // QT_CONFIG(tooltip)
        save_path_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Save Directory", nullptr));
        save_path_label->setText(QCoreApplication::translate("configuration_dialog", "Loc&ation:", nullptr));
#if QT_CONFIG(tooltip)
        save_path_display_label->setToolTip(QCoreApplication::translate("configuration_dialog", "Path to which .WAV files are saved.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        save_path_select_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Click to select a different save directory for .WAV files.", nullptr));
#endif // QT_CONFIG(tooltip)
        save_path_select_push_button->setText(QCoreApplication::translate("configuration_dialog", "S&elect", nullptr));
#if QT_CONFIG(tooltip)
        azel_path_group_box->setToolTip(QCoreApplication::translate("configuration_dialog", "AzEl Directory", nullptr));
#endif // QT_CONFIG(tooltip)
        azel_path_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "AzEl Directory", nullptr));
        azel_path_label->setText(QCoreApplication::translate("configuration_dialog", "Location:", nullptr));
#if QT_CONFIG(tooltip)
        azel_path_display_label->setToolTip(QCoreApplication::translate("configuration_dialog", "Path to which the azel.dat file is saved.", nullptr));
#endif // QT_CONFIG(tooltip)
        azel_path_select_push_button->setText(QCoreApplication::translate("configuration_dialog", "Select", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxAzElExtraLines->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Enables additional line in azel.dat for Dpol parameter.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxAzElExtraLines->setText(QCoreApplication::translate("configuration_dialog", "Enable extra line in azel.dat", nullptr));
#if QT_CONFIG(tooltip)
        split_operation_group_box_2->setToolTip(QCoreApplication::translate("configuration_dialog", "Power Memory By Band", nullptr));
#endif // QT_CONFIG(tooltip)
        split_operation_group_box_2->setTitle(QCoreApplication::translate("configuration_dialog", "Remember power settings by band", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxPwrBandTxMemory->setToolTip(QCoreApplication::translate("configuration_dialog", "Enable power memory during transmit", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxPwrBandTxMemory->setText(QCoreApplication::translate("configuration_dialog", "Transmit", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxPwrBandTuneMemory->setToolTip(QCoreApplication::translate("configuration_dialog", "Enable power memory during tuning", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxPwrBandTuneMemory->setText(QCoreApplication::translate("configuration_dialog", "Tune", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(audio_tab), QCoreApplication::translate("configuration_dialog", "A&udio", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(audio_tab), QCoreApplication::translate("configuration_dialog", "Audio interface settings", nullptr));
#endif // QT_CONFIG(tooltip)
        add_macro_push_button->setText(QCoreApplication::translate("configuration_dialog", "&Add", nullptr));
        delete_macro_push_button->setText(QCoreApplication::translate("configuration_dialog", "&Delete", nullptr));
#if QT_CONFIG(tooltip)
        macros_list_view->setToolTip(QCoreApplication::translate("configuration_dialog", "Drag and drop items to rearrange order\n"
"Right click for item specific actions\n"
"Click, SHIFT+Click and, CRTL+Click to select items", nullptr));
#endif // QT_CONFIG(tooltip)
        configuration_tabs->setTabText(configuration_tabs->indexOf(tx_macros_tab), QCoreApplication::translate("configuration_dialog", "Tx &Macros", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(tx_macros_tab), QCoreApplication::translate("configuration_dialog", "Canned free text messages setup", nullptr));
#endif // QT_CONFIG(tooltip)
        logging_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Logging", nullptr));
#if QT_CONFIG(tooltip)
        prompt_to_log_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "The program will pop up a partially completed Log QSO dialog when you send a 73 or free text message.", nullptr));
#endif // QT_CONFIG(tooltip)
        prompt_to_log_check_box->setText(QCoreApplication::translate("configuration_dialog", "Promp&t me to log QSO", nullptr));
#if QT_CONFIG(tooltip)
        cbLogDialFrequency->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check to log dial frequency instead of the actual Tx frequency.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLogDialFrequency->setText(QCoreApplication::translate("configuration_dialog", "Log dial frequency instead of Tx frequency", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoLog->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check to have QSOs logged automatically, when complete.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAutoLog->setText(QCoreApplication::translate("configuration_dialog", "Log automatically", nullptr));
#if QT_CONFIG(tooltip)
        cbContestingOnly->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use 'Log automatically' only for special operating activities.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbContestingOnly->setText(QCoreApplication::translate("configuration_dialog", "Contesting only", nullptr));
        logpath_label->setText(QCoreApplication::translate("configuration_dialog", "Logbook location: ", nullptr));
#if QT_CONFIG(tooltip)
        logpath_lineEdit->setToolTip(QCoreApplication::translate("configuration_dialog", "Path to which the wsjtx_log.adi file is saved.", nullptr));
#endif // QT_CONFIG(tooltip)
        logpath_select_pushButton->setText(QCoreApplication::translate("configuration_dialog", "Select", nullptr));
#if QT_CONFIG(tooltip)
        cbZZ00->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Log 'ZZ00' as grid if the other station doesn't send you a grid.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbZZ00->setText(QCoreApplication::translate("configuration_dialog", "Fill missing grids with 'ZZ00'", nullptr));
#if QT_CONFIG(tooltip)
        cbLog4digitGrids->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Shorten 6-digit grid entries and log 4-digit grids instead.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLog4digitGrids->setText(QCoreApplication::translate("configuration_dialog", "Log 4-digit grids", nullptr));
        label_13->setText(QCoreApplication::translate("configuration_dialog", "Op Call:", nullptr));
#if QT_CONFIG(tooltip)
        opCallEntry->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>The callsign of the operator, if different from the station callsign.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        report_in_comments_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Some logging programs will not accept the type of reports\n"
"saved by this program.\n"
"Check this option to save the sent and received reports in the\n"
"comments field.", nullptr));
#endif // QT_CONFIG(tooltip)
        report_in_comments_check_box->setText(QCoreApplication::translate("configuration_dialog", "d&B reports to comments", nullptr));
#if QT_CONFIG(tooltip)
        log_as_RTTY_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Some logging programs will not accept WSJT-X mode names.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        log_as_RTTY_check_box->setText(QCoreApplication::translate("configuration_dialog", "Con&vert mode to RTTY", nullptr));
#if QT_CONFIG(tooltip)
        specOp_in_comments_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check this option to note any Special Operating Activity in the comments field.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        specOp_in_comments_check_box->setText(QCoreApplication::translate("configuration_dialog", "Special operating activity to comments", nullptr));
        network_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "PSK Reporter", nullptr));
#if QT_CONFIG(tooltip)
        psk_reporter_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>The program can send your station details and all decoded signals with grid squares as spots to the http://pskreporter.info web site.</p><p>This is used for reverse beacon analysis which is very useful for assessing propagation and system performance.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        psk_reporter_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable &PSK Reporter Spotting", nullptr));
#if QT_CONFIG(tooltip)
        psk_reporter_tcpip_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check this option if a reliable connection is needed</p><p>Most users do not need this, the default uses UDP which is more efficient. Only check this if you have evidence that UDP traffic from you to PSK Reporter is being lost.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        psk_reporter_tcpip_check_box->setText(QCoreApplication::translate("configuration_dialog", "Use TCP/IP connection", nullptr));
        livecq_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "LiveCQ", nullptr));
#if QT_CONFIG(tooltip)
        livecq_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Master switch for the Q65 LiveCQ service: uploads of your Q65 decodes to the enabled destinations, and the who-heard-me green checks in Q65 Pileup operation. In a pile-up this lets the DX see which callers are actually copying him.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        livecq_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable Q65 LiveCQ", nullptr));
#if QT_CONFIG(tooltip)
        livecq_official_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Send CQ-family messages (only) to the W3SZ LiveCQ at w3sz.com \342\200\224 the same reports WS-MAP and EME65 send there.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        livecq_official_check_box->setText(QCoreApplication::translate("configuration_dialog", "W3SZ (w3sz.com)", nullptr));
        livecq_w3sz_id_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "WSJTX", nullptr));
        livecq_w3sz_id_combo_box->setItemText(1, QCoreApplication::translate("configuration_dialog", "WS", nullptr));

#if QT_CONFIG(tooltip)
        livecq_w3sz_id_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Program name reported to w3sz.com: WSJTX, as before the re-branding, or WS. N6NU and custom destinations always receive WS.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        livecq_n6nu_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Full-featured destination: CQ and directed messages, and the source of the who-heard-me green checks. Required for Q65 Pileup operation.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        livecq_n6nu_check_box->setText(QCoreApplication::translate("configuration_dialog", "N6NU (livecq.n6nu.org)", nullptr));
#if QT_CONFIG(tooltip)
        livecq_custom_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Send CQ-family messages (only) to your own LiveCQ endpoint. Does nothing while the URL field is empty.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        livecq_custom_check_box->setText(QCoreApplication::translate("configuration_dialog", "Custom:", nullptr));
#if QT_CONFIG(tooltip)
        livecq_other_url_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Full URL of your own LiveCQ endpoint, e.g. http://localhost:3000/api/livecq_update</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_4->setTitle(QCoreApplication::translate("configuration_dialog", "UDP Server", nullptr));
        udp_server_label->setText(QCoreApplication::translate("configuration_dialog", "UDP Server:", nullptr));
#if QT_CONFIG(tooltip)
        udp_server_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Optional hostname of network service to receive decodes.</p><p>Formats:</p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">hostname</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv4 address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv6 address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv4 multicast group address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv6 multicast group address</li></ul><p>Clearing this field will disable the broadcasting of UDP status updates.</p></body></htm"
                        "l>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("configuration_dialog", "UDP Server port number:", nullptr));
#if QT_CONFIG(tooltip)
        udp_server_port_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Enter the service port number of the UDP server that WS should send updates to. If this is zero no updates will be sent.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        udp_interfaces_label->setText(QCoreApplication::translate("configuration_dialog", "Outgoing interfaces:", nullptr));
#if QT_CONFIG(tooltip)
        udp_interfaces_combo_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>When sending updates to a multicast group address it is necessary to specify which network interface(s) to send them to. If the loop-back interface is multicast capable then at least that one will be selected.</p><p>For most users the loop-back interface is all that is needed, that will allow multiple other applications on the same machine to interoperate with WS. If applications running on other hosts are to receive status updates then a suitable network interface should be used.</p><p>On some Linux systems it may be necessary to enable multicast on the loop-back network interface.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        udp_TTL_label->setText(QCoreApplication::translate("configuration_dialog", "Multicast TTL:", nullptr));
#if QT_CONFIG(tooltip)
        udp_TTL_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Sets the number or router hops that multicast datagrams are allowed to make. Almost everyone should set this to 1 to keep outgoing multicast traffic withn the local subnet.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        accept_udp_requests_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>With this enabled WS will accept certain requests back from a UDP server that receives decode messages.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        accept_udp_requests_check_box->setText(QCoreApplication::translate("configuration_dialog", "Accept UDP requests", nullptr));
#if QT_CONFIG(tooltip)
        udpWindowToFront->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Indicate acceptance of an incoming UDP request. The effect of this option varies depending on the operating system and window manager, its intent is to notify the acceptance of an incoming UDP request even if this application is minimized or hidden.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        udpWindowToFront->setText(QCoreApplication::translate("configuration_dialog", "Notify on accepted UDP request", nullptr));
#if QT_CONFIG(tooltip)
        udpWindowRestore->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Restore the window from minimized if an UDP request is accepted.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        udpWindowRestore->setText(QCoreApplication::translate("configuration_dialog", "Accepted UDP request restores window", nullptr));
#if QT_CONFIG(tooltip)
        udpWSJTXCompatibilityMode->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Identify to UDP servers as WSJT-X instead of WS, for programs that only recognise WSJT-X.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        udpWSJTXCompatibilityMode->setText(QCoreApplication::translate("configuration_dialog", "WSJT-X compatibility mode", nullptr));
        n1mm_group_box->setTitle(QCoreApplication::translate("configuration_dialog", "Secondary UDP Server", nullptr));
#if QT_CONFIG(tooltip)
        enable_n1mm_broadcast_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>When checked, WS will broadcast a logged contact in ADIF format to the configured hostname and port. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        enable_n1mm_broadcast_check_box->setText(QCoreApplication::translate("configuration_dialog", "Enable logged contact ADIF broadcast", nullptr));
        n1mm_server_name_label->setText(QCoreApplication::translate("configuration_dialog", "Server name or IP address:", nullptr));
#if QT_CONFIG(tooltip)
        n1mm_server_name_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Optional host name of N1MM Logger+ program to receive ADIF UDP broadcasts. This is usually 'localhost' or ip address 127.0.0.1</p><p>Formats:</p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">hostname</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv4 address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv6 address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv4 multicast group address</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IPv6 multicast group address</li></ul><p>Clearing this fiel"
                        "d will disable broadcasting of ADIF information via UDP.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        n1mm_server_port_label->setText(QCoreApplication::translate("configuration_dialog", "Server port number:", nullptr));
#if QT_CONFIG(tooltip)
        n1mm_server_port_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Enter the port number that WS should use for UDP broadcasts of ADIF log information. For N1MM Logger+, this value should be 2333. If this is zero,  no updates will be broadcast.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        configuration_tabs->setTabText(configuration_tabs->indexOf(reporting_tab), QCoreApplication::translate("configuration_dialog", "Reportin&g", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(reporting_tab), QCoreApplication::translate("configuration_dialog", "Reporting and logging settings", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        groupBox_3->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>See &quot;Frequency Calibration&quot; in the WSJT-X User Guide for details of how to determine these parameters for your radio.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_3->setTitle(QCoreApplication::translate("configuration_dialog", "Frequency Calibration", nullptr));
        label_8->setText(QCoreApplication::translate("configuration_dialog", "Slope:", nullptr));
        calibration_slope_ppm_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " ppm", nullptr));
        label_7->setText(QCoreApplication::translate("configuration_dialog", "Intercept:", nullptr));
        calibration_intercept_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " Hz", nullptr));
        groupBox->setTitle(QCoreApplication::translate("configuration_dialog", "Working Frequencies", nullptr));
#if QT_CONFIG(tooltip)
        frequencies_table_view->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Right click to maintain the working frequencies list.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QCoreApplication::translate("configuration_dialog", "Station Information", nullptr));
#if QT_CONFIG(tooltip)
        stations_table_view->setToolTip(QCoreApplication::translate("configuration_dialog", "Items may be edited.\n"
"Right click for insert and delete options.", nullptr));
#endif // QT_CONFIG(tooltip)
        configuration_tabs->setTabText(configuration_tabs->indexOf(frequencies_tab), QCoreApplication::translate("configuration_dialog", "Frequencies", nullptr));
#if QT_CONFIG(tooltip)
        configuration_tabs->setTabToolTip(configuration_tabs->indexOf(frequencies_tab), QCoreApplication::translate("configuration_dialog", "Default frequencies and band specific station details setup", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_12->setTitle(QCoreApplication::translate("configuration_dialog", "Decode Highlightling", nullptr));
#if QT_CONFIG(tooltip)
        reset_highlighting_to_defaults_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Push to reset all highlight items above to default values and priorities.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        reset_highlighting_to_defaults_push_button->setText(QCoreApplication::translate("configuration_dialog", "Reset Highlighting to WSJT-X default", nullptr));
        reset_highlighting_to_defaults2_push_button->setText(QCoreApplication::translate("configuration_dialog", "Reset Highlighting to WS default", nullptr));
#if QT_CONFIG(tooltip)
        rescan_log_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Click to scan the wsjtx_log.adi ADIF file again for worked before information</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rescan_log_push_button->setText(QCoreApplication::translate("configuration_dialog", "Rescan ADIF Log", nullptr));
#if QT_CONFIG(tooltip)
        highlighting_list_view->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Enable or disable using the check boxes and right-click an item to change or unset the foreground color, background color, or reset the item to default values. Drag and drop the items to change their priority, higher in the list is higher in priority.</p><p>Note that each foreground or background color may be either set or unset, unset means that it is not allocated for that item's type and lower priority items may apply.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        highlight_orange_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight callsigns or grids or prefixes with orange background color. Callsigns and grids must be separated by a comma, and there must be a comma after each callsign. Prefixes require a semicolon before and after them. Wildcards (*) are only allowed after single-digit prefixes. To exclude 2-or 3-digit prefixes, place an exclamation mark before and after them (e.g., ;K*;!KH6!KL!KP!).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        highlight_orange_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight orange:", nullptr));
#if QT_CONFIG(tooltip)
        highlight_by_mode_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check to indicate new DXCC entities, grid squares, and callsigns per mode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        highlight_by_mode_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight by Mode", nullptr));
#if QT_CONFIG(tooltip)
        only_fields_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "Check to for grid highlighting to only apply to unworked grid fields", nullptr));
#endif // QT_CONFIG(tooltip)
        only_fields_check_box->setText(QCoreApplication::translate("configuration_dialog", "Only grid Fields sought", nullptr));
        include_WAE_check_box->setText(QCoreApplication::translate("configuration_dialog", "Include extra WAE entities", nullptr));
        highlight_73_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight also messages with 73 or RR73", nullptr));
        highlight_all_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight all messages", nullptr));
#if QT_CONFIG(tooltip)
        highlight_orange_callsigns->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight callsigns or grids or prefixes with orange background color. Callsigns and grids must be separated by a comma, and there must be a comma after each callsign. For directional calls, a comma must be placed before and after (e.g. ,DX,YOTA,POTA,). Prefixes require a semicolon before and after them. Wildcards (*) are only allowed after single-digit prefixes. To exclude 2-or 3-digit prefixes, place an exclamation mark before and after them (e.g., ;K*;!KH6!KL!KP!).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        highlight_blue_check_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight callsigns or grids or prefixes with blue background color. Callsigns and grids must be separated by a comma, and there must be a comma after each callsign. Prefixes require a semicolon before and after them. Wildcards (*) are only allowed after single-digit prefixes. To exclude 2-or 3-digit prefixes, place an exclamation mark before and after them (e.g., ;K*;!KH6!KL!KP!).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        highlight_blue_check_box->setText(QCoreApplication::translate("configuration_dialog", "Highlight blue:", nullptr));
#if QT_CONFIG(tooltip)
        highlight_blue_callsigns->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Highlight callsigns or grids or prefixes with blue background color. Callsigns and grids must be separated by a comma, and there must be a comma after each callsign. Prefixes require a semicolon before and after them. Wildcards (*) are only allowed after single-digit prefixes. To exclude 2-or 3-digit prefixes, place an exclamation mark before and after them (e.g., ;K*;!KH6!KL!KP!).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        groupBox_11->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Controls for Logbook of the World user lookup.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_11->setTitle(QCoreApplication::translate("configuration_dialog", "Logbook of the World User Validation", nullptr));
        label_15->setText(QCoreApplication::translate("configuration_dialog", "Users CSV file URL:", nullptr));
#if QT_CONFIG(tooltip)
        LotW_CSV_URL_line_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>URL of the ARRL LotW user's last upload dates and times data file which is used to highlight decodes from stations that are known to upload their log file to LotW.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        LotW_CSV_URL_line_edit->setAccessibleName(QCoreApplication::translate("configuration_dialog", "URL", nullptr));
#endif // QT_CONFIG(accessibility)
        LotW_CSV_URL_line_edit->setText(QCoreApplication::translate("configuration_dialog", "http://lotw.arrl.org/lotw-user-activity.csv", nullptr));
#if QT_CONFIG(tooltip)
        LotW_CSV_fetch_push_button->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Push this button to fetch the latest LotW user's upload date and time data file.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        LotW_CSV_fetch_push_button->setText(QCoreApplication::translate("configuration_dialog", "Fetch Now", nullptr));
#if QT_CONFIG(tooltip)
        LotW_days_since_upload_spin_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Adjust this spin box to set the age threshold of LotW user's last upload date that is accepted as a current LotW user.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        LotW_days_since_upload_spin_box->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Days since last upload", nullptr));
#endif // QT_CONFIG(accessibility)
        LotW_days_since_upload_spin_box->setSuffix(QCoreApplication::translate("configuration_dialog", " days", nullptr));
        LotW_CSV_status_label->setText(QString());
        label_14->setText(QCoreApplication::translate("configuration_dialog", "Age of last upload less than:", nullptr));
        downloads_groupBox->setTitle(QCoreApplication::translate("configuration_dialog", "Downloads", nullptr));
#if QT_CONFIG(tooltip)
        CALL3_download_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Dowload latest CALL3.TXT file.", nullptr));
#endif // QT_CONFIG(tooltip)
        CALL3_download_button->setText(QCoreApplication::translate("configuration_dialog", "Download CALL3.TXT for terrestrial use", nullptr));
        CTY_file_label->setText(QCoreApplication::translate("configuration_dialog", "CTY File Version: ", nullptr));
        callsign_states_label->setText(QCoreApplication::translate("configuration_dialog", "Callsign States DB: ", nullptr));
        CALL3_file_label->setText(QCoreApplication::translate("configuration_dialog", "CALL3 File Version:", nullptr));
#if QT_CONFIG(tooltip)
        CALL3_EME_download_button->setToolTip(QCoreApplication::translate("configuration_dialog", "Dowload latest CALL3.TXT file for EME. This version is suitable for JT65 Deep Search.", nullptr));
#endif // QT_CONFIG(tooltip)
        CALL3_EME_download_button->setText(QCoreApplication::translate("configuration_dialog", "Download CALL3.TXT for EME", nullptr));
        callsign_states_download_button->setText(QCoreApplication::translate("configuration_dialog", "Download US Callsign States database", nullptr));
        CTY_download_button->setText(QCoreApplication::translate("configuration_dialog", "Download Latest CTY.dat", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(colors_tab), QCoreApplication::translate("configuration_dialog", "Colors", nullptr));
#if QT_CONFIG(tooltip)
        gbCloudlog->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Upload logged QSOs to Cloudlog or Wavelog.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbCloudlog->setTitle(QCoreApplication::translate("configuration_dialog", "Upload QSOs to Cloudlog or Wavelog", nullptr));
#if QT_CONFIG(tooltip)
        api_url_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>API URL for Cloudlog or Wavelog.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        api_url_label->setText(QCoreApplication::translate("configuration_dialog", "API URL: ", nullptr));
#if QT_CONFIG(tooltip)
        api_key_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your API key.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        api_key_label->setText(QCoreApplication::translate("configuration_dialog", "API Key: ", nullptr));
#if QT_CONFIG(tooltip)
        station_id_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your Station ID.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        station_id_label->setText(QCoreApplication::translate("configuration_dialog", "Station ID: ", nullptr));
#if QT_CONFIG(tooltip)
        sbCloudlogStationID->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your Station ID.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leCloudlogApiKey->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your API key.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leCloudlogApiUrl->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>API URL for Cloudlog or Wavelog.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pbTestCloudlog->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Test the Cloudlog or Wavelog API key.</p><p>The button will turn green if the API key is writable. It will turn orange if the API key is read-only. If the API key is invalid it will turn red.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pbTestCloudlog->setText(QCoreApplication::translate("configuration_dialog", "Test API Key", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("configuration_dialog", "Miscellaneous", nullptr));
        label_3->setText(QCoreApplication::translate("configuration_dialog", "Degrade S/N of .wav file: ", nullptr));
#if QT_CONFIG(tooltip)
        sbDegrade->setToolTip(QCoreApplication::translate("configuration_dialog", "For offline sensitivity tests", nullptr));
#endif // QT_CONFIG(tooltip)
        sbDegrade->setSuffix(QCoreApplication::translate("configuration_dialog", " dB", nullptr));
        label_9->setText(QCoreApplication::translate("configuration_dialog", "Receiver bandwidth:", nullptr));
#if QT_CONFIG(tooltip)
        sbBandwidth->setToolTip(QCoreApplication::translate("configuration_dialog", "For offline sensitivity tests", nullptr));
#endif // QT_CONFIG(tooltip)
        sbBandwidth->setSuffix(QCoreApplication::translate("configuration_dialog", "  Hz", nullptr));
        label_11->setText(QCoreApplication::translate("configuration_dialog", "Tx delay:", nullptr));
#if QT_CONFIG(tooltip)
        sbTxDelay->setToolTip(QCoreApplication::translate("configuration_dialog", "Minimum delay between assertion of PTT and start of Tx audio.", nullptr));
#endif // QT_CONFIG(tooltip)
        sbTxDelay->setSuffix(QCoreApplication::translate("configuration_dialog", "  s", nullptr));
#if QT_CONFIG(accessibility)
        groupBox_10->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Tone spacing", nullptr));
#endif // QT_CONFIG(accessibility)
        groupBox_10->setTitle(QCoreApplication::translate("configuration_dialog", "Tone spacing", nullptr));
#if QT_CONFIG(tooltip)
        cbx2ToneSpacing->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Generate Tx audio with twice the normal tone spacing.  Intended for special LF/MF transmitters that use a divide-by-2 before generating RF.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbx2ToneSpacing->setText(QCoreApplication::translate("configuration_dialog", "x 2", nullptr));
#if QT_CONFIG(tooltip)
        cbx4ToneSpacing->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Generate Tx audio with four times the normal tone spacing. Intended for special LF/MF transmitters that use a divide-by-4 before generating RF.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbx4ToneSpacing->setText(QCoreApplication::translate("configuration_dialog", "x 4 ", nullptr));
#if QT_CONFIG(accessibility)
        groupBox_7->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Waterfall spectra", nullptr));
#endif // QT_CONFIG(accessibility)
        groupBox_7->setTitle(QCoreApplication::translate("configuration_dialog", "Waterfall spectra", nullptr));
        rbLowSidelobes->setText(QCoreApplication::translate("configuration_dialog", "Low sidelobes", nullptr));
        rbMaxSensitivity->setText(QCoreApplication::translate("configuration_dialog", "Most sensitive", nullptr));
#if QT_CONFIG(tooltip)
        groupBox_6->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>User-selectable parameters for JT65 VHF/UHF/Microwave decoding.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_6->setTitle(QCoreApplication::translate("configuration_dialog", "JT65 VHF/UHF/Microwave decoding parameters", nullptr));
        label_2->setText(QCoreApplication::translate("configuration_dialog", "Random erasure patterns:", nullptr));
#if QT_CONFIG(tooltip)
        sbNtrials->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Maximum number of erasure patterns for stochastic soft-decision Reed Solomon decoder is 10^(n/2).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("configuration_dialog", "Aggressive decoding level:", nullptr));
#if QT_CONFIG(tooltip)
        sbAggressive->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Higher levels will increase the probability of decoding, but will also increase probability of a false decode.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTwoPass->setText(QCoreApplication::translate("configuration_dialog", "Two-pass decoding", nullptr));
#if QT_CONFIG(tooltip)
        gbEQSL->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Upload logged QSOs to eqsl.cc.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbEQSL->setTitle(QCoreApplication::translate("configuration_dialog", "Upload QSOs to eQSL.cc", nullptr));
#if QT_CONFIG(tooltip)
        eqsluser_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your username.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        eqsluser_label->setText(QCoreApplication::translate("configuration_dialog", "Username:", nullptr));
#if QT_CONFIG(tooltip)
        eqslpasswd_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your logon password.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        eqslpasswd_label->setText(QCoreApplication::translate("configuration_dialog", "Password:", nullptr));
#if QT_CONFIG(tooltip)
        eqslnick_label->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your QTH nickname, if you have more than one QTH.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        eqslnick_label->setText(QCoreApplication::translate("configuration_dialog", "QTH:", nullptr));
#if QT_CONFIG(tooltip)
        eqslnick_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your QTH nickname, if you have more than one QTH.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        eqslpasswd_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your logon password.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        eqsluser_edit->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Your username.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_8->setTitle(QCoreApplication::translate("configuration_dialog", "GUI tweaks for high-resolution monitors", nullptr));
#if QT_CONFIG(tooltip)
        cbHighDPI->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>HighDPI scaling enables a larger and more proportionally correct display of the controls on 4K monitors (if supported by the OS).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHighDPI->setText(QCoreApplication::translate("configuration_dialog", "HighDPI scaling (restart required)", nullptr));
#if QT_CONFIG(tooltip)
        cbLargerTabWidget->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Increased height of some control elements.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbLargerTabWidget->setText(QCoreApplication::translate("configuration_dialog", "Increased height of the tab widget (restart required)", nullptr));
        gbSpecialOpActivity->setTitle(QCoreApplication::translate("configuration_dialog", "Special operating activity", nullptr));
#if QT_CONFIG(tooltip)
        rbARRL_Digi->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>ARRL International Digital Contest</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbARRL_Digi->setText(QCoreApplication::translate("configuration_dialog", "ARRL Digi Contest", nullptr));
#if QT_CONFIG(tooltip)
        rbWW_DIGI->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>World-Wide Digi-mode contest</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbWW_DIGI->setAccessibleName(QCoreApplication::translate("configuration_dialog", "WW Digital Contest", nullptr));
#endif // QT_CONFIG(accessibility)
        rbWW_DIGI->setText(QCoreApplication::translate("configuration_dialog", "WW Digi Contest", nullptr));
#if QT_CONFIG(tooltip)
        cb_NCCC_Sprint->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Toggle the NCCC Sprint FT4 short message protocol On/Off.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_NCCC_Sprint->setText(QCoreApplication::translate("configuration_dialog", "NCCC Sprint", nullptr));
#if QT_CONFIG(tooltip)
        rbField_Day->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>ARRL Field Day exchange: number of transmitters, Class, and ARRL/RAC section or &quot;DX&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbField_Day->setAccessibleName(QCoreApplication::translate("configuration_dialog", "A R R L Field Day", nullptr));
#endif // QT_CONFIG(accessibility)
        rbField_Day->setText(QCoreApplication::translate("configuration_dialog", "ARRL Field Day", nullptr));
#if QT_CONFIG(accessibility)
        labFD->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Field Day exchange", nullptr));
#endif // QT_CONFIG(accessibility)
        labFD->setText(QCoreApplication::translate("configuration_dialog", "FD Exch:", nullptr));
#if QT_CONFIG(tooltip)
        Field_Day_Exchange->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>ARRL Field Day exchange: number of transmitters, Class, and ARRL/RAC section or &quot;DX&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Field_Day_Exchange->setText(QCoreApplication::translate("configuration_dialog", "6A SNJ", nullptr));
#if QT_CONFIG(tooltip)
        rbHound->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>FT8 DXpedition mode:  Hound operator calling the DX.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbHound->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Hound", nullptr));
#endif // QT_CONFIG(accessibility)
        rbHound->setText(QCoreApplication::translate("configuration_dialog", "Hound", nullptr));
#if QT_CONFIG(tooltip)
        rbRTTY_Roundup->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>FT Roundup and similar contests. Exchange is US state, Canadian province, or &quot;DX&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbRTTY_Roundup->setAccessibleName(QCoreApplication::translate("configuration_dialog", "R T T Y Roundup", nullptr));
#endif // QT_CONFIG(accessibility)
        rbRTTY_Roundup->setText(QCoreApplication::translate("configuration_dialog", "FT Roundup messages", nullptr));
#if QT_CONFIG(accessibility)
        labRTTY->setAccessibleName(QCoreApplication::translate("configuration_dialog", "RTTY Roundup exchange", nullptr));
#endif // QT_CONFIG(accessibility)
        labRTTY->setText(QCoreApplication::translate("configuration_dialog", "FT RU Exch:", nullptr));
#if QT_CONFIG(tooltip)
        RTTY_Exchange->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>FT Roundup and similar contests. Exchange is US state, Canadian province, or &quot;DX&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RTTY_Exchange->setText(QCoreApplication::translate("configuration_dialog", "NJ", nullptr));
#if QT_CONFIG(tooltip)
        rbEU_VHF_Contest->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>European VHF+ contests requiring a signal report, serial number, and 6-character locator.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbEU_VHF_Contest->setAccessibleName(QCoreApplication::translate("configuration_dialog", "EU VHF Contest", nullptr));
#endif // QT_CONFIG(accessibility)
        rbEU_VHF_Contest->setText(QCoreApplication::translate("configuration_dialog", "EU VHF Contest", nullptr));
#if QT_CONFIG(tooltip)
        cbSuperFox->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Check this box to transmit (Fox) or receive (Hound) the SuperFox waveform.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSuperFox->setText(QCoreApplication::translate("configuration_dialog", "SuperFox mode", nullptr));
#if QT_CONFIG(tooltip)
        cbShowOTP->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Show OTP messages in the Band Activity window.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbShowOTP->setText(QCoreApplication::translate("configuration_dialog", "Show OTP messages", nullptr));
        lblOTPUrl->setText(QCoreApplication::translate("configuration_dialog", "OTP URL:", nullptr));
#if QT_CONFIG(tooltip)
        OTPUrl->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>URL used to verify OTP codes.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OTPUrl->setText(QCoreApplication::translate("configuration_dialog", "https://www.9dx.cc", nullptr));
#if QT_CONFIG(tooltip)
        rbNA_VHF_Contest->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>North American VHF/UHF/Microwave contests and others in which a 4-character grid locator is the required exchange.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbNA_VHF_Contest->setAccessibleName(QCoreApplication::translate("configuration_dialog", "NA VHF Contest", nullptr));
#endif // QT_CONFIG(accessibility)
        rbNA_VHF_Contest->setText(QCoreApplication::translate("configuration_dialog", "NA VHF", nullptr));
#if QT_CONFIG(tooltip)
        rbFox->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>FT8 DXpedition mode:  Fox (DXpedition) operator.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        rbFox->setAccessibleName(QCoreApplication::translate("configuration_dialog", "Fox", nullptr));
#endif // QT_CONFIG(accessibility)
        rbFox->setText(QCoreApplication::translate("configuration_dialog", "Fox", nullptr));
#if QT_CONFIG(tooltip)
        cbOTP->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Click to enable OTP method of Fox verification. Requires internet.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbOTP->setText(QCoreApplication::translate("configuration_dialog", "OTP", nullptr));
        lblOTPSeed->setText(QCoreApplication::translate("configuration_dialog", "Key:", nullptr));
#if QT_CONFIG(tooltip)
        OTPSeed->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Fox's key to generate OTP Codes.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OTPSeed->setText(QCoreApplication::translate("configuration_dialog", "M2ZUU5CW6EVOY2HU", nullptr));
        lblOTPEvery->setText(QCoreApplication::translate("configuration_dialog", "Interval", nullptr));
#if QT_CONFIG(tooltip)
        sbOTPinterval->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Interval at which the OTP messages are sent. Select 1 to sign every message.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbContestName->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Call CQ with an individual contest name instead of TEST, RU, or WW (for example CQ PACC).</p></body></html>\n"
"", nullptr));
#endif // QT_CONFIG(tooltip)
        cbContestName->setText(QCoreApplication::translate("configuration_dialog", "CQ with individual contest name", nullptr));
        labCN->setText(QCoreApplication::translate("configuration_dialog", "Contest name:", nullptr));
        Contest_Name->setText(QString());
#if QT_CONFIG(tooltip)
        rbQ65pileup->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Exchange 4-character locator instead of signal report.  Provides q3-level sensitivities for the DX operator.  Especially useful for 6m EME DXpeditions.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbQ65pileup->setText(QCoreApplication::translate("configuration_dialog", "Q65 Pileup", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(advanced_tab), QCoreApplication::translate("configuration_dialog", "Advanced", nullptr));
        label_23->setText(QCoreApplication::translate("configuration_dialog", "Ensure that you have made meaningful settings on the Colors tab, so that you see which message triggered the alert.", nullptr));
        label_25->setText(QCoreApplication::translate("configuration_dialog", "NOTES", nullptr));
        label_19->setText(QCoreApplication::translate("configuration_dialog", "Ensure that your rig is NOT connected via \"Default Device\".", nullptr));
        label_21->setText(QCoreApplication::translate("configuration_dialog", "Audio Alerts will be played on the default audio device (usually the loudspeaker of your PC).", nullptr));
        label_24->setText(QCoreApplication::translate("configuration_dialog", "\"Wanted callsigns, grids, prefixes and directional calls\" uses the entries from \"Highlight orange\" and \"Highlight blue\".", nullptr));
        label_20->setText(QCoreApplication::translate("configuration_dialog", "This requirement is fulfilled when your rig is connected via USB audio.", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("configuration_dialog", "Audio Alerts", nullptr));
#if QT_CONFIG(tooltip)
        cbMyCall->setToolTip(QCoreApplication::translate("configuration_dialog", "My Call in message", nullptr));
#endif // QT_CONFIG(tooltip)
        cbMyCall->setText(QCoreApplication::translate("configuration_dialog", "My Call", nullptr));
#if QT_CONFIG(tooltip)
        cbUSState->setToolTip(QCoreApplication::translate("configuration_dialog", "New US State", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUSState->setText(QCoreApplication::translate("configuration_dialog", "New US State", nullptr));
#if QT_CONFIG(tooltip)
        cbGrid->setToolTip(QCoreApplication::translate("configuration_dialog", "New Grid", nullptr));
#endif // QT_CONFIG(tooltip)
        cbGrid->setText(QCoreApplication::translate("configuration_dialog", "New Grid", nullptr));
        cbQSYmessage->setText(QCoreApplication::translate("configuration_dialog", "Message received", nullptr));
#if QT_CONFIG(tooltip)
        cbWanted->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Wanted callsigns, grids, prefixes and directional calls. This alert category uses the entries from &quot;Highlight orange&quot; and &quot;Highlight blue&quot;.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbWanted->setText(QCoreApplication::translate("configuration_dialog", "Wanted callsigns, grids, prefixes and directional calls", nullptr));
#if QT_CONFIG(tooltip)
        cbDXCCOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New DXCC on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDXCCOB->setText(QCoreApplication::translate("configuration_dialog", "New DXCC on Band", nullptr));
#if QT_CONFIG(tooltip)
        cbContinentOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New Continent on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbContinentOB->setText(QCoreApplication::translate("configuration_dialog", "New Continent on Band", nullptr));
#if QT_CONFIG(tooltip)
        cbGridOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New Grid on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbGridOB->setText(QCoreApplication::translate("configuration_dialog", "New Grid on Band", nullptr));
#if QT_CONFIG(tooltip)
        cbITUZ->setToolTip(QCoreApplication::translate("configuration_dialog", "New ITU Zone", nullptr));
#endif // QT_CONFIG(tooltip)
        cbITUZ->setText(QCoreApplication::translate("configuration_dialog", "New ITU Zone", nullptr));
#if QT_CONFIG(tooltip)
        cbCQZ->setToolTip(QCoreApplication::translate("configuration_dialog", "New CQ Zone", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCQZ->setText(QCoreApplication::translate("configuration_dialog", "New CQ Zone", nullptr));
#if QT_CONFIG(tooltip)
        cbCQ->setToolTip(QCoreApplication::translate("configuration_dialog", "CQ in message", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCQ->setText(QCoreApplication::translate("configuration_dialog", "CQ in message", nullptr));
#if QT_CONFIG(tooltip)
        cbDXCC->setToolTip(QCoreApplication::translate("configuration_dialog", "New DXCC", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDXCC->setText(QCoreApplication::translate("configuration_dialog", "New DXCC", nullptr));
#if QT_CONFIG(tooltip)
        cbDXcall->setToolTip(QCoreApplication::translate("configuration_dialog", "DX Call or DX Grid in message", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDXcall->setText(QCoreApplication::translate("configuration_dialog", "DX Call or DX Grid in message", nullptr));
#if QT_CONFIG(tooltip)
        cbContinent->setToolTip(QCoreApplication::translate("configuration_dialog", "New Continent", nullptr));
#endif // QT_CONFIG(tooltip)
        cbContinent->setText(QCoreApplication::translate("configuration_dialog", "New Continent", nullptr));
#if QT_CONFIG(tooltip)
        cbCQZOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New CQ Zone on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCQZOB->setText(QCoreApplication::translate("configuration_dialog", "New CQ Zone on Band", nullptr));
#if QT_CONFIG(tooltip)
        cbITUZOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New ITU Zone on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbITUZOB->setText(QCoreApplication::translate("configuration_dialog", "New ITU Zone on Band", nullptr));
#if QT_CONFIG(tooltip)
        cbUSStateOB->setToolTip(QCoreApplication::translate("configuration_dialog", "New US State on Band", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUSStateOB->setText(QCoreApplication::translate("configuration_dialog", "New US State on Band", nullptr));
        label_16->setText(QCoreApplication::translate("configuration_dialog", "IMPORTANT ", nullptr));
        voicesLabel->setText(QCoreApplication::translate("configuration_dialog", "Voices:", nullptr));
        voices_combo_box->setItemText(0, QCoreApplication::translate("configuration_dialog", "default", nullptr));

#if QT_CONFIG(tooltip)
        pb_test_alerts->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Test the alert sounds.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_test_alerts->setText(QCoreApplication::translate("configuration_dialog", "Test", nullptr));
        label_17->setText(QCoreApplication::translate("configuration_dialog", "Use of this feature requires that your computer is equipped with two sound cards.", nullptr));
        label_22->setText(QCoreApplication::translate("configuration_dialog", "Alert categories above the line require to have the box \"Show DXCC, grid, and worked-before status\" on the General tab checked.", nullptr));
#if QT_CONFIG(tooltip)
        pbAlerts->setToolTip(QCoreApplication::translate("configuration_dialog", "Toggle Audio Alerts on/off. Alerts will be played on \"DefaultAudioDevice\". DON'T ENABLE AUDIO ALERTS WHEN YOUR RIG IS CONNECTED VIA THIS SOUNDCARD !!!", nullptr));
#endif // QT_CONFIG(tooltip)
        pbAlerts->setText(QCoreApplication::translate("configuration_dialog", "Enable Audio Alerts", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(alerts_tab), QCoreApplication::translate("configuration_dialog", "Alerts", nullptr));
        territory_label->setText(QCoreApplication::translate("configuration_dialog", "Territories 1-4 for the Hide checkboxes in the Filters menu", nullptr));
        blacklist_label->setText(QCoreApplication::translate("configuration_dialog", "Blacklist", nullptr));
        label_18->setText(QCoreApplication::translate("configuration_dialog", "Filters for the Band Activity window", nullptr));
        cbBlacklist->setText(QCoreApplication::translate("configuration_dialog", "Hide messages containing the following callsigns or keywords:", nullptr));
        cbWhitelist->setText(QCoreApplication::translate("configuration_dialog", "Show only messages containing the following callsigns or keywords:", nullptr));
#if QT_CONFIG(tooltip)
        cb_filters_for_Wait_and_Pounce_only->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use filters for Wait and Pounce, CQ: First, etc. only (all messages are still displayed).</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_filters_for_Wait_and_Pounce_only->setText(QCoreApplication::translate("configuration_dialog", "Use filters for Wait and Pounce, CQ: First, etc. only (all messages are still displayed)", nullptr));
        cbPass->setText(QCoreApplication::translate("configuration_dialog", "Always pass messages with the following keywords:", nullptr));
        whitelist_label->setText(QCoreApplication::translate("configuration_dialog", "Whitelist", nullptr));
#if QT_CONFIG(tooltip)
        cb_filters_for_word2->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Apply filters only to the callsigns of the calling stations. Usually the second word of the messages is analyzed, for directional calls the third word.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_filters_for_word2->setText(QCoreApplication::translate("configuration_dialog", "Apply filters only to the callsigns of the calling stations", nullptr));
        always_pass_label->setText(QCoreApplication::translate("configuration_dialog", "Always Pass", nullptr));
#if QT_CONFIG(tooltip)
        cb_twoDays->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Use \342\200\234worked today and yesterday\342\200\235 instead of \342\200\234worked today\342\200\235 for the 3 related Quick Filters.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cb_twoDays->setText(QCoreApplication::translate("configuration_dialog", "Quick Filters: Hide/Ignore/Highlight \"worked today and yesterday\" instead of \"worked today\" (UTC)", nullptr));
        configuration_tabs->setTabText(configuration_tabs->indexOf(filters_tab), QCoreApplication::translate("configuration_dialog", "Filters", nullptr));
#if QT_CONFIG(tooltip)
        configuration_dialog_button_box->setToolTip(QCoreApplication::translate("configuration_dialog", "<html><head/><body><p>Discard (Cancel) or apply (OK) configuration changes including</p><p>resetting the radio interface and applying any soundcard changes</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class configuration_dialog: public Ui_configuration_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
