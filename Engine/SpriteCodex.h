#pragma once

#include "Graphics.h"
#include "Vector.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vector& center,Graphics& gfx );
	// centered drawing of 200x160 sprite
	static void DrawTitle( const Vector& center,Graphics& gfx );
	// centered drawing of 84x64 sprite
	static void DrawGameOver( const Vector& center,Graphics& gfx );
	// centered drawing of 104x19 sprite
	static void DrawReady( const Vector& center,Graphics& gfx );
	// centered drawing of 24x24 sprite
	static void DrawPoo( const Vector& center,Graphics& gfx );
	static void face(const Vector& pos, Graphics& gfx);
	static void game_over(const Vector& center, Graphics& gfx);
};