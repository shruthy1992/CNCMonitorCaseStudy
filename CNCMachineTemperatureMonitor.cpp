#include "stdafx.h"
#include "CNCMachineTemperatureMonitor.h"

CNCMachineTemperatureMonitor::CNCMachineTemperatureMonitor()
{
}

CNCMachineTemperatureMonitor::~CNCMachineTemperatureMonitor()
{
	_temperature = 0;
}

float CNCMachineTemperatureMonitor::GetTemperature()
{
	return _temperature;
}

void CNCMachineTemperatureMonitor::SetTemperature(float temp)
{
	_temperature = temp;
	printf("Temperature : %f degree\n", _temperature);
	Notify();
}
