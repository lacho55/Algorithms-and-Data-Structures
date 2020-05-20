#pragma once
#include<fstream>
#include <iostream>
#include <cstring>
#include <cassert>

#define INITIAL_CAPACITY 256

class String {
private:
	char* _data = nullptr;
	size_t _length = 0;
	size_t _capacity = 0;

	/*------------- Help Functions ------------*/

	void assign(const char*, size_t);
	void move(String&);
	void swap(String&);
	void concat(const char*, size_t);
	int  compare(const char*);


public:

	/* ----- Constructors ----- */

	String();
	String(char const*);
	String(String const&);                  //Copy constructor...
	String(String&&) noexcept;              //Move constructor...
	~String();

	String& operator=(const String&);       //Copy assignment operator...
	String& operator=(const char*);
	String& operator=(String&&) noexcept;   //Move assignment operator...


	/*-------- Accessors ---------*/

	char* c_str() const;
	const char& operator[](size_t) const;
	const char& front() const;
	const char& back() const;

	/* -------- Capacity -------- */

	bool empty() const;
	void clear();
	void erase();
	size_t capacity() const;
	size_t length() const;
	void reserve(size_t);
	void resize(size_t, char = '\0');


	/* ------- Modifiers ------- */

	void push_back(const char&);
	char pop_back();
	String& operator+=(const String&);
	String& operator+=(const char*);
	String operator+(char s);


	/*---------- Non-member function overloads -------------*/

	friend void swap(String&, String&);
	friend String operator+(const  String&, const String&);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	bool operator==(const String& other);
	bool operator==(const char* other);
	bool operator==(char* other);
	bool operator !=(const String& other);
	bool operator !=(const char* other);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
	friend std::ifstream& operator>>(std::ifstream&, String&);
	
};
