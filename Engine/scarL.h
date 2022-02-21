#pragma once

#include "Graphics.h"
#include "Vector.h"
#include "Sound.h"
#include "SoundEffect.h"
#include <math.h>

class scarL
{
public:
	scarL() = default;
	void draw(Graphics& gfx, Vector& pos);
	bool on_target(Vector& aim_pos, Vector& tar_pos);
	void set_scale(double scale);
	bool fire();
	void aim();
	void aim_out();
	void recoil(int& recoil);
	int get_recoil();
	int aim_get_recoil();
	SoundEffect snd_scr = SoundEffect({ L"sounds\\rifle_medium_02.wav"});
	SoundEffect snd_aim_in = SoundEffect({ L"sounds\\Weapon_SCAR_ADS_IN_01.wav" ,L"sounds\\Weapon_SCAR_ADS_IN_02.wav" });
	SoundEffect snd_aim_out = SoundEffect({ L"sounds\\Weapon_SCAR_ADS_OUT_01.wav" ,L"sounds\\Weapon_SCAR_ADS_OUT_02.wav" });
	int r = 255;
	int g = 255;
	int b = 255;
	static constexpr double fire_rate = 0.18;
	static constexpr double cool_rate = 0.08;

private:
	random_device snd_rd;
	mt19937 snd_rnd;
	Vector p_vec;
	double scale = 1;
	double size = 15;
	int cond_size = int(14 * scale);
	int cond_min = int(5 * scale);
	chrono::high_resolution_clock::time_point fire_time;
	chrono::high_resolution_clock::time_point fire_now;
	chrono::duration<double> fire_dr;
	double time;
	const int recoill = 6;
	const int aim_recoill = 4;
};