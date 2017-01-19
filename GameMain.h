#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include"Title.h"
#include"Main.h"
#include"Win.h"
#include"Lose.h"
#include"Ui.h"
#include"Enemy.h"
#include"Player.h"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// ïœêîêÈåæ

	enum GAME_SCENE{
		TITLE,
		MAIN,
		LOSE,
		WIN
	};

	int game_scene;

	Title title;
	Main main;
	Lose lose;
	Win win;
	Ui ui;
	Player player;
	Enemy enemy;

	bool player_flag;
	bool enemy_flag;

	MUSIC main_bgm;
	MUSIC win_bgm;
	MUSIC lose_bgm;

	KeyboardBuffer key_buffer;

	// ä÷êîêÈåæ

};
