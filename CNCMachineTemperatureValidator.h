#pragma once
#include"I_CNCMachineUpdator.h"
#include "CNCMachineTemperatureMonitor.h"
#include "IAlaram.h"

class CNCMachineTemperatureValidator :public I_CNCMachineUpdator
{
public:
	CNCMachineTemperatureValidator(CNCMachineTemperatureMonitor& tempMonitor, IAlaram& alaram);
	~CNCMachineTemperatureValidator();
	virtual void Update()override;
private:
	void ValidateTemparature();
	CNCMachineTemperatureMonitor& _CNCMachineTemperatureMonitor;
	IAlaram& _alaram;
};

