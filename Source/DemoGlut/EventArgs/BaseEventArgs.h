#pragma once

#include "../Includes.h"

//��� ��������
//�� ������� ��������� ������� �� ����� ������ 1 �����
class BaseEventArgs abstract
{
private:
	double _elapsedMilliseconds;
public:
	BaseEventArgs(double elapsedMilliseconds);
	double GetElapsedMilliseconds();
};

