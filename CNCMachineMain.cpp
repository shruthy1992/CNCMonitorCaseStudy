// CNCMachineMonitor_1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include"CNCMachineTemperatureMonitor.h"
#include"CNCMachineTemperatureValidator.h"

#include "CNCMachinePartDimentionValidator.h"
#include "CNCMachinePartDimentionMonitor.h"

#include "CNCMachineOperationTimeValidator.h"
#include "CNCMachineOperationTimeMonitor.h"

#include "CNCMachineSelfStatusMonitor.h"
#include "CNCMachineSelfStatusValidator.h"

#include "Alaram.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Alaram alaram;
	CNCMachineTemperatureMonitor _cNCMachineTempProvider;
	CNCMachineTemperatureValidator _CNCMachineTempValidator1(_cNCMachineTempProvider, alaram);
	_cNCMachineTempProvider.Add(&_CNCMachineTempValidator1);
	_cNCMachineTempProvider.SetTemperature(20);
	_cNCMachineTempProvider.SetTemperature(40);

	CNCMachinePartDimentionMonitor _CNCMachinePartDimentionMonitor;
	CNCMachinePartDimentionValidator _CNCMachinePartDimentionValidator1(_CNCMachinePartDimentionMonitor, alaram);
	_CNCMachinePartDimentionMonitor.Add(&_CNCMachinePartDimentionValidator1);
	_CNCMachinePartDimentionMonitor.SetPartDimention(0.2f);
	_CNCMachinePartDimentionMonitor.SetPartDimention(0.01f);

	CNCMachineOperationTimeMonitor _CNCMachineTimeOfOperationMonitor;
	CNCMachineOperationTimeValidator _CNCMachineOperationTimeValidator1(_CNCMachineTimeOfOperationMonitor, alaram);
	_CNCMachineTimeOfOperationMonitor.Add(&_CNCMachineOperationTimeValidator1);
	_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(4000);
	_CNCMachineTimeOfOperationMonitor.SetTimeOfOperation(100);

	CNCMachineSelfStatusMonitor _CNCMachineSelfStatusMonitor;
	CNCMachineSelfStatusValidator _CNCMachineSelfStatusValidator1(_CNCMachineSelfStatusMonitor, alaram);
	_CNCMachineSelfStatusMonitor.Add(&_CNCMachineSelfStatusValidator1);
	_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::AllOk);
	_CNCMachineSelfStatusMonitor.SetStatusCode(enumStatusCode::ControlBoardNotOk);

	return 0;
}

