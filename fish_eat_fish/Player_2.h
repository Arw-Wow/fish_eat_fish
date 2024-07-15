#pragma once
#include "Player.h"
class Player_2 :
	public Player
{
public:

	Player_2() : Player()
	{
		atlas_player_left = &atlas_player_2_left;
		atlas_player_right = &atlas_player_2_right;

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
			case VK_UP:	// up
				is_move_up = true;
				break;
			case VK_DOWN:	// down
				is_move_down = true;
				break;
			case VK_LEFT:	// left
				is_move_left = true;
				break;
			case VK_RIGHT:	// right
				is_move_right = true;
				break;
			}
			break;

		case WM_KEYUP:
			switch (msg.vkcode)
			{
			case VK_UP:	// up
				is_move_up = false;
				break;
			case VK_DOWN:	// down
				is_move_down = false;
				break;
			case VK_LEFT:	// left
				is_move_left = false;
				break;
			case VK_RIGHT:	// right
				is_move_right = false;
				break;
			}
			break;
		}
	}

};
