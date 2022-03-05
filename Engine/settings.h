#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class settings {
public:
	settings();
	char scar_key = 1;
	char pump_key = 2;
	void create();
private:
	string filename = "config.ini";
	void load();
	bool is_exist = false;
};