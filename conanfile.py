from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout


class MultidrawConan(ConanFile):
    name = "libmultidraw"
    version = "0.1"
    requires = "doxygen/1.9.4", "fltk/1.3.8"
    generators = "cmake"
    
    # Optional metadata
    license = "MIT"
    author = "Terry Lorber terry@metatooth.com"
    url = "https://github.com/metatooth/libmultidraw"
    description = "A multi-platform framework for domain-specific editors."
    topics = ("framework", "design", "visualization", "2D", "3D")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "libmultidraw/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["libmultidraw"]
