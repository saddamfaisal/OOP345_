
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           22/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		bool val = false;

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size() && !val; j++) {
				if (desc[i].code == price[j].code) {
					val = true;
					Product* tmpy{ new Product(desc[i].desc,
							price[j].price) };

					try {
						tmpy->validate();
					}
					catch (const std::string & msg) {
						Product::Trace = false;
						delete tmpy;
						Product::Trace = true;
						throw;
					}
					priceList += tmpy;
					delete tmpy;

				}
			}
			val = false;
		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {

			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {
					std::shared_ptr<Product> tmpy(new Product(desc[i].desc, price[j].price));
					tmpy->validate();
					priceList += tmpy;
				}
			}
		}

		return priceList;
	}
}