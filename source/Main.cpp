#include <stdio.h>
#include "esUtil.h"
#include "log.h"
#include "define.h"
#include "VideoDriver.h"
#include "../Object.h"
#include"../SceneManager.h"
#include"../CollisionManager.h"
#include <crtdbg.h>
#pragma warning(disable:4996)
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

SceneManager *gSM = new SceneManager();
CollisionManager *gCM = new CollisionManager();

float positionMouse[2];

void PaintObject()
{
	// Limit FPS
	DWORD start, end;
	start = GetTickCount();

	// Render something here
	
	gSM->Render();
	

	// Limit FPS
	end = GetTickCount();
	DWORD frameTime = end - start;
	if (frameTime < 1000.0/LIMIT_FPS)
		Sleep(1000/LIMIT_FPS - frameTime);
}

bool InitGraphics(int w, int h)
{
	// Init scene
	LOGI("Initializing...");
	glViewport(0, 0, w, h);
	LOGI("Done1!");
	return true;
}

void TouchActionDown(ESContext *esContext,int x, int y)
{
	positionMouse[0]=x;
	positionMouse[1]=y;

	gSM->selectionDownMouseHandling(gSM->listObj, x, y);
	
	// Mouse down
}

void TouchActionUp(ESContext *esContext,int x, int y)
{
	gSM->selectionUpMouseHandling(gSM->listObj, x, y);
	
	// Mouse up
}

void TouchActionMove(ESContext *esContext,int x, int y)
{
	gSM->selectionMoveMouseHandling(gSM->listObj, x, y);
	
	// Mouse move
}

void KeyDown(ESContext *ESContext, unsigned char keyCode, int x, int y)
{
	switch (keyCode)
	{
	case 'W':
	case 'w':
		break;
	case 'S': 
	case 's': 
		break;
	case 'A':
	case 'a':
		break;
	case 'D':
	case 'd':
		break;
	}
}

void KeyUp(ESContext *ESContext, unsigned char keyCode, int x, int y)
{
	switch (keyCode)
	{
	case 'W':
	case 'w':
		break;
	case 'S':
	case 's':
		break;
	case 'A':
	case 'a':
		break;
	case 'D':
	case 'd':
		break;
	}
}

void GameUpdate(ESContext *esContext, float deltaTime)
{
	VideoDriver::GetInstance()->CleanScreen();
	gCM->checkCollision(gSM->listObj);
	gSM->Update(deltaTime);
}

void GameDraw(ESContext *esContext)
{
	// Draw scene then swap buffer to display to screen
	PaintObject();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void GameExit()
{
	// Cleanup memory here
}

int main(int argc, char *argv[])
{
	gSM->Init();
	ESContext esContext;
	esInitContext(&esContext );

	esCreateWindow(&esContext, "Framework", (int)SCREEN_W, (int)SCREEN_H, ES_WINDOW_RGB);
	if (!InitGraphics((int)SCREEN_W, (int)SCREEN_H))
		return 0;

	esRegisterDrawFunc(&esContext, GameDraw);
	esRegisterKeyDownFunc(&esContext, KeyDown);
	esRegisterKeyUpFunc(&esContext, KeyUp);
	esRegisterUpdateFunc(&esContext, GameUpdate);
	esRegisterMouseDownFunc(&esContext, TouchActionDown);
	esRegisterMouseUpFunc(&esContext, TouchActionUp);
	esRegisterMouseMoveFunc(&esContext, TouchActionMove);
	esMainLoop(&esContext);
	GameExit();
}