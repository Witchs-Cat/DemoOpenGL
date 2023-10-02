#pragma once

#include "WindowSettings.h"
#include "../Entities/Entity.h"
#include "../EventArgs/EventsFactory.h"

class RenderWindow : IDisplayedObject
{
private:
	EventsFactory* _eventsFactory;
	int _displayMode;
	int _positionX;
	int _positionY;
	int _width;
	int _height;
	int _updateTime;
	std::string _title;

	std::list<Entity*> _renderedEntities;

public:
	RenderWindow(WindowSettings* settings);
	// ������� ������������� ����
	void Init();
	// �������, ���������� ��� ��������� �������� ����
	void Resize(int w, int h);
	// ������� ���������� ��� ���������� ���������
	void Update(UpdateEventArgs* args) override;
	// ��� �����������
	void Render(RenderEventArgs* args) override;
	// ������� ���������� ������ updateTime ��

	void AddEntity(Entity* entity);

	void Display(void);

	int GetUpdateTime();
};

