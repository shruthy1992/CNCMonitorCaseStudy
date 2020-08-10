#include "stdafx.h"
#include "Alaram.h"


Alaram::Alaram():_alaramType(None)
{
}


Alaram::~Alaram()
{
}

void Alaram::SendAlert(AlaramType alertType)
{
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

AlaramType Alaram::GetAlert()
{
	return _alaramType;
}
