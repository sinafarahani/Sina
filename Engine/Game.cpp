#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
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
	if (wnd.kbd.KeyIsPressed('1')) {
		gun.set_status(weapon::select::scarL);
	}if (wnd.kbd.KeyIsPressed('2')) {
		gun.set_status(weapon::select::pump);
	}
	aim.pos.x = wnd.mouse.GetPosX();
	aim.pos.y = wnd.mouse.GetPosY() - recoil;
	if(gun.get_status() == weapon::select::pump)
		pump.inside_scr(gfx, aim.pos);
	if (gun.get_status() == weapon::select::scarL)
		scar.inside_scr(gfx, aim.pos);
	if (pump.on_target(aim.pos,tar.pos))
		tar.targeted = true;
	else
		tar.targeted = false;
	if (scar.on_target(aim.pos,tar.pos))
		tar.targeted = true;
	else
		tar.targeted = false;
	if (tar.pos.x + 20 > gfx.ScreenWidth || tar.pos.x - 20 < 0 || tar.pos.y + 20 > gfx.ScreenHeight || tar.pos.y - 20 < 0) {
		tar.pos.x = (gfx.ScreenWidth / 2);
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
			if (evt.GetType() == Mouse::Event::Type::LPress && (gun.get_status() == weapon::select::pump)) {
				fire_now = chrono::high_resolution_clock::now();
				fire_dr = fire_now - fire_time;
				fire_rate = fire_dr.count();
				if (fire_rate >= pump.fire_rate) {
					if (snd_rnd % 3 != 0) {
						pump.snd_pmp1.Play();
						pump.snd_pmp_bul1.Play();
					}
					else {
						pump.snd_pmp2.Play();
						pump.snd_pmp_bul2.Play();
					}
				}
			}
			if (evt.GetType() == Mouse::Event::Type::RPress) {
				if (gun.get_status() == weapon::select::pump) {
					if (snd_rnd % 3 != 0) {
						pump.snd_pmp_aim_in1.Play();
					}
					else
						pump.snd_pmp_aim_in2.Play();
				}if (gun.get_status() == weapon::select::scarL) {

				}
			}
			if (evt.GetType() == Mouse::Event::Type::LRelease) {
				LeftIsPressed = false;
			}
			if (evt.GetType() == Mouse::Event::Type::RRelease) {
				if (gun.get_status() == weapon::select::pump)
					pump.snd_pmp_aim_out.Play(); 
				if (gun.get_status() == weapon::select::scarL){}
			}
		}
		if (recoil > 0) {
			rec_cool = chrono::high_resolution_clock::now();
			rec_dr = rec_cool - cooldown;
			cooldown_rate = rec_dr.count();
			if (gun.get_status() == weapon::select::pump) {
				if (cooldown_rate > pump.cool_rate) {
					cooldown = chrono::high_resolution_clock::now();
					if (recoil > 60)
						recoil -= 4;
					if (recoil > 30)
						recoil -= 2;
					if (recoil > 15)
						recoil--;
					recoil--;
				}
			}if (gun.get_status() == weapon::select::scarL) {

			}
		}
		if (wnd.mouse.LeftIsPressed() && !LeftIsPressed && (gun.get_status() == weapon::select::pump)) {
			fire_now = chrono::high_resolution_clock::now();
			fire_dr = fire_now - fire_time;
			fire_rate = fire_dr.count();
			LeftIsPressed = true;
			if (fire_rate >= pump.fire_rate) {
				cooldown = chrono::high_resolution_clock::now();
				fire_time = chrono::high_resolution_clock::now();
				recoil += 20;
				if (tar.targeted) {
					tar.dead = true;
					tar.rand(gfx);
					counter += 5;
				}
				else {
					counter--;
				}
			}
		}if (wnd.mouse.LeftIsPressed() && (gun.get_status() == weapon::select::scarL)) {

		}
		if (wnd.mouse.RightIsPressed()) {
			if (tar.targeted) {
				if (gun.get_status() == weapon::select::pump) {
					pump.set_scale(0.6);
					pump.g = 0;
					pump.b = 0;
				}
				if (gun.get_status() == weapon::select::scarL) {
					scar.set_scale(0.6);
					scar.g = 0;
					scar.b = 0;
				}
			}
			else {
				if (gun.get_status() == weapon::select::pump) {
					pump.g = 255;
					pump.b = 255;
					pump.set_scale(0.6);
				}if (gun.get_status() == weapon::select::scarL) {
					scar.g = 255;
					scar.b = 255;
					scar.set_scale(0.6);
				}
			}
		}
		else {
			if (gun.get_status() == weapon::select::scarL) {
				pump.g = 255;
				pump.b = 255;
				pump.set_scale(1);
			}if (gun.get_status() == weapon::select::scarL) {
				scar.g = 255;
				scar.b = 255;
				scar.set_scale(1);
			}
		}
	if (gun.get_status() == weapon::select::pump)
		pump.draw(gfx, aim.pos);
	if (gun.get_status() == weapon::select::scarL)
		scar.draw(gfx, aim.pos);
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
