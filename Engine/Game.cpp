#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	tar.rand(gfx);
	center.x = gfx.ScreenWidth / 2;
	center.y = gfx.ScreenHeight / 2;
}

void Game::Go()
{
	if (!GameOver) {
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	}	
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed('W') && aim.hud < (gfx.ScreenHeight / 20) && aim.pos.x + (aim.hud * 2.3) < gfx.ScreenWidth && aim.pos.x - (aim.hud * 2.3) > 0) {
		aim.toogled_hud += 0.5;
		aim.hud += 1;
	}if (wnd.kbd.KeyIsPressed('S') && aim.toogled_hud > 3) {
		aim.toogled_hud -= 0.5;
		aim.hud -= 1;
	}
	aim.pos.x = wnd.mouse.GetPosX();
	aim.pos.y = wnd.mouse.GetPosY() - recoil;
	if (aim.pos.x + (aim.hud * 2.3) > gfx.ScreenWidth)
		aim.pos.x = (aim.hud * 2.3);
	else if (aim.pos.x - (aim.hud * 2.3) < 0)
		aim.pos.x = gfx.ScreenWidth - (aim.hud * 2.3);
	if (aim.pos.y + (aim.hud * 2.3) > gfx.ScreenHeight)
		aim.pos.y = (aim.hud * 2.3);
	else if (aim.pos.y - (aim.hud * 2.3) < 0)
		aim.pos.y = gfx.ScreenHeight - (aim.hud * 2.3);
	if (aim.pos.x < (tar.pos.x + 20) && aim.pos.x >(tar.pos.x - 1) && aim.pos.y < (tar.pos.y + 20) && aim.pos.y >(tar.pos.y - 1))
		tar.targeted = true;
	else
		tar.targeted = false;
	if (tar.pos.x + 20 > gfx.ScreenWidth || tar.pos.x - 20 < 0 || tar.pos.y + 20 > gfx.ScreenHeight || tar.pos.y - 20 < 0) {
		aim.pos.x = (gfx.ScreenWidth / 2);
		tar.pos.x = (gfx.ScreenWidth / 2);
		aim.pos.y = (gfx.ScreenHeight / 2);
		tar.pos.y = (gfx.ScreenHeight / 2);
	}
}

void Game::ComposeFrame()
{
		if (!tar.dead) {
			SpriteCodex::face(tar.pos,gfx);
			tar.move();
		}
		else {
			tar.dead = false;
		}
		while (!wnd.mouse.IsEmpty()) {
			const auto evt = wnd.mouse.Read();
			if (evt.GetType() == Mouse::Event::Type::LPress) {
				if (!snd_play_shot) {
					snd_play_shot = true;
					if (snd_rnd % 3 != 0) {
						snd_pmp1.Play();
						snd_pmp_bul1.Play();
					}
					else {
						snd_pmp2.Play();
						snd_pmp_bul2.Play();
					}
				}
			}
			if (evt.GetType() == Mouse::Event::Type::RPress) {
				if (!snd_play_aim) {
					snd_play_aim = true;
					if (snd_rnd % 3 != 0) {
						snd_pmp_aim_in1.Play();
					}
					else
						snd_pmp_aim_in2.Play();
				}
			}
			if (evt.GetType() == Mouse::Event::Type::LRelease) {
				snd_play_shot = false;
				LeftIsPressed = false;
			}
			if (evt.GetType() == Mouse::Event::Type::RRelease) {
				snd_play_aim = false;
			}
		}
		if (recoil > 0) {
			rec_cool = chrono::high_resolution_clock::now();
			rec_dr = rec_cool - cooldown;
			cooldown_rate = rec_dr.count();
			if (cooldown_rate > cool_rate) {
				cooldown = chrono::high_resolution_clock::now();
				if (recoil > 60)
					recoil -= 4;
				if (recoil > 30)
					recoil -= 2;
				if (recoil > 15)
					recoil--;
				recoil--;
			}
		}
		if (wnd.mouse.LeftIsPressed() && !LeftIsPressed) {
			LeftIsPressed = true;
			cooldown = chrono::high_resolution_clock::now();
			recoil += 15;
			if (tar.targeted) {
				tar.dead = true;
				tar.rand(gfx);
				counter += 5;
			}
			else {
				counter--;
			}
		}
		if (wnd.mouse.RightIsPressed()) {
			if (tar.targeted) {
				aim.DrawAimtoogledtar(gfx);
			}
			else
				aim.DrawAimtoogled(gfx);
		}
		else {
			aim.DrawAim(gfx);
		}
	now = chrono::high_resolution_clock::now();
	dr = now - start;
	time = dr.count();
	if (time> game_total_time) {
		GameOver = true;
		SpriteCodex::game_over(center, gfx);
		wstring str = to_wstring(counter);
		wnd.ShowMessageBox(L"Score", L"Your Score is: " + str);
	}
}
