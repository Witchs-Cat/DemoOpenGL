#include <windows.h>

#include <iostream>
#include <vector>

#include <chrono>

#include "Entity.h"
#include "Cup.h"
#include "Teapot.h"
#include "Cube.h"
#include "Camera.h"

using namespace std;
using namespace glm;

const int mSIMULATION_TIME = 20;

int mCurrentTick = 0;

vector<Entity*> mEntities;

Camera mCamera;

long getCurrentTimeInMillis() {
	return std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
}

// �������, ���������� ��� ��������� �������� ����
void reshape(int w, int h)
{
	// ���������� ����� ������� ���������, ������ ���� ������� ����
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// ���������� ������� �������� � ���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// ������� ���������� ��� ����������� ����
// � ��� ����� � �������������, �� �������� glutPostRedisplay
void display(void)
{
	// �������� ����� ����� � ����� �������
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	float r = sin(mCurrentTick / 180.0f * 3.14159f);

	// �������� ���� �������
	glEnable(GL_DEPTH_TEST);
	// ������������� ������
	mCamera.requestLayout();
	//gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);

	for (Entity* en : mEntities) {
		//en->setAngle(mCurrentTick * 3.0f);
		//en->translate(r * 10, 0,0);
		//en->rotateXZ(mCurrentTick);
		en->render();
	}

	// ����� ��������� � ������� �������
	glutSwapBuffers();

	mCurrentTick++;
};

// ������� ���������� ������ 20 ��
void simulation(int value) {
	// ������������� ������� ����, ��� ���� ��������� � �����������
	glutPostRedisplay();
	// ��� �� ������� ����� ������� ��� ��� ����� 20 ��
	glutTimerFunc(mSIMULATION_TIME, simulation, 0);
};

// ������� ��������� ������� ������
void keyboardFunc(unsigned char key, int x, int y) {
	//printf("Key code is %i\n", key);
	
	switch (key) {
		case 'w':
			break;
		case 'a':
			break;
		case 's':
			break;
		case 'd':
			break;
	}
};


void main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	// ������������� ���������� GLUT
	glutInit(&argc, argv);
	// ������������� ������� (������ ������)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// �������� ����:
	// 1. ������������� ������� ����� ���� ����
	glutInitWindowPosition(0, 0);
	// 2. ������������� ������ ����
	glutInitWindowSize(1280, 720);
	// 3. ������� ����
	glutCreateWindow("Teapot");

	mCamera.setPosition(50,0,0);

	mEntities.push_back(new Teapot(2.0f));
	mEntities.push_back(new Cube(1.5f));
	mEntities.push_back(new Cup(2.5f));
	mEntities.push_back(new Teapot(1.5f));

	mEntities[0]->setPosition(5, 0, 0);
	mEntities[1]->setPosition(-5, 0, 0);
	mEntities[2]->setPosition(0, 0, 5);
	mEntities[3]->setPosition(0, 0, -5);

	// ��������� ������� ��������� ������
	// ������������� �������, ������� ����� ���������� ��� ����������� ����
	glutDisplayFunc(display);
	// ������������� �������, ������� ����� ���������� ��� ��������� �������� ����
	glutReshapeFunc(reshape);
	// ������������� �������, ������� ����� ������� ����� 20 ��
	glutTimerFunc(mSIMULATION_TIME, simulation, 0);
	// ������������� �������, ������� ����� ���������� ��� ������� �� �������
	glutKeyboardFunc(keyboardFunc);

	// �������� ���� ��������� ��������� ��
	glutMainLoop();


};