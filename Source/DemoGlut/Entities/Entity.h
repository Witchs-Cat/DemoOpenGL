#pragma once
#include "..\IDisplayedObject.h"

class Entity : IDisplayedObject
{
private:
	float _x = 0;
	float _y = 0;
	float _z = 0;

	float _translateX = 0;
	float _translateY = 0;
	float _translateZ = 0;

protected:
	GLfloat _viewProjectionMatrix[16] = {
		 1,  0,  0,  0, // ��� Ox
		 0,  1,  0,  0, // ��� Oy
		 0,  0,  1,  0, // ��� Oz
		 0,  0,  0,  1  // ������� ������� (������ ������� ���������)
	};

public:
	void SetPosition(float x, float y, float z);
	void SetAngle(float angle);
	void RotateXY(float angle);
	void RotateXZ(float angle);
	void Translate(float x, float y, float z);

	void virtual Render(RenderEventArgs* args) override;
	void virtual Update(UpdateEventArgs* args) override;
};

