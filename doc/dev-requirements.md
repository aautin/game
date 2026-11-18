# Development requirements

## Common

- Python 3 + pipx: Python tooling, used to install Conan
- Conan 2: C++ dependency management
- A GitHub SSH key: repository access without entering credentials
- Git identity configured: user name and email (preferably the GitHub account email), commit message editor

## Windows

- Visual Studio 2026 with the "Desktop development with C++" workload: MSVC compiler (C++23), debugger, Windows SDK (includes OpenGL), plus the bundled CMake, Ninja, and Git for Windows
- "C++ Clang tools for Windows" component: clang-format, clang-tidy, and clang-cl as an alternative compiler

## Linux (Debian-based)

- build-essential: GCC toolchain
- cmake, ninja-build: build system configuration and backend
- git: version control
- gdb: debugger
- clang, clang-format, clang-tidy: alternative compiler, formatting, static analysis
- python3-venv, python3-pip
- libgl1-mesa-dev: OpenGL development files

Notes:
- Common holds only what Visual Studio 2026 does not already provide. CMake, Ninja, Git, clang-format and clang-tidy come with VS on Windows, so they are listed only under Linux.
- Keep each item to a name plus a short purpose, with no code blocks or commands.
- Use the same list formatting as the rest of the doc folder. Bold the item names if the GDD bolds them; it does (- **CMake:** ...), so match that style.