#pragma once
//#include"Alaram.h"
enum AlertType
{
	Enviornment,
	Machine,
	None
};
class IAlaram
{
public:
	//IAlaram();
	~IAlaram(){};

	virtual void SendAlert(AlertType alertType)=0;
	virtual AlertType GetAlert()=0;
//private:
	//AlertType _alertType;
};

