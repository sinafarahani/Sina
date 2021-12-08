#pragma once

#include "MainWindow.h"
#include "Graphics.h"
#include "target.h"
#include "aim.h"
#include "SoundEffect.h";
#include "FrameTimer.h"
#include <chrono>

using namespace std;
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void game_over(int x, int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	Sound snd_pmp1 = Sound(L"sounds\\Shotgun_Pump_NewFire2_01.wav");
	Sound snd_pmp2 = Sound(L"sounds\\Shotgun_Pump_NewFire2_02.wav");
	Sound snd_pmp_bul1 = Sound(L"sounds\\weapon_shotgun_new_pump_01.wav");
	Sound snd_pmp_bul2 = Sound(L"sounds\\weapon_shotgun_new_pump_02.wav");
	Sound snd_pmp_aim_in1 = Sound(L"sounds\\Weapon_Shotgun_ADS_In_01.wav");
	Sound snd_pmp_aim_in2 = Sound(L"sounds\\Weapon_Shotgun_ADS_In_02.wav");
	//Sound snd_pmp_aim_out = Sound(L"sounds\\Weapon_HEAVYSHOT_ADS_OUT_02.wav");
	/********************************/
	/*  User Variables              */
	aim aim;
	static constexpr int game_total_time = 30;
	target tar;
	bool GameOver = false;
	int snd_rnd = 0;
	bool snd_play_shot = false;
	bool snd_play_aim = false;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
	chrono::high_resolution_clock::time_point now;
	chrono::duration<double> dr;
	double time;
	int counter = 0;
	chrono::high_resolution_clock::time_point f_kill;
	chrono::high_resolution_clock::time_point kill_now;
	chrono::duration<double> respawn_dr;
	double respawn_time;
	static constexpr double respawn_time_check = 3;
	bool f_blood = true;
	bool LeftIsPressed = false;
	/********************************/
};