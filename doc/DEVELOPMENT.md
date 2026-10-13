# Development environment setup

## Linux : debian-based

### 1. System dependencies

| Dependencies | Purpose |
|---|---|
| `build-essential`, `cmake`, `ninja-build` | Compilation and project configuration |
| `git`, `gdb` | Version control and debugging |
| `clang`, `clang-format`, `clang-tidy` | Alternative compiler, code formatting, and static analysis |
| `python3`, `python3-venv`, `python3-pip`, `pipx` | Python environment and Conan installation |
| `libgl1-mesa-dev` | OpenGL development files required for linking |

```sh
sudo apt install -y \
                    build-essential \
                    cmake \
                    ninja-build \
                    \
                    git \
                    gdb \
                    \
                    clang \
                    clang-format \
                    clang-tidy \
                    \
                    python3 \
                    python3-venv \
                    python3-pip \
                    pipx \
                    \
                    libgl1-mesa-dev \
```

### 2. Pipx

Make pipx-installed packages accessible by PATH environment variable.
```sh
pipx ensurepath
pipx install conan
source ~/.bashrc
```

### 3. SSH key generation

SSH authentication allows you to interact with GitHub repositories without entering your credentials for every operation.
```sh
ssh-keygen
```

Then copy the public key to the Github list of SSH keys.

### 4. Git configuration

1. Configure your Git name and email so commits have the correct author information.

- Name: Your preferred name or GitHub username.
- Email: Prefer an email associated with your GitHub account.

```sh
git config --global user.name "<name>"
git config --global user.email "<email>"
```

2. Configure Git for commit messages editor.

| Editor | Value |
|---|---|
| VS Code | code --wait |
| Vim | vim |
```sh
git config --global core.editor "<value>"
```
