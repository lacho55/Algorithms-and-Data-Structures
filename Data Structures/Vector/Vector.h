#pragma once
#include <iostream>
#include <cassert>
using namespace std;

#define INITIAL_CAPACITY 64

template<typename T>
class Vector
{
private:
	T* _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;


	/* ------ Help Functions ------- */
	void assign(size_t n, T = T());
	void assign(T* data, size_t n);
	void move(Vector& other) const;

public:
	/*----- Constructors ------*/
	Vector();
	Vector(size_t n, T = T());
	Vector(const Vector& other); //Copy constructor
	Vector(const Vector&& other) noexcept; //Move constructor
	~Vector();

	Vector& operator=(const Vector& other); //copy assign operator
	Vector& operator=(const Vector&& other) noexcept; //move assign operator


	/* ------- Accessors ---------*/
	T* data() const;
	T& operator[](size_t index) const;
	const char& front() const;
	const char& back() const;


	/* ------ Capacity --------*/
	bool empty() const;
	void clear();
	void erase();
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	void resize(size_t new_size, T = T());
	void print() const;

	/* ----- Modifiers ------ */
	void push_back(const T& val);
	void removeAtIndex(int index);
	void removeElement(const T& element);
	T pop_back();
	void swap(Vector& other);

};