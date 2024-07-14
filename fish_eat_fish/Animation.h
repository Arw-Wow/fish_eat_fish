#pragma once

#include <graphics.h>
#include <functional>	//回调函数
#include <vector>

#include "Tools.h"
#include "Atlas.h"
#include "Vector2.h"

class Animation
{
public:

	Animation() = default;

	~Animation() = default;
	
	// 动画重头播放
	void restart();

	void set_atlas(Atlas* new_altas);

	void set_loop(bool in);

	void set_interval(int ms);

	void set_size(int w, int h);

	int get_current_frame_index() const;

	IMAGE* get_current_frame() const;

	//是否播放完
	bool check_finished();

	void on_update(int delta);

	void on_draw(int x, int y) const;

	void set_callback(std::function< void() > callback);

private:

	Vector2 m_size;

	int timer = 0;					//计时器
	int current_frame_index = 0;	//帧索引
	int interval = 0;				//帧间隔
	bool is_loop = true;			//是否循环播放

	std::function < void() > callback = nullptr;

	std::vector <IMAGE> img_list;

};

/*
function是一个模板类，void()表示这个函数对象存储的函数类型是void且无参数。
这就是回调函数的原理：用function临时存储这个函数，之后可以在某个时刻调用callback来调用之前存储的函数。（类似于函数指针）
*/
