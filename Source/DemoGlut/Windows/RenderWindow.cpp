#include "RenderWindow.h"

RenderWindow::RenderWindow(WindowSettings* settings)
{
	Camera = nullptr;
	_eventsFactory = new EventsFactory();
	_displayMode = settings->DisplayMode;
	_positionX = settings->PositionX;
	_positionY = settings->PositionY;
	_width = settings->Width;
	_height = settings->Height;
	_updateTime = settings->UpdateTime;
	_title = settings->Title;
}

void RenderWindow::Resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
	glutPostRedisplay();
}

void RenderWindow::Update(UpdateEventArgs* args)
{
	if (Camera != nullptr)
		Camera->Update(args);

	for (Entity* entity : _renderedEntities)
		entity->Update(args);
}

void RenderWindow::Render(RenderEventArgs* args)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	if (Camera != nullptr)
		Camera->Render(args);

	for (Entity* entity : _renderedEntities)
		entity->Render(args);

	glutSwapBuffers();
}

void RenderWindow::Display(void)
{
	UpdateEventArgs* updateArgs;
	RenderEventArgs* renderArgs;
	_eventsFactory->GetEventArgs(updateArgs, renderArgs);
	Update(updateArgs);
	Render(renderArgs);


	delete updateArgs;
	delete renderArgs;
}

int RenderWindow::GetUpdateTime()
{
	return _updateTime;
}

void RenderWindow::AddEntity(Entity* entity)
{
	_renderedEntities.push_back(entity);
}

void RenderWindow::SetCamera(BaseCamera* camera)
{
	Camera = camera;
}

void RenderWindow::Init()
{
	// ������������� ������� (������ ������)
	glutInitDisplayMode(_displayMode);

	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(_positionX, _positionY);
	// 2. ������������� ������ ����
	glutInitWindowSize(_width, _height);
	// 3. ������� ����
	glutCreateWindow(_title.c_str());

	//�������� ���� ��� ���� ������� � �� �������.
	glEnable(GL_DEPTH_TEST);

	_eventsFactory->UpdateState();
}