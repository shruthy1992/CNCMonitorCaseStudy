#pragma once
#include "I_CNCMachineUpdator.h"
#include "CNCMachineSelfStatusMonitor.h"
#include "IAlaram.h"

class CNCMachineSelfStatusValidator :
	public I_CNCMachineUpdator
{
public:
	CNCMachineSelfStatusValidator(CNCMachineSelfStatusMonitor& statusMonitor, IAlaram& alaram);
	~CNCMachineSelfStatusValidator();
	virtual void Update()override;
private:
	void CheckMachineStatus();
	CNCMachineSelfStatusMonitor& _CNCMachineSelfStatusMonitor;
	IAlaram& _Alaram;
};


