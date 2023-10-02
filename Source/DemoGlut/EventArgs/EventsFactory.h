#pragma once

#include "UpdateEventArgs.h"
#include "RenderEventArgs.h"

class EventsFactory
{
private:
	std::chrono::system_clock::time_point _lastRenderingTime;
	POINT* _lastCursorPosition;
public:
	EventsFactory();
	//��� ��������
	//�� ������� ��������� ������� �� ����� ������ 1 �����
	//�������� ����� ������������ ����� ���������
	void GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs);
	void UpdateState();
};

