<p align="center">
      <img src="https://i.ibb.co/xqrzhTmc/logo.png" width="726">
</p>
 
## 📄 About
PyRocketSim is an open-source trajectory analysis tool designed for post-flight simulation of rocket dynamics. Built with Python and C++ through pybind11, this library specializes in reconstructing flight paths after launch using recorded telemetry or predefined physical parameters. The core simulation engine implements six-degrees-of-freedom dynamics with variable mass calculations, accounting for thrust curves, basic aerodynamic drag, and multi-stage separation events. Unlike real-time systems, PyRocketSim operates in post-processing mode, enabling detailed analysis of completed flights through its visualization toolkit that generates trajectory plots, velocity profiles, and phase separation markers.

The tool serves primarily as an educational platform for aerospace engineering students and amateur rocketry enthusiasts, providing a sandbox for testing physical models without requiring actual launches. Its hybrid architecture combines Python's visualization capabilities (Matplotlib) with C++'s computational efficiency, striking a balance between accessibility and performance. Current modeling focuses on suborbital trajectories with simplified atmospheric assumptions, making it unsuitable for professional guidance systems but ideal for demonstrating fundamental rocket physics concepts. Future development may expand atmospheric modeling features while maintaining the project's educational focus on accessible post-flight analysis.

## 🚀 Features
- **Post-Flight Trajectory Reconstruction** – Analyze completed launches using telemetry data or simulation parameters
- **6DOF Physics Engine** – Models thrust, variable mass, and basic aerodynamics with C++ precision
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

#### Prerequisites
- Windows 11: Visual Studio 2022 with C++ tools
- Ubuntu/Debian: gcc, g++, make

## 🧪 Testing

Test.py you can find on [GitHub](https://github.com/LiptonVova/RocketPy)

## 📌 System Requirements

- OS: Windows 11 or Ubuntu 24.04
- Python: 3.10 or higher

## 💡 Dependencies

- numpy
- matplotlib

## 📜 License

Project PyRocketSim is distributed under the MIT license

## 🔨 Support

For issues and questions, please open an issue on our [GitHub repository](https://github.com/LiptonVova/RocketPy)
