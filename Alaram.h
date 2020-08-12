#pragma once
#include"IAlaram.h"

class Alaram : public IAlaram
{
public:
	Alaram();
	~Alaram();

	virtual void SendAlaram(AlaramType alert);
	virtual AlaramType GetAlaram();
private:
	AlaramType _alaram;
};

