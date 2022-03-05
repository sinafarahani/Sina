#include "settings.h"

settings::settings()
{
	fstream file(filename);
	for (string line; getline(file, line);) {
		if (line == "[keys]")
			load();
		is_exist = true;
	}
	if (!is_exist) {
		create();
		load();
	}
}

void settings::create()
{
	ofstream file(filename);
	file << "[keys]" << endl
		<< "scar=" << scar_key << endl
		<< "pump=" << pump_key << endl;
}

void settings::load()
{
	ifstream file(filename);
	string data = "";
	for (string line; getline(file, line);) {
		data += line;
	}
	int loc;
	if ((loc = data.find("scar=", 0)) != string::npos)
		scar_key = data[loc + 5];
	if ((loc = data.find("pump=", 0)) != string::npos)
		pump_key = data[loc + 5];
}


