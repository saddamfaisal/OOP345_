//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;



size_t Station::m_widthField = 0;
int Station::id_generator = 1;

Station::Station(const std::string& str) {
	m_identity = id_generator;

	Utilities object;
	size_t next_pos = 0;
	bool more = true;

	try {
		m_name = object.extractToken(str, next_pos, more);
		m_serialnum = stoi(object.extractToken(str, next_pos, more));
		m_currentnum = stoi(object.extractToken(str, next_pos, more));
		m_widthField = max(object.getFieldWidth(), m_widthField);
		m_description = object.extractToken(str, next_pos, more);
	}
	catch (string & text) {
		cout << text;
	}



	id_generator++;

}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	m_serialnum++;
	return m_serialnum - 1;
}

unsigned int Station::getQuantity() const {
	return m_currentnum;
}

void Station::updateQuantity() {
	m_currentnum--;
	if (m_currentnum < 0) {
		m_currentnum = 0;
	}
}

void Station::display(std::ostream& os, bool full) const {
	ios init(NULL);
	init.copyfmt(cout);
	os << right;
	os << "[";
	os << setw(3);
	os << setfill('0');
	os << m_identity;
	os << "]";
	os << left;

	os << " Item: ";
	os << setw(m_widthField);
	os << setfill(' ');
	os << m_name;
	os << right;

	os << " [";
	os << setw(6);
	os << setfill('0');
	os << m_serialnum;
	os << "]";
	os << left;

	if (full != true) {
		os << endl;

	}
	else {
		os << " Quantity: ";
		os << setw(m_widthField);
		os << setfill(' ');
		os << m_currentnum;

		os << " Description: ";
		os.copyfmt(init);
		os << m_description;
		os << endl;


	}
}
