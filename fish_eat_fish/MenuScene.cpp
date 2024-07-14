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
        case VK_RETURN:	// ���س�������Ϸ����
            scene_manager->switch_to(SceneType::Game);
            break;
        case VK_ESCAPE:	// ��ESC�˳���Ϸ
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
    settextstyle(40, 20, "��������");
    outtextxy(getwidth() / 2 - textwidth("��ENTER��ʼ��Ϸ") / 2, getheight() / 4 * 3 - textheight("��ENTER��ʼ��Ϸ") / 2, "��ENTER��ʼ��Ϸ");
    outtextxy(getwidth() / 2 - textwidth("��ESC�˳���Ϸ") / 2, getheight() / 4 * 3 - textheight("��ESC�˳���Ϸ") / 2 + textheight("��ENTER��ʼ��Ϸ") + 25, "��ESC�˳���Ϸ");
}

void MenuScene::on_exit()
{

}
