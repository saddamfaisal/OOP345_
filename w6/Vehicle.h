
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

// Workshop 6 - STL Containers
// 2020/02/26 - Cornel

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

namespace sdds
{
	class Vehicle
	{
	public:
		virtual double topSpeed() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual std::string condition() const = 0;
		virtual ~Vehicle() {};
	};
}

#endif

