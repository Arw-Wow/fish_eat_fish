#include "Fish_6.h"

Fish_6::Fish_6()
{
    base_score = 2.5;

    max_size = 190;
    min_size = 115;
    x_y_proportion = 539 / 295.0;

    double size = (rand() % (int)(max_size - min_size)) + min_size;	// ��max��min֮��ȡһ��ֵ
    m_size = { size * x_y_proportion, size };

    // ����atlas�ĳߴ�
    atlas_fish6_left.resize(m_size.x, m_size.y);
    atlas_fish6_left.save_flip_atlas_to(atlas_fish6_right);

    animation_fish_left.set_atlas(&atlas_fish6_left);
    animation_fish_left.set_size(m_size.x, m_size.y);
    animation_fish_left.set_interval(200);
    animation_fish_left.set_loop(true);
    animation_fish_left.set_callback(nullptr);

    animation_fish_right.set_atlas(&atlas_fish6_right);
    animation_fish_right.set_size(m_size.x, m_size.y);
    animation_fish_right.set_interval(200);
    animation_fish_right.set_loop(true);
    animation_fish_right.set_callback(nullptr);

    Fish::init();

    m_touch_size.x /= 1.1;
    m_touch_size.y /= 1.65;

    score = base_score * sqrt(m_touch_size.x * m_touch_size.y);
}
