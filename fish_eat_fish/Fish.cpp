#include "Fish.h"

Fish::Fish()
{

}

Fish::~Fish()
{

}

void Fish::on_update(int delta)
{
    if ((is_facing_left && m_position.x < 0 - m_size.x) || (!is_facing_left && m_position.x > getwidth()))
        is_invalid = true;

    // move
    m_position.x += m_speed;
}

void Fish::on_draw()
{
    current_animation->on_draw(m_position.x, m_position.y);
}

bool Fish::check_is_invalid() const
{
    return is_invalid;
}

void Fish::set_invalid()
{
    is_invalid = true;
}

double Fish::get_score() const
{
    return score;
}

Vector2& Fish::get_size()
{
    return m_size;
}

Vector2& Fish::get_touch_size()
{
    return m_touch_size;
}

Vector2& Fish::get_position()
{
    return m_position;
}

void Fish::debug_on_draw() const
{
    double touch_x = m_position.x + m_size.x / 2 - m_touch_size.x / 2;
    double touch_y = m_position.y + m_size.y / 2 - m_touch_size.y / 2;
    double touch_w = m_touch_size.x;
    double touch_h = m_touch_size.y;

    setlinecolor(YELLOW);
    line(touch_x, touch_y, touch_x + touch_w, touch_y);
    line(touch_x, touch_y + touch_h, touch_x, touch_y);
    line(touch_x + touch_w, touch_y + touch_h, touch_x + touch_w, touch_y);
    line(touch_x + touch_w, touch_y + touch_h, touch_x, touch_y + touch_h);
}
