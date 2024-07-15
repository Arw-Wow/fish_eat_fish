#include "Player.h"

Player::Player()
{

    hp = 5;

    // 初始大小
    m_size.x = player_origin_size * player_x_y_proportion;
    m_size.y = player_origin_size;

    m_touch_size = m_size;
    m_touch_size.x /= 1.1;
    m_touch_size.y /= 1.3;

    // 初始位置
    m_position.x = getwidth() / 2.0 - m_size.x / 2.0;
    m_position.y = getheight() / 2.0 - m_size.y / 2.0;



    timer_invincible.set_interval(2000);
    timer_invincible.set_loop(false);
    timer_invincible.set_callback_shot(
        [&]() {
            is_invincible = false;
        }
    );

}

Player::~Player()
{
	
}

void Player::on_input(const ExMessage& msg)
{
    switch (msg.message)
    {
    case WM_KEYDOWN:
        switch (msg.vkcode)
        {
        case to_vkcode('w'):	//w
            is_move_up = true;
            break;
        case to_vkcode('s'):	//s
            is_move_down = true;
            break;
        case to_vkcode('a'):	//a
            is_move_left = true;
            break;
        case to_vkcode('d'):	//d
            is_move_right = true;
            break;
        }
        break;

    case WM_KEYUP:
        switch (msg.vkcode)
        {
        case to_vkcode('w'):	//w
            is_move_up = false;
            break;
        case to_vkcode('s'):	//s
            is_move_down = false;
            break;
        case to_vkcode('a'):	//a
            is_move_left = false;
            break;
        case to_vkcode('d'):	//d
            is_move_right = false;
            break;
        }
        break;
    }
}

void Player::on_update(int delta)
{
    on_move();

    timer_invincible.on_update(delta);

    // 调整大小并播放动画
    if (is_size_change)
    {
        double current_area = player_origin_size * player_origin_size + score * 30.0 / player_x_y_proportion;
        m_size.x = sqrt(current_area) * player_x_y_proportion;
        m_size.y = sqrt(current_area);
        rejust_touch_size();
        atlas_player_left->resize(m_size.x, m_size.y);
        atlas_player_left->save_flip_atlas_to(*atlas_player_right);
        animation_player_left.set_atlas(atlas_player_left);
        animation_player_right.set_atlas(atlas_player_right);
        is_size_change = false;
    }
    current_animation->on_update(delta);
}

void Player::on_draw()
{
    current_animation->on_draw(m_position.x, m_position.y);
}

Vector2& Player::get_size()
{
    return m_size;
}

Vector2& Player::get_touch_size()
{
    return m_touch_size;
}

Vector2& Player::get_position()
{
    return m_position;
}

void Player::add_score(int value)
{
    is_size_change = true;
    score += value;

    mciSendString("play eat_sound from 0", NULL, 0, NULL);
}

bool Player::check_can_eat(const Vector2& fish_touch_size) const
{
    return (m_touch_size.x * m_touch_size.y > fish_touch_size.x * fish_touch_size.y);
}

void Player::be_attacked()
{
    if (is_invincible)
        return;

    is_invincible = true;
    timer_invincible.restart();
    hp--;

    mciSendString("play be_attacked_sound from 0", NULL, 0, NULL);
}

int Player::get_hp() const
{
    return hp;
}

int Player::get_score() const
{
    return score;
}

void Player::rejust_touch_size()
{
    m_touch_size = m_size;
    m_touch_size.x /= 1.1;
    m_touch_size.y /= 1.3;
}

void Player::debug_on_draw() const
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

void Player::on_move()
{
    double x_delta = is_move_right - is_move_left;	//right
    double y_delta = is_move_down - is_move_up;	//down

    double length = sqrt(x_delta * x_delta + y_delta * y_delta);

    if (length >= 0.0000001)
    {
        double x_change = x_delta / length * m_speed;
        double y_change = y_delta / length * m_speed;

        m_position.x += x_change;
        m_position.y += y_change;

        // 复位
        if (m_position.x < 0)						m_position.x = 0;
        if (m_position.x + m_size.x > getwidth())	m_position.x = getwidth() - m_size.x;
        if (m_position.y < 0 + 120)					m_position.y = 0 + 120;
        if (m_position.y + m_size.y > getheight())	m_position.y = getheight() - m_size.y;

        // 朝左还是朝右
        if (x_change > 0)
        {
            current_animation = &animation_player_right;
        }
        else if (x_change < 0)
        {
            current_animation = &animation_player_left;
        }
    }
}
