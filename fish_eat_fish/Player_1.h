#pragma once
#include "Player.h"

class Player_1 :
    public Player
{
public:

	Player_1() : Player()
	{
		atlas_player_left = &atlas_player_1_left;
		atlas_player_right = &atlas_player_1_right;

		atlas_player_left->resize(m_size.x, m_size.y);
		atlas_player_left->save_flip_atlas_to(*atlas_player_right);

		animation_player_left.set_atlas(atlas_player_left);
		animation_player_left.set_size(m_size.x, m_size.y);
		animation_player_left.set_interval(200);
		animation_player_left.set_loop(true);
		animation_player_left.set_callback(nullptr);

		animation_player_right.set_atlas(atlas_player_right);
		animation_player_right.set_size(m_size.x, m_size.y);
		animation_player_right.set_interval(200);
		animation_player_right.set_loop(true);
		animation_player_right.set_callback(nullptr);

		current_animation = &animation_player_left;

	}

	void on_input(const ExMessage& msg) override
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
	
};

