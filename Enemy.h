#pragma once
#include"ESGLib.h"
#include"Ui.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	void Initialize();
	void Move();
	void Hit();
	void Reset();
	float EnemyPosX();
	float EnemyPosY();
	void Draw();
	int EnemyStock();
	int EnemtStop();

	Ui ui;

	SPRITE tentcle;
	SPRITE effect;
	SPRITE atack_eria;
	
	float t_x, t_y;
	float up, down;

	int t_atack;
	int efe_state;
	int count;
	int position_state;
	int p_state;
	int loss_time;

	int stock_state;
	bool stock_flag;
	bool flag;
	bool enemy_stop;

	int speed;
	
	SOUND atack;
};

