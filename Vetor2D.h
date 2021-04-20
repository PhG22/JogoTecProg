#pragma once
#include <cmath>
#include <ostream>
using namespace std;

namespace gerenciadorGrafico {
	template<typename T>
	class Vetor2D
	{
	public:
		T x, y;

		Vetor2D(T X = 0.0, T Y = 0.0) : x(X), y(Y) {}
		~Vetor2D() {}

		Vetor2D operator+(Vetor2D v) const;
		Vetor2D operator-(Vetor2D v) const;
		Vetor2D operator*(int i) const;
		Vetor2D operator*(float f) const;
		Vetor2D operator*(double d) const;
		T operator*(Vetor2D v) const;
		T modulo() const;
		Vetor2D versor() const;
		//projeta esse vetor na direção de v
		Vetor2D projOrtogonal(Vetor2D v) const;
	};

	typedef Vetor2D<float> Vetor2F;
	typedef Vetor2D<unsigned> Vetor2U;
	typedef Vetor2D<int> Vetor2I;

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator+(Vetor2D v) const {
		return Vetor2D<T>(x + v.x, y + v.y);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator-(Vetor2D v) const {
		return Vetor2D<T>(x - v.x, y - v.y);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(int i) const {
		return Vetor2D<T>(x * i, y * i);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(float f) const {
		return Vetor2D<T>(x * f, y * f);
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::operator*(double d) const {
		return Vetor2D<T>(x * d, y * d);
	}

	template<typename T>
	T Vetor2D<T>::operator*(Vetor2D v) const {
		return (x * v.x) + (y * v.y);
	}

	template<typename T>
	T Vetor2D<T>::modulo() const {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::versor() const {
		return this->operator*(1.0 / modulo());
	}

	template<typename T>
	Vetor2D<T> Vetor2D<T>::projOrtogonal(Vetor2D v) const {
		return v * (this->operator*(v) / pow(v.modulo(), 2));
	}

	template<typename T>
	ostream& operator<<(ostream& out, const Vetor2D<T> v){
		out << "(" << v.x << " , " << v.y << ")";

		return out;
	}
}