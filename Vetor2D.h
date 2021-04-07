#pragma once
#include <cmath>

namespace gerenciadorGrafico {
	template<typename T>
	class Vetor2D
	{
	public:
		T x, y;

		Vetor2D(T X = 0.0, T Y = 0.0) : x(X), y(Y) {}
		~Vetor2D() {}

		Vetor2D operator+(Vetor2D v);
		Vetor2D operator-(Vetor2D v);
		Vetor2D operator*(int i);
		Vetor2D operator*(float f);
		Vetor2D operator*(double d);
		T operator*(Vetor2D v);
		T modulo();
		Vetor2D versor();
		//projeta esse vetor na direção de v
		Vetor2D projOrtogonal(Vetor2D v);
	};

	typedef Vetor2D<float> Vetor2F;
	typedef Vetor2D<unsigned> Vetor2U;
	typedef Vetor2D<int> Vetor2I;

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator+(Vetor2D v) {
		return Vetor2D<T>(x + v.x, y + v.y);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator-(Vetor2D v) {
		return Vetor2D<T>(x - v.x, y - v.y);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(int i) {
		return Vetor2D<T>(x * i, y * i);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(float f) {
		return Vetor2D<T>(x * f, y * f);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(double d) {
		return Vetor2D<T>(x * d, y * d);
	}

	template<typename T>
	T Vetor2D<T>::operator*(Vetor2D v) {
		return (x * v.x) + (y * v.y);
	}

	template<typename T>
	T Vetor2D<T>::modulo() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::versor() {
		return this->operator*(1.0 / modulo());
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::projOrtogonal(Vetor2D v) {
		return v * (this->operator*(v) / pow(v.modulo(), 2));
	}
}