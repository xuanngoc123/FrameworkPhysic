#pragma once
#include"videoDriver.h"
#include<iostream>
using namespace std;

class Object {
public:
	char* type;
	float fposition[2];
	int iMass;
	int iVelocity;
	bool iDrop = true;
	bool iSelect = false;
	float time = 0;
public:
	float* getPosition();
	void setPosition(float x, float y);
	int getMass() ;
	void setMass(int mass);
	int getVelocity();
	char *getType();
	void setVelocity(int velocity);
	
	virtual void Move(float, float)=0;
	virtual float GetWidth() =0;
	virtual float GetHeight() =0;
	virtual float GetRadius() =0;
	virtual void Render() = 0;
	virtual void HighLight() =0;
	virtual	void Update(float deltaTime) = 0;
};