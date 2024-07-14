#pragma once

#include "Scene.h"

extern Scene* menu_scene;
extern Scene* game_scene;

enum SceneType
{
	Menu, Game, 
};

class SceneManager
{
public:

	void set_current_scene(Scene* scene);

	void switch_to(SceneType type);

	void on_input(const ExMessage& msg);

	void on_update(int delta);

	void on_draw();

private:

	Scene* current_scene = nullptr;

};

