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
CNCMachineTemperatureMonitor _CNCMachineTemperatureMonitor;
CNCMachineTemperatureValidator _CNCMachineTempValidator1(_CNCMachineTemperatureMonitor, alaram);
_CNCMachineTemperatureMonitor.Add(&_CNCMachineTempValidator1);

TEST(TemperatureTest1, Temp_normal) 
{	
_CNCMachineTemperatureMonitor.SetTemperature(20);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

TEST(TemperatureTest2, Temp_high)
{
_CNCMachineTemperatureMonitor.SetTemperature(40);
ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
}

CNCMachinePartDimentionMonitor _CNCMachinePartDimentionMonitor;
CNCMachinePartDimentionValidator _CNCMachinePartDimentionValidator1(_CNCMachinePartDimentionMonitor, alaram);
_CNCMachinePartDimentionMonitor.Add(&_CNCMachinePartDimentionValidator1);

TEST(PartDimentionTest1, Part_variation) {
_CNCMachinePartDimentionMonitor.SetPartDimention(0.2f);
ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
}
TEST(PartDimentionTest2, Part_normal) 
{
_CNCMachinePartDimentionMonitor.SetPartDimention(0.01f);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

CNCMachineOperationTimeMonitor _CNCMachineTimeOfOperationMonitor;
CNCMachineOperationTimeValidator _CNCMachineOperationTimeValidator1(_CNCMachineTimeOfOperationMonitor, alaram);
_CNCMachineTimeOfOperationMonitor.Add(&_CNCMachineOperationTimeValidator1);

TEST(TimeOfOperationTest1, Time_high) {
_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(4000);
ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
}
TEST(TimeOfOperationTest2, Time_normal) {
_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(100);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

CNCMachineSelfStatusMonitor _CNCMachineSelfStatusMonitor;
CNCMachineSelfStatusValidator _CNCMachineSelfStatusValidator1(_CNCMachineSelfStatusMonitor, alaram);
_CNCMachineSelfStatusMonitor.Add(&_CNCMachineSelfStatusValidator1);

TEST(SelfStatusCode1, Satus_normal) {
_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::AllOk);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());

TEST(SelfStatusCode2, Satus_error) {
_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::ControlBoardNotOk);
ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
