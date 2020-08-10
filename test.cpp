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
	ASSERT_EQ(AlaramType::None,alaram.GetAlert());
	_cNCMachineTempProvider.SetTemperature(40);
	ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
}
TEST(PartDimentionTest1, Part) {
CNCMachinePartDimentionMonitor _CNCMachinePartDimentionMonitor;
	CNCMachinePartDimentionValidator _CNCMachinePartDimentionValidator1(_CNCMachinePartDimentionMonitor, alaram);
	_CNCMachinePartDimentionMonitor.Add(&_CNCMachinePartDimentionValidator1);
	_CNCMachinePartDimentionMonitor.SetPartDimention(0.2f);
	ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
	_CNCMachinePartDimentionMonitor.SetPartDimention(0.01f);
	ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}
TEST(TimeOfOperationTest1, Time) {
	CNCMachineOperationTimeMonitor _CNCMachineTimeOfOperationMonitor;
	CNCMachineOperationTimeValidator _CNCMachineOperationTimeValidator1(_CNCMachineTimeOfOperationMonitor, alaram);
	_CNCMachineTimeOfOperationMonitor.Add(&_CNCMachineOperationTimeValidator1);
	_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(4000);
	ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
	_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(100);
	ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}
TEST(SelfStatusCode1, Satus) {
	CNCMachineSelfStatusMonitor _CNCMachineSelfStatusMonitor;
	CNCMachineSelfStatusValidator _CNCMachineSelfStatusValidator1(_CNCMachineSelfStatusMonitor, alaram);
	_CNCMachineSelfStatusMonitor.Add(&_CNCMachineSelfStatusValidator1);
	_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::AllOk);
	ASSERT_EQ(AlaramType::None,alaram.GetAlert());
	_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::ControlBoardNotOk);
	ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
