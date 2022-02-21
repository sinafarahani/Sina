#pragma once

#include "MainWindow.h"
#include "Graphics.h"
#include "target.h"
#include "aim.h"
#include "weapon.h"
#include "SoundEffect.h";
#include "FrameTimer.h"
#include "SpriteCodex.h"
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
	bool GameOver = false;
	bool snd_play_aim = false;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
	chrono::high_resolution_clock::time_point now;
	chrono::duration<double> dr;
	double time;
	int counter = 0;
	int recoil = 0;
	int HP = 3;
	chrono::high_resolution_clock::time_point cooldown;
	chrono::high_resolution_clock::time_point rec_cool;
	chrono::duration<double> rec_dr;
	double cooldown_rate;
	bool f_blood = true;
	bool LeftIsPressed = false;
	/********************************/
};