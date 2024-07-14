#include "Fish_5.h"

Fish_5::Fish_5()
{
    base_score = 2.25;

    max_size = 150;
    min_size = 95;
    x_y_proportion = 365 / 235.0;

    double size = (rand() % (int)(max_size - min_size)) + min_size;	// 在max与min之间取一个值
    m_size = { size * x_y_proportion, size };

    // 重置atlas的尺寸
    atlas_fish5_left.resize(m_size.x, m_size.y);
    atlas_fish5_left.save_flip_atlas_to(atlas_fish5_right);

    animation_fish_left.set_atlas(&atlas_fish5_left);
    animation_fish_left.set_size(m_size.x, m_size.y);
    animation_fish_left.set_interval(200);
    animation_fish_left.set_loop(true);
    animation_fish_left.set_callback(nullptr);

    animation_fish_right.set_atlas(&atlas_fish5_right);
    animation_fish_right.set_size(m_size.x, m_size.y);
    animation_fish_right.set_interval(200);
    animation_fish_right.set_loop(true);
    animation_fish_right.set_callback(nullptr);

    Fish::init();

    m_touch_size.x /= 1.3;
    m_touch_size.y /= 2.0;

    score = base_score * sqrt(m_touch_size.x * m_touch_size.y);
}
