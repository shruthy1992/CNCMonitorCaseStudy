#pragma once

enum AlaramType
{
	Enviornment,
	Machine,
	None
};
class IAlaram
{
public:

	~IAlaram(){};

	virtual void SendAlaram(AlaramType alert)=0;
	virtual AlaramType GetAlaram()=0;
};

