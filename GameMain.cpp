// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	game_scene = TITLE;

	title.Initialize();
	main.Initialize();
	lose.Initialize();
	win.Initialize();

	main_bgm = SoundDevice.CreateMusicFromFile(_T("music\\main.wav"));
	win_bgm = SoundDevice.CreateMusicFromFile(_T("music\\win.wav"));
	lose_bgm = SoundDevice.CreateMusicFromFile(_T("music\\lose.wav"));

	player_flag = false;
	enemy_flag = false;
	
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here


	key_buffer = Keyboard->GetBuffer();

	player_flag = main.PlayerFlag();
	enemy_flag = main.EnemyFlag();

		switch (game_scene){
	case TITLE:
		win_bgm->Stop();
		lose_bgm->Stop();
		title.Update(key_buffer);
		if (key_buffer.IsPressed(Keys_Enter)){
			main_bgm->Play();
			game_scene = MAIN;
		}
		break;
	case MAIN:
		main.Update(key_buffer);
		main.Hit();
		if (player_flag == true){
			main_bgm->Stop();
			lose_bgm->Play();
			game_scene = LOSE;
		}
		if (enemy_flag == true){
			main_bgm->Stop();
			win_bgm->Play();
			game_scene = WIN;
		}
		break;
	case LOSE:
		lose.Update(key_buffer);
		main.Reset();
		player_flag = false;
		enemy_flag = false;
		if (key_buffer.IsPressed(Keys_Enter)){
			game_scene = TITLE;
		}
		break;
	case WIN:
		win.Update(key_buffer);
		main.Reset();
		player_flag = false;
		enemy_flag = false;
		if (key_buffer.IsPressed(Keys_Enter)){
			game_scene = TITLE;
		}
		break;
	}

		

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();

	switch (game_scene){
	case TITLE:
		title.Draw();
		break;
	case MAIN:
		main.Draw();
		break;
	case LOSE:
		lose.Draw();
		break;
	case WIN:
		win.Draw();
		break;
	}
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
