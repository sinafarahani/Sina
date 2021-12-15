#include "weapon.h"

void weapon::set_status(select c)
{
	status = c;
}

weapon::select weapon::get_status()
{
	return status_sw(status);
}

weapon::select weapon::status_sw(select s)
{
	switch (s)
	{
	case weapon::select::scarL:
		return weapon::select::scarL;
		break;
	case weapon::select::pump:
		return weapon::select::pump;
		break;
	default:
		break;
	}
}


