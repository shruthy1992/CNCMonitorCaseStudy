#include"CNCMachineTemperatureMonitor.h"
#include"CNCMachineTemperatureValidator.h"

#include "CNCMachinePartDimentionValidator.h"
#include "CNCMachinePartDimentionMonitor.h"

#include "CNCMachineOperationTimeValidator.h"
#include "CNCMachineOperationTimeMonitor.h"

#include "CNCMachineSelfStatusMonitor.h"
#include "CNCMachineSelfStatusValidator.h"

#include <gtest/gtest.h>
Alaram alaram;
TEST(TemperatureTest1, Temp) {	
	CNCMachineTemperatureMonitor _cNCMachineTempProvider;
	CNCMachineTemperatureValidator _CNCMachineTempValidator1(_cNCMachineTempProvider, alaram);
	_cNCMachineTempProvider.Add(&_CNCMachineTempValidator1);
	_cNCMachineTempProvider.SetTemperature(20);
	_cNCMachineTempProvider.SetTemperature(40);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
