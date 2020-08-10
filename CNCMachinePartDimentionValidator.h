#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachinePartDimentionMonitor.h"
#include "Alaram.h"


class CNCMachinePartDimentionValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachinePartDimentionValidator(CNCMachinePartDimentionMonitor& partDimentionMonitor,Alaram& alaram);
	~CNCMachinePartDimentionValidator();
	virtual void Update()override;
private:
	void ValidatePartDimention();
	CNCMachinePartDimentionMonitor& _CNCMachinePartDimentionMonitor;
	Alaram& _alaram;
};

