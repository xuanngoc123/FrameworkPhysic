#pragma once
#include"Object.h"
#include"Rect.h"
#include"Circle.h"
#include"Plane.h"
#include<vector>
#pragma warning(disable:4996)
class SceneManager {
public:
		SceneManager();
		~SceneManager();
		vector<Object*> listObj;
		void Update(float deltaTime);
		void Render();
		void AddObject(Object *object);
		void Init();
		void checkSelectionForDown(Object *obj,float x, float y);
		void checkSelectionForUp(Object *obj, float x, float y);
		void checkSelectionForMove(Object *obj, float x, float y);
		bool checkSelectionRect(Object *rect, float x, float y);
		bool checkSelectionCircle(Object *circle, float x, float y);
		void selectionDownMouseHandling(vector<Object*> listObj, float x, float y);
		void selectionUpMouseHandling(vector<Object*> listObj, float x, float y);
		void selectionMoveMouseHandling(vector<Object*> listObj, float x, float y);

};