#include "Title.h"


Title::Title()
{
}


Title::~Title()
{
}

void Title::Initialize()
{
	title = GraphicsDevice.CreateSpriteFromFile(_T("stage\\title.png"));
}

void Title::Update(KeyboardBuffer &key_buffer)
{

}

void Title::Draw()
{
	SpriteBatch.Draw(*title, Vector3(0.0f, 0.0f, 0.0f));
}