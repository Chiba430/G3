#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Initialize()
{

	ui.PlayerInitialize();

	player = GraphicsDevice.CreateSpriteFromFile(_T("player\\G3_kamae.png"));

	atack = GraphicsDevice.CreateSpriteFromFile(_T("player\\G3_iai.png"));

	slash_efe = GraphicsDevice.CreateSpriteFromFile(_T("player\\slash.png"));

	slash_point = GraphicsDevice.CreateSpriteFromFile(_T("player\\slash_point.png"));

	p_x = 430.0f;
	p_y = 450.0f;

	change = 0;

	count = 0;

	speed = 0.0f;

	speed_state = 0;

	loss_time = 0;

	gage = 439;

	hit_flag = false;
	flag = false;

}

void Player::Move(KeyboardBuffer &key_buffer)
{
	if (key_buffer.IsPressed(Keys_Left)){
		hit_flag = false;
		p_x -= 510.0f;
		if (p_x < -80.0f){
			p_x = -80.0f;
		}
	}

	if (key_buffer.IsPressed(Keys_Right)){
		hit_flag = false;
		p_x += 510.0f;
		if (p_x > 940.0f){
			p_x = 940.0f;
		}
	}
}

void Player::Slash(KeyboardBuffer &key_buffer)
{
	count++;
	if (key_buffer.IsPressed(Keys_Space)){
		hit_flag = false;
		speed_state = 1;
		change = 1;
		count = 0;
	}
	if (count >= 30){
		change = 0;
	}

	if (speed_state == 0){
		speed = 0;
	}
	if (speed_state == 1){
		speed += 150.0f;
		if (speed > 1400.0f){
			speed_state = 0;
		}
	}
}

void Player::Hit()
{

	loss_time++;
	change = 2;
	
	if (hit_flag == false){
		gage -= 147;
		hit_flag = true;
	}
	if (gage <= 0){
		flag = true;
	}
	if (loss_time > 60){
		change = 0;
		loss_time = 0;
	}
}

void Player::Reset()
{
	p_x = 430.0f;
	p_y = 450.0f;

	change = 0;

	count = 0;

	speed = 0.0f;

	speed_state = 0;

	loss_time = 0;

	gage = 439;

	hit_flag = false;
	flag = false;
	flag = false;
}

int Player::SlashCheck()
{
	return change;
}

float Player::PlayerPos()
{
	return p_x;
}

void Player::Draw()
{
	if (change == 0){
		SpriteBatch.Draw(*player, Vector3(p_x, p_y, 10.0f));
	}
	if (change == 1){
		SpriteBatch.Draw(*atack, Vector3(p_x, p_y, 10.0f));
	}
	if (change == 2){
		SpriteBatch.Draw(*player, Vector3(p_x, p_y, 10.0f), float(0.5));
	}

	SpriteBatch.Draw(*slash_efe, Vector3(-1280 + speed, 40.0f, 20.0f));

	SpriteBatch.Draw(*slash_point, Vector3(0.0f, 340.0f, 50), float(0.2));

	ui.PlayerDraw(gage);

}

int Player::PlayerLife()
{
	return flag;
}
