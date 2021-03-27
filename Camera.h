#pragma once
#include<Windows.h>
#include<gl/GLU.h>
#include"Vetor.h"
#include<cmath>
 
class Camera
{
private:
	float m_raio;
	float m_phi;
	float m_theta;
	vec3 m_position;
	vec3 m_look;
	const float PI= 3.14159265359;

public:
	Camera(float raio, float theta, float phi);
	~Camera();
	void Ativar();
	void Forward();
	void Back();
	void UpdateTheta(float delta);
	void UpdatePhi(float delta);
private:
	vec3 cvt2Cartesiano();
	inline float Sen(float ang) { return sin(ang*PI / 180.f); }
	inline float Cos(float ang) { return cos(ang*PI / 180.f); }
	void update();
};