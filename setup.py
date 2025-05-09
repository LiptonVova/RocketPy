import os
import sys
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import pybind11

class CMakeBuildExt(build_ext):
    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        
        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}",
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-Dpybind11_DIR={pybind11.get_cmake_dir()}",
            "-DCMAKE_BUILD_TYPE=Release"
        ]

        build_temp = os.path.join(self.build_temp, ext.name)
        os.makedirs(build_temp, exist_ok=True)

        subprocess.check_call(["cmake", os.path.abspath(".")] + cmake_args, cwd=build_temp)
        subprocess.check_call(["cmake", "--build", "."], cwd=build_temp)

setup(
    name="PyRocketSim",
    version="0.1",
    packages=["PyRocketSim"],
    ext_modules=[Extension("PyRocketSim._rocketSim", [])],
    cmdclass={"build_ext": CMakeBuildExt},
    install_requires=["matplotlib", "numpy"],
    zip_safe=False,
)