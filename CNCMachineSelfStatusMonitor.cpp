#include "stdafx.h"
#include "CNCMachineSelfStatusMonitor.h"


CNCMachineSelfStatusMonitor::CNCMachineSelfStatusMonitor()
{
}


CNCMachineSelfStatusMonitor::~CNCMachineSelfStatusMonitor()
{
}

void CNCMachineSelfStatusMonitor::SetStatusCode(enumStatusCode code)
{
	_StatusCode = code;
	printf("Machine Self Status Code : %x\n", _StatusCode);
	Notify();
}


enumStatusCode CNCMachineSelfStatusMonitor::GetStatusCode()
{
	return _StatusCode;
}
