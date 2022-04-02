
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <sstream>
#include <string>
#include "Utilities.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string blank;
		char kind = '\0';
		char extract = '\0';

		std::getline(in, blank);
		std::stringstream str(blank);
		str >> kind >> extract;

		if (str) {
			switch (kind)
			{
			case 'c':
			case 'C':
				return new Car(str);
				break;
			case 'r':
			case 'R':
				return new Racecar(str);
				break;
			default:
				throw kind;
				break;
			}
		}
		return nullptr;
	}
}