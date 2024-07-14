#pragma once

#include "Scene.h"

#include <vector>

#include "SceneManager.h"
#include "Player.h"
#include "Fish.h"
#include "Fish_0.h"
#include "Fish_1.h"
#include "Fish_2.h"
#include "Fish_3.h"
#include "Fish_4.h"
#include "Fish_5.h"
#include "Fish_6.h"
#include "Fish_7.h"
#include "Fish_8.h"
#include "Fish_9.h"

extern SceneManager* scene_manager;
extern Player* player;
extern IMAGE img_background;
extern IMAGE img_bar;
extern std::vector <Fish*> fish_list;
extern bool is_debug;

class GameScene :
    public Scene
{
private:

	int interval_generate_fish = 2000;

public:

	GameScene();

	void on_enter() override;

	void on_input(const ExMessage& msg) override;

	void on_update(int delta) override;

	void on_draw() override;

	void on_exit() override;

private:

	void generate_fish_randomly();

	void check_touch();

private:

	Timer timer_generate_fish;

};

