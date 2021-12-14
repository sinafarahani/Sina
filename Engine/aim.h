#pragma once
#include "Graphics.h"
#include "Vector.h"

class aim {
public:
	void DrawAimtoogled(Graphics& gfx);
	void DrawAimtoogledtar(Graphics& gfx);
	void DrawAim(Graphics& gfx);
	Vector pos;
	int r = 255;
	int g = 255;
	int b = 255;
	double hud = 5;
	double toogled_hud = 3.5;
	double scale = 2.3;
};