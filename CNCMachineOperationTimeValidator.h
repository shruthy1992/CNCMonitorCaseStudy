#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachineOperationTimeMonitor.h"
#include "IAlaram.h"

class CNCMachineOperationTimeValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachineOperationTimeValidator(CNCMachineOperationTimeMonitor& timemonitor, IAlaram& alaram);
	~CNCMachineOperationTimeValidator();
	virtual void Update()override;
private:
	void ValidateTimeofOperation();
	float ConvertToHour(float minutes);
	CNCMachineOperationTimeMonitor& _CNCMachinTimeOfOperationMonitor;
	IAlaram& _Alaram;
};


