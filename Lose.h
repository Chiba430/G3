#pragma once
#include"ESGLib.h"
class Lose
{
public:
	Lose();
	~Lose();

	void Initialize();

	void Update(KeyboardBuffer &key_buffer);

	void Draw();

	SPRITE lose;
};

