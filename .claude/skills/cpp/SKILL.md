---
name: cpp
description: >
  Generic C++ coding conventions and modern C++ best practices.
  Use this skill for C++ source files, headers, templates, APIs, classes, CMake, code generation,
  review, and architecture.
---

# C++ coding standard

Apply these conventions to modern C++ code. Every rule is listed in this file under its category
with an index, title, and description.

## Naming and layout

1. **NL.1 — Prefix class names with `C`.** Name classes with a leading `C` to distinguish them
   from other types.
2. **NL.2 — Prefix interface names with `I`.** Use `I` for pure abstract interfaces without
   instance state.
3. **NL.3 — Prefix plain data structures with `S`.** Use `S` for passive aggregate data types.
4. **NL.4 — Prefix enumerations with `E`.** Use `E` and prefer `enum class` for scoped values.
5. **NL.5 — Use verb-led camelCase functions.** Name functions in camelCase and start names with
   an action verb.
6. **NL.6 — Prefix pointer variables with `p`.** Apply the prefix to raw and smart pointer
   variables.
7. **NL.7 — Do not prefix references.** Name references after the value they refer to.
8. **NL.8 — Prefix non-static members with `m_`.** Make object state recognizable in class code.
9. **NL.9 — Prefix static class members with `s_`.** Distinguish static class state from instance
   state (`m_`), for example `s_loadedCount`.
10. **NL.10 — Prefix file-scope and namespace-scope variables and constants with `g`.** This
    covers anonymous-namespace variables in `.cpp` files and constants declared at namespace
    scope in headers, for example `gMaxTextureSize`.
11. **NL.11 — Use plural container names.** Name a container after its contents rather than its
    implementation type.
12. **NL.12 — Name files after classes without prefixes.** Use camelCase filenames based on the
    class name without its naming prefix (`CRenderer` in `renderer.h` and `renderer.cpp`).
    - A file with no class is named after its concept, in camelCase (`version.h` for
      `getVersion()`).
    - A test file is named `<testedFile>Tests.cpp` and lives in `code/tests/<module>/`,
      mirroring the tested code (`code/tests/core/versionTests.cpp` tests `code/core/version.h`).
    - A file holds one main class. Small helper types used only by that class may share its
      file.
13. **NL.13 — Use tabs and Allman braces.** Indent with tabs and put opening braces on their own
    line.
14. **NL.14 — Let clang-format align code.** Do not hand-maintain column alignment.
15. **NL.15 — Limit lines to 100 columns.** No line of code or comment goes past column 100,
    counting a tab as 4 columns. Break longer statements and comments over several lines; the
    clang-format configuration uses the same limit (`ColumnLimit: 100`, `TabWidth: 4`).

## Source files

1. **SF.1 — Separate declarations and definitions.** Use `.h` for declarations, `.hpp` for
   template definitions, and `.cpp` for implementations.
2. **SF.2 — Start files with the license header only.** Every `.h`, `.hpp`, and `.cpp` file
   begins with the two lines below, followed by an empty line. Do not add a file documentation
   block (`\file`, file name, or file description): the path already names the file, and the
   declarations carry their own documentation (DOC.1).

   ```cpp
   // Copyright (c) 2026 Autin Alexandre
   // SPDX-License-Identifier: MIT
   ```
3. **SF.3 — Use `#pragma once`.** Add it to new headers instead of handwritten include guards.
4. **SF.4 — Group includes from general to specific, under a comment.** Use up to four groups,
   in this order, separated by an empty line and each introduced by its comment. Omit a group
   when it is empty.
   1. `// STL headers`: the C++ standard library.
   2. `// External headers`: third-party dependencies (GoogleTest, SDL3, GLM...).
   3. `// Project headers`: other modules of the project.
   4. `// <Module> headers`: the module the file belongs to, its own header included, named
      after the module (`// Core headers` for files in `code/core/`).

   ```cpp
   // STL headers
   #include <memory>
   #include <string_view>

   // External headers
   #include <glm/vec3.hpp>

   // Project headers
   #include <core/version.h>

   // Render headers
   #include <render/renderer.h>
   ```
5. **SF.5 — Always use angle brackets.** Include every header with `<>`, project headers
   included, written from the `code/` include root (`#include <core/version.h>`). Never use
   `""`: it searches the including file's folder first and can pick a same-named file there.
   The SF.4 group comments already show where each header comes from.
6. **SF.6 — Include what you use.** Do not rely on transitive includes.
7. **SF.7 — Use structured namespaces.** Organize symbols under namespaces such as `app::module`.
8. **SF.8 — Do not write `using namespace` in headers.** Prevent namespace pollution for consumers.
9. **SF.9 — Keep internal helpers in an anonymous namespace.** Do not use private static functions
   or data members for file-local implementation details.
10. **SF.10 — Prefer forward declarations for references.** Include a full definition only when
    the type is required.
11. **SF.11 — Keep namespace aliases local.** Declare aliases in `.cpp` files unless a public API
    requires otherwise.

## Classes

1. **C.1 — Declare members in canonical sections.** Group members by access level, always in the
   order public, protected, private. Inside each access level, use these sections, always in
   this order:
   1. `definitions`: nested types, enumerations, and type aliases.
   2. `constructors/destructors`: constructors, destructor, and copy and move operations.
   3. `parameters`: getters and setters (`get...`, `set...`).
   4. `operations`: every other member function.
   5. `data`: data members, static ones included.

   A section is named after its access level and kind, for example `Public operations` or
   `Private data`. Omit a section when it is empty. Each section repeats its access specifier,
   so moving a section never changes the access of its members.
2. **C.2 — Introduce each section with a separator banner.** The banner is three lines, 90
   characters wide: a `//---...---//` line, the section name line `//- <Section name>` padded
   with spaces to the closing `//`, and a second `//---...---//` line. The access specifier
   comes first, then the banner at the indentation of the members, which is where clang-format
   keeps it. Documentation blocks
   (DOC.1) are omitted below to keep the example short; real code keeps them.

   ```cpp
   namespace game::render
   {
   	class CTexture
   	{
   	public:
   		//--------------------------------------------------------------------------------------//
   		//- Public definitions                                                                  //
   		//--------------------------------------------------------------------------------------//
   		enum class EFilter
   		{
   			Nearest,
   			Linear
   		};

   	public:
   		//--------------------------------------------------------------------------------------//
   		//- Public constructors/destructors                                                     //
   		//--------------------------------------------------------------------------------------//
   		explicit CTexture(const std::filesystem::path& path);
   		~CTexture();

   		CTexture(const CTexture&) = delete;
   		CTexture& operator=(const CTexture&) = delete;
   		CTexture(CTexture&& other) noexcept;
   		CTexture& operator=(CTexture&& other) noexcept;

   	public:
   		//--------------------------------------------------------------------------------------//
   		//- Public parameters                                                                   //
   		//--------------------------------------------------------------------------------------//
   		[[nodiscard]] std::uint32_t getWidth() const;
   		[[nodiscard]] std::uint32_t getHeight() const;
   		[[nodiscard]] EFilter getFilter() const;
   		void setFilter(EFilter filter);

   		[[nodiscard]] static std::uint32_t getLoadedCount();

   	public:
   		//--------------------------------------------------------------------------------------//
   		//- Public operations                                                                   //
   		//--------------------------------------------------------------------------------------//
   		void bind(std::uint32_t unit) const;

   	public:
   		//--------------------------------------------------------------------------------------//
   		//- Public data                                                                         //
   		//--------------------------------------------------------------------------------------//
   		static constexpr std::uint32_t s_maxSize = 16384;

   	private:
   		//--------------------------------------------------------------------------------------//
   		//- Private definitions                                                                 //
   		//--------------------------------------------------------------------------------------//
   		enum class EState
   		{
   			Unloaded,
   			Loaded
   		};

   	private:
   		//--------------------------------------------------------------------------------------//
   		//- Private operations                                                                  //
   		//--------------------------------------------------------------------------------------//
   		void upload(const std::filesystem::path& path);

   	private:
   		//--------------------------------------------------------------------------------------//
   		//- Private data                                                                        //
   		//--------------------------------------------------------------------------------------//
   		std::uint32_t m_handle = 0;
   		std::uint32_t m_width = 0;
   		std::uint32_t m_height = 0;
   		EFilter m_filter = EFilter::Linear;
   		EState m_state = EState::Unloaded;

   		inline static std::uint32_t s_loadedCount = 0;
   	};
   }
   ```

   This class has no protected members and no private constructors or parameters, so those
   sections are omitted. A protected section uses the same names (`Protected definitions`...)
   and sits between the public and private ones.
3. **C.3 — Define methods in declaration order, under the same banners.** Keep `.cpp`
   definitions in the same order as the header declarations, and repeat the header's C.2
   banners in the `.cpp`, with the same names and in the same order, at the indentation of the
   definitions. A `.cpp` has no access specifiers, so the banner alone separates the sections.
   Omit a section that has nothing to define (definitions, data, `= default` members declared
   in the header).

   ```cpp
   // Copyright (c) 2026 Autin Alexandre
   // SPDX-License-Identifier: MIT

   // STL headers
   #include <cstdint>
   #include <filesystem>

   // External headers
   #include <glad/gl.h>

   // Render headers
   #include <render/texture.h>

   namespace game::render
   {
   	//--------------------------------------------------------------------------------------//
   	//- Public constructors/destructors                                                     //
   	//--------------------------------------------------------------------------------------//
   	CTexture::CTexture(const std::filesystem::path& path)
   	{
   		upload(path);
   	}

   	//--------------------------------------------------------------------------------------//
   	//- Public parameters                                                                   //
   	//--------------------------------------------------------------------------------------//
   	std::uint32_t CTexture::getWidth() const
   	{
   		return m_width;
   	}

   	void CTexture::setFilter(EFilter filter)
   	{
   		m_filter = filter;
   	}

   	//--------------------------------------------------------------------------------------//
   	//- Public operations                                                                   //
   	//--------------------------------------------------------------------------------------//
   	void CTexture::bind(std::uint32_t unit) const
   	{
   		glBindTextureUnit(unit, m_handle);
   	}

   	//--------------------------------------------------------------------------------------//
   	//- Private operations                                                                  //
   	//--------------------------------------------------------------------------------------//
   	void CTexture::upload(const std::filesystem::path& path)
   	{
   		m_handle = createGlTexture(path, m_width, m_height);
   		m_state = EState::Loaded;
   		++s_loadedCount;
   	}
   }
   ```

   This excerpt of `texture.cpp` skips the other definitions of `CTexture` (destructor, moves,
   remaining getters) to stay short; a real file defines all of them, in the same order.
4. **C.4 — Prefer the Rule of Zero.** Let standard members manage resources whenever possible.
5. **C.5 — Declare all special members together.** If one of the five special members is needed,
   make the intended behavior of all five explicit.
6. **C.6 — Use `= default`.** Prefer defaulted special members to empty function bodies.
7. **C.7 — Default derived destructors correctly.** Use `~Derived() override = default` when the
   derived destructor needs no custom behavior.
8. **C.8 — Initialize trivial members at declaration.** Give simple members safe defaults where
   they are declared.
9. **C.9 — Initialize dependent members in initializer lists.** Keep construction order explicit
   and avoid assignment in constructor bodies.
10. **C.10 — Use `final` selectively.** Mark leaf classes final when preventing extension benefits
    correctness or a demonstrated hot path.
11. **C.11 — Make single-argument constructors explicit.** Prevent unintended implicit conversions.
12. **C.12 — Prefer the non-virtual interface pattern.** Keep public behavior stable while
    delegating customization to protected virtual functions.
13. **C.13 — Pass polymorphic objects by reference or pointer.** Never slice polymorphic values.
14. **C.14 — Use `= delete` to forbid operations.** Express unsupported copying or conversions in
    the type interface.
15. **C.15 — Return owning clone pointers safely.** A polymorphic `clone()` should return
    `std::unique_ptr<Base>`.

## Functions

1. **F.1 — Omit `void` in parameter lists.** Use `f()` for a function with no parameters.
2. **F.2 — Use traditional return syntax.** Prefer `type function()` over trailing return syntax
   unless a dependent type requires it.
3. **F.3 — Mark read-only members `const`.** A member function that does not change observable
   object state should be callable on const objects.
4. **F.4 — Use one virtual-specifier role.** Mark a declaration with exactly one of `virtual`,
   `override`, or `final` where applicable.
5. **F.5 — Match parameter passing to use.** Pass small values by value, read-only objects by
   reference, and ownership transfers explicitly.
6. **F.6 — Use `std::string_view` for read-only strings.** Avoid unnecessary allocation and copies.
7. **F.7 — Return named result types.** Use a named struct instead of an unnamed pair or tuple when
   multiple results have meaning.
8. **F.8 — Use `[[nodiscard]]` selectively.** Apply it when ignoring a result is clearly a bug.
9. **F.9 — Keep lambdas short.** Extract multi-step lambda logic into a named function.
10. **F.10 — Capture lambda state explicitly.** Avoid broad default captures that hide dependencies.

## Resources and ownership

1. **R.1 — Give every resource one owner.** Represent ownership with an object whose lifetime is
   clear.
2. **R.2 — Do not write `new` or `delete` directly.** Construct resources through RAII helpers.
3. **R.3 — Prefer `std::unique_ptr`.** Use `std::shared_ptr` only when ownership is genuinely
   shared.
4. **R.4 — Treat raw pointers and references as borrowed.** They do not transfer ownership.
5. **R.5 — Move into sink parameters.** Use `std::move` when a function takes ownership.
6. **R.6 — Wrap non-RAII resources.** Create a small RAII type around handles, locks, or other
   resources with manual release requirements.

## Expressions and statements

1. **ES.1 — Use `nullptr`.** Never use `0` or `NULL` as a null pointer value.
2. **ES.2 — Use `auto` when helpful.** Use it when the type is already stated or difficult to
   spell, but keep important type information readable.
3. **ES.3 — Use range-based `for`.** Prefer it for iteration over ranges.
4. **ES.4 — Use structured bindings.** Unpack aggregates when the individual names improve clarity.
5. **ES.5 — Scope temporary variables to conditions.** Use `if` and `switch` initializers when
   the value is needed only for the test and its body.
6. **ES.6 — Use `std::variant` for closed alternatives.** Model a fixed set of possible types
   without unsafe unions or type tags.
7. **ES.7 — Compose range views.** Avoid temporary containers when a lazy view expresses the
   operation clearly.
8. **ES.8 — Compute constants at compile time.** Use `constexpr` or `consteval` where evaluation
   can be guaranteed before runtime.
9. **ES.9 — Reserve known container capacity.** Call `reserve` when the final size is known.

## Error handling

1. **E.1 — Throw for unexpected failure.** Throw when an operation that should succeed cannot.
2. **E.2 — Use `std::optional` for legitimate absence.** Do not use it to hide errors.
3. **E.3 — Catch at boundaries.** Translate or report exceptions at an API, thread, or process
   boundary rather than at every call site.
4. **E.4 — Rely on RAII for exception safety.** Keep cleanup automatic on every exceptional path.
5. **E.5 — Document exceptions.** State the conditions under which a public function throws.

## Templates

1. **T.1 — Put template definitions in `.hpp`.** Keep definitions available to all instantiations.
2. **T.2 — Separate template declarations clearly.** Put a template declaration on its own line
   before the associated declaration.
3. **T.3 — Use `typename` for type parameters.** Reserve `class` for class declarations.
4. **T.4 — Constrain every template.** Use concepts, requires-clauses, or another clear constraint.
5. **T.5 — Forward and move correctly.** Use `std::forward` for forwarding references and
   `std::move` for intentional moves.
6. **T.6 — Specialize only when necessary.** Keep the generic form when it can express the needed
   behavior clearly and efficiently.

## Architecture and portability

1. **A.1 — Keep headers next to their implementation.** Each module folder under `code/` holds
   its `.h` and `.cpp` files side by side. The include root is `code/`, so headers are included
   as `<module/file.h>`. The public API is what the headers declare; implementation details stay
   in the `.cpp` files (SF.9).
2. **A.2 — Use fixed-width integers for stored data.** Choose types such as `std::uint32_t` when
   representation width matters.
3. **A.3 — Use `std::size_t` for sizes.** Use it for counts, indices, and object sizes.
4. **A.4 — Serialize explicitly.** Never copy a C++ object representation directly to or from a
   wire or persistent buffer.
5. **A.5 — Use `std::filesystem::path`.** Do not manipulate filesystem paths as ad-hoc strings.
6. **A.6 — Assert platform assumptions.** Use `static_assert` for compile-time representation and
   platform requirements.
7. **A.7 — Isolate platform-specific code.** Keep operating-system and hardware details behind a
   narrow interface.
8. **A.8 — Test public behavior.** Write tests against the public API using the same conventions
   as production code.

## Documentation

Two kinds of comments exist: documentation blocks on declarations (DOC.1 to DOC.4) and plain
comments inside function bodies (DOC.5 to DOC.6).

1. **DOC.1 — Use `/*!` Doxygen blocks for declarations.** Document types, functions, and members
   in headers with a `/*!` block placed directly above the declaration, one ` * ` per line.
   Write commands with a backslash: `\brief`, `\param`, `\return`, `\throw`.
2. **DOC.2 — Give public entities a `\brief`.** State the purpose of every public type, function,
   and member in one sentence.
3. **DOC.3 — Document parameters, returns, and throws.** Use the standard Doxygen forms and omit
   a command when it does not apply:
   - `\param[in|out|in,out] <name> <description>`: one per parameter, in declaration order. The
     direction goes in brackets; the description says what the value is (ownership, valid range).
   - `\return <description>`: for non-`void` functions, what the result means.
   - `\throw <exception type> <description>`: one per exception type, with the condition that
     raises it.

   Layout: `\brief` first, then one group per command kind (`\param`, `\return`, `\throw`),
   separated by an empty ` *` line. Every block in the project uses the same fixed columns,
   counted from the character after ` * ` and padded with spaces (tabs render differently
   between editors):
   - Command: 16 characters wide (fits `\param[in,out]`).
   - Name: 24 characters wide (parameter name or exception type). Commands without a name
     (`\brief`, `\return`) start their text in this column.
   - Description: starts at character 40. Continuation lines start at the same column.
   - A name longer than 23 characters is followed by a single space.

   This hand alignment is the only exception to NL.14: clang-format does not align inside
   comments.

   ```cpp
   /*!
    * \brief          Load a texture from an image file.
    *
    * \param[in]      path                    Image file path, relative to the assets folder.
    * \param[in]      generateMipmaps         Whether to build the mipmap chain after loading.
    *
    * \return         The loaded texture, owned by the caller.
    *
    * \throw          std::runtime_error      If the file is missing or is not a supported
    *                                         image format.
    * \throw          std::bad_alloc          If the texture memory cannot be allocated.
    */
   [[nodiscard]] std::unique_ptr<CTexture> loadTexture(
   	const std::filesystem::path& path, bool generateMipmaps);
   ```
4. **DOC.4 — Do not restate signatures.** Add information that the declaration itself cannot
   convey.
5. **DOC.5 — Use framed `//` comments inside function bodies.** Put the comment on its own lines
   above the code it explains, as full sentences, with an empty `//` line above and below it.
   Never use `/* */` in a body: it cannot be nested, which breaks commenting out a block that
   already contains one.
6. **DOC.6 — Comment only the why, never the what.** A body comment exists only to record a
   reason the code cannot show: a constraint, an ordering requirement, a workaround, a rejected
   alternative. Do not describe what the code does; when the what is unclear, rename or extract
   a function instead. Code without a reason to explain has no comment.

   ```cpp
   void CRenderer::drawFrame()
   {
   	//
   	// Sort by material first: switching shaders costs more than overdraw.
   	//
   	sortDrawCalls(m_drawCalls);
   	submitDrawCalls(m_drawCalls);

   	//
   	// ImGui must render before the swap, otherwise the debug UI lags one frame behind.
   	//
   	m_pImGui->render();
   	m_pWindow->swapBuffers();
   }
   ```

## CMake

1. **CM.1 — Declare project requirements.** Set the minimum CMake version, project version, and
   enabled languages.
2. **CM.2 — Set the C++ standard on targets.** Do not change the standard globally.
3. **CM.3 — Scope include directories.** Use `PUBLIC`, `PRIVATE`, and generator expressions to
   describe build and install interfaces.
4. **CM.4 — Avoid directory-scoped commands.** Configure targets rather than every target in a
   directory.
5. **CM.5 — Enable strict warnings per target.** Keep compiler diagnostics explicit and scoped.
6. **CM.6 — Register tests with CTest.** Make tests runnable through the standard build workflow.
7. **CM.7 — Give libraries a `game::` alias.** CMake forbids `::` in real target names, so name
   the target plainly and add an alias. Link libraries through the alias: a typo in a `::` name
   fails at configure time, while a plain name is silently treated as a system library.
   Executables get no alias: nothing links to them. Commands that require a real target, such as
   `gtest_discover_tests`, use the plain name.

   ```cmake
   add_library(core)
   add_library(game::core ALIAS core)

   target_link_libraries(tests PRIVATE game::core)
   ```
8. **CM.8 — Find every dependency in the root `CMakeLists.txt`.** Call `find_package` for each
   Conan dependency in the root file, before `add_subdirectory`, so the list mirrors
   `conanfile.py`. The imported targets are visible in every subdirectory.
9. **CM.9 — Define the version only in `project()`, on one line.** The root
   `project(game VERSION MAJOR.MINOR.PATCH LANGUAGES CXX)` is the single source of the version:
   numbers only, never repeated elsewhere. Keep the call on one line, because the CD workflow
   reads the version from it with a regex. C++ code receives it through
   `target_compile_definitions` from `PROJECT_VERSION`.
