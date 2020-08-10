#include "stdafx.h"
#include "CNCMachineOperationTimeMonitor.h"


CNCMachineOperationTimeMonitor::CNCMachineOperationTimeMonitor():_minutes(0.0f)
{
}


CNCMachineOperationTimeMonitor::~CNCMachineOperationTimeMonitor()
{
}


float CNCMachineOperationTimeMonitor::GetTimeOfOperation()
{
	return _minutes;
}

void CNCMachineOperationTimeMonitor::SetTimeOfOperation(float minutes)
{
	_minutes = minutes;
	Notify();
}

