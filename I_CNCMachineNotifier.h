#pragma once
#include "I_CNCMachineUpdator.h"
#include<vector>
class I_CNCMachineNotifier
{
public:
	
	~I_CNCMachineNotifier(){};
	virtual void Add(I_CNCMachineUpdator* updatorObj)
	{
		updatorsList.push_back(updatorObj);
	}
	virtual void Remove(I_CNCMachineUpdator* updatorObj)
	{
		for (unsigned int i = 0; i < updatorsList.size(); i++)
		{
			if (updatorsList[i] == updatorObj)
			{
				updatorsList.erase(updatorsList.begin() + i);
			}
		}
	}
	virtual void Notify()
	{
		for (unsigned int i = 0; i < updatorsList.size(); i++)
		{
			updatorsList[i]->Update();
		}
	}
private:
	std::vector<I_CNCMachineUpdator*> updatorsList;
};

