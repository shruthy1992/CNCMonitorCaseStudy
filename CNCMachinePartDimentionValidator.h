#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachinePartDimentionMonitor.h"
#include "IAlaram.h"


class CNCMachinePartDimentionValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachinePartDimentionValidator(CNCMachinePartDimentionMonitor& partDimentionMonitor,IAlaram& alaram);
	~CNCMachinePartDimentionValidator();
	virtual void Update()override;
private:
	void ValidatePartDimention();
	CNCMachinePartDimentionMonitor& _CNCMachinePartDimentionMonitor;
	IAlaram& _alaram;
};

