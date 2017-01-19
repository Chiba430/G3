#include "Ui.h"


Ui::Ui()
{
}


Ui::~Ui()
{
}

void Ui::PlayerInitialize()
{
	life_b = GraphicsDevice.CreateSpriteFromFile(_T("UI\\HP\\gage_blue.png"));
	life_r = GraphicsDevice.CreateSpriteFromFile(_T("UI\\HP\\gage_red.png"));
}

void Ui::EnemyInitialize()
{
	stock[0] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数1.png"));
	stock[1] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数2.png"));
	stock[2] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数3.png"));
	stock[3] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数4.png"));
	stock[4] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数5.png"));
	stock[5] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数6.png"));
	stock[6] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数7.png"));
	stock[7] = GraphicsDevice.CreateSpriteFromFile(_T("UI\\stock\\残数8.png"));
}

void Ui::Reset()
{
	
}

void Ui::PlayerDraw(int &gage)
{

	SpriteBatch.Draw(*life_b, Vector3(0.0f, 0.0f, 0.0f), Rect(0, 0, gage, 701));
	SpriteBatch.Draw(*life_r, Vector3(0.0f, 0.0f, 0.1f));
}

void Ui::EnemyDraw(int &stock_state)
{

	if (stock_state == 0){
		SpriteBatch.Draw(*stock[0], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 1){
		SpriteBatch.Draw(*stock[1], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 2){
		SpriteBatch.Draw(*stock[2], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 3){
		SpriteBatch.Draw(*stock[3], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 4){
		SpriteBatch.Draw(*stock[4], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 5){
		SpriteBatch.Draw(*stock[5], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 6){
		SpriteBatch.Draw(*stock[6], Vector3(0.0f, 0.0f, 0.0f));
	}
	if (stock_state == 7){
		SpriteBatch.Draw(*stock[7], Vector3(0.0f, 0.0f, 0.0f));
	}
}