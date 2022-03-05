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
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();	
}

void Game::UpdateModel()
{
	if (Started && !GameOver) {
		if (wnd.kbd.KeyIsPressed(settings.scar_key)) {
			gun.set_status(weapon::select::scarL);
		}if (wnd.kbd.KeyIsPressed(settings.pump_key)) {
			gun.set_status(weapon::select::pump);
		}
		if (!(m.is_modify_pump || m.is_modify_scar)) {
			while (!wnd.kbd.KeyIsEmpty()) {
				const auto evt = wnd.kbd.ReadKey();
				if (evt.GetCode() == VK_ESCAPE && evt.IsPress()) {
					if (m.is_modify_pump || m.is_modify_scar) {}
					else if (m.control) {
						m.control = !m.control;
					}
					else if (setting) {
						setting = !setting;
					}
					else {
						paused = !paused;
						if (paused)
							paused_s = chrono::high_resolution_clock::now();
						if (!paused) {
							paused_e = chrono::high_resolution_clock::now();
							paused_d = paused_e - paused_s;
							paused_t += paused_d.count();
						}
					}
				}
			}
		}
		aim.pos.x = wnd.mouse.GetPosX();
		aim.pos.y = wnd.mouse.GetPosY() - recoil;
		if (pump.on_target(aim.pos, tar.pos))
			tar.targeted = true;
		else
			tar.targeted = false;
		if (scar.on_target(aim.pos, tar.pos))
			tar.targeted = true;
		else
			tar.targeted = false;
		if (tar.pos.x + 20 > gfx.ScreenWidth || tar.pos.x - 20 < 0 || tar.pos.y + 20 > gfx.ScreenHeight || tar.pos.y - 20 < 0) {
			tar.pos.x = (gfx.ScreenWidth / 2);
			tar.pos.y = (gfx.ScreenHeight / 2);
		}
	}
}

void Game::reset()
{
	start = chrono::high_resolution_clock::now();
	GameOver = false;
	counter = 0;
	recoil = 0;
	HP = 3;
	Started = false;
	setting = false;
	paused = false;
	paused_t = 0;
}

void Game::ComposeFrame()
{
	if (Started && !paused && !GameOver) {
		if (!tar.dead) {
			tar.draw(gfx);
		}
		else {
			tar.dead = false;
		}
		while (!wnd.mouse.IsEmpty()) {
			const auto evt = wnd.mouse.Read();
			if (evt.GetType() == Mouse::Event::Type::LPress && (gun.get_status() == weapon::select::pump)) {
				if (pump.shot()) {
					cooldown = chrono::high_resolution_clock::now();
					recoil += pump.get_recoil();
					if (tar.targeted) {
						tar.dead = true;
						tar.rand(gfx);
						counter += 5;
					}
					else {
						counter--;
					}
				}
			}
			if (evt.GetType() == Mouse::Event::Type::RPress) {
				if (gun.get_status() == weapon::select::pump) {
					pump.aim();
				}if (gun.get_status() == weapon::select::scarL) {
					scar.aim();
				}
			}
			if (evt.GetType() == Mouse::Event::Type::RRelease) {
				if (gun.get_status() == weapon::select::pump)
					pump.aim_out();
				if (gun.get_status() == weapon::select::scarL)
					scar.aim_out();
			}
		}
		if (recoil > 0) {
			rec_cool = chrono::high_resolution_clock::now();
			rec_dr = rec_cool - cooldown;
			cooldown_rate = rec_dr.count();
			if (gun.get_status() == weapon::select::pump) {
				if (cooldown_rate > pump.cool_rate) {
					cooldown = chrono::high_resolution_clock::now();
					pump.recoil(recoil);
				}
			}if (gun.get_status() == weapon::select::scarL) {
				if (cooldown_rate > scar.cool_rate) {
					cooldown = chrono::high_resolution_clock::now();
					scar.recoil(recoil);
				}
			}
		}if (wnd.mouse.LeftIsPressed() && (gun.get_status() == weapon::select::scarL)) {
			if (scar.fire()) {
				cooldown = chrono::high_resolution_clock::now();
				if (wnd.mouse.RightIsPressed())
					recoil += scar.aim_get_recoil();
				else
					recoil += scar.get_recoil();
				if (tar.targeted) {
					HP--;
					if (HP <= 0) {
						tar.dead = true;
						tar.rand(gfx);
						counter += 5;
						HP = 3;
					}
				}
				else {
					counter--;
				}
			}
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
			if (gun.get_status() == weapon::select::pump) {
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
		time = dr.count() - paused_t;
		rem_time = game_total_time - time;
		m.F.Drawtext(to_string(rem_time),{1,1},Colors::White,gfx);
		m.F.Drawtext(to_string(counter), { int(center.x),1 }, Colors::White, gfx);
		if (time > game_total_time) {
			GameOver = true;
			gfx.DrawSprite(int(center.x), int(center.y), its_over, SpriteEffect::Copy());
			wstring str = to_wstring(counter);
			wnd.ShowMessageBox(L"Score", L"Your Score is: " + str);
		}
	}
	else {
	if (!GameOver) {
		if (!(m.is_modify_pump || m.is_modify_scar)) {
			while (!wnd.kbd.KeyIsEmpty()) {
				const auto evt = wnd.kbd.ReadKey();
				if (evt.GetCode() == VK_ESCAPE && evt.IsPress()) {
					if (m.is_modify_pump || m.is_modify_scar) {}
					else if (m.control) {
						m.control = !m.control;
					}
					else if (setting) {
						setting = !setting;
					}
				}
			}
		}
		m.draw(Started,setting, gfx, wnd, settings);
		while (!wnd.mouse.IsEmpty()) {
			const auto evt = wnd.mouse.Read();
			if (evt.GetType() == Mouse::Event::Type::LPress) {
				m.detect(wnd.mouse.GetPos(), Started, setting,wnd, settings);
				if (!Started && !setting)
					reset();
			}
		}
	}
	else
		gfx.DrawSprite(int(center.x), int(center.y), its_over, SpriteEffect::Copy());
		while (!wnd.mouse.IsEmpty()) {
			const auto evt = wnd.mouse.Read();
			if (evt.GetType() == Mouse::Event::Type::LPress || wnd.kbd.KeyIsPressed(VK_RETURN))
				reset();
		}
	}
}
