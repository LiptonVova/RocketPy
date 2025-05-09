import os
import sys
import subprocess
from pathlib import Path
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

        build_temp = Path(self.build_temp) / ext.name
        build_temp.mkdir(parents=True, exist_ok=True)

        subprocess.check_call(["cmake", str(Path.cwd())] + cmake_args, cwd=build_temp)
        subprocess.check_call(["cmake", "--build", "."], cwd=build_temp)

setup(
    name="PyRocketSim",
    version="0.1",
    packages=["PyRocketSim"],
    ext_modules=[Extension("PyRocketSim._rocketSim", [])],
    cmdclass={"build_ext": CMakeBuildExt},
    install_requires=["matplotlib"],
    zip_safe=False,
)