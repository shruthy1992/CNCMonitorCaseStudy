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


TEST(TemperatureTest1, Temp_normal) 
{
 CNCMachineTemperatureMonitor _CNCMachineTemperatureMonitor;
CNCMachineTemperatureValidator _CNCMachineTempValidator1(_CNCMachineTemperatureMonitor, alaram);
_CNCMachineTemperatureMonitor.Add(&_CNCMachineTempValidator1);
_CNCMachineTemperatureMonitor.SetTemperature(20);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

TEST(TemperatureTest2, Temp_high)
{
 CNCMachineTemperatureMonitor _CNCMachineTemperatureMonitor;
CNCMachineTemperatureValidator _CNCMachineTempValidator1(_CNCMachineTemperatureMonitor, alaram);
_CNCMachineTemperatureMonitor.Add(&_CNCMachineTempValidator1);
_CNCMachineTemperatureMonitor.SetTemperature(40);
ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
}


TEST(PartDimentionTest1, Part_variation) 
{
CNCMachinePartDimentionMonitor _CNCMachinePartDimentionMonitor;
CNCMachinePartDimentionValidator _CNCMachinePartDimentionValidator1(_CNCMachinePartDimentionMonitor, alaram);
_CNCMachinePartDimentionMonitor.Add(&_CNCMachinePartDimentionValidator1);
_CNCMachinePartDimentionMonitor.SetPartDimention(0.2f);
ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
}

TEST(PartDimentionTest2, Part_normal) 
{
 CNCMachinePartDimentionMonitor _CNCMachinePartDimentionMonitor;
CNCMachinePartDimentionValidator _CNCMachinePartDimentionValidator1(_CNCMachinePartDimentionMonitor, alaram);
_CNCMachinePartDimentionMonitor.Add(&_CNCMachinePartDimentionValidator1);
_CNCMachinePartDimentionMonitor.SetPartDimention(0.01f);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

TEST(TimeOfOperationTest1, Time_high) 
{
 CNCMachineOperationTimeMonitor _CNCMachineTimeOfOperationMonitor;
CNCMachineOperationTimeValidator _CNCMachineOperationTimeValidator1(_CNCMachineTimeOfOperationMonitor, alaram);
_CNCMachineTimeOfOperationMonitor.Add(&_CNCMachineOperationTimeValidator1);
_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(4000);
ASSERT_EQ(AlaramType::Enviornment,alaram.GetAlert());
}

TEST(TimeOfOperationTest2, Time_normal) 
{
CNCMachineOperationTimeMonitor _CNCMachineTimeOfOperationMonitor;
CNCMachineOperationTimeValidator _CNCMachineOperationTimeValidator1(_CNCMachineTimeOfOperationMonitor, alaram);
_CNCMachineTimeOfOperationMonitor.Add(&_CNCMachineOperationTimeValidator1);
_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(100);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

TEST(SelfStatusCode1, Satus_normal) 
{
CNCMachineSelfStatusMonitor _CNCMachineSelfStatusMonitor;
CNCMachineSelfStatusValidator _CNCMachineSelfStatusValidator1(_CNCMachineSelfStatusMonitor, alaram);
_CNCMachineSelfStatusMonitor.Add(&_CNCMachineSelfStatusValidator1);
_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::AllOk);
ASSERT_EQ(AlaramType::None,alaram.GetAlert());
}

TEST(SelfStatusCode2, Satus_error) 
{
CNCMachineSelfStatusMonitor _CNCMachineSelfStatusMonitor;
CNCMachineSelfStatusValidator _CNCMachineSelfStatusValidator1(_CNCMachineSelfStatusMonitor, alaram);
_CNCMachineSelfStatusMonitor.Add(&_CNCMachineSelfStatusValidator1);
_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::ControlBoardNotOk);
ASSERT_EQ(AlaramType::Machine,alaram.GetAlert());
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
