#pragma once
#include "I_CNCMachineNotifier.h"
#include <vector>

enum enumStatusCode
{
	AllOk = 0xFF,
	NoData = 0x00,
	ControlBoardNotOk = 0x01,
	ConfigDataCorrupted = 0x02
};

class CNCMachineSelfStatusMonitor :
	public I_CNCMachineNotifier
{
public:
	CNCMachineSelfStatusMonitor();
	~CNCMachineSelfStatusMonitor();

	enumStatusCode GetStatusCode();
	void SetStatusCode(enumStatusCode code);

private:
	enumStatusCode _StatusCode;
	std::vector<I_CNCMachineUpdator*> updatorsList;
};



