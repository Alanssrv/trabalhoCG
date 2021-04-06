#include "Camera.h"

Camera::Camera(float raio, float theta, float phi) {
	m_raio = raio;
	m_theta = theta;
	m_phi = phi;
	update();
}
 
Camera::~Camera() {
}

void Camera::ativar() {
	gluLookAt(
		m_position.getX(), m_position.getY(), m_position.getZ(),
		m_look.getX(), m_look.getY(), m_look.getZ(),
		0.0, 1.0, 0.0);
}

void Camera::forward() {
	Ponto dir = m_look;
	dir.normaliza();
	Ponto veloc = dir * (0.25);
	m_position = m_position + veloc;
	m_raio = m_position.mag();
}

void Camera::back() {
	Ponto dir = m_look;
	dir.normaliza();
	Ponto veloc = dir * (-0.25);
	m_position = m_position + veloc;
	m_raio = m_position.mag();
}

void Camera::updateTheta(float delta) {
	m_theta -= delta;
	update();
}

void Camera::updatePhi(float delta) {
	m_phi -= delta;
	if (m_phi < 1.f) m_phi = 1.f;
	if (m_phi > 150.f) m_phi = 150.f;
	update();
}

Ponto Camera::cvt2Cartesiano() {
	float aux = m_raio * Sen(m_phi);
	float x = aux * Sen(m_theta);
	float y = m_raio * Cos(m_phi);
	float z = aux * Cos(m_theta);
	Ponto result(x, y, z);
	
	return result;
}

void Camera::update() {
	m_position = cvt2Cartesiano();
	m_look = m_position * (-1.f);
}