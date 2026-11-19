add_executable(tests)

target_sources(tests PRIVATE
	core/versionTests.cpp
)
target_link_libraries(tests PRIVATE
	game::core
	GTest::gtest_main
)
target_compile_definitions(tests PRIVATE
	"GAME_VERSION=\"${PROJECT_VERSION}\""
)
target_compile_features(tests PRIVATE
	cxx_std_23
)

game_set_warnings(tests)

gtest_discover_tests(tests)
