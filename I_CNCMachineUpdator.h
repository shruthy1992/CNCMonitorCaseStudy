#pragma once
class I_CNCMachineUpdator
{
public:
	~I_CNCMachineUpdator(){};
	virtual void Update()=0;
};

