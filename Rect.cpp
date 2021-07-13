#include"Rect.h"

Rect::Rect(float x, float y, float width, float length, float velocity, float mass) {
	fposition[0] = x;
	fposition[1] = y;
	m_fWidth = width;
	m_fLength = length;
	iVelocity = (int)velocity;
	iMass = (int)mass;
	type = "RECT";
	time=0;
	iDrop = true;
}
Rect::~Rect(){

}
void Rect::Render() {
	VideoDriver::GetInstance()->DrawRect((int)fposition[0], (int)fposition[1], m_fWidth, m_fLength);

}
void Rect::HighLight() {
	VideoDriver::GetInstance()->DrawRect((int)fposition[0] - 1, (int)fposition[1] - 1, (int)m_fWidth - 2, (int)m_fLength - 2, (int)iMass);
}
float Rect::GetWidth() {
	return m_fWidth;
}
float Rect::GetHeight() {
	return m_fLength;
}
void Rect::Move(float x, float y) {
	fposition[0]=x - m_fWidth/2;
	fposition[1]=y - m_fLength/2;
}
void Rect::Update(float deltaTime) {
	if (fposition[0] < 0) {
		fposition[0]=0;
	}
	if (fposition[1] < 0) {
		fposition[1]=0;
	}
	if (fposition[0] >= SCREEN_W - m_fWidth) {
		fposition[0]= SCREEN_W - m_fWidth;
	}
	if (fposition[1] >= SCREEN_H - m_fLength) {
		fposition[1] = SCREEN_H - m_fLength;
	}
	//time += deltaTime;
	//iVelocity = G* time + iVelocity;
	fposition[1] += 1;
}
float Rect::GetRadius() {
	return 0;
}
