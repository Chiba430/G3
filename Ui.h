#pragma once
#include"ESGLib.h"

class Ui
{
public:
	Ui();
	~Ui();

	void EnemyInitialize();
	void PlayerInitialize();
	void Update();
	void PlayerDraw(int &gage);
	void EnemyDraw(int &stock_state);
	void Reset();
	
	SPRITE stock[8];

	//int stock_state;

	SPRITE life_b;
	SPRITE life_r;

	int gage;

};

