#include<cmath>
#include<iostream>

struct vec3 {
	float x, y, z;
	vec3();
	vec3(float x_, float y_, float z_);
	vec3 operator+(const vec3& v)const;
	vec3 operator-(const vec3& v)const;
	vec3 operator*(float k)const;
	float mag();
	void normaliza();
	vec3 prodVetorial(vec3 v);
	void print();
};


struct vec2 {
	float x, y;
	vec2() :x(0.0), y(0.0) {}
	vec2(float x_, float y_) :x(x_), y(y_) {}
};

namespace vec {
	vec3 sub(vec3 u, vec3 v);
	float dist(vec3 u, vec3 v);
}