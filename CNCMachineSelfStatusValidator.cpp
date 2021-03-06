#include "stdafx.h"
#include "CNCMachineSelfStatusValidator.h"


CNCMachineSelfStatusValidator::CNCMachineSelfStatusValidator(CNCMachineSelfStatusMonitor& statusMonitor, IAlaram& alaram) :
_CNCMachineSelfStatusMonitor(statusMonitor), _Alaram(alaram)
{
}


CNCMachineSelfStatusValidator::~CNCMachineSelfStatusValidator()
{
}

void CNCMachineSelfStatusValidator::Update()
{
	CheckMachineStatus();
}

void CNCMachineSelfStatusValidator::CheckMachineStatus()
{
	if (_CNCMachineSelfStatusMonitor.GetStatusCode() != AllOk)
	{
		_Alaram.SendAlaram(AlaramType::Machine);
	}
	else
	{
		_Alaram.SendAlaram(None);
	}
}
