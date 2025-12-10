#include "String.h"

unsigned int String::str_length(const char* s)
{
	if (!s)
	{
		return 0;
	}

	unsigned int len = 0;

	while (s[len] != '\0')
	{
		++len;
	}
	return len;
}

int String::str_compare(const char* a, const char* b)
{
	if (a == b)
	{
		return 0;
	}

	if (!a)
	{
		a = "";
	}

	if (!b)
	{
		b = "";
	}

	unsigned int i = 0;

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] < b[i])
		{
			return -1;
		}
		if (a[i] > b[i])
		{
			return 1;
		}
		++i;
	}

	if (a[i] == '\0' && b[i] == '\0')
	{
		return 0;
	}
	else if (a[i] == '\0')
	{
		return -1;
	}
	else
	{
		return 1;
	}

}

void String::str_copy(char* destination, unsigned int destinationSize, const char* source)
{
	if (!destination || destinationSize == 0)
	{
		return;
	}

	if (!source)
	{
		destination[0] = '\0';
		return;
	}

	unsigned int i = 0;

	while (i + 1 < destinationSize && source[i] != '\0')
	{
		destination[i] = source[i];
		++i;
	}
	destination[i] = '\0';
}

void String::str_concat(char* destination, unsigned int destinationSize, const char* source)
{
	if (!destination || destinationSize == 0)
	{
		return;
	}

	unsigned int destLen = str_length(destination);

	if (destLen + 1 >= destinationSize)
	{
		if (destinationSize > 0)
		{
			destination[destinationSize - 1] = '\0';
		}
		return;
	}

	if (!source)
	{
		return;
	}

	unsigned int i = 0;

	while (destLen + i + 1 < destinationSize && source[i] != '\0')
	{
		destination[destLen + i] = source[i];
		++i;
	}
	destination[destLen + i] = '\0';

}

void String::set_from_cstring(const char* s)
{
	m_length = str_length(s);

	char* newData = new char[m_length + 1];
	if (!newData)
	{
		m_data = new char[1];
		if (m_data)
		{
			m_data[0] = '\0';
		}
		m_length = 0;
		return;
	}

	str_copy(newData, m_length + 1, s);

	if (m_data)
	{
		delete[] m_data;
	}

	m_data = newData;
}

String::String()
{
	m_data = new char[1];
	if (m_data)
	{
		m_data[0] = '\0';
	}
	m_length = 0;
}

String::String(const char* s)
{
	m_data = 0;
	m_length = 0;
	set_from_cstring(s);
}

String::String(char c)
{
	m_data = new char[2];
	if (m_data)
	{
		m_data[0] = c;
		m_data[1] = '\0';
		m_length = 1;
	}
	else
	{
		m_length = 0;
	}
}

String::String(const String& other)
{
	m_data = 0;
	m_length = 0;
	set_from_cstring(other.m_data);
}

String::~String()
{
	if (m_data)
	{
		delete[]m_data;
		m_data = 0;
	}
	m_length = 0;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		set_from_cstring(other.m_data);
	}
	return *this;
}

String& String::operator=(const char* s)
{
	set_from_cstring(s);
	return *this;
}

char& String::operator[](unsigned int index)
{
	if (index >= m_length)
	{
		if (m_length == 0)
		{
			return m_data[0];
		}
		return m_data[m_length - 1];
	}

	return m_data[index];
}

const char& String::operator[](unsigned int index) const
{
	if (index >= m_length)
	{
		if (m_length == 0)
		{
			return m_data[0];
		}
		return m_data[m_length - 1];
	}

	return m_data[index];
}

unsigned int String::size()  const
{
	return m_length;
}

bool	String::empty() const
{
	return m_length == 0;
}

const char* String::c_str() const
{
	return m_data;
}

void String::clear()
{
	if (m_data)
	{
		delete[]m_data;
	}
	m_data = new char[1];
	if (m_data)
	{
		m_data[0] = '\0';
	}
	m_length = 0;
}

void String::push_back(char c)
{
	char* newData = new char[m_length + 2];
	if (!newData)
	{
		return;
	}
	for (unsigned int i = 0; i < m_length; ++i)
	{
		newData[i] = m_data[i];
	}
	newData[m_length] = c;
	newData[m_length + 1] = '\0';

	if (m_data)
	{
		delete[]m_data;
	}
	m_data = newData;
	++m_length;
}

void String::pop_back()
{
	--m_length;

	char* newData = new char[m_length + 1];
	if (!newData)
	{
		m_data[m_length] = '\0';
		return;
	}

	for (unsigned int i = 0; i < m_length; ++i)
	{
		newData[i] = m_data[i];
	}
	newData[m_length] = '\0';

	if (m_data)
	{
		delete[]m_data;
	}
	m_data = newData;
}

int String::compare(const String& other) const
{
	return str_compare(m_data, other.m_data);
}

int String::compare(const char* s) const
{
	return str_compare(m_data, s);
}

String String::substr(unsigned int start, unsigned int count) const
{
	if (start >= m_length || count == 0)
	{
		return String();
	}

	if (start + count > m_length)
	{
		count = m_length - start;
	}

	String result;
	if (result.m_data)
	{
		delete[]result.m_data;
	}

	result.m_data = new char[count + 1];
	if (!result.m_data)
	{
		result.m_length = 0;
		return result;
	}

	for (unsigned int i = 0; i < count; i++)
	{
		result.m_data[i] = m_data[start + i];
	}
	result.m_data[count] = '\0';
	result.m_length = count;

	return result;
}

int String::find(char c) const
{
	for (unsigned int i = 0; i < m_length; i++)
	{
		if (m_data[i] == c)
		{
			return (int)i;
		}
	}
	return -1;
}

int String::find(const String& part) const
{
	return find(part.m_data);
}

int String::find(const char* part) const
{
	if (!part || part[0] == '\0')
	{
		return 0;
	}

	unsigned int partLen = str_length(part);
	if (partLen == 0 || partLen > m_length)
	{
		return -1;
	}

	for (unsigned int i = 0; i <= m_length - partLen; i++)
	{
		unsigned int j = 0;
		while (j < partLen && m_data[i + j] == part[j])
		{
			j++;
		}
		if (j == partLen)
		{
			return (int)i;
		}
	}

	return -1;
}

bool String::starts_with(const String& prefix) const
{
	if (prefix.m_length > m_length)
	{
		return false;
	}

	for (unsigned int i = 0; i < prefix.m_length; i++)
	{
		if (m_data[i] != prefix.m_data[i])
		{
			return false;
		}
	}
	return true;
}

bool String::ends_with(const String& suffix) const
{
	if (suffix.m_length > m_length)
	{
		return false;
	}
	unsigned int offset = m_length - suffix.m_length;
	for (unsigned int i = 0; i < suffix.m_length; i++)
	{
		if (m_data[offset + i] != suffix.m_data[i])
		{
			return false;
		}
	}
	return true;
}

void String::to_upper()
{
	if (!m_data)
	{
		return;
	}

	for (unsigned int i = 0; i < m_length; i++)
	{
		char c = m_data[i];
		if (c >= 'a' && c <= 'z')
		{
			m_data[i] = (char)(c - 'a' + 'A');
		}
	}
}

void String::to_lower()
{
	if (!m_data)
	{
		return;
	}

	for (unsigned int i = 0; i < m_length; i++)
	{
		char c = m_data[i];
		if (c >= 'A' && c <= 'Z')
		{
			m_data[i] = (char)(c - 'A' + 'a');
		}
	}
}

void String::trim()
{
	if (m_length == 0)
	{
		return;
	}

	unsigned int start = 0;
	while (start < m_length && (m_data[start] == ' ' || m_data[start] == '\t' || m_data[start] == '\n'))
	{
		++start;
	}

	if (start == m_length)
	{
		clear();
		return;
	}

	unsigned int end = m_length - 1;
	while (end > start && (m_data[end] == ' ' || m_data[end] == '\t' || m_data[end] == '\n'))
	{
		--end;
	}

	unsigned int newLen = end - start + 1;
	String temp = substr(start, newLen);
	*this = temp;
}

void String::reverse()
{
	for (unsigned int i = 0; i < m_length / 2; i++)
	{
		char temp = m_data[i];
		m_data[i] = m_data[m_length - 1 - i];
		m_data[m_length - 1 - i] = temp;
	}
}

String& String::operator+=(const String& other)
{
	return (*this += other.m_data);
}

String& String::operator+=(const char* s)
{
	if (!s || s[0] == '\0')
	{
		return *this;
	}

	unsigned int addLen = str_length(s);
	char* newData = new char[m_length + addLen + 1];
	if (!newData)
	{
		return *this;
	}

	for (unsigned int i = 0; i < m_length; ++i)
	{
		newData[i] = m_data[i];
	}

	for (unsigned int i = 0; i < addLen; ++i)
	{
		newData[m_length + i] = s[i];
	}
	newData[m_length + addLen] = '\0';

	if (m_data)
	{
		delete[] m_data;
	}

	m_data = newData;
	m_length += addLen;

	return *this;
}

String& String::operator+=(char c)
{
	push_back(c);
	return *this;
}

String operator+(const String& a, const String& b)
{
	String result(a);
	result += b;
	return result;
}

String operator+(const String& a, const char* b)
{
	String result(a);
	result += b;
	return result;
}

String operator+(const char* a, const String& b)
{
	String result(a);
	result += b;
	return result;
}

String operator+(const String& a, char b)
{
	String result(a);
	result += b;
	return result;
}

String operator+(char a, const String& b)
{
	String result(a);
	result += b;
	return result;
}

bool operator==(const String& a, const String& b)
{
	return String::str_compare(a.m_data, b.m_data) == 0;
}

bool operator!=(const String& a, const String& b)
{
	return !(a == b);
}

bool operator<(const String& a, const String& b)
{
	return String::str_compare(a.m_data, b.m_data) < 0;
}

bool operator<=(const String& a, const String& b)
{
	return String::str_compare(a.m_data, b.m_data) <= 0;
}

bool operator>(const String& a, const String& b)
{
	return String::str_compare(a.m_data, b.m_data) > 0;
}

bool operator>=(const String& a, const String& b)
{
	return String::str_compare(a.m_data, b.m_data) >= 0;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.m_data;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	s.clear();

	char ch = '\0';
	bool started = false;

	while (true)
	{
		if (!is.get(ch))
		{
			return is;
		}

		if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			continue;
		}

		started = true;
		s.push_back(ch);
		break;
	}
	while (true)
	{
		if (!is.get(ch))
		{
			break;
		}

		if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			break;
		}

		s.push_back(ch);
	}

	return is;
}
