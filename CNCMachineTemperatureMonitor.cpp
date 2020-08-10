#include "stdafx.h"
#include "CNCMachineTemperatureMonitor.h"

CNCMachineTemperatureMonitor::CNCMachineTemperatureMonitor():_temperature (0.0f)
{
}

CNCMachineTemperatureMonitor::~CNCMachineTemperatureMonitor()
{
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
