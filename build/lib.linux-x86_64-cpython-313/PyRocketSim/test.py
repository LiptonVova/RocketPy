import visualization
from . import _rocketSim


dfinal = _rocketSim.fvec()
rp1 = _rocketSim.prock()
rf1 = _rocketSim.frock()

tstep = 0.01
delay = 7.0

_rocketSim.initialize(rp1, rf1, "../src/spec/Arachnid_D12-7.txt")
_rocketSim.use_thrustCurve("../src/spec/Payloader_D12-7.txt")

btime = _rocketSim.get_btime()
ind = 0



#--------------thrust----------------#
for i in range(int(btime/tstep)):
    _rocketSim.calc_forces(rp1, rf1, (ind * tstep))
    _rocketSim.calc_kinematics(rp1, tstep)
    _rocketSim.log_data(rp1, dfinal)
    ind += 1

index1 = ind


#----------------delay----------------#
_rocketSim.set_thrust(0.0)
_rocketSim.set_stmass(0.0)

for i in range(int(delay/tstep)):
    _rocketSim.calc_forces(rp1, rf1, 0)
    _rocketSim.calc_kinematics(rp1, tstep)
    _rocketSim.log_data(rp1, dfinal)
    ind += 1

index2 = ind

#---------recovery---------------------#

_rocketSim.deploy_Chute()

while(rp1.d.y > 0):
    _rocketSim.calc_forces(rp1, rf1, 0)
    _rocketSim.calc_kinematics(rp1, tstep)
    _rocketSim.log_data(rp1, dfinal)
    
print(f"\n\ndata size dfinal: {len(dfinal.v)}\nDrawing Data...ctrl-c to quit\n")
if (len(dfinal.v) > 0):
    visualization.draw(dfinal, index1, index2)



    