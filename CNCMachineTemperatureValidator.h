#pragma once
#include"I_CNCMachineUpdator.h"
#include "CNCMachineTemperatureMonitor.h"
#include "Alaram.h"

class CNCMachineTemperatureValidator :public I_CNCMachineUpdator
{
public:
	CNCMachineTemperatureValidator(CNCMachineTemperatureMonitor& tempMonitor, Alaram& alaram);
	~CNCMachineTemperatureValidator();
	virtual void Update()override;
private:
	void ValidateTemparature();
	CNCMachineTemperatureMonitor& _CNCMachineTemperatureMonitor;
	Alaram& _alaram;
};

