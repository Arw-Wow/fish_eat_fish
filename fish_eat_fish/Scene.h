#pragma once

#include <graphics.h>

class Scene
{
public:

	Scene();

	virtual ~Scene();

	virtual void on_enter();

	virtual void on_input(const ExMessage& msg);

	virtual void on_update(int delta);

	virtual void on_draw();

	virtual void on_exit();


private:



};

