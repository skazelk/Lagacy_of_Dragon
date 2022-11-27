#pragma once
#include <vector>
#include "Enemy.h"
#include "Shooting.h"
#include "Tutorial.h"

constexpr double enemyradius = 15;
constexpr double chararadius = 25;
constexpr double bulletradius = 5;

inline double hp_timer = 0.0;
inline double hp_time_check = 0.7;

struct Interaction
{
	void player_enemy_interaction(std::vector<Enemy_1_1*>& enemys, Player* player);
	void bullet_enemy_interaction(std::vector<Enemy_tuto*>& enemys, std::vector<Shooting*>& bullets);
	void bullet_enemy_interaction(std::vector<Enemy_1_1*>& enemys, std::vector<Shooting*>& bullets);
	void bullet_enemy_interaction(std::vector<Enemy_1_3*>& enemys, std::vector<Shooting*>& bullets);
	void bullet_enemy_interaction(std::vector<Enemy_2_1*>& enemys, std::vector<Shooting*>& bullets);
};
extern Interaction interaction;