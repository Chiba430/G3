#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	ui.EnemyInitialize();

	tentcle = GraphicsDevice.CreateSpriteFromFile(_T("enemy\\Tentacle.png"));

	effect = GraphicsDevice.CreateSpriteFromFile(_T("enemy\\effect.png"));

	atack_eria = GraphicsDevice.CreateSpriteFromFile(_T("enemy\\eria.png"));

	atack = SoundDevice.CreateSoundFromFile(_T("music\\enemy_attack.wav"));

	t_x = 430.0f;
	t_y = -800.0f;

	up = 10.0f;
	down = 10.0f;

	t_atack = 0;

	efe_state = 0;

	count = 0;

	position_state = 0;

	p_state = 0;

	loss_time = 0;

	stock_state = 7;
	stock_flag = true;

	flag = false;
	enemy_stop = true;
}

void Enemy::Move()
{
	int rand = 0;

	

	count++;
	if (t_atack == 0){
		t_y += down;
		if (t_y > -40.0f){
			stock_flag = false;
			enemy_stop = false;
			t_atack = 1;
			efe_state = 1;
			count = 0;
			atack->Play();
		}
	}



	if (t_atack == 1){
		if (count > 10){
			stock_flag = true;
			enemy_stop = true;
			efe_state = 0;
			t_y -= up;
		}
		if (t_y < -800.0f){
			t_atack = 0;
			rand = MathHelper_Random(2) + 1;
			if (rand == 1){
				t_x = 430.0f;
			}
			if (rand == 2){
				t_x = -80.0f;
			}
			if (rand == 3){
				t_x = 940.0f;
			}
		}
	}
}

void Enemy::Hit()
{
	efe_state = 2;
	if (stock_flag == false){
		loss_time++;
		stock_state -= 1;
		down += 3.0f;
		up += 3.0f;
		stock_flag = true;
		
	}
	if (loss_time > 40){
		efe_state = 0;
		loss_time = 0;
		
	}

}

void Enemy::Reset()
{
	t_x = 430.0f;
	t_y = -800.0f;

	up = 10.0f;
	down = 10.0f;

	t_atack = 0;

	efe_state = 0;

	count = 0;

	position_state = 0;

	p_state = 0;

	loss_time = 0;

	stock_state = 7;
	stock_flag = true;

	flag = false;
	enemy_stop = true;
}

float Enemy::EnemyPosX()
{
	return t_x;
}

float Enemy::EnemyPosY()
{
	return t_y;
}

int Enemy::EnemtStop()
{
	return enemy_stop;
}

void Enemy::Draw()
{
	if (efe_state == 0){
		SpriteBatch.Draw(*tentcle, Vector3(t_x, t_y, 80.0f));
	}

	if (efe_state == 1){
		SpriteBatch.Draw(*tentcle, Vector3(t_x, t_y, 80.0f));
		SpriteBatch.Draw(*effect, Vector3(t_x - 30.0f, t_y + 360.0f, 80.0f));
	}
	if (efe_state == 2){
		SpriteBatch.Draw(*tentcle, Vector3(t_x, t_y, 80.0f), float(0.5));
		SpriteBatch.Draw(*effect, Vector3(t_x - 30.0f, t_y + 360.0f, 80.0f));
	}

	SpriteBatch.Draw(*atack_eria, Vector3(t_x, 620.0f, 50.0f), float(0.2));

	ui.EnemyDraw(stock_state);

}

int Enemy::EnemyStock()
{
	if (stock_state < 0){
		flag = true;
	}

	return flag;
}