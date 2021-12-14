#pragma once

#include "Graphics.h"
#include "Vector.h"
#include <math.h>

class pump
{
public:
	pump() = default;
	void draw(Graphics& gfx, Vector& pos);
	void inside_scr(Graphics& gfx, Vector& pos);
	bool on_target(Vector& aim_pos, Vector& tar_pos);
	void set_scale(double scale);
	
	int r = 255;
	int g = 255;
	int b = 255;

private:
	Vector p_vec;
	double scale = 1;
	double redius = 24 * scale;
	double size = 20 * scale;
	int cond_size = 14 * scale;
	int cond_min = 5 * scale;
};