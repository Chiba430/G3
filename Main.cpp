#include "Main.h"


Main::Main()
{
}


Main::~Main()
{
}

void Main::Initialize()
{
	player.Initialize();
	enemy.Initialize();
	stage.Initialize();

	enemy_x = 0.0f;
	enemy_y = 0.0f;
	player_x = 0.0f;

	slash_state = 0;

	enemy_stop = true;
}

void Main::Update(KeyboardBuffer &key_buffer)
{
	player.Move(key_buffer);
	enemy.Move();
	stage.Update();
	player.Slash(key_buffer);
}

void Main::Hit()
{
	enemy_x = enemy.EnemyPosX();
	enemy_y = enemy.EnemyPosY();
	player_x = player.PlayerPos();
	slash_state = player.SlashCheck();
	enemy_stop = enemy.EnemtStop();

	if (slash_state != 0){
		if (enemy_stop == false){
			enemy.Hit();
		}
	}

	if (enemy_x == player_x){
		if (enemy_y > -400.0f){
			player.Hit();
		}
	}
}

void Main::Reset()
{
	player.Reset();
	enemy.Reset();
	stage.Reset();
	ui.Reset();

	enemy_x = 0.0f;
	enemy_y = 0.0f;
	player_x = 0.0f;

	slash_state = 0;

	enemy_stop = true;
}

void Main::Draw()
{
	player.Draw();
	enemy.Draw();
	stage.Draw();	
}

int Main::PlayerFlag()
{
	return player.PlayerLife();
}

int Main::EnemyFlag()
{
	return enemy.EnemyStock();
}