#include"Plane.h"


void Plane::Render() {
	VideoDriver::GetInstance()->DrawRect(0,0, (int)width, (int)height);
}
void Plane::HighLight() {
	VideoDriver::GetInstance()->DrawRect(1,1,(int)width-2, (int)height-2);
}
Plane::Plane() {
	type = "PLANE";
}
void Plane::Update(float deltaTime) {
	
}
float Plane::GetWidth() {
	return 0;
}
float Plane::GetHeight() {
	return 0;
}
float Plane::GetRadius() {
	return 0;
}
void Plane::Move(float, float) {

}
