#include "Enemy.h"
#include <doodle\doodle.hpp>
#include <iostream>
#include "Camera.h"
using namespace std;
using namespace doodle;

void Enemy::enemy1_draw()
{
	draw_image(enemy1, x, y, enemysize, enemysize);
}
void Enemy::enemy2_draw()
{
	draw_image(enemy2, x, y, enemysize, enemysize);
}
void Enemy::enemy3_draw()
{
	draw_image(enemy3, x, y, enemysize, enemysize);
}
void Enemy::enemy4_draw()
{
	draw_image(enemy4, x, y, enemysize, enemysize);
}
void Enemy::enemy5_draw()
{
	draw_image(enemy5, x, y, enemysize, enemysize);
}
void Enemy::enemy6_draw()
{
	draw_image(enemy6, x, y, enemysize, enemysize);
}

void Enemy_attack::draw_enemy_attack()
{
	set_fill_color(HexColor{ 0xff6a00ff });
	draw_image(g3attack, attack_pos_x, attack_pos_y, attack_size, attack_size);
}

void Enemy_attack::fire_attack()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * E_Bvelocity);
	float velocityY = (sin(aimAngle) * E_Bvelocity);

	attack_pos_x += static_cast<int>(velocityX);
	attack_pos_y += static_cast<int>(velocityY);
}

void Enemy_update::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 0, 0.5, 30, 0xffffffff, 0 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::enemy_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy1_draw();
		/*	enemys[i]->enemy2_draw();
			enemys[i]->enemy3_draw();
			enemys[i]->enemy4_draw();
			enemys[i]->enemy5_draw();
			enemys[i]->enemy6_draw();*/

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
	}
}
void Enemy_update::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy1_draw();
		/*	enemys[i]->enemy2_draw();
			enemys[i]->enemy3_draw();
			enemys[i]->enemy4_draw();
			enemys[i]->enemy5_draw();
			enemys[i]->enemy6_draw();*/

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}

void Enemy_update_1_1::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy1_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}
void Enemy_update_1_2::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy2_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}
void Enemy_update_1_3::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy3_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}
void Enemy_update_2_1::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy4_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}
void Enemy_update_2_2::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy5_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}
void Enemy_update_2_3::enemy_fix_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy6_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}

		if (moveW == true) {
			enemys[i]->y += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			enemys[i]->x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			enemys[i]->y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			enemys[i]->x -= DeltaTime * 150 * 2;
		}

	}
}

void Enemy_update_1_3::enemy_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->enemy3_draw();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max);
		}

	}
}
void Enemy_update_tuto::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 2, 0, 0.5, 70, 0xffffffff, 0 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_1::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 2, 1, 0.5, 70, 0xffffffff, 1 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_2::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 0, 0.5, 70, 0xffffffff, 2 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_3::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);
	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 6, 3, 1.5, 110, 0xfff00fff, 3 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_1::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 1, 4, 70, 0xf00fffff, 4 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_2::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 2, 2, 4, 70, 0xff00ffff , 5 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_3::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 5, 3, 2.5, 70, 0xf000ffff, 6 });
			pop_settings();
		}
		count_once = int_timer;
	}
}


void Enemy_update::attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy*>& enemys, Player player)
{
	int_timer = static_cast<int>(timer);
	if (int_timer % attack_delay == 0 && count_once != int_timer) {
		for (int i = 0; i < enemys.size(); i++) {
			attack.push_back(new Enemy_attack{ enemys[i]->x , enemys[i]->y, attackSize, static_cast<float>(player.chara_pos_x), static_cast<float>(player.chara_pos_y) });
		}
		count_once = int_timer;
	}
}
void Enemy_update::attack_draw(std::vector<Enemy_attack*>& attack)
{
	{
		for (int i = 0; i < attack.size(); i++)
		{
			push_settings();
			attack[i]->draw_enemy_attack();
			attack[i]->fire_attack();
			pop_settings();
		}
	}
}
void Enemy_update::attack_remove(std::vector<Enemy_attack*>& attack)
{
	for (int i = 0; i < attack.size(); i++)
	{
		if (attack[i]->attack_pos_x > 3500 || attack[i]->attack_pos_x < 100 || attack[i]->attack_pos_y > 100 || attack[i]->attack_pos_y < 3500)
		{
			delete attack[i];
			attack.erase(attack.begin() + i);
		}
	}
}
