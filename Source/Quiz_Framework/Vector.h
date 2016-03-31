#pragma once

/********************************************************************
**                                                                 **
**     Vector3 <Template>                    -Trial ver-           **
**                                                                 **
**          Created by Ending2012 (103062372) on 2016/3/18         **
**                                                                 **
**        Copyright (c) 2015 Ending's APP. All rights reserved.    **
**                                                                 **
*********************************************************************/

#include<cmath>

template <typename TYPE>
class Vector3{

public:
	TYPE v[3];

	Vector3(){ v[0] = v[1] = v[2] = TYPE(0); }
	Vector3(TYPE x, TYPE y, TYPE z){
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}

	Vector3(Vector3 &v2){
		v[0] = v2.v[0];
		v[1] = v2.v[1];
		v[2] = v2.v[2];
	}

	Vector3 &operator=(Vector3 &v2){
		for (int i = 0; i < 3; i++)(*this)[i] = v2[i];
		return (*this);
	}

	Vector3 &operator-=(Vector3 &v2){
		for (int i = 0; i < 3; i++)(*this)[i] -= v2[i];
		return (*this);
	}

	TYPE & operator[](int j){
		if (j >= 2)return v[2];
		if (j <= 0)return v[0];
		return v[j];
	}

	TYPE operator*(Vector3 &v2){
		return (v[0] * v2[0] + v[1] * v2[1] + v[2] * v2[2]);
	}

	Vector3 operator/(Vector3 &v2){
		Vector3<TYPE> ans;
		ans[0] = v[1] * v2[2] - v2[1] * v[2];
		ans[1] = -v[0] * v2[2] + v2[0] * v[2];
		ans[2] = v[0] * v2[1] - v2[0] * v[1];
		return ans;
	}

	TYPE norm(){
		return sqrt(this->operator*(*this));
	}

	Vector3 &normalize(){
		TYPE n = this->norm();
		(*this)[0] /= n; (*this)[1] /= n; (*this)[2] /= n;
		return *this;
	}

	template<typename T>
	friend Vector3<T> normalize(T x, T y, T z);

	Vector3 &operator+=(Vector3 &v2){
		(*this)[0] += v2[0];
		(*this)[1] += v2[1];
		(*this)[2] += v2[2];
		return *this;
	}

	TYPE * toArray(){
		return &v[0];
	}

	Vector3 &operator*(int c){
		(*this)[0] = c*(*this)[0];
		(*this)[1] = c*(*this)[1];
		(*this)[2] = c*(*this)[2];
		return *this;
	}

	Vector3 &operator*(GLfloat c){
		(*this)[0] = c*(*this)[0];
		(*this)[1] = c*(*this)[1];
		(*this)[2] = c*(*this)[2];
		return *this;
	}

	Vector3 & coord(int x, int y, int z){
		(*this)[0] = x*(*this)[0];
		(*this)[1] = y*(*this)[1];
		(*this)[2] = z*(*this)[2];
		return *this;
	}

};


template<typename T>
Vector3<T> normalize(T x, T y, T z){
	Vector3<T> v2(x, y, z);
	T n = v2.norm();
	if (n == 0)n = 1;
	v2[0] /= n; v2[1] /= n; v2[2] /= n;
	return v2;
}