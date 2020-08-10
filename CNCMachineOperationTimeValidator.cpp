#include "stdafx.h"
#include "CNCMachineOperationTimeValidator.h"

#define TIME_LIMIT 6.0f

CNCMachineOperationTimeValidator::CNCMachineOperationTimeValidator(CNCMachineOperationTimeMonitor& timemonitor, Alaram& alaram) :
_CNCMachinTimeOfOperationMonitor(timemonitor), _Alaram(alaram)
{
}


CNCMachineOperationTimeValidator::~CNCMachineOperationTimeValidator()
{
}

void CNCMachineOperationTimeValidator::Update()
{
	ValidateTimeofOperation();
}

void CNCMachineOperationTimeValidator::ValidateTimeofOperation()
{
	if (ConvertToHour(_CNCMachinTimeOfOperationMonitor.GetTimeOfOperation()) > TIME_LIMIT)
	{
		_Alaram.SendAlert(AlaramType::Enviornment);
	}
	else
	{
		_Alaram.SendAlert(None);
	}
}
float CNCMachineOperationTimeValidator::ConvertToHour(float minutes)
{
	float hour = 0;
	hour = (minutes / 60);
	printf("Machine continuously Operated time : %f hour\n", hour);
	return hour;
}