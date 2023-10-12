#pragma once

#include ".\RenderArgs\RenderEventArgs.h"
#include ".\UpdateArgs\UpdateEventArgs.h"

class EventsFactory
{
private:
	std::chrono::system_clock::time_point _lastRenderingTime;
	//POINT* _lastCursorPosition;
	UpdateEventArgs* _updateArgs;
	RenderEventArgs* _renderArgs;
public:
	EventsFactory();
	//��� ��������
	//�� ������� ��������� ������� ����� � ������� ����� ������� ������ ���������
	//�������� ����� ������������ ����� ���������
	void GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs);
	UpdateEventArgs* GetUpdateArgs();
	RenderEventArgs* GetRenderArgs();
	void UpdateState();
};

