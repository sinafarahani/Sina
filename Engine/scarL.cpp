#include "scarL.h"

void scarL::draw(Graphics& gfx, Vector& pos)
{
	for (int i = int(pos.x - cond_size); i < pos.x - cond_min; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + cond_min); i < pos.x + cond_size; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.y - cond_size); i < pos.y - cond_min; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + cond_min); i < pos.y + cond_size; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}
}

void scarL::inside_scr(Graphics& gfx, Vector& pos)
{
	if ((pos.x + size) > gfx.ScreenWidth) {
		pos.x = gfx.ScreenWidth - size;
	}if ((pos.x - size) < 0) {
		pos.x = size;
	}if ((pos.y + size) > gfx.ScreenHeight) {
		pos.y = gfx.ScreenHeight - size;
	}if ((pos.y - size) < 0) {
		pos.y = size;
	}
}

bool scarL::on_target(Vector& aim_pos, Vector& tar_pos)
{
	return (aim_pos.x < (tar_pos.x + 20) && aim_pos.x >(tar_pos.x - 1) && aim_pos.y < (tar_pos.y + 20) && aim_pos.y >(tar_pos.y - 1));
}

void scarL::set_scale(double scale)
{
	this->scale = scale;
	cond_size = 14 * scale;
	cond_min = 5 * scale;
}
