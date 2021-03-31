#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <Windows.h>
#include <gl/GLU.h>
#include "Ponto.h"
#include <cmath>
 
class Camera {
	private:
		float m_raio;
		float m_phi;
		float m_theta;
		Ponto m_position;
		Ponto m_look;
		const float PI = 3.14159265359;

	public:
		Camera(float raio, float theta, float phi);
		~Camera();
		void ativar();
		void forward();
		void back();
		void UpdateTheta(float delta);
		void UpdatePhi(float delta);
	private:
		Ponto cvt2Cartesiano();
		inline float Sen(float ang) { return sin(ang*PI / 180.f); }
		inline float Cos(float ang) { return cos(ang*PI / 180.f); }
		void update();
};

#endif //CAMERA_H