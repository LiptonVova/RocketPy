<p align="center">
      <img src="https://i.ibb.co/xqrzhTmc/logo.png" width="726">
</p>
 
## 📄 About
PyRocketSim is an open-source trajectory analysis tool designed for post-flight simulation of rocket dynamics. Built with Python and C++ through pybind11, this library specializes in reconstructing flight paths after launch using predefined physical parameters. The core simulation implements 3DOF linear dynamics (position, velocity, acceleration) with variable mass calculations, accounting for thrust curves and basic aerodynamic drag. Unlike real-time systems, PyRocketSim operates in post-processing mode, enabling analysis through its visualization toolkit that generates trajectory plots, velocity profiles, and phase separation markers (thrust/coast/recovery).

The tool serves as an educational platform for aerospace students and rocketry enthusiasts, providing a sandbox for testing simplified physics models without actual launches. Its hybrid architecture combines Python's visualization (Matplotlib) with C++'s computational efficiency. Current modeling focuses on suborbital trajectories with fixed atmospheric density, ideal for demonstrating fundamental concepts like mass flow and drag. Future development may expand features while maintaining the educational focus on accessible post-flight analysis.

## 🚀 Features
- **Post-Flight Trajectory Reconstruction** – Analyze completed launches using telemetry data or simulation parameters
- **3DOF Flight Dynamics** – Models linear motion (X-Y position, velocity) with thrust, drag, and gravity
- **Python Visualization** – Generate plots of altitude, velocity, and flight phases
- **Educational Focus** – Designed for teaching rocket dynamics, not mission-critical applications

## 💻 Installation
### 1. Pre-built binaries (recommended)

#### 1.1. Windows 11
    pip install PyRocketSim

Available for Python 3.10, 3.11, 3.12, and 3.13

#### 1.2. Ubuntu 24.04
    pip install PyRocketSim

Available for Python 3.10, 3.11, 3.12, and 3.13

### 2. From source
#### 2.1. Windows 11
**Prerequisites**: Visual Studio 2022 with C++ tools

#### 2.2. Ubuntu/Debian
**Prerequisites**: git, cmake, gcc/g++, make, python3, python3-pip (for point 2.2.3.)

##### 2.2.1. Install Dependencies (if necessary)
    sudo apt update
    sudo apt install git cmake g++ make python3 python3-pip

##### 2.2.2. Clone & Build Library
    git clone --recursive https://github.com/LiptonVova/PyRocketSim.git
    cd PyRocketSim
    mkdir build
    cd build
    cmake ..
    make

##### 2.2.3. Install Python Package (editable mode)
    cd ..
    pip install -e .

## 🧪 Testing
Test.py you can find on [GitHub](https://github.com/LiptonVova/RocketPy)

## 📌 System Requirements
- OS: Windows 11 or Ubuntu 24.04
- Python: 3.10 or higher

## 💡 Dependencies
- NumPy
- Matplotlib

## 💾 PyPI
You can find the project on PyPI [here](https://pypi.org/project/PyRocketSim/)

## 📜 License
Project PyRocketSim is distributed under the MIT license

## 🔨 Support
For issues and questions, please open an issue on our [GitHub repository](https://github.com/LiptonVova/RocketPy)
