#include "aim.h"
#include"Graphics.h"

void aim::DrawAimtoogled(Graphics& gfx) {
	for (int i = x - (toogled_hud * 2.3); i < x - toogled_hud; i++) {
		gfx.PutPixel(i, y, r, g, b);
	}for (int i = x + toogled_hud; i < x + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(i, y, r, g, b);
	}for (int i = y - (toogled_hud * 2.3); i < y - toogled_hud; i++) {
		gfx.PutPixel(x, i, r, g, b);
	}for (int i = y + toogled_hud; i < y + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(x, i, r, g, b);
	}

}
void aim::DrawAimtoogledtar(Graphics& gfx) {
	for (int i = x - (toogled_hud * 2.3); i < x - toogled_hud; i++) {
		gfx.PutPixel(i, y, r, 0, 0);
	}for (int i = x + toogled_hud; i < x + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(i, y, r, 0, 0);
	}for (int i = y - (toogled_hud * 2.3); i < y - toogled_hud; i++) {
		gfx.PutPixel(x, i, r, 0, 0);
	}for (int i = y + toogled_hud; i < y + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(x, i, r, 0, 0);
	}

}
void aim::DrawAim(Graphics& gfx) {
	for (int i = x - (hud * 2.3); i < x - hud; i++) {
		gfx.PutPixel(i, y, r, g, b);
	}for (int i = x + hud; i < x + (hud * 2.3); i++) {
		gfx.PutPixel(i, y, r, g, b);
	}for (int i = y - (hud * 2.3); i < y - hud; i++) {
		gfx.PutPixel(x, i, r, g, b);
	}for (int i = y + hud; i < y + (hud * 2.3); i++) {
		gfx.PutPixel(x, i, r, g, b);
	}
}