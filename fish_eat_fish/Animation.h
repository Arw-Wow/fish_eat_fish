#pragma once

#include <graphics.h>
#include <functional>	//�ص�����
#include <vector>

#include "Tools.h"
#include "Atlas.h"
#include "Vector2.h"

class Animation
{
public:

	Animation() = default;

	~Animation() = default;
	
	// ������ͷ����
	void restart();

	void set_atlas(Atlas* new_altas);

	void set_loop(bool in);

	void set_interval(int ms);

	void set_size(int w, int h);

	int get_current_frame_index() const;

	IMAGE* get_current_frame() const;

	//�Ƿ񲥷���
	bool check_finished();

	void on_update(int delta);

	void on_draw(int x, int y) const;

	void set_callback(std::function< void() > callback);

private:

	Vector2 m_size;

	int timer = 0;					//��ʱ��
	int current_frame_index = 0;	//֡����
	int interval = 0;				//֡���
	bool is_loop = true;			//�Ƿ�ѭ������

	std::function < void() > callback = nullptr;

	std::vector <IMAGE> img_list;

};

/*
function��һ��ģ���࣬void()��ʾ�����������洢�ĺ���������void���޲�����
����ǻص�������ԭ����function��ʱ�洢���������֮�������ĳ��ʱ�̵���callback������֮ǰ�洢�ĺ������������ں���ָ�룩
*/
