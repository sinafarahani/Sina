#include "pump.h"

pump::pump()
	:
	snd_rnd(snd_rd())
{}

void pump::draw(Graphics& gfx, Vector& pos)
{
	for (int i = (int(pos.x - cond_size) > 1 ? int(pos.x - cond_size) : 1); i<int(pos.x - cond_min); i++) {
		if(int(pos.y - size) > 1)
			gfx.PutPixel(i, int(pos.y - size), r, g, b);
		if(int(pos.y + size) < gfx.ScreenHeight - 1)
			gfx.PutPixel(i, int(pos.y + size), r, g, b);
	}for (int i = int(pos.x + cond_min); i<(int(pos.x + cond_size)<gfx.ScreenWidth - 1?int(pos.x + cond_size): gfx.ScreenWidth - 1); i++) {
		if(int(pos.y - size) > 1)
			gfx.PutPixel(i, int(pos.y - size), r, g, b);
		if(int(pos.y + size) < gfx.ScreenHeight - 1)
			gfx.PutPixel(i, int(pos.y + size), r, g, b);
	}for (int i = (int(pos.y - cond_size) > 1 ? int(pos.y - cond_size) : 1); i<int(pos.y - cond_min); i++) {
		if (int(pos.x - size) > 1)
			gfx.PutPixel(int(pos.x - size), i, r, g, b);
		if (int(pos.x + size) < gfx.ScreenWidth - 1)
			gfx.PutPixel(int(pos.x + size), i, r, g, b);
	}for (int i = int(pos.y + cond_min); i< (int(pos.y + cond_size) < gfx.ScreenHeight - 1 ? int(pos.y + cond_size) : gfx.ScreenHeight - 1); i++) {
		if(int(pos.x - size) > 1)
			gfx.PutPixel(int(pos.x - size), i, r, g, b);
		if(int(pos.x + size) < gfx.ScreenWidth - 1)
			gfx.PutPixel(int(pos.x + size), i, r, g, b);
	}for (int i = pos.x - 100; i < pos.x + 100; i++) {
		for (int j = pos.y - 100; j < pos.y + 100; j++) {
			p_vec.x = i - pos.x;
			p_vec.y = j - pos.y;
			int r = p_vec.GetLength();
			if (r == int(redius)) {
				int a = cond_size - 1;
				if ((p_vec.x < -a && p_vec.y < -a) || (p_vec.x > a && p_vec.y < -a) || (p_vec.x<-a && p_vec.y>a) || (p_vec.x > a && p_vec.y > a)) {
					if (i > 1 && j > 1 && i < gfx.ScreenWidth - 1 && j < gfx.ScreenHeight - 1)
						gfx.PutPixel(i, j, this->r, g, b);
				}
			}
		}
	}
}

bool pump::on_target(Vector& aim_pos, Vector& tar_pos)
{
	return (aim_pos.x < (tar_pos.x + 28) && aim_pos.x >(tar_pos.x - 9) && aim_pos.y < (tar_pos.y + 28) && aim_pos.y >(tar_pos.y - 9));
}

void pump::set_scale(double scale)
{
	this->scale = scale;
	redius = 24 * scale;
	size = 20 * scale;
	cond_size = int(14 * scale);
	cond_min = int(5 * scale);
}

bool pump::shot()
{
	fire_now = chrono::high_resolution_clock::now();
	fire_dr = fire_now - fire_time;
	time = fire_dr.count();
	if (time >= fire_rate) {
		snd_pmp.Play(snd_rnd);
		fire_time = chrono::high_resolution_clock::now();
		return true;
	}
	else
		return false;
}

void pump::aim()
{
	snd_aim_in.Play(snd_rnd);
}

void pump::aim_out()
{
	snd_aim_out.Play(snd_rnd);
}

void pump::recoil(int& recoil)
{
	if (recoil > 60)
		recoil -= 4;
	if (recoil > 30)
		recoil -= 2;
	if (recoil > 15)
		recoil--;
	recoil--;
}

int pump::get_recoil()
{
	return recoill;
}
