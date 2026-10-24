# Project Memory & Remote Build Guidelines

## Remote Build Node: raspi5-attic
- **SSH Target**: `raspi5-attic`
- **Remote Directory**: `/home/christian/Downloads/ws-3.2.1/src/ws/build`
- **Remote Source Repository**: `/home/christian/Downloads/ws-3.2.1/src/ws` (tracked on git branch `master`)

## Development & Deployment Workflow
1. **Local Changes**:
   - Implement changes in local workspace (`/home/christian/temp/wsjtx/build/ws`).
   - Configure/build locally using:
     ```bash
     cmake -B build -DWSJT_GENERATE_DOCS=OFF -DWSJT_SKIP_MANPAGES=ON
     cmake --build build --target wsjtx jt9 -j$(nproc)
     ctest --test-dir build -R "rtty|psk" --output-on-failure
     ```
2. **Git Commit & Push**:
   - Inspect changes (`git status`, `git diff`).
   - Commit with concise, descriptive message matching repository style.
   - Push to GitHub origin (`git push origin master`).
3. **Remote Node Sync & Build**:
   - Both local and `raspi5-attic` share the GitHub origin.
   - After pushing locally, run:
     ```bash
     ssh raspi5-attic "cd /home/christian/Downloads/ws-3.2.1/src/ws/build && git pull && cmake --build . --target wsjtx jt9 -j4 && ctest -R \"rtty|psk\" --output-on-failure"
     ```
