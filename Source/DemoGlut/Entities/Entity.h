#pragma once
#include "..\IDisplayedObject.h"

class Entity : IDisplayedObject
{
private:
	float _x;
	float _y;
	float _z;

	float _size;

protected:
	GLfloat _modelMatrix[16] = {
		 1,  0,  0,  0, // ��� Ox
		 0,  1,  0,  0, // ��� Oy
		 0,  0,  1,  0, // ��� Oz
		 0,  0,  0,  1  // ������� ������� (������ ������� ���������)
	};

public:

	Entity();

	void SetPosition(float x, float y, float z);
	void SetSize(float size);
	void RotateXZ(float angle);

	void virtual Render(RenderEventArgs* args) override;
	void virtual Update(UpdateEventArgs* args) override;
};

