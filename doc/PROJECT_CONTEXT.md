# Project Context — Independent Isometric RPG in C++

## 1. Project Goal

I am a software engineer with solid programming fundamentals, mainly in C++, and some experience with OpenGL. I want to develop my own indie game from scratch, without relying on a full game engine such as Unity, Unreal Engine, or Godot.

The game would be inspired by Dofus or similar tactical RPGs, with features such as:

- An isometric camera and a 3D world.
- A grid-based movement system.
- Characters, enemies, and NPCs.
- Turn-based combat.
- Resource gathering.
- Inventory, equipment, progression, and potentially quests.
- Potential multiplayer functionalities in the future.
- Eventual Windows distribution, potentially through Steam.

I am still exploring the game concept and do not have a definitive name yet.

My ambition is to build my first game as an independent developer. I want to build a small, complete and playable game.

I am interested in understanding the underlying technology and building my own minimal engine. However, I do not want to spend months developing an engine without producing a playable game.

## 2. My Technical Background

- Software engineer with good programming fundamentals.
- Comfortable with C++ and object-oriented programming (OOP).
- Experience with CMake, Conan and development tooling.
- Some OpenGL experience.
- No professional game-development experience.
- Interested in learning game architecture, rendering, game design, networking, and ECS.

I am setting up a development environment on Ubuntu, with Windows as an eventual primary target for the game.

I prefer understanding how things work rather than blindly copying code or adopting unnecessarily complex frameworks. I will try to scope the game development as small as possible to not go into an overwhelming project complexity.

## 3. Proposed Technical Stack

### Core technologies

- **C++20 or C++23:** Main programming language.
- **CMake:** Build system.
- **Conan:** C++ dependency management.
- **Git and GitHub:** Version control and project management.
- **SDL3:** Window creation, keyboard and mouse input, audio, platform abstraction and OpenGL context creation.
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

These libraries should be added when they solve actual problems. I do not need to install every dependency at the beginning.

## 4. Game Perspective: (perspective) 3D

The current recommendation is to use a real 3D world.

Reasons:

- The vertical axis of the 2D grid can be utilised (for flying, building upwards, etc.).
- I want genuine 3D rotation and animations.
- The camera might be able to move around the grid to enhance the cinematics and allow players to choose their own viewpoint.

A click-to-move workflow could be:

1. SDL receives the mouse position.
2. Convert the screen position into a camera ray.
3. Intersect the ray with the game world or grid.
4. Determine the corresponding grid cell.
5. Run pathfinding.
6. Convert the path into world-space positions.
7. Animate the character along the path.

The grid is a gameplay system, not a feature that must be implemented by OpenGL.

## 5. ECS and OOP Architecture

I have always used object-oriented programming and am considering Entity Component System (ECS) architecture for the game.

The current conclusion is that **ECS and OOP can coexist in the same project**.

### ECS: game-world entities

ECS is a candidate for representing:

- Players.
- Enemies and NPCs.
- Collectible resources.
- Projectiles.
- Objects on the ground.
- Other entities composed of different capabilities.

Potential components:

- `GridPosition`
- `Health`
- `AttackPower`
- `Movement`Power
- `Inventory`
- `Renderable`
- `PlayerControlled`
- `Collectible`
- Other components the entities could have.

Systems can operate on entities that have the relevant components:

- Movement system.
- Combat system.
- Resource-gathering system.
- Rendering system.
- AI system.

### OOP: services and cohesive objects

Traditional classes remain useful for:

- `Renderer`
- `AssetManager`
- `AudioManager`
- `InputManager`
- `SaveManager`
- `GameServer`
- Other services or objects with well-defined responsibilities.

Game rules can also use ordinary classes where they have well-define responsabilities. For example, a `CombatRules` class could encapsulate damage calculations while an ECS system coordinates combat between entities.

## 7. ECS library choice : EnTT

- C++-oriented.
- Lightweight and suitable for integration into a custom engine.
- Entity registry and component storage.
- Views for querying entities.
- Additional facilities such as event dispatching.

Flecs is a credible alternative, especially if more advanced relationships, prefabs, reflection, and querying features become important.

Do not force every part of the program into ECS, only where it is beneficial.

## 7. Development Workflow

The recommended approach is iterative development, with the game itself guiding the evolution of the engine.

### Step 1: Game design document

Create a short one-pager explaining:

- What the game is.
- The core player fantasy.
- The design pillars.

### Step 2: Prototypes

A prototype is a way to test a system. Build the smallest playable version of a system that tests whether it's interesting and worthy or not. Document it through a dedicated prototype document.

Possible prototypes:

- 2d rendered grid.
- Characters pathfinding.
- Picking algorithm, turning a mouse click into an entity selection (ray-casting vs color-picking).
- Click-to-move.
- An AI ennemy.
- A basic attack system.

No detailed models, animations, textures, elaborate UI or optimizations are required.

### Step 3: Complete a gameplay loop

Aim for a complete sequence integrating all the prototypes together. The sequence can be improved and prototypes can be created and added as much as wanted.

## 8. GitHub Repository

Should use GitHub from day one. Recommended to start with **one repository under my personal GitHub account**, rather than create an organization immediately.

I have not chosen the game name. A neutral repository name such as `game-project` is appropriate. It can be renamed later.

A possible repository structure:

```text
game-project/
├── README.md
│
├── CMakeLists.txt
├── CMakePresets.json
│
├── conanfile.py
│
├── .gitignore
├── docs/
│   ├── game-design-document.md
│   └── prototypes/
├── src/
│   ├── core/
│   │   ├── engine/
│   │   └── game/
│   ├── main/
│   └── tests/
│
├── assets/
└── .github/
    └── workflows/
```

The exact structure should evolve with the project.
A GitHub organization becomes more useful if:

- Multiple developers collaborate.
- The game, launcher, server, and tools become separate repositories.
- The project develops an identity independent of my personal account.
- Multiple games are developed under the same studio identity.

For now, a single personal repository is sufficient.

## 10. Multiplayer and Steam

Multiplayer is a possible future feature, not part of the initial project, and still haven't choose between a server or a client-authoritative model.

Steamworks can provide services and APIs for:
- Achievements and stats.
- Steam Cloud.
- Overlay integration.
- Lobbies and matchmaking.
- Networking APIs and relay-assisted connectivity.

Steam does not automatically implement my game's rules or eliminate the need to design a protocol and server architecture. Hosting and operating dedicated game servers remains a separate consideration. I am not obliged to use Steam matchmaking or Steam networking. I could implement my own backend or use Steam for selected services.

Networking should be deferred until the single-player gameplay loop is established.

## 11. Learning and References

I have been considering resources for learning game design.

Books discussed:

- *The Art of Game Design: A Book of Lenses* by Jesse Schell — recommended starting point.
- *Game Design Workshop* by Tracy Fullerton — practical, iterative design and playtesting.
- *Rules of Play: Game Design Fundamentals* by Katie Salen and Eric Zimmerman — more theoretical and academic.

Open-source games and projects mentioned as references:

- **OpenRA:** Useful for studying game architecture and an open-source RTS.
- **Veloren:** A 3D multiplayer RPG, relevant to world, entity, and networking architecture.
- **Mindustry:** Useful for studying gameplay systems and project organization.

These projects should be studied to answer specific architectural questions, not copied wholesale.

## 12. Important Principles for Future Advice

When helping me with this project:

- Assume I know general programming concepts but am learning game development and design.
- Explain the reasons behind architectural choices.
- Prefer concrete examples in modern C++.
- Keep the solution appropriate for a solo developer.
- Avoid unnecessary frameworks and premature abstraction.
- Help me balance engine development with actual gameplay progress.
- Allow ECS and OOP to coexist.
- Prefer incremental milestones and playable prototypes.
- Distinguish essential requirements from optional future improvements.
- Avoid assuming multiplayer, a final game name, or a fully defined concept.
- Do not assume every library listed here must be used; the stack is a starting point, not a fixed requirement.

## Current State

The game concept is still being explored. The next step is to continue refining the one-pager GDD.
