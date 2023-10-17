#pragma once

#include "WindowSettings.h"
#include "../Entities/Entity.h"
#include "../EventArgs/EventsFactory.h"
#include "../Camera/MovingCamera.h"
#include "../Lights/BaseLight.h"

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

	string _title;
	
	list<shared_ptr<Entity>> _renderedEntities;
	shared_ptr<BaseCamera> _camera;
	shared_ptr<BaseLight> _light;

	unsigned short int _framesCount;
	double _elapsedMilliseconds;


public:
	//���������, ��� �� ��������� ������ ������, 
	//�� ������� ������ �������� �� nullptr

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

	void AddEntity(shared_ptr<Entity> entity);

	void SetCamera(shared_ptr<BaseCamera> camera);
	void SetLigth(shared_ptr<BaseLight> ligth);

	void Display(void);

	int GetUpdateTime();

private:
	void CalculateFPS(RenderEventArgs* args);
};

