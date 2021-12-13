#pragma once
#include "Graphics.h"
#include "Vector.h"
#include <random>

class target {
public:
	void move();
	void rand(Graphics& gfx);
	Vector pos;
	Vector v;
	double mov_speed = 3;
	bool dead = false;
	bool targeted = false;
};