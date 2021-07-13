#pragma once
#include "Object.h"
#include"videoDriver.h"

class Rect: public Object
{
public:
	Rect(float x, float y, float width, float length, float velocity, float mass);
	~Rect();
	void Render();
	void HighLight();
	float GetWidth();
	float GetHeight();
	void Move(float, float);
	void Update(float deltaTime);

	float GetRadius();
private:
	float m_fWidth;
	float m_fLength;
};

