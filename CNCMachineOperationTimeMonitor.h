#pragma once
#include "I_CNCMachineNotifier.h"
#include<vector>

class CNCMachineOperationTimeMonitor : public I_CNCMachineNotifier
{
public:
	CNCMachineOperationTimeMonitor();
	~CNCMachineOperationTimeMonitor();

	float GetTimeOfOperation();
	void SetTimeOfOperation(float minutes);

private:
	float _minutes;
	std::vector<I_CNCMachineUpdator*> updatorsList;
};

