//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <iostream>

namespace sdds {
	template<typename T, size_t N>
	class Set {
		T array[N]{};///
		size_t elment = 0;  ////

	public:
		size_t size() const {
			return elment;
		}

		const T& operator[](size_t idx) const {
			return array[idx];
		}

		void operator+=(const T& item) {
			if (elment < N) {
				array[elment++] = item;
			}
		}
	};

}
#endif // !SDDS_SET_H

