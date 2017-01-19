#include "Win.h"


Win::Win()
{
}


Win::~Win()
{
}

void Win::Initialize()
{
	win = GraphicsDevice.CreateSpriteFromFile(_T("stage\\win.png"));
}

void Win::Update(KeyboardBuffer &key_buffer)
{

}

void Win::Draw()
{
	SpriteBatch.Draw(*win, Vector3(0.0f, 0.0f, 0.0f));
}