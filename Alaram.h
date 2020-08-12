#pragma once
#include"IAlaram.h"

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

