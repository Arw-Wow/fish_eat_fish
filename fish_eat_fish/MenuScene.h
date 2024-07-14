#pragma once

#include "Scene.h"
#include "SceneManager.h"

extern IMAGE img_background;
extern IMAGE img_bar;

extern SceneManager* scene_manager;

extern bool is_running;

class MenuScene :
    public Scene
{
public:

	void on_enter() override;

	void on_input(const ExMessage& msg) override;

	void on_update(int delta) override;

	void on_draw() override;

	void on_exit() override;

};

