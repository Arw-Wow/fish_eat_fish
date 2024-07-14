#include "Atlas.h"

void Atlas::load_from_file(LPCTSTR path, int num)
{
    img_list.clear();
    img_list.resize(num);

    m_path = path;
    m_num = num;

    char file_path[256] = { 0 };

    for (int i = 0; i < num; i++)
    {
        sprintf_s(file_path, sizeof(file_path), path, i);

        loadimage(&img_list[i], file_path);
    }
}

void Atlas::save_flip_atlas_to(Atlas& dst)
{
    dst.clear();
    for (int i = 0; i < get_size(); i++)
    {
        IMAGE img_flip;
        flip_image(this->get_image(i), &img_flip);
        dst.push_back_image(img_flip);
    }

    dst.m_num = m_num;
}

void Atlas::clear()
{
    img_list.clear();
}

int Atlas::get_size()
{
    return (int)img_list.size();
}

IMAGE* Atlas::get_image(int index)
{
    if (index < 0 || index >= (int)img_list.size())
        return nullptr;

    return &img_list[index];
}

void Atlas::push_back_image(IMAGE img)
{
    img_list.push_back(img);
}

void Atlas::resize(int w, int h)
{
    img_list.clear();
    img_list.resize(m_num);

    char file_path[256] = { 0 };

    for (int i = 0; i < m_num; i++)
    {
        sprintf_s(file_path, sizeof(file_path), m_path, i);

        loadimage(&img_list[i], file_path, w, h, true);
    }
}
