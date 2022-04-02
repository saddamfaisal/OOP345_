//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <algorithm>
#include "Utilities.h"

using namespace std;


char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	string temporary = "";
	size_t init_pos = next_pos;
	next_pos = str.find(m_delimiter, init_pos);

	if (next_pos == string::npos) {
		temporary = str.substr(init_pos);
		m_widthField = max(temporary.length(), m_widthField);
		more = true;
	}
	else if (init_pos == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {
		temporary = str.substr(init_pos, next_pos - init_pos);
		m_widthField = max(temporary.length(), m_widthField);
		more = true;
	}
	next_pos++;
	return temporary;

}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}