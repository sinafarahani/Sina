#pragma once

#include "Graphics.h"
#include "Vector.h"
#include "Sound.h"
#include <math.h>

class pump
{
public:
	pump() = default;
	void draw(Graphics& gfx, Vector& pos);
	void inside_scr(Graphics& gfx, Vector& pos);
	bool on_target(Vector& aim_pos, Vector& tar_pos);
	void set_scale(double scale);
	void shot();
	Sound snd_pmp1 = Sound(L"sounds\\Shotgun_Pump_NewFire2_01.wav");
	Sound snd_pmp2 = Sound(L"sounds\\Shotgun_Pump_NewFire2_02.wav");
	Sound snd_pmp_bul1 = Sound(L"sounds\\weapon_shotgun_new_pump_01.wav");
	Sound snd_pmp_bul2 = Sound(L"sounds\\weapon_shotgun_new_pump_02.wav");
	Sound snd_pmp_aim_in1 = Sound(L"sounds\\Weapon_Shotgun_ADS_In_01.wav");
	Sound snd_pmp_aim_in2 = Sound(L"sounds\\Weapon_Shotgun_ADS_In_02.wav");
	Sound snd_pmp_aim_out = Sound(L"sounds\\Weapon_HEAVYSHOT_ADS_OUT_02.wav");
	int r = 255;
	int g = 255;
	int b = 255;
	static constexpr double fire_rate = 1.8;
	static constexpr double cool_rate = 0.08;
private:
	Vector p_vec;
	double scale = 1;
	double redius = 24 * scale;
	double size = 20 * scale;
	int cond_size = 14 * scale;
	int cond_min = 5 * scale;
};