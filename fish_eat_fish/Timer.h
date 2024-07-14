#pragma once

#include <functional>

class Timer
{
public:

	Timer();

	~Timer();

	void set_interval(int interval);

	void set_loop(bool in);

	void set_callback_shot(std::function <void()> callback);

	void pause();

	void resume();

	void restart();

	void on_update(int delta);



private:

	int pass_time = 0;
	int wait_time = 0;

	bool is_loop = false;
	bool shotted = false;
	bool m_pause = false;
	
	std::function <void()> callback_shot = nullptr;

};

