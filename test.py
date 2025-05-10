# import visualization
# from . import _rocketSim
import PyRocketSim


dfinal = PyRocketSim.fvec()
rp1 = PyRocketSim.prock()
rf1 = PyRocketSim.frock()

tstep = 0.01
delay = 7.0

PyRocketSim.initialize(rp1, rf1, "src/spec/Arachnid_D12-7.txt")
PyRocketSim.use_thrustCurve("src/spec/Payloader_D12-7.txt")

btime = PyRocketSim.get_btime()
ind = 0



#--------------thrust----------------#
for i in range(int(btime/tstep)):
    PyRocketSim.calc_forces(rp1, rf1, (ind * tstep))
    PyRocketSim.calc_kinematics(rp1, tstep)
    PyRocketSim.log_data(rp1, dfinal)
    ind += 1

index1 = ind


#----------------delay----------------#
PyRocketSim.set_thrust(0.0)
PyRocketSim.set_stmass(0.0)

for i in range(int(delay/tstep)):
    PyRocketSim.calc_forces(rp1, rf1, 0)
    PyRocketSim.calc_kinematics(rp1, tstep)
    PyRocketSim.log_data(rp1, dfinal)
    ind += 1

index2 = ind

#---------recovery---------------------#

PyRocketSim.deploy_Chute()

while(rp1.d.y > 0):
    PyRocketSim.calc_forces(rp1, rf1, 0)
    PyRocketSim.calc_kinematics(rp1, tstep)
    PyRocketSim.log_data(rp1, dfinal)
    
print(f"\n\ndata size dfinal: {len(dfinal.v)}\nDrawing Data...ctrl-c to quit\n")
if (len(dfinal.v) > 0):
    PyRocketSim.draw(dfinal, index1, index2)



    