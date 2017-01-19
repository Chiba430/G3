#pragma once
#include"ESGLib.h"
#include"Enemy.h"
#include"Player.h"
#include"Stage.h"
#include"Ui.h"
class Main
{
public:
	Main();
	~Main();

	void Initialize();
	void Update(KeyboardBuffer &key_buffer);
	void Draw();
	void Hit();
	void Reset();
	int PlayerFlag();
	int EnemyFlag();

	Player player;
	Enemy enemy;
	Stage stage;
	Ui ui;

	float enemy_x;
	float enemy_y;
	float player_x;

	int slash_state;

	bool enemy_stop;
};

