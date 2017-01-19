#include "Lose.h"


Lose::Lose()
{
}


Lose::~Lose()
{
}

void Lose::Initialize()
{
	lose = GraphicsDevice.CreateSpriteFromFile(_T("stage\\lose.png"));
}

void Lose::Update(KeyboardBuffer &key_buffer)
{

}

void Lose::Draw()
{
	SpriteBatch.Draw(*lose, Vector3(0.0f, 0.0f, 0.0f));
}