#pragma once

#include "MainWindow.h"
#include "Graphics.h"
#include "target.h"
#include "aim.h"
#include "weapon.h"
#include "SoundEffect.h";
#include "FrameTimer.h"
#include "menu.h"
#include <chrono>
#include <vector>

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
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	/********************************/
	/*  User Variables              */
	aim aim;
	weapon gun;
	pump pump;
	scarL scar;
	static constexpr int game_total_time = 30;
	target tar;
	Vector center;
	void reset();
	bool GameOver = false;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
	chrono::high_resolution_clock::time_point now;
	chrono::duration<double> dr;
	chrono::high_resolution_clock::time_point paused_s;
	chrono::high_resolution_clock::time_point paused_e;
	chrono::duration<double> paused_d;
	double paused_t = 0;
	double time;
	double rem_time;
	int counter = 0;
	int recoil = 0;
	int HP = 3;
	Surface its_over = "Images\\game_over.bmp";
	chrono::high_resolution_clock::time_point cooldown;
	chrono::high_resolution_clock::time_point rec_cool;
	chrono::duration<double> rec_dr;
	double cooldown_rate;
	bool Started = false;
	bool setting = false;
	bool paused = false;
	menu m;
	settings settings;
	/********************************/
};