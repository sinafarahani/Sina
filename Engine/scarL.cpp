#include "scarL.h"

void scarL::draw(Graphics& gfx, Vector& pos)
{
	if (pos.x < 0)
		pos.x = 0;
	if (pos.x > gfx.ScreenWidth)
		pos.x = gfx.ScreenWidth;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > gfx.ScreenHeight)
		pos.y = gfx.ScreenHeight;
	for (int i = (int(pos.x - cond_size) > 1 ? int(pos.x - cond_size) : 1); i < int(pos.x - cond_min); i++) {
		if (int(pos.y) > 1 && int(pos.y) < gfx.ScreenHeight)
			gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + cond_min); i < (int(pos.x + cond_size) < gfx.ScreenWidth - 1 ? int(pos.x + cond_size) : gfx.ScreenWidth - 1); i++) {
		if (int(pos.y) > 1 && int(pos.y) < gfx.ScreenHeight)
			gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = (int(pos.y - cond_size) > 1 ? int(pos.y - cond_size) : 1); i < int(pos.y - cond_min); i++) {
		if (int(pos.x) > 1 && int(pos.x) < gfx.ScreenWidth)
			gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + cond_min); i < (int(pos.y + cond_size) < gfx.ScreenHeight - 1 ? int(pos.y + cond_size) : gfx.ScreenHeight - 1); i++) {
		if (int(pos.x) > 1 && int(pos.x) < gfx.ScreenWidth)
			gfx.PutPixel(int(pos.x), i, r, g, b);
	}
}

bool scarL::on_target(Vector& aim_pos, Vector& tar_pos)
{
	return (aim_pos.x < (tar_pos.x + 20) && aim_pos.x >(tar_pos.x - 1) && aim_pos.y < (tar_pos.y + 20) && aim_pos.y >(tar_pos.y - 1));
}

void scarL::set_scale(double scale)
{
	this->scale = scale;
	cond_size = int(14 * scale);
	cond_min = int(5 * scale);
}

bool scarL::fire()
{
	fire_now = chrono::high_resolution_clock::now();
	fire_dr = fire_now - fire_time;
	time = fire_dr.count();
	if (time >= fire_rate) {
		snd_scr.Play(snd_rnd);
		fire_time = chrono::high_resolution_clock::now();
		return true;
	}
	else
		return false;
}

void scarL::aim()
{
	snd_aim_in.Play(snd_rnd);
}

void scarL::aim_out()
{
	snd_aim_out.Play(snd_rnd);
}

void scarL::recoil(int& recoil)
{
	if (recoil > 60)
		recoil -= 15;
	if (recoil > 30)
		recoil -= 5;
	if (recoil > 15)
		recoil--;
	recoil--;
}

int scarL::get_recoil()
{
	return recoill;
}

int scarL::aim_get_recoil()
{
	return aim_recoill;
}
