#include "Timer.h"

Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::set_interval(int interval)
{
    wait_time = interval;
}

void Timer::set_loop(bool in)
{
    is_loop = in;
}

void Timer::set_callback_shot(std::function<void()> callback)
{
    callback_shot = callback;
}

void Timer::pause()
{
    m_pause = true;
}

void Timer::resume()
{
    m_pause = false;
}

void Timer::restart()
{
    pass_time = 0;
    shotted = false;
}

void Timer::on_update(int delta)
{
    if (m_pause)
        return;

    pass_time += delta;

    if (pass_time >= wait_time)
    {
        if ((is_loop || !is_loop && !shotted) && callback_shot)
            callback_shot();

        shotted = true;
        if (is_loop)
            pass_time -= wait_time;
        else
            pass_time = 0;
    }
}
