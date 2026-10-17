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
9. **NL.9 — Prefix static class members with `g_`.** Distinguish static class state from instance
   state.
10. **NL.10 — Prefix file-scope statics and constants with `g`.** Use the same convention for
    internal file-level names.
11. **NL.11 — Use plural container names.** Name a container after its contents rather than its
    implementation type.
12. **NL.12 — Name files after classes without prefixes.** Use camelCase filenames based on the
    class name without its naming prefix.
13. **NL.13 — Use tabs and Allman braces.** Indent with tabs and put opening braces on their own
    line.
14. **NL.14 — Let clang-format align code.** Do not hand-maintain column alignment.

## Source files

1. **SF.1 — Separate declarations and definitions.** Use `.h` for declarations, `.hpp` for
   template definitions, and `.cpp` for implementations.
2. **SF.2 — Start files with the project documentation block.** Keep file-level ownership and
   purpose information consistent.
3. **SF.3 — Use `#pragma once`.** Add it to new headers instead of handwritten include guards.
4. **SF.4 — Order includes from general to specific.** Put standard headers before external and
   project headers.
5. **SF.5 — Use appropriate include syntax.** Use angle brackets for headers and quoted includes
   for local implementation files when the project layout requires it.
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

1. **C.1 — Declare members in canonical order.** Keep types, constructors, public API, protected
   API, and private state in a consistent order.
2. **C.2 — Mark class sections clearly.** Introduce sections with a consistent separator comment.
3. **C.3 — Define methods in declaration order.** Keep `.cpp` definitions in the same order as the
   header declarations.
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

1. **A.1 — Separate public API from implementation.** Reflect the boundary in the directory
   layout and target configuration.
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

1. **DOC.1 — Use `/*!` documentation blocks.** Keep public documentation compatible with the
   project’s documentation tooling.
2. **DOC.2 — Give public entities a `\brief`.** State the purpose of every public type, function,
   and member.
3. **DOC.3 — Document parameters, returns, and throws.** Explain direction, ownership, result
   meaning, and exceptional conditions.
4. **DOC.4 — Do not restate signatures.** Add information that the declaration itself cannot
   convey.
5. **DOC.5 — Comment why, not what.** Record constraints and rationale rather than narrating
   obvious statements.

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
