
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           08/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include <iomanip>
#include "Car.h"
using namespace std;
namespace sdds {
	string Car::trim(string& src) {
		while (src.length() > 0 && src[0] == ' ')
			src.erase(0, 1);
		while (src.length() > 0 && src[src.length() - 1] == ' ')
			src.erase(src.length() - 1, 1);
		return src;
	}

	Car::Car(istream& str) {
		string tag;
		
		getline(str, tag, ',');
		v_maker = trim(tag);

		getline(str, tag, ',');
		trim(tag);
		if (tag == "n" || tag == "") {
			v_condition = "new";
		}
		else if (tag == "u") {
			v_condition = "used";
		}
		else if (tag == "b") {
			v_condition = "broken";
		}
		else {
			throw "Invalid record!";
		}

		getline(str, tag, ',');
		try {
			v_topSpeed = stoi(trim(tag));
		}
		catch (...) {
			throw "Invalid record!";
		}

	}

	string Car::condition() const {
		return v_condition;
	};

	double Car::topSpeed() const {
		return v_topSpeed;
	};

	void Car::display(ostream& out) const {
		out << "| " << setw(10) << right << v_maker
			<< " | " << setw(6) << left << v_condition
			<< " | " << setw(6) << fixed << setprecision(2) << topSpeed()
			<< " |";
	};
}
