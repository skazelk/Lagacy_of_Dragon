#include "Shooting.h"
#include <doodle\doodle.hpp>
using namespace doodle;

double Shooting::radius() {
	double radius = static_cast<int>(size / 2);
	return radius;
}

void Shooting::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Shooting::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Bvelocity);
	float velocityY = (sin(aimAngle) * Bvelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Shooting_update::bullet_create(std::vector<Shooting*> &bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked = true;
	}
	if (MouseIsPressed && not_clicked == true)
	{
		bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
		not_clicked = false;
	}
}
void Shooting_update::bullet_draw(std::vector<Shooting*> &bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}


void Shooting_update::bullet_remove(std::vector<Shooting*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}