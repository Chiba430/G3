#pragma once
#include "ESGLib.h"
class Win
{
public:
	Win();
	~Win();

	void Initialize();

	void Update(KeyboardBuffer &key_buffer);

	void Draw();

	SPRITE win;
};

