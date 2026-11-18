# Technical design

## Technical choices

- Implementation of a custom game engine.
- ECS architecture preferred to OOP, whenever its possible.

## Core technologies

- **C++23:** Main programming language.
- **CMake:** Build system.
- **Conan:** C++ dependency management.
- **Git and GitHub:** Version control and project management.
- **SDL3:** Window creation, keyboard and mouse input, audio, platform abstraction, OpenGL context.
- **OpenGL:** Graphics rendering.
- **GLAD:** OpenGL function loading.
- **GLM:** Vectors, matrices, transformations, and other graphics mathematics.
- **EnTT:** ECS library; current first choice.
- **stb_image:** Image loading.
- **Assimp:** Importing 3D models and associated data.
- **Dear ImGui:** Create a GUI (buttons and text fields) devs use while debugging the game.
- **spdlog:** Logging.
- **nlohmann/json:** JSON parsing and serialization.
- **SDL_ttf or FreeType:** Font rendering.
- **GoogleTest:** Unit testing.
- **Asio:** Network library for custom TCP/UDP server and client architecture, for online support.

These libraries should be added when they solve actual problems. No need to install every dependency at the beginning.
