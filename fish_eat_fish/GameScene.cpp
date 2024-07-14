#include "GameScene.h"

GameScene::GameScene()
{
    timer_generate_fish.set_interval(interval_generate_fish);
    timer_generate_fish.set_loop(true);
    timer_generate_fish.set_callback_shot(
        [&]() {
            generate_fish_randomly();
        }
    );
}

void GameScene::on_enter()
{
    timer_generate_fish.restart();

    if (player)
    {
        delete player;
        player = new Player();
    }

    mciSendString("play game_bgm repeat from 0", NULL, 0, NULL);
}

void GameScene::on_input(const ExMessage& msg)
{
    player->on_input(msg);

    switch (msg.message)
    {
    case WM_KEYDOWN:
        switch (msg.vkcode)
        {
        case VK_SPACE:
            is_debug = !is_debug;
            break;
        case VK_ESCAPE:
            scene_manager->switch_to(SceneType::Menu);
            break;
        }
        break;
    }
}

void GameScene::on_update(int delta)
{
    player->on_update(delta);

    timer_generate_fish.on_update(delta);

    for (Fish* fish : fish_list)
    {
        fish->on_update(delta);
    }

    check_touch();

    for (int i = 0; i < fish_list.size(); i++)
    {
        if (fish_list[i]->check_is_invalid())
        {
            delete fish_list[i];
            std::swap(fish_list[i], fish_list.back());
            fish_list.pop_back();
            i--;
        }
    }
}

void GameScene::on_draw()
{
    // 绘制背景
    putimage(0, 0, &img_bar);
    putimage(0, 120, &img_background);

    for (Fish* fish : fish_list)
    {
        fish->on_draw();
    }

    player->on_draw();

    // 显示hp
    char text_hp[256] = { 0 };
    sprintf_s(text_hp, sizeof(text_hp), "hp: %d", player->get_hp());
    outtextxy(20, 20, text_hp);

    // 显示score
    char text_score[256] = { 0 };
    sprintf_s(text_score, sizeof(text_score), "score: %d", player->get_score());
    outtextxy(20, 60, text_score);

    if (is_debug)
    {
        for (Fish* fish : fish_list)
        {
            fish->debug_on_draw();
        }

        player->debug_on_draw();
    }
}

void GameScene::on_exit()
{
    for (int i = 0; i < fish_list.size(); i++)
    {
        delete fish_list[i];
    }
    fish_list.clear();

    mciSendString("stop game_bgm", NULL, 0, NULL);
}

void GameScene::generate_fish_randomly()
{
    Fish* fish = nullptr;
    Fish_Type type = Fish_Type::Fish0;

    int rand_num = rand() % 100;
    if (rand_num < 0 + 17)		type = Fish_Type::Fish0;	// 小白鱼
    else if (rand_num < 17 + 18)	type = Fish_Type::Fish1;	// 小棕鱼
    else if (rand_num < 35 + 22)	type = Fish_Type::Fish2;	// 红鱼
    else if (rand_num < 57 + 13)	type = Fish_Type::Fish3;	// 带鱼
    else if (rand_num < 70 + 11)	type = Fish_Type::Fish4;	// 橙鱼
    else if (rand_num < 81 + 6)		type = Fish_Type::Fish5;	// 黄鱼
    else if (rand_num < 87 + 5)		type = Fish_Type::Fish6;	// 黑鱼
    else if (rand_num < 92 + 3)		type = Fish_Type::Fish7;	// 金枪鱼
    else if (rand_num < 95 + 2)		type = Fish_Type::Fish8;	// 鲨鱼
    else if (rand_num < 97 + 3)		type = Fish_Type::Fish9;	// 海马

    fish = new Fish_0();
    switch (type)
    {
    case Fish0:		fish = new Fish_0();	break;
    case Fish1:		fish = new Fish_1();	break;
    case Fish2:		fish = new Fish_2();	break;
    case Fish3:		fish = new Fish_3();	break;
    case Fish4:		fish = new Fish_4();	break;
    case Fish5:		fish = new Fish_5();	break;
    case Fish6:		fish = new Fish_6();	break;
    case Fish7:		fish = new Fish_7();	break;
    case Fish8:		fish = new Fish_8();	break;
    case Fish9:		fish = new Fish_9();	break;
    }

    fish_list.push_back(fish);
}

void GameScene::check_touch()
{
    Vector2& player_position = player->get_position();
    Vector2& player_size = player->get_size();
    Vector2& player_touch_size = player->get_touch_size();

    double player_x = player_position.x + player_size.x / 2 - player_touch_size.x / 2;
    double player_w = player_touch_size.x;
    double player_y = player_position.y + player_size.y / 2 - player_touch_size.y / 2;
    double player_h = player_touch_size.y;

    for (Fish* fish : fish_list)
    {
        Vector2& fish_position = fish->get_position();
        Vector2& fish_size = fish->get_size();
        Vector2& fish_touch_size = fish->get_touch_size();

        double fish_x = fish_position.x + fish_size.x / 2 - fish_touch_size.x / 2;
        double fish_w = fish_touch_size.x;
        double fish_y = fish_position.y + fish_size.y / 2 - fish_touch_size.y / 2;
        double fish_h = fish_touch_size.y;

        // 如果 "touch" 并 "可以吃" 就 "加分" 并 "删除fish"
        if (player_x + player_w > fish_x && player_x < fish_x + fish_w &&
            player_y + player_h > fish_y && player_y < fish_y + fish_h)
        {
            if (player->check_can_eat(fish->get_touch_size()))
            {
                player->add_score(fish->get_score());
                fish->set_invalid();
            }
            else
            {
                player->be_attacked();
                if (player->get_hp() <= 0)
                {
                    scene_manager->switch_to(SceneType::Menu);
                }
            }
        }
    }
}
