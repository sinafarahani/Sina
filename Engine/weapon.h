#pragma once

#include "pump.h"
#include "scarL.h"

class weapon
{
public:
	enum class select {
		scarL,
		pump
	};
	void set_status(select c);
	select get_status();
private:
	select status_sw(select s);
	select status = select::pump;
};