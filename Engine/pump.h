#pragma once

#include "Graphics.h"
#include "Vector.h"
#include "Sound.h"
#include "SoundEffect.h"
#include <math.h>

class pump
{
public:
	pump();
	void draw(Graphics& gfx, Vector& pos);
	bool on_target(Vector& aim_pos, Vector& tar_pos);
	void set_scale(double scale);
	bool shot();
	void aim();
	void aim_out();
	void recoil(int& recoil);
	int get_recoil();
	SoundEffect snd_pmp = SoundEffect({ L"sounds\\Shotgun_Pump_NewFire2_01.wav" , L"sounds\\Shotgun_Pump_NewFire2_02.wav" });
	SoundEffect snd_bul = SoundEffect({ L"sounds\\weapon_shotgun_new_pump_01.wav" ,L"sounds\\weapon_shotgun_new_pump_02.wav" });
	SoundEffect snd_aim_in = SoundEffect({ L"sounds\\Weapon_Shotgun_ADS_In_01.wav" ,L"sounds\\Weapon_Shotgun_ADS_In_02.wav" });
	SoundEffect snd_aim_out = SoundEffect({ L"sounds\\Weapon_HEAVYSHOT_ADS_OUT_02.wav" });
	int r = 255;
	int g = 255;
	int b = 255;
	static constexpr double fire_rate = 1.8;
	static constexpr double cool_rate = 0.08;
private:
	random_device snd_rd;
	mt19937 snd_rnd;
	Vector p_vec;
	double scale = 1;
	double redius = 24 * scale;
	double size = 20 * scale;
	int cond_size = int(14 * scale);
	int cond_min = int(5 * scale);
	chrono::high_resolution_clock::time_point fire_time;
	chrono::high_resolution_clock::time_point fire_now;
	chrono::duration<double> fire_dr;
	double time;
	const int recoill = 20;
};