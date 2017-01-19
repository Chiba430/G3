#pragma once
#include"ESGLib.h"
#include"Ui.h"
class Player
{
public:
	Player();
	~Player();

	void Initialize();
	void Move(KeyboardBuffer &key_buffer);
	void Slash(KeyboardBuffer &key_buffer);
	void Hit();
	void Reset();
	int SlashCheck();
	float PlayerPos();
	void Draw();
	int PlayerLife();

	Ui ui;

	SPRITE player;
	SPRITE atack;
	SPRITE slash_efe;
	SPRITE slash_point;

	float p_x, p_y;
	float speed;

	int speed_state;
	int loss_time;
	int change;
	int count;
	int gage;

	bool hit_flag;
	bool flag;

};

