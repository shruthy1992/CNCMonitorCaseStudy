#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachineOperationTimeMonitor.h"
#include "Alaram.h"

class CNCMachineOperationTimeValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachineOperationTimeValidator(CNCMachineOperationTimeMonitor& timemonitor, Alaram& alaram);
	~CNCMachineOperationTimeValidator();
	virtual void Update()override;
private:
	void ValidateTimeofOperation();
	float ConvertToHour(float minutes);
	CNCMachineOperationTimeMonitor& _CNCMachinTimeOfOperationMonitor;
	Alaram& _Alaram;
};


