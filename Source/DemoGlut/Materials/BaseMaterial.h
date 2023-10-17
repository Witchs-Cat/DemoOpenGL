#pragma once
#include "..\IDisplayedObject.h"

using namespace YAML;

class BaseMaterial
{
private:
	// ������� ������������
	vec4 _ambient;
	// ��������� ������������
	vec4 _diffuse;
	// ���������� ������������
	vec4 _specular;
	// ������������
	vec4 _emission;
	// ������� ����������������
	float _shininess;

public:
	// ����������� �� ���������
	BaseMaterial();
	BaseMaterial(
		vec4 ambient,vec4 diffuse,
		vec4 specular,vec4 emission,
		float shininess);

	// �������� ���������� ��������� �� �������� ���������� �����
	static shared_ptr<BaseMaterial> LoadFromYaml(std::string filename);
	// ������� ���������� ���������
	void SetAmbient(vec4 color);
	void SetDiffuse(vec4 color);
	void SetSpecular(vec4 color);
	void SetEmission(vec4 color);
	void SetShininess(float p);
	// ��������� ���� ���������� ���������
	void Apply();
};

