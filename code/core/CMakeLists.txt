add_library(core)
add_library(game::core ALIAS core)

target_sources(core PRIVATE
	version.h
	version.cpp
)
target_include_directories(core PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/code>
)
target_compile_definitions(core PRIVATE
	"GAME_VERSION=\"${PROJECT_VERSION}\""
)
target_compile_features(core PUBLIC
	cxx_std_23
)

game_set_warnings(core)
