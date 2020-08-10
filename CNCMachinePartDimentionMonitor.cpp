#include "stdafx.h"
#include "CNCMachinePartDimentionMonitor.h"


CNCMachinePartDimentionMonitor::CNCMachinePartDimentionMonitor():_partDimention(0.0f)
{
}


CNCMachinePartDimentionMonitor::~CNCMachinePartDimentionMonitor()
{
}

void CNCMachinePartDimentionMonitor::SetPartDimention(float dim)
{
	_partDimention = dim;
	printf("Part Dimention Variation is : %f mm\n", _partDimention);
	Notify();
}


float CNCMachinePartDimentionMonitor::GetPartDimention()
{
	return _partDimention;
}
