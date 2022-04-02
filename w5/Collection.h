//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	template <class T>
	class Collection {

		string b_collectionName;
		T* b_collection;
		size_t b_arraySize;
		void (*b_observer)(const Collection<T>&, const T&);

	public:
		Collection(string name) {
			b_collectionName = name;
			b_collection = nullptr;
			b_arraySize = 0;
			b_observer = nullptr;
		};

		Collection(const Collection&) = delete;

		~Collection() {
			delete[] b_collection;
			b_collection = nullptr;
		};

		const std::string& name() const {
			return b_collectionName;
		};
		size_t size() const {
			return b_arraySize;
		};

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			b_observer = *observer;
			observer = nullptr;
		};


		Collection<T>& operator+=(const T& item) {
			bool editTitle = false;

			for (int i = 0; i < int(b_arraySize) && editTitle == false; i++) {
				if (item.title() == b_collection[i].title())
					editTitle = true;
			}

			if (editTitle == false) {
				if (b_arraySize > 0) {
					T* temp = new T[b_arraySize + 1];

					for (int i = 0; i < int(b_arraySize); i++) {
						temp[i] = b_collection[i];
					}
					b_arraySize++;

					delete[] b_collection;
					b_collection = new T[b_arraySize];

					for (int i = 0; i < int(b_arraySize - 1); i++) {
						b_collection[i] = temp[i];
					}
					b_collection[b_arraySize - 1] = item;
					delete[] temp;
					temp = nullptr;
				}
				else {
					b_arraySize++;
					b_collection = new T[b_arraySize];
					b_collection[b_arraySize - 1] = item;
				}
				if (b_observer != nullptr) {
					b_observer(*this, item);
				}

			}
			return *this;
		};

		T& operator[](size_t idx) const {
			if (idx >= b_arraySize) {

				string txt = "Bad index [" + to_string(idx) + "]. Collection has [" + to_string(b_arraySize) + "] items.";
				throw out_of_range(txt);
			}
			return b_collection[idx];
		};
		T* operator[](string title) const {
			bool validate = false;
			T* edit = nullptr;
			for (int i = 0; i < int(b_arraySize) && validate == false; i++) {
				if (b_collection[i].title() == title) {
					validate = true;
					edit = &b_collection[i];
				}
			}

			return edit;
		};

		friend ostream& operator<<(ostream& ost, const Collection& item) {
			for (int i = 0; i < int(item.size()); ++i) {
				ost << item.b_collection[i];
			}
			return ost;
		};
	};
}
#endif // !SDDS_COLLECTION_H__
