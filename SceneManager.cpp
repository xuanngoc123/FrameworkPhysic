#include"SceneManager.h"
#include<vector>
#include<math.h>
#include<iostream>

#pragma warning(disable:4996)
using namespace std;
SceneManager::SceneManager() {

}
SceneManager::~SceneManager() {

}
void SceneManager::Init() {
	FILE * f;
	int objNum;
	int id;
	f = fopen("SceneManager.txt", "r");
	//ifstream f("SceneManager.txt");
	fscanf(f, "#OBJECT_NUM %d\n", &objNum);
	
	for (int i = 0; i < objNum; i++) {
		fscanf(f,"#ID %d\n" , &id);
		cout << "id: " << id;
		float x, y, width, height, radius, velocity;
		char type[10];
		fscanf(f, "TYPE: %s\n" , type);
		Object *obj;
		if (strcmp(type, "RECT")==0) {
			fscanf(f, "POSITION: %f, %f, %f, %f\n", &x, &y, &width, &height);
			fscanf(f, "VELOCITY: %f\n", &velocity);
			obj = new Rect(x,y,width,height,velocity,0.5);
		}
		else if (strcmp(type, "CIRCLE") == 0) 
		{
			fscanf(f, "POSITION: %f, %f, %f\n", &x, &y, &radius);
			fscanf(f, "VELOCITY: %f\n", &velocity);
			obj = new Circle(x,y,radius,velocity,1);
		}
		AddObject(obj);

	}
	Object *a = new Plane();
	a->type = "PLANE";
	AddObject(a);
}
void SceneManager::AddObject(Object *obj) {
	listObj.push_back(obj);
}
void SceneManager::Update(float deltaTime) {
	for (int i = 0; i < listObj.size(); i++)
	{
		if(listObj.at(i)->iDrop==true)
			listObj.at(i)->Update(deltaTime);
	}
}
void SceneManager::Render() {
	for (int i = 0; i < listObj.size(); i++)
	{
		listObj.at(i)->Render();
	}
}

void SceneManager::selectionDownMouseHandling(vector<Object*> listObj, float x, float y) {
	for (int i = 0; i < listObj.size(); i++) {
		checkSelectionForDown(listObj.at(i), x, y);
	}
}
void SceneManager::selectionUpMouseHandling(vector<Object*> listObj, float x, float y) {
	for (int i = 0; i < listObj.size(); i++) {
		checkSelectionForUp(listObj.at(i), x, y);
	}
}
void SceneManager::selectionMoveMouseHandling(vector<Object*> listObj, float x, float y) {
	for (int i = 0; i < listObj.size(); i++) {
		checkSelectionForMove(listObj.at(i), x, y);
	}
}
void SceneManager::checkSelectionForDown(Object *obj, float x, float y) {
	
	if (strcmp(obj->type, "RECT") == 0) {
		if (checkSelectionRect(obj, x, y)) {
			obj->iDrop = false;
			obj->iVelocity = 0;
			obj->time = 0;
			obj->fposition[0] = x - obj->GetWidth()/2;
			obj->fposition[1] = y - obj->GetWidth() / 2;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (checkSelectionCircle(obj, x, y)) {
			obj->iDrop = false;
			obj->iVelocity = 0;
			obj->time = 0;
			obj->fposition[0] = x;
			obj->fposition[1] = y;
		}
		
	}
}
void SceneManager::checkSelectionForUp(Object *obj, float x, float y) {

	if (strcmp(obj->type, "RECT") == 0) {
		if (checkSelectionRect(obj, x, y)) {
			obj->iDrop = true;
			obj->iVelocity = 0;
			obj->time = 0;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (checkSelectionCircle(obj, x, y)) {
			obj->iDrop = true;
			obj->iVelocity = 0;
			obj->time = 0;
		}
	}

}
void SceneManager::checkSelectionForMove(Object *obj, float x, float y) {
	if (strcmp(obj->type, "RECT") == 0) {
		if (checkSelectionRect(obj, x, y)) {
			obj->iDrop = false;
			obj->Move(x,y);
			obj->iVelocity = 0;
			obj->time = 0;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (checkSelectionCircle(obj, x, y)) {
			obj->iDrop = false;
			obj->Move(x, y);
			obj->iVelocity = 0;
			obj->time = 0;
		}

	}
}
bool SceneManager::checkSelectionRect(Object *rect, float x, float y) {
	if ((x > rect->fposition[0] && x < rect->fposition[0] + rect->GetHeight()) && (y > rect->fposition[1] && y < rect->fposition[1] + rect->GetWidth())) {
		return true;
	}
	return false;
}
bool SceneManager::checkSelectionCircle(Object *circle, float x, float y) {
	float kc = sqrt((x - circle->fposition[0])*(x - circle->fposition[0]) + (y - circle->fposition[1])*(y - circle->fposition[1]));
		if(kc < circle->GetRadius()) return true;
	return false;
}