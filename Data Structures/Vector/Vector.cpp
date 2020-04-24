#include "Vector.h"

/* ------ Constructors --------*/
template<typename T>
Vector<T>::Vector() {
	reserve(INITIAL_CAPACITY);
}


template<typename T>
Vector<T>::Vector(size_t n, T val) {
	assign(n, val);
}


template<typename T>
Vector<T>::Vector(const Vector& other) {
	assign(other._data, other._size);
}


template<typename T>
Vector<T>::Vector(const Vector&& other) noexcept{
	move(other);
}


template<typename T>
Vector<T>::~Vector() {
	delete[] _data;
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
	if (this != &other) {
		assign(other._data, other._size);
	}
	return *this;
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector&& other) noexcept{
	if (this != &other) {
		delete[] _data;
		move(other);
	}

	return *this;
}



/* ------- Help Functions --------*/
template<typename T>
void Vector<T>::assign(size_t n, T val) {
	_size = n;
	reserve(_size);
	for (int i = 0; i < _size; i++) {
		_data[i] = val;
	}
}


template<typename T>
void Vector<T>::assign(T* data, size_t n) {
	_size = n;
	reserve(n);
	for (int i = 0; i < _size; i++) {
		_data[i] = data[i];
	}
}


template<typename T>
void Vector<T>::move(Vector& other) const {
	_size = other._size;
	_capacity = other._capacity;
	_data = other._data;
	other.clear();
}



/* --------- Accessors ------------*/
template<typename T>
T* Vector<T>::data() const {
	return _data;
}


template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	if(index < 0 || index >= _size) throw std::out_of_range("Out of range exception");
	return *(_data + index);
}


template<typename T>
const char& Vector<T>::front() const {
	return operator[](0);
}


template<typename T>
const char& Vector<T>::back() const {
	return operator[](_size - 1);
}



/* ------ Capacity ------*/
template<typename T>
bool Vector<T>::empty() const {
	return (_size == 0);
}


template<typename T>
void Vector<T>::clear() {
	_data = nullptr;
	_size = 0;
	_capacity = 0;
}


template<typename T>
size_t Vector<T>::capacity() const {
	return _capacity;
}


template<typename T>
size_t Vector<T>::size() const {
	return _size;
}


template<typename T>
void Vector<T>::reserve(size_t n) {
	if (n <= _capacity)
		return;
	T* temp = new T[n];
	if (_data != nullptr) {
		for (int i = 0; i < _size; i++) {
			temp[i] = _data[i];
		}
		delete[] _data;
	}
	_data = temp;
	_capacity = n;

}


template<typename T>
void Vector<T>::resize(size_t new_size, T val) {

	reserve(new_size);

	for (size_t i = _size; i < new_size; i++) {
		_data[i] = val;
	}
	_size = new_size;
}



/* ----- Modifiers ------ */
template<typename T>
void Vector<T>::swap(Vector& other) {
	Vector<T> temp;
	temp.move(*this);
	(*this).move(other);
	other.move(temp);
}


template<typename T>
void Vector<T>::push_back(const T& val) {
	if (_capacity == 0 || !_data) {
		reserve(INITIAL_CAPACITY);
	}
	else if (_size == _capacity) {
		reserve(2 * _capacity);
	}

	_data[_size++] = val;
}


template<typename T>
T Vector<T>::pop_back() {
	if (_size == 0)
		return '\0';
	T c = _data[_size - 1];
	_data[_size - 1] = '\0';
	_size--;

	return c;
}
