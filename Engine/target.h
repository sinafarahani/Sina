#pragma once
#include "Graphics.h"
class target {
public:
	void move();
	void rand(Graphics& gfx);
	void face(Graphics& gfx);
	int x;
	int y;
	int vx;
	int vy;
	int mov_speed = 2;
	bool dead = false;
	bool targeted = false;
};