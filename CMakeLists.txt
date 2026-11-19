cmake_minimum_required(VERSION 3.25)

# Here is defined the current game version. Keep this call on one line (CM.9).
project(game VERSION 0.1.0 LANGUAGES CXX)

# Applies the project's strict warning set to a single target. Should be called by each target.
function(game_set_warnings target)
	target_compile_options(${target} PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive- /WX>
		$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
	)
endfunction()

# --- Dependencies ------------------------------------------------------------------------------
find_package(GTest REQUIRED)

# --- Tests -------------------------------------------------------------------------------------
include(GoogleTest)
enable_testing()

# --- Subdirectories ----------------------------------------------------------------------------
add_subdirectory(code/core)
add_subdirectory(code/tests)
