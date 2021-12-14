#include "aim.h"


void aim::DrawAimtoogled(Graphics& gfx) {
	for (int i = int(pos.x - (toogled_hud * scale)); i < pos.x - toogled_hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + toogled_hud); i < pos.x + (toogled_hud * scale); i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.y - (toogled_hud * scale)); i < pos.y - toogled_hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + toogled_hud); i < pos.y + (toogled_hud * scale); i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}

}
void aim::DrawAimtoogledtar(Graphics& gfx) {
	for (int i = int(pos.x - (toogled_hud * scale)); i < pos.x - toogled_hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, 0, 0);
	}for (int i = int(pos.x + toogled_hud); i < pos.x + (toogled_hud * scale); i++) {
		gfx.PutPixel(i, int(pos.y), r, 0, 0);
	}for (int i = int(pos.y - (toogled_hud * scale)); i < pos.y - toogled_hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, 0, 0);
	}for (int i = int(pos.y + toogled_hud); i < pos.y + (toogled_hud * scale); i++) {
		gfx.PutPixel(int(pos.x), i, r, 0, 0);
	}

}
void aim::DrawAim(Graphics& gfx) {
	for (int i = int(pos.x - (hud * scale)); i < pos.x - hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + hud); i < pos.x + (hud * scale); i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.y - (hud * scale)); i < pos.y - hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + hud); i < pos.y + (hud * scale); i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}
}