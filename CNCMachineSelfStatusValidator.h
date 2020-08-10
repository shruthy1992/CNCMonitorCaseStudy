#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachineSelfStatusMonitor.h"
#include "Alaram.h"

class CNCMachineSelfStatusValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachineSelfStatusValidator(CNCMachineSelfStatusMonitor& statusMonitor, Alaram& alaram);
	~CNCMachineSelfStatusValidator();
	virtual void Update()override;
private:
	void CheckMachineStatus();
	CNCMachineSelfStatusMonitor& _CNCMachineSelfStatusMonitor;
	Alaram& _Alaram;
};


