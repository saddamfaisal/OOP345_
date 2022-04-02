//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           13/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/



#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds {
	template<typename K, typename V>
	class Pair {
		K m_key;//
		V m_value;///

	public:

		Pair() : m_key{ 0 }, m_value{ 0 } {}

		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;

		};

		const K& key() const {
			return m_key;
		}

		const V& value() const {
			return m_value;
		}

		void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}
	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif// !SDDS_PAIR_H
