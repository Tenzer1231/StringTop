#pragma once

#include <iostream>
using namespace std;

#include "String.h"

class NamesMatrix
{
private:
	unsigned int m_count;
	unsigned int m_rows;
	unsigned int m_cols;

	String* m_names;
	String** m_matrix;

	void allocate(unsigned int count, unsigned int rows, unsigned int cols);
	void free_memory();

public:
	NamesMatrix();
	NamesMatrix(unsigned int count, unsigned int rows, unsigned int cols);
	NamesMatrix(const NamesMatrix& other);
	~NamesMatrix();

	NamesMatrix& operator=(const NamesMatrix& other);

	unsigned int get_count() const;
	unsigned int get_rows() const;
	unsigned int get_cols() const;

	String&		  name(unsigned int index);
	const String& name(unsigned int index) const;

	String&		  at(unsigned int row, unsigned int col);
	const String& at(unsigned int row, unsigned int col) const;

	void fill_names (const String& prefix);
	void fill_matrix(const String& prefix);

	void print(ostream& os) const;
};

