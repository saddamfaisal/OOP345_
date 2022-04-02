
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include "Autoshop.h"
namespace sdds {
	Autoshop::~Autoshop() {
		while (!m_vehicles.empty()) {
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}

}