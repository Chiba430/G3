#include "Stage.h"


Stage::Stage()
{
}


Stage::~Stage()
{
}

void Stage::Initialize()
{
	main_stage = GraphicsDevice.CreateSpriteFromFile(_T("stage\\background.png"));
}

void Stage::Update()
{

}

void Stage::Reset()
{
	
}

void Stage::Draw()
{
	SpriteBatch.Draw(*main_stage, Vector3(0.0f, 0.0f, 100.0f));
}
