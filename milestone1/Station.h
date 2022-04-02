//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>



class Station {
	int m_identity;
	std::string m_name;
	std::string m_description;
	int m_serialnum;
	int m_currentnum;
	static size_t m_widthField;
	static int id_generator;
public:
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;


};






#endif