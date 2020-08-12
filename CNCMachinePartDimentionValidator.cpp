#include "stdafx.h"
#include "CNCMachinePartDimentionValidator.h"

#define PART_DIM_LIMIT 0.05

CNCMachinePartDimentionValidator::CNCMachinePartDimentionValidator(CNCMachinePartDimentionMonitor& partDimentionMonitor, IAlaram& alaram):
_CNCMachinePartDimentionMonitor(partDimentionMonitor),
_alaram(alaram)
{
}


CNCMachinePartDimentionValidator::~CNCMachinePartDimentionValidator()
{

}

void CNCMachinePartDimentionValidator::Update()
{
	ValidatePartDimention();
}

void CNCMachinePartDimentionValidator::ValidatePartDimention()
{
	if (_CNCMachinePartDimentionMonitor.GetPartDimention() > PART_DIM_LIMIT)
	{
		_alaram.SendAlaram(AlaramType::Machine);
	}
	else
	{
		_alaram.SendAlaram(None);
	}
}
