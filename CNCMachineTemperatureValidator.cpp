#include "stdafx.h"
#include "CNCMachineTemperatureValidator.h"

#define TEMPARATURE_LIMIT 35

CNCMachineTemperatureValidator::CNCMachineTemperatureValidator(CNCMachineTemperatureMonitor& tempMonitor, Alaram& alaram):
_CNCMachineTemperatureMonitor(tempMonitor), _alaram(alaram)
{
}

CNCMachineTemperatureValidator::~CNCMachineTemperatureValidator()
{
}

void CNCMachineTemperatureValidator::Update()
{
	ValidateTemparature();
}

void CNCMachineTemperatureValidator::ValidateTemparature()
{
	if (_CNCMachineTemperatureMonitor.GetTemperature() > TEMPARATURE_LIMIT)
	{
		_alaram.SendAlert(AlaramType::Enviornment);
	}
	else
	{
		_alaram.SendAlert(None);
	}
}
