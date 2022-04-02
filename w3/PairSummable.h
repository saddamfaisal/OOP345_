//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/10/2020

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/





#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include "Pair.h"
#include <iomanip>

namespace sdds {

	template <typename K, typename V>
	class PairSummable : public Pair<K, V> {
	private:
		static V initial; //
		static size_t m_val;  ///

	public:


		PairSummable() :Pair<K, V>() {	}

		static const V& getInitial() {
			return initial;
		}

		

		PairSummable(const K& key, const V& value = initial) : Pair<K, V>(key, value) {
			if (m_val < key.size()) {
				m_val = key.size();
			}
		}

		PairSummable<K, V >& operator+=(const PairSummable<K, V >& p) {
			if (this != &p && Pair<K, V>::key() == p.key()) {
				*this = PairSummable(this->key(), this->value() + p.value());

				return *this;
			}
			return *this;
		}

		void display(std::ostream& os) const {

			os << std::left << std::setw(m_val);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};

	template<typename K, typename V> size_t PairSummable<K, V >::m_val = 0;
	template <> std::string PairSummable<std::string, std::string >::initial = std::string("");
	template<> int PairSummable<std::string, int>::initial = 0;
	template<> PairSummable<std::string, std::string >& PairSummable<std::string, std::string >::operator+=(const PairSummable<std::string, std::string>& p)
	{
		if (this != &p && Pair<std::string, std::string>::key() == p.key()) {
			*this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() == "" ? p.value() : Pair<std::string, std::string>::value() + ", " + p.value());
		}
		return *this;

	}
}
#endif
