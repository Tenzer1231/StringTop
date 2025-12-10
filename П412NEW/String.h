#pragma once

#include <iostream>
using namespace std;

class String
{
private:
	char* m_data;
	unsigned int m_length;

	static unsigned int str_length(const char* s);
	static int			str_compare(const char* a, const char* b);
	static void			str_copy(char* destination, unsigned int destinationSize, const char* source);
	static void			str_concat(char* destination, unsigned int destinationSize, const char* source);

	void set_from_cstring(const char* s);

public:
	String();
	String(const char* s);
	String(char c);
	String(const String& other);

	~String();

	String& operator=(const String& other);
	String& operator=(const char* s);

	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;

	unsigned int size()  const;
	bool		 empty() const;
	const char* c_str() const;
	void		 clear();

	void push_back(char c);
	void pop_back();

	int compare(const String& other) const;
	int compare(const char* s) const;

	String substr(unsigned int start, unsigned int count) const;
	int	   find(char c) const;
	int	   find(const String& part) const;
	int    find(const char* part) const;

	bool starts_with(const String& prefix) const;
	bool ends_with(const String& suffix) const;

	void to_upper();
	void to_lower();
	void trim();
	void reverse();

	String& operator+=(const String& other);
	String& operator+=(const char* s);
	String& operator+=(char c);

	friend String operator+(const String& a, const String& b);
	friend String operator+(const String& a, const char* b);
	friend String operator+(const char* a, const String& b);
	friend String operator+(const String& a, char b);
	friend String operator+(char a, const String& b);

	friend bool operator==(const String& a, const String& b);
	friend bool operator!=(const String& a, const String& b);
	friend bool operator<(const String& a, const String& b);
	friend bool operator<=(const String& a, const String& b);
	friend bool operator>(const String& a, const String& b);
	friend bool operator>=(const String& a, const String& b);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};