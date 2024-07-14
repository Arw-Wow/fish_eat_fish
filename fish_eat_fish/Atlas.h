#pragma once

#include <graphics.h>
#include <vector>

#include "Tools.h"

class Atlas
{
public:

	Atlas() = default;

	~Atlas() = default;

	void load_from_file(LPCTSTR path, int num);

	void save_flip_atlas_to(Atlas& dst);

	void clear();

	int get_size();

	IMAGE* get_image(int index);

	void push_back_image(IMAGE img);

	void resize(int w, int h);

private:

	std::vector <IMAGE> img_list;
	LPCTSTR m_path;
	int m_num = 0;

};

