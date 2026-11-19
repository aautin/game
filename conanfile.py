from conan import ConanFile
from conan.tools.cmake import cmake_layout


class GameConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def build_requirements(self):
        # Test-only dependency: never propagated to consumers of the game.
        self.test_requires("gtest/1.15.0")

    def layout(self):
        cmake_layout(self)
