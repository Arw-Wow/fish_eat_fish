#include "Animation.h"

// 动画重头播放

void Animation::restart()
{
    timer = 0;
    current_frame_index = 0;
}

void Animation::set_atlas(Atlas* new_altas)
{
    restart();
	img_list.clear();
	for (int i = 0; i < new_altas->get_size(); i++)
	{
		img_list.push_back(*(new_altas->get_image(i)));
	}
}

void Animation::set_loop(bool in)
{
    is_loop = in;
}

void Animation::set_interval(int ms)
{
    interval = ms;
}

void Animation::set_size(int w, int h)
{
	m_size.x = w;
	m_size.y = h;
}

int Animation::get_current_frame_index() const
{
    return current_frame_index;
}

IMAGE* Animation::get_current_frame() const
{
    return (IMAGE*)(&img_list[current_frame_index]);
}

//是否播放完

bool Animation::check_finished()
{
    if (is_loop)
        return false;

    return (current_frame_index == img_list.size() - 1);
}

void Animation::on_update(int delta)
{
    timer += delta;
    if (timer >= interval)
    {
        timer -= interval;
        current_frame_index++;
        if (current_frame_index >= img_list.size())
        {
            if (is_loop)
                current_frame_index = 0;
            else if (!is_loop)
            {
                current_frame_index = img_list.size() - 1;
                if (callback)
                {
                    callback();
                }
            }
        }
    }
}

void Animation::on_draw(int x, int y) const
{
    putimage_alpha(x, y, (IMAGE*)(&img_list[current_frame_index]));
}

void Animation::set_callback(std::function<void()> callback)
{
    this->callback = callback;
}
