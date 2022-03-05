#include "target.h"

void target::move() {
	std::random_device rr;
	std::mt19937_64 rnd(rr());
	std::uniform_int_distribution<int> xv(-int(mov_speed), int(mov_speed));
	std::uniform_int_distribution<int> yv(-int(mov_speed), int(mov_speed));
	v.x = xv(rr);
	v.y = yv(rr);
	pos.x += v.x;
	pos.y += v.y;
}
void target::draw(Graphics& gfx)
{
	gfx.DrawSprite(pos.x, pos.y, s, SpriteEffect::Chroma(Colors::Magenta));
	move();
}
void target::rand(Graphics& gfx) {
	std::random_device rd;
	std::mt19937_64 rnd(rd());
	std::uniform_int_distribution<int> xdis(0, gfx.ScreenWidth - 20);
	std::uniform_int_distribution<int> ydis(0, gfx.ScreenHeight - 20);
	pos.x = xdis(rnd);
	pos.y = ydis(rnd);
}