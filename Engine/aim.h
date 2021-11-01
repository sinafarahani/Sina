#pragma once
#include "Graphics.h"

class aim {
public:
	void DrawAimtoogled(Graphics& gfx);
	void DrawAimtoogledtar(Graphics& gfx);
	void DrawAim(Graphics& gfx);
	int x = Graphics::ScreenWidth / 2;
	int y = Graphics::ScreenHeight / 2;
	int r = 255;
	int g = 255;
	int b = 255;
	double hud = 5;
	double toogled_hud = 3.5;
};