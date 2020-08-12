#include "stdafx.h"
#include "CNCMachineTemperatureValidator.h"

#define TEMPARATURE_LIMIT 35

CNCMachineTemperatureValidator::CNCMachineTemperatureValidator(CNCMachineTemperatureMonitor& tempMonitor, IAlaram& alaram):
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
		_alaram.SendAlaram(AlaramType::Enviornment);
	}
	else
	{
		_alaram.SendAlaram(None);
	}
}
