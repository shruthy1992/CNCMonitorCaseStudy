#pragma once

enum AlertType
{
	Enviornment,
	Machine,
	None
};
class IAlaram
{
public:

	~IAlaram(){};

	virtual void SendAlert(AlertType alertType)=0;
	virtual AlertType GetAlert()=0;
};

