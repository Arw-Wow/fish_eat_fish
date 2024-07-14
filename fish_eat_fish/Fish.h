#pragma once

#include "Vector2.h"
#include "Animation.h"

extern bool is_debug;

constexpr double max_speed = 1.0;

enum Fish_Type {
	Fish0, Fish1, Fish2, Fish3, Fish4, 
	Fish5, Fish6, Fish7, Fish8, Fish9,
};

class Fish
{
public:

	Fish();

	~Fish();

	virtual void on_update(int delta);

	virtual void on_draw();

	bool check_is_invalid() const;

	void set_invalid();

	double get_score() const;

	Vector2& get_size();

	Vector2& get_touch_size();

	Vector2& get_position();

	void debug_on_draw() const;

protected:

	void init()
	{
		// 随机左侧或者右侧
		is_facing_left = (bool)(rand() % 2);
		switch (is_facing_left)
		{
		case false:	// born from left
			m_position.x = 0 - m_size.x;
			current_animation = &animation_fish_right;
			break;
		case true:	// born from right
			m_position.x = getwidth();
			current_animation = &animation_fish_left;
			break;
		}

		// 随机y坐标
		m_position.y = rand() % (int)(getheight() - m_size.y - 120) + 120;

		// 随机速度
		m_speed = (max_speed) * (40 + rand() % 60) / 100 * (is_facing_left ? -1 : 1);	// speed 为 max_speed 的 40% ~ 100%

		m_touch_size = m_size;
	}

protected:

	Vector2 m_size = { 0 };
	Vector2 m_position = { 0 };
	Vector2 m_touch_size = { 0 };

	double m_speed = 0;
	
	bool is_facing_left = false;
	bool is_invalid = false;

	Animation animation_fish_left;
	Animation animation_fish_right;
	Animation* current_animation = nullptr;

	double max_size = 10;
	double min_size = 10;
	double x_y_proportion = 1;	// x/y的值

	double score = 0;
	double base_score = 1;

};

