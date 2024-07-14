#include <iostream>
#include <graphics.h>
#include <vector>

#include "Atlas.h"
#include "Animation.h"

#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

#include "Player.h"
#include "Fish.h"

/*---------------------resource_begin--------------------*/

#pragma comment(lib, "Winmm.lib")

Atlas atlas_player_left;
Atlas atlas_player_right;

Atlas atlas_fish0_left;
Atlas atlas_fish0_right;

Atlas atlas_fish1_left;
Atlas atlas_fish1_right;

Atlas atlas_fish2_left;
Atlas atlas_fish2_right;

Atlas atlas_fish3_left;
Atlas atlas_fish3_right;

Atlas atlas_fish4_left;
Atlas atlas_fish4_right;

Atlas atlas_fish5_left;
Atlas atlas_fish5_right;

Atlas atlas_fish6_left;
Atlas atlas_fish6_right;

Atlas atlas_fish7_left;
Atlas atlas_fish7_right;

Atlas atlas_fish8_left;
Atlas atlas_fish8_right;

Atlas atlas_fish9_left;
Atlas atlas_fish9_right;

IMAGE img_background;
IMAGE img_bar;

void load_total_resouce()
{
	atlas_player_left.load_from_file("res/img/player_left_%d.png", 1);
	atlas_player_left.save_flip_atlas_to(atlas_player_right);

	atlas_fish0_left.load_from_file("res/img/fish0_left_%d.png", 1);
	atlas_fish0_left.save_flip_atlas_to(atlas_fish0_right);

	atlas_fish1_left.load_from_file("res/img/fish1_left_%d.png", 1);
	atlas_fish1_left.save_flip_atlas_to(atlas_fish1_right);

	atlas_fish2_left.load_from_file("res/img/fish2_left_%d.png", 1);
	atlas_fish2_left.save_flip_atlas_to(atlas_fish2_right);

	atlas_fish3_left.load_from_file("res/img/fish3_left_%d.png", 1);
	atlas_fish3_left.save_flip_atlas_to(atlas_fish3_right);
	
	atlas_fish4_left.load_from_file("res/img/fish4_left_%d.png", 1);
	atlas_fish4_left.save_flip_atlas_to(atlas_fish4_right);
	
	atlas_fish5_left.load_from_file("res/img/fish5_left_%d.png", 1);
	atlas_fish5_left.save_flip_atlas_to(atlas_fish5_right);
	
	atlas_fish6_left.load_from_file("res/img/fish6_left_%d.png", 1);
	atlas_fish6_left.save_flip_atlas_to(atlas_fish6_right);
	
	atlas_fish7_left.load_from_file("res/img/fish7_left_%d.png", 1);
	atlas_fish7_left.save_flip_atlas_to(atlas_fish7_right);
	
	atlas_fish8_left.load_from_file("res/img/fish8_left_%d.png", 1);
	atlas_fish8_left.save_flip_atlas_to(atlas_fish8_right);
	
	atlas_fish9_left.load_from_file("res/img/fish9_left_%d.png", 1);
	atlas_fish9_left.save_flip_atlas_to(atlas_fish9_right);

	loadimage(&img_background, "res/img/background.png", 1024, 650, true);
	loadimage(&img_bar, "res/img/bar.png", 1024, 120, true);

	mciSendString("open res/msc/game_bgm.mp3 alias game_bgm", NULL, 0, NULL);
	mciSendString("open res/msc/eat_sound.mp3 alias eat_sound", NULL, 0, NULL);
	mciSendString("open res/msc/be_attacked_sound.mp3 alias be_attacked_sound", NULL, 0, NULL);

}

/*---------------------resource_end----------------------*/



/*---------------------global__start---------------------*/

SceneManager* scene_manager = nullptr;

Scene* game_scene = nullptr;
Scene* menu_scene = nullptr;

Player* player = nullptr;

std::vector <Fish*> fish_list;

bool is_running = false;
bool is_debug = false;

/*---------------------global__end-----------------------*/


/*----------------------constexpr_start------------------------*/

constexpr int FPS = 144;	// Ö¡ÂÊ

/*----------------------constexpr_end------------------------*/



int main()
{
	srand(time(NULL));

	initgraph(1024, 770, EX_SHOWCONSOLE);

	load_total_resouce();

	scene_manager = new SceneManager();

	game_scene = new GameScene();
	menu_scene = new MenuScene();

	player = new Player();

	scene_manager->set_current_scene(menu_scene);

	ExMessage msg;

	BeginBatchDraw();

	is_running = true;
	while (is_running)
	{
		static clock_t frame_begin_time = clock();
		static clock_t last_tick_time = clock();

		// input
		while (peekmessage(&msg))
		{
			scene_manager->on_input(msg);
		}

		// update
		clock_t current_tick_time = clock();
		int delta = (int)(current_tick_time - last_tick_time);
		scene_manager->on_update(delta);
		last_tick_time = current_tick_time;

		// draw
		cleardevice();
		scene_manager->on_draw();
		FlushBatchDraw();

		// fps
		clock_t frame_delta_time = clock() - frame_begin_time;
		if (frame_delta_time < 1000.0 / FPS)
		{
			Sleep(DWORD(1000.0 / FPS - frame_delta_time));
		}
		frame_begin_time = clock();
	}

	EndBatchDraw();

	delete scene_manager;
	delete game_scene;
	delete menu_scene;
	delete player;
	for (Fish* fish : fish_list)
	{
		delete fish;
	}
	fish_list.clear();

	return 0;
}