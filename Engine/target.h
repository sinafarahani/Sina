#pragma once
#include "Graphics.h"
#include "Vector.h"
#include <random>

class target {
public:
	void move();
	void rand(Graphics& gfx);
	void face(Graphics& gfx);
	Vector pos;
	Vector v;
	double mov_speed = 5;
	bool dead = false;
	bool targeted = false;
};