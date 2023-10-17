#pragma once
#include "..\IDisplayedObject.h"

class BaseLight
{
private:
	// ������� ��������� �����
	vec4 _position;
	// ������� ������������ ��������� �����
	vec4 _ambient;
	// ��������� ������������
	vec4 _diffuse;
	// ���������� ������������
	vec4 _specular;

public:
	// ������������
	BaseLight();
	BaseLight(vec3 position);
	BaseLight(float x, float y, float z);
	// ������� ��������� ���������� ��������� �����
	void SetPosition(vec3 position);
	void SetAmbient(vec4 color);
	void SetDiffuse(vec4 color);
	void SetSpecular(vec4 color);
	// ��������� ���� ���������� ��������� ����� � �������� �������
	// ������ ������� ������ ���������� ����� ��������� ������,
	// �.�. ����� ��������������� ������� ��������� �����
	void Apply(GLenum LightNumber = GL_LIGHT0);
};

