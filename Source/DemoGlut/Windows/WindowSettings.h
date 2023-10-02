#pragma once
#include <string>

class WindowSettings
{
public:
	int DisplayMode;
	int PositionX;
	int PositionY;
	int Width;
	int Height;
	unsigned int UpdateTime; //��
	std::string Title;

	WindowSettings();
};

