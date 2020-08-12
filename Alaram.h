#pragma once
#include"IAlaram.h"
enum AlaramType
{
	Enviornment, 
	Machine,
	None
};
class Alaram : public IAlaram
{
public:
	Alaram();
	~Alaram();

	virtual void SendAlert(AlaramType alertType);
	virtual AlaramType GetAlert();
private:
	AlaramType _alaramType;
};

