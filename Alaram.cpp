#include "stdafx.h"
#include "Alaram.h"


Alaram::Alaram():_alaram(AlaramType::None)
{
}


Alaram::~Alaram()
{
}

void Alaram::SendAlaram(AlaramType alert)
{
	_alaram = alertType;
	switch (alertType)
	{
	case AlaramType::Enviornment:
	{
		printf("ENVIORNMENT NEED ATTENTION\n\n");
	}
	break;
	case AlaramType::Machine:
	{
		printf("MACHINE NEED ATTENTION\n\n");
	}
	break;
	default:
		printf("NO ATTENTION NEEDED\n\n");
	}
}

AlaramType Alaram::GetAlaram()
{
	return _alaram;
}
