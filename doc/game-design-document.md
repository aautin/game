# Game design document one-pager

A 3D gardening puzzle game played on a 2D grid. The player plants seeds from several plant species without knowing what each one needs.
By watching how plants react, failing, and trying again, the player gradually works out each species' needs and how the garden should be arranged.
The final goal is to grow every species of plant to full maturity.

## Game Identity / Mantra:

**Grow, fail, understand.**

Every plant is a small mystery. Losing a plant is not a failure but a lesson: each attempt reveals a bit more about what a species needs.

## Design Pillars:

- **Discovery by observation:** Plant needs are never shown directly. The player infers them from visual cues.
- **Spatial puzzle:** Tall plants cast shade on their neighbors, crowded plants compete for space, and some tiles get more sun than others. Arranging the garden is part of the challenge.
- **Collection & mastery:** A journal fills in as the player learns about each species. Long-term progression is a central part of the game.

## Interface:

- **Isometric view** of the garden grid, so plant height, shade, and sunlight are easy to read.
- **Mouse-driven:** click a tile to plant a seed, water, dig up, or inspect a plant.
- **Toolbar** with the available tools and the seed inventory.
- **Journal panel** that records the player's discoveries per species; unknown needs stay marked as `???` until learned.
- **Time controls:** time passes in real time with pause / 1x / 2x / 3x speed controls.

## Art Style:

- Animated **low-poly 3D** models, placed according to the 2D grid logic.
- Real-time lighting and shadows from the engine show sunlight and shade directly, supporting the spatial puzzle.
- Plant health is shown through model changes, color shifts, and simple animations.
- Soft, natural color palette to keep a calm atmosphere.

## Music/Sound:

- **Nature soundscape:** wind, rain, birds, rustling leaves, varying with time of day and weather.
- **Sparse piano** only at key moments: discovering a new species, learning a need, a plant reaching full growth, a player action, or a UI click.

## Out of Scope:

Here are a few examples of features that are deliberately excluded:

- **Economy:** no money and no buying of seeds.
- **Multiplayer:** the game is single-player only.
- **Crafting:** plants cannot be turned into items or products.
- **Decoration:** no cosmetic garden items (paths, fences, ornaments, etc.).
- **Sun movement:** the light source stays in one fixed position; it neither moves on its own nor can be controlled by the player.
- **Controller support:** mouse and keyboard only.
- **Localization:** English only.
