from conans import ConanFile, CMake


class OpenCQTConanBuild(ConanFile):
    name = "OpenCQT"
    version = "0.1"
    requires = \
        "rang/3.0.0@rang/stable", \
        "boost/1.70.0@conan/stable"
    generators = "cmake"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")

    def build(self):
        self.run("conan install .. --build missing")
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
