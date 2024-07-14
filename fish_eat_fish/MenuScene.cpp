#include "MenuScene.h"

void MenuScene::on_enter()
{

}

void MenuScene::on_input(const ExMessage& msg)
{
    switch (msg.message)
    {
    case WM_KEYDOWN:
        switch (msg.vkcode)
        {
        case VK_RETURN:	// 按回车进入游戏场景
            scene_manager->switch_to(SceneType::Game);
            break;
        case VK_ESCAPE:	// 按ESC退出游戏
            is_running = false;
        }
        break;
    }
}

void MenuScene::on_update(int delta)
{

}

void MenuScene::on_draw()
{
    putimage(0, 0, &img_bar);
    putimage(0, 120, &img_background);

    settextcolor(WHITE);
    setbkmode(TRANSPARENT);
    settextstyle(40, 20, "华文琥珀");
    outtextxy(getwidth() / 2 - textwidth("按ENTER开始游戏") / 2, getheight() / 4 * 3 - textheight("按ENTER开始游戏") / 2, "按ENTER开始游戏");
    outtextxy(getwidth() / 2 - textwidth("按ESC退出游戏") / 2, getheight() / 4 * 3 - textheight("按ESC退出游戏") / 2 + textheight("按ENTER开始游戏") + 25, "按ESC退出游戏");
}

void MenuScene::on_exit()
{

}
