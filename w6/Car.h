
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_CAR_H 
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string v_maker = "";
		std::string v_condition = "";
		double v_topSpeed = 0.0;

	public:

		Car(std::istream&);
		std::string condition() const;

		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(std::string&);
		
		
		
	};
}

#endif 
