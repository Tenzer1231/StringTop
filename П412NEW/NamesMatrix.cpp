#include "NamesMatrix.h"

void NamesMatrix::allocate(unsigned int count, unsigned int rows, unsigned int cols)
{
	m_count = count;
	m_rows  = rows;
	m_cols  = cols;

	m_names = 0;
	m_matrix = 0;

	if (m_count > 0)
	{
		m_names = new String[m_count];
	}

	if (m_rows > 0 && m_cols > 0)
	{
		m_matrix = new String * [m_rows];
		for (unsigned int i = 0; i < m_rows; ++i)
		{
			m_matrix[i] = new String[m_cols];
		}
	}
}

void NamesMatrix::free_memory()
{
	if (m_matrix)
	{
		for (unsigned int i = 0; i < m_rows; ++i)
		{
			delete[] m_matrix[i];
		}
		delete[] m_matrix;
		m_matrix = 0;
	}

	if (m_names)
	{
		delete[] m_names;
		m_names = 0;
	}

	m_count = 0;
	m_rows  = 0;
	m_cols  = 0;
}

NamesMatrix::NamesMatrix()
{
	m_count  = 0;
	m_rows	 = 0;
	m_cols   = 0;
	m_names  = 0;
	m_matrix = 0;
}

NamesMatrix::NamesMatrix(unsigned int count, unsigned int rows, unsigned int cols) : NamesMatrix()
{
	allocate(count, rows, cols);
}

NamesMatrix::NamesMatrix(const NamesMatrix& other) : NamesMatrix(other.m_count, other.m_rows, other.m_cols)
{
	for (unsigned int i = 0; i < m_count; ++i)
	{
		m_names[i] = other.m_names[i];
	}

	for (unsigned int r = 0; r < m_rows; ++r)
	{
		for (unsigned int c = 0; c < m_cols; ++c)
		{
			m_matrix[r][c] = other.m_matrix[r][c];
		}
		
	}
}

NamesMatrix::~NamesMatrix()
{
	free_memory();
}

NamesMatrix& NamesMatrix::operator=(const NamesMatrix& other)
{
	if (this != &other)
	{
		free_memory();

		allocate(other.m_count, other.m_rows, other.m_cols);

		for (unsigned int i = 0; i < m_count; ++i)
		{
			m_names[i] = other.m_names[i];
		}

		for (unsigned int r = 0; r < m_rows; ++r)
		{
			for (unsigned int c = 0; c < m_cols; ++c)
			{
				m_matrix[r][c] = other.m_matrix[r][c];
			}

		}
	}

	return *this;
}

unsigned int NamesMatrix::get_count() const
{
	return m_count;
}

unsigned int NamesMatrix::get_rows() const
{
	return m_rows;
}

unsigned int NamesMatrix::get_cols() const
{
	return m_cols;
}

String& NamesMatrix::name(unsigned int index)
{
	if (index >= m_count)
	{
		return m_names[m_count - 1];
	}
	return m_names[index];
}

const String& NamesMatrix::name(unsigned int index) const
{
	if (index >= m_count)
	{
		return m_names[m_count - 1];
	}
	return m_names[index];
}

String& NamesMatrix::at(unsigned int row, unsigned int col)
{
	if (row >= m_rows)
	{
		row = m_rows - 1;
	}
	if (col >= m_cols)
	{
		col = m_cols - 1;
	}
	return m_matrix[row][col];
}

const String& NamesMatrix::at(unsigned int row, unsigned int col) const
{
	if (row >= m_rows)
	{
		row = m_rows - 1;
	}
	if (col >= m_cols)
	{
		col = m_cols - 1;
	}
	return m_matrix[row][col];
}

void NamesMatrix::fill_names(const String& prefix)
{
	for (unsigned int i = 0; i < m_count; ++i)
	{
		String idx_char('0' + (char)i);
		m_names[i] = prefix + "_" + idx_char;
	}
}

void NamesMatrix::fill_matrix(const String& prefix)
{
	for (unsigned int r = 0; r < m_rows; ++r)
	{
		for (unsigned int c = 0; c < m_cols; ++c)
		{
			String r_char('0' + (char)r);
			String c_char('0' + (char)c);
			m_matrix[r][c] = prefix + "_r" + r_char + "_c" + c_char;

		}
		
	}
}

void NamesMatrix::print(ostream& os) const
{
	os << "Names (" << m_count << "):" << endl;
	for (unsigned int i = 0; i < m_count; ++i)
	{
		os << "  [" << i << "] = " << m_names[i] << endl;
	}

	os << "Matrix (" << m_rows << " x " << m_cols << "):" << endl;
	for (unsigned int r = 0; r < m_rows; ++r)
	{
		for (unsigned int c = 0; c < m_cols; ++c)
		{
			os << m_matrix[r][c] << ' ';
		}
		os << endl;

	}
}
