import visualization
import rocket_core


dfinal = rocket_core.fvec()
rp1 = rocket_core.prock()
rf1 = rocket_core.frock()

tstep = 0.01
delay = 7.0

rocket_core.initialize(rp1, rf1, "../src/spec/Arachnid_D12-7.txt")
rocket_core.use_thrustCurve("../src/spec/Payloader_D12-7.txt")

btime = rocket_core.get_btime()
ind = 0



#--------------thrust----------------#
for i in range(int(btime/tstep)):
    rocket_core.calc_forces(rp1, rf1, (ind * tstep))
    rocket_core.calc_kinematics(rp1, tstep)
    rocket_core.log_data(rp1, dfinal)
    ind += 1

index1 = ind


#----------------delay----------------#
rocket_core.set_thrust(0.0)
rocket_core.set_stmass(0.0)

for i in range(int(delay/tstep)):
    rocket_core.calc_forces(rp1, rf1, 0)
    rocket_core.calc_kinematics(rp1, tstep)
    rocket_core.log_data(rp1, dfinal)
    ind += 1

index2 = ind

#---------recovery---------------------#

rocket_core.deploy_Chute()

while(rp1.d.y > 0):
    rocket_core.calc_forces(rp1, rf1, 0)
    rocket_core.calc_kinematics(rp1, tstep)
    rocket_core.log_data(rp1, dfinal)
    
print(f"\n\ndata size dfinal: {len(dfinal.v)}\nDrawing Data...ctrl-c to quit\n")
if (len(dfinal.v) > 0):
    visualization.draw(dfinal, index1, index2)



    