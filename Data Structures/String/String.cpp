
#include "String.h"

/* ------ Constructors --------*/

String::String() {
	reserve(INITIAL_CAPACITY);
}


String::String(const char* str) {
	assign(str, strlen(str));
}


String::String(String const& other) {
	assign(other._data, other._length);
}


String::String(String&& other) noexcept {
	move(other);
}


String::~String() {
	delete[] _data;
}


String& String::operator=(const String& other) {
	if (this != &other) {
		assign(other.c_str(), other.length());
	}

	return *this;
}


String& String::operator=(const char* str) {
	assign(str,strlen(str));
	return *this;
}


String& String::operator=(String&& other) noexcept {
	if (this != &other) {
		delete[] _data;
		move(other);
	}
	return *this;
}


/* ------- Accessors --------- */

const char* String::c_str() const {
	return _data;
}


const char& String::operator[](size_t index) const {
	if (index < 0 || index >= _length) throw std::out_of_range("Out of range exception");
	return *(_data + index);
}


const char& String::front() const {
	return operator[](0);
}


const char& String::back() const {
	return operator[](_length - 1);
}

/* -------- Capacity ---------*/

bool String::empty() const {
	return (_length == 0);
}


void String::clear() {
	_data = nullptr;
	_length = 0;
	_capacity = 0;
}


size_t String::length() const {
	return _length;
}


size_t String::capacity() const {
	return _capacity;
}


void String::reserve(size_t n) {
	if (n <= _capacity)
		return;
	char* temp = new char[n];
	if (_data != nullptr) {
		for (int i = 0; i < _length; i++) {
			temp[i] = _data[i];
		}
		delete[] _data;
	}

	_data = temp;
	_capacity = n;
}


void String::resize(size_t new_size, char val) {

	reserve(new_size);

	for (size_t i = _length; i < new_size; i++) {
		_data[i] = val;
	}
	_length = new_size;
}


/* ------- Help Functions ------- */

void String::assign(const char* str, const size_t n) {
	_length = n;
	reserve(n + INITIAL_CAPACITY);
	strcpy_s(_data, _length + 1, str);
	_data[_length + 1] = '\0';
}


void String::move(String& other) {
	_length = other._length;
	_capacity = other._capacity;
	_data = other._data;
	other.clear();
}


void String::swap(String& S) {
	String T;
	T.move(*this);
	(*this).move(S);
	S.move(T);
}


void String::concat(const char* str, size_t n) {
	if (_capacity - _length < n) {
		reserve(n + INITIAL_CAPACITY);
	}
	for (int i = 0; i < n; i++) {
		_data[_length + i] = str[i];
	}
	_length += n;
	_data[_length + 1] = '\0';
}


int String::compare(const char* str) {
	return strcmp(_data, str);
}


/* ------ Modifiers ------*/

void String::push_back(const char& val) {
	if (_capacity == 0 || !_data) {
		reserve(INITIAL_CAPACITY);
	}
	else if (_length == _capacity) {
		reserve(2*_capacity);
	}

	
	_data[_length++] = val;
}


char String::pop_back() {
	if (_length == 0) 
		return '\0';

	char c = _data[_length - 1];
	_data[_length - 1] = '\0';
	_length--;

	return c;
}


String& String::operator+=(const char* str) {
	concat(str, strlen(str));
	return *this;
}


String& String::operator+=(const String& other) {
	concat(other.c_str(), other.length());
	return *this;
}


/*---------- Non-member function overloads -------------*/

void swap(String& S, String& T) {
	S.swap(T);
}


String operator+(const String& obj1, const String& obj2) {
	String temp = obj1;
	temp += obj2;
	return temp;
}


String operator+(const String& object, const char* str) {
	String temp = object;
	temp += str;
	return temp;
}

String operator+(const char* str, const String& object) {
	String temp;
	temp += str;
	temp += object;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.c_str();
	return out;
}

std::istream& operator>>(std::istream& in, String& str) {
	str.clear();
	char c;
	do {
		c = in.get();
		if (c == '\n')
			break;
		str.push_back(c);
	} while (true);

	return in;
}
