#pragma once
#include <functional>
#include <ctime>   
#include <chrono>
#include <list>

#include "WindowSettings.h"
#include "../Entities/Entity.h"
class RenderWindow
{
private:
	int displayMode;
	int positionX;
	int positionY;
	int width;
	int height;
	int updateTime;
	std::string title;
	
	std::chrono::system_clock::time_point lastRenderingTime;

	std::list<Entity*> renderedEntities;

public:
	RenderWindow(WindowSettings* settings);
	// ������� ������������� ����
	void init();
	// �������, ���������� ��� ��������� �������� ����
	void resize(int w, int h);
	// ������� ���������� ��� ���������� ���������
	void update(double elapsed);
	// ��� �����������
	void render(double elapsed);
	// ������� ���������� ������ updateTime ��

	void addEntity(Entity* entity);

	void display(void);

	int getUpdateTime();
};

