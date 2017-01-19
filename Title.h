#pragma once
#include"ESGLib.h"
class Title
{
public:
	Title();
	~Title();

	void Initialize();

	void Update(KeyboardBuffer &key_buffer);

	void Draw();

	SPRITE title;

};

