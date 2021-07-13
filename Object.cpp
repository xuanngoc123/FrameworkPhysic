#include"Object.h"

float* Object::getPosition() {
	
	return fposition;
}
void Object::setPosition(float x, float y){
	fposition[0] = x;
	fposition[1] = y;
}
int Object::getMass() {
	return iMass;
}
void Object::setMass(int mass) {
	iMass = mass;
}
int Object::getVelocity() {
	return iVelocity;
}
void Object::setVelocity(int velocity) {
	iVelocity = velocity;
}
char* Object::getType() {
	return type;
}