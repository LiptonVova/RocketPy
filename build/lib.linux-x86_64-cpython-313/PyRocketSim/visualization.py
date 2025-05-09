import matplotlib.pyplot as plt
from . import _rocketSim

def draw(dfinal: _rocketSim.fvec , index1: int, index2: int) -> None:
    fig1, ax1 = plt.subplots()
    fig2, ax2 = plt.subplots()
    
    gr1_x = [] 
    gr1_y = []
    
    if (index1 > 0):
        for i in range(index1):
            temp = dfinal.d[i]
            x = temp.x
            y = temp.y
            gr1_x.append(x)
            gr1_y.append(y)
    
    gr12_x = []
    gr12_y = []
    
    if (index2 > 0):
        for i in range(index1, index2):
            temp = dfinal.d[i]
            x = temp.x
            y = temp.y
            gr12_x.append(x)
            gr12_y.append(y)
    
    gr13_x = []
    gr13_y = []
    for i in range(index2, len(dfinal.d)):
        temp = dfinal.d[i]
        x = temp.x
        y = temp.y
        gr13_x.append(x)
        gr13_y.append(y)
        
    gr_x = []
    gr_y = []
    for i in range(len(dfinal.d)):
        temp = dfinal.d[i]
        x = temp.x
        y = temp.y
        gr_x.append(x)
        gr_y.append(y)
        
    ax1.plot(gr_x, gr_y)
    ax1.plot(gr1_x, gr1_y, label="Thrust")
    ax1.plot(gr12_x, gr12_y, label="Delay")
    ax1.plot(gr13_x, gr13_y, label="Recovery")
    
    gr2_x = []
    gr2_y = []
    
    gr3_x = []
    gr3_y = []
    
    gr4_x = []
    gr4_y = []
    
    for i in range(len(dfinal.v)):
        temp = dfinal.v[i]
        x = temp.x
        y = temp.y
        
        gr3_x.append(i * 0.01)
        gr3_y.append(x)
        
        gr4_x.append(i * 0.01)
        gr4_y.append(y)        
        
        ny = (x ** 2 + y ** 2) ** 0.5
        gr2_x.append(i * 0.01)
        gr2_y.append(ny)
    
    ax2.plot(gr2_x, gr2_y, label='Velocity')
    ax2.plot(gr3_x, gr3_y, label="X-Velocity")
    ax2.plot(gr4_x, gr4_y, label="Y-Velocity")
    
    ax1.legend()
    ax2.legend()
    
    ax1.set_xlabel("Displacement (m)")
    ax1.set_ylabel("Altitude (m)")
    
    ax2.set_xlabel("Time (s)")
    ax2.set_ylabel("Velocity (m/s)")
    
    ax1.set_title("Payloader D12-7 Rocket Trajectory")
    ax2.set_title("Payloader D12-7 Rocket Velocity")
       
    plt.show()