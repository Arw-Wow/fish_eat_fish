#pragma once

#include <graphics.h>

#include "Animation.h"
#include "Vector2.h"
#include "Timer.h"
#include "Tools.h"

extern Atlas atlas_player_left;
extern Atlas atlas_player_right;
extern bool is_debug;

class Player
{
private:

	static constexpr double player_origin_size = 45;
	static constexpr long double player_x_y_proportion = 50 / 35.0;

public:

	Player();

	~Player();

	void on_input(const ExMessage& msg);

	void on_update(int delta);

	void on_draw();

	Vector2& get_size();

	Vector2& get_touch_size();

	Vector2& get_position();

	void add_score(int value);

	bool check_can_eat(const Vector2& fish_touch_size) const;

	void be_attacked();

	int get_hp() const;

	int get_score() const;

	void rejust_touch_size();

	void debug_on_draw() const;

private:

	void on_move();

private:

	Vector2 m_size;
	Vector2 m_position;
	Vector2 m_touch_size;

	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

	double m_speed = 1.8;

	Animation animation_player_left;
	Animation animation_player_right;
	Animation* current_animation = nullptr;

	bool is_size_change = false;

	int score = 0;

	int hp = 5;

	Timer timer_invincible;
	bool is_invincible = false;

};

