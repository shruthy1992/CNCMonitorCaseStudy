#pragma once
#include "I_CNCMachineNotifier.h"
#include<vector>

class CNCMachinePartDimentionMonitor :
	public I_CNCMachineNotifier
{
public:
	CNCMachinePartDimentionMonitor();
	~CNCMachinePartDimentionMonitor();

	float GetPartDimention();
	void SetPartDimention(float dim);
	
private:
	float _partDimention;
	std::vector<I_CNCMachineUpdator*> updatorsList;
};

