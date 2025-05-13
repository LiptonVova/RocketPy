import matplotlib.pyplot as plt
import numpy as np
from . import _rocketSim

def draw(dfinal: _rocketSim.fvec , index1: int, index2: int) -> None:
    d_array = np.array( [ (item.x, item.y) for item in dfinal.d], dtype=np.float32)
    v_array = np.array( [ (item.x, item.y) for item in dfinal.v], dtype=np.float32)
    
    x_pos = d_array[:, 0]
    y_pos = d_array[:, 1]
    
    x_vel = v_array[:, 0]
    y_vel = v_array[:, 1]
    vel = np.sqrt(x_vel ** 2, y_vel ** 2)
    
    time = np.arange(len(v_array)) * 0.01
     
    fig1, ax1 = plt.subplots()
    fig2, ax2 = plt.subplots()
    
    if (index1 > 0):
        ax1.plot(x_pos[:index1], y_pos[:index1], label="Thrust")

    if (index2 > 0):
        ax1.plot(x_pos[index1:index2], y_pos[index1:index2], label="Delay")

    ax1.plot(x_pos[index2:], y_pos[index2:], label="Recovery")

    ax2.plot(time, x_vel, label="X-Velocity")
    ax2.plot(time, y_vel, label="Y-Velocity")
    ax2.plot(time, vel, label="Velocity")
    
    ax1.legend()
    ax2.legend()
    
    ax1.set_xlabel("Displacement (m)")
    ax1.set_ylabel("Altitude (m)")
    
    ax2.set_xlabel("Time (s)")
    ax2.set_ylabel("Velocity (m/s)")
    
    ax1.set_title("Payloader D12-7 Rocket Trajectory")
    ax2.set_title("Payloader D12-7 Rocket Velocity")
       
    plt.show()