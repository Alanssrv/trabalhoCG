#include "Camera.h"

Camera::Camera(float raio, float theta, float phi)
{
	m_raio = raio;
	m_theta = theta;
	m_phi = phi;
	update();
}
 
Camera::~Camera()
{
}

void Camera::Ativar()
{
	gluLookAt(
		m_position.x, m_position.y, m_position.z,
		m_look.x, m_look.y, m_look.z,
		0.0, 1.0, 0.0);
}

void Camera::Forward()
{
	vec3 dir = m_look;
	dir.normaliza();
	vec3 veloc = dir * (0.25);
	m_position = m_position + veloc;
	m_raio = m_position.mag();
}

void Camera::Back()
{
	vec3 dir = m_look;
	dir.normaliza();
	vec3 veloc = dir * (-0.25);
	m_position = m_position + veloc;
	m_raio = m_position.mag();
}

void Camera::UpdateTheta(float delta)
{
	m_theta -= delta;
	update();
}

void Camera::UpdatePhi(float delta)
{
	m_phi -= delta;
	if (m_phi < 1.f) m_phi = 1.f;
	if (m_phi > 150.f) m_phi = 150.f;
	update();
}

vec3 Camera::cvt2Cartesiano()
{
	float aux = m_raio * Sen(m_phi);
	float x = aux * Sen(m_theta);
	float y = m_raio * Cos(m_phi);
	float z = aux * Cos(m_theta);
	vec3 result(x, y, z);
	
	return result;
}

void Camera::update()
{
	m_position = cvt2Cartesiano();
	m_look = m_position * (-1.f);
}