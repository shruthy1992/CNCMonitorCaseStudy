#pragma once
#include "I_CNCMachineNotifier.h"
#include<vector>


class CNCMachineTemperatureMonitor :public I_CNCMachineNotifier
{
public:

	CNCMachineTemperatureMonitor();
	~CNCMachineTemperatureMonitor();

	float GetTemperature();
	void SetTemperature(float temp);

private:
	float _temperature;
	std::vector<I_CNCMachineUpdator*> updatorsList;
};

