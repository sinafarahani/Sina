#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "target.h"
#include "aim.h"

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
	/********************************/
	/*  User Variables              */
	aim aim;
	static constexpr int count = 10;
	target tar[count];
	bool GameOver = false;
	bool alldead = true;
	/********************************/
};