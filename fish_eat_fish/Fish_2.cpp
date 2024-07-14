#include "Fish_2.h"

Fish_2::Fish_2()
{
    base_score = 1.5;

    max_size = 55;
    min_size = 25;
    x_y_proportion = 243 / 99.0;

    double size = (rand() % (int)(max_size - min_size)) + min_size;	// 在max与min之间取一个值
    m_size = { size * x_y_proportion, size };

    // 重置atlas的尺寸
    atlas_fish2_left.resize(m_size.x, m_size.y);
    atlas_fish2_left.save_flip_atlas_to(atlas_fish2_right);

    animation_fish_left.set_atlas(&atlas_fish2_left);
    animation_fish_left.set_size(m_size.x, m_size.y);
    animation_fish_left.set_interval(200);
    animation_fish_left.set_loop(true);
    animation_fish_left.set_callback(nullptr);

    animation_fish_right.set_atlas(&atlas_fish2_right);
    animation_fish_right.set_size(m_size.x, m_size.y);
    animation_fish_right.set_interval(200);
    animation_fish_right.set_loop(true);
    animation_fish_right.set_callback(nullptr);

    Fish::init();

    m_touch_size.x /= 1.2;
    m_touch_size.y /= 1.7;

    score = base_score * sqrt(m_touch_size.x * m_touch_size.y);
}
