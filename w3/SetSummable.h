//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include "Set.h"
namespace sdds {

	template <typename T, unsigned int N>
	class SetSummable : public Set<T, N> {

	public:

		T accumulate(const std::string& filter) const
		{
			T summable(filter);
			for (size_t i = 0; i < this->size(); i++)
			{
				summable += (*this)[i];
			}
			return summable;
		}


	};
}

#endif
