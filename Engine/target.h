#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "Surface.h"
#include "SpriteEffect.h"
#include <random>

class target {
public:
	void move();
	void draw(Graphics& gfx);
	void rand(Graphics& gfx);
	Vector pos;
	Vector v;
	bool dead = false;
	bool targeted = false;
private:
	double mov_speed = 2;
	Surface s = "Images\\target.bmp";
};