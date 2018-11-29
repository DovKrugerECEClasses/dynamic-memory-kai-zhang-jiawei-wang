#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Vec3d {
private:
	T x,y,z;
public:
	Vec3d(T x, T y, T z): x(x), y(y), z(z){}
	friend ostream& operator << (ostream& s, const Vec3d& v){
		return s << '('<< v.x<<','<< v.y << ','<< v.z << ')';
	}
	friend Vec3d operator + (const Vec3d& first, const Vec3d& last){
		return Vec3d(first.x+last.x, first.y+last.y, first.z+last.z);
	}

};

