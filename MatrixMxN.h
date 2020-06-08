#pragma once
#include <iostream>
template<class T>
class MatrixMxN
{
private:
	int m;
	int n;
	T** elem;
public:
	MatrixMxN(int _m, int _n) : m(_m), n(_n) 
	{
		elem = new T*[m];
		for (size_t i = 0; i < m; i++)
			elem[i] = new T[n];

		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				elem[i][j] = 0;
	}

	T* operator[](const int &idx) { return elem[idx]; }
	T* operator[](const int &idx) const { return elem[idx]; }

	MatrixMxN operator+=(const MatrixMxN _second)
	{
		if (_second.m != m || _second.n != n)
		{
			std::cerr << "For Matrix addition, size for each other should be equal.\n";
			exit(-1);
		}
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				elem[i][j] += _second.elem[i][j];
		return *this;
	}

	MatrixMxN operator+(const MatrixMxN _second)
	{
		MatrixMxN<T> result(m, n);
		if (_second.m != m || _second.n != n)
		{
			std::cerr << "For Matrix addition, size for each other should be equal.\n";
			exit(-1);
		}
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				result[i][j] = elem[i][j] + _second.elem[i][j];
		return result;
	}

	//with simple method
	MatrixMxN operator*(const MatrixMxN _second)
	{
		if (this->n != _second.m)
		{
			std::cerr << "Matrix multiplication error, check the conditions";
			exit(-1);
		}
		MatrixMxN<T> result(m, _second.n);
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < _second.n; j++)
				for (size_t k = 0; k < this->n; k++)
					result[i][j] += this->elem[i][k] * _second[k][j];
		return result;
	}

	MatrixMxN operator*=(const MatrixMxN _second)
	{
		if (this->n != _second.m)
		{
			std::cerr << "Matrix multiplication error, check the conditions";
			exit(-1);
		}
		MatrixMxN<T> result(m, _second.n);
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < _second.n; j++)
				for (size_t k = 0; k < this->n; k++)
					result[i][j] += this->elem[i][k] * _second[k][j];
		return result;
	}
	
	void print()
	{
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
				std::cout << elem[i][j] << " ";
			std::cout << '\n';
		}
	}
};
