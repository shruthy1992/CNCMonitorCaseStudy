#pragma once
#include"Alaram.h"
enum AlaramType
{
	Enviornment, 
	Machine,
	None
};
class Alaram
{
public:
	Alaram();
	~Alaram();

	void SendAlert(AlaramType alertType);
};

