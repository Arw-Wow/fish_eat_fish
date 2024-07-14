#include "SceneManager.h"

void SceneManager::set_current_scene(Scene* scene)
{
    if (current_scene)
        current_scene->on_exit();

    current_scene = scene;

    if (current_scene)
        current_scene->on_enter();
}

void SceneManager::switch_to(SceneType type)
{
    if (current_scene)
        current_scene->on_exit();

    switch (type)
    {
    case Menu:
        current_scene = menu_scene;
        break;
    case Game:
        current_scene = game_scene;
        break;
    default:
        current_scene = nullptr;
        break;
    }

    if (current_scene)
        current_scene->on_enter();
}

void SceneManager::on_input(const ExMessage& msg)
{
    current_scene->on_input(msg);
}

void SceneManager::on_update(int delta)
{
    current_scene->on_update(delta);
}

void SceneManager::on_draw()
{
    current_scene->on_draw();
}
