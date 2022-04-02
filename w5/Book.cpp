//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "Book.h"

namespace sdds {

	void Book::setEmpty() {
		b_author = "";
		b_title = "";
		pb_country = "";
		pb_year = 0;
		b_price = 0.00;
		b_description = "";

	}

	Book::Book() {
		setEmpty();
	}

	const string& Book::title() const {
		return b_title;
	}

	const string& Book::country() const {
		return pb_country;
	}

	const size_t& Book::year() const {
		return pb_year;
	}

	double& Book::price() {
		return b_price;
	}

	Book::Book(const string& strBook) {
		setEmpty();
		int chek = 0;
		int division = 1;
		int size = 0;

		for (int i = 0; i <= int(strBook.length()); i++) {
			if (division == 1 && strBook[i] == ',') {
				b_author = strBook.substr(chek, size);
				eraseSpace(b_author);
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			if (division == 2 && strBook[i] == ',') {
				b_title = strBook.substr(chek, size);
				eraseSpace(b_title);
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			if (division == 3 && strBook[i] == ',') {
				pb_country = strBook.substr(chek, size);
				eraseSpace(pb_country);
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			if (division == 4 && strBook[i] == ',') {
				b_price = stod(strBook.substr(chek, size));
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			if (division == 5 && strBook[i] == ',') {
				pb_year = stoi(strBook.substr(chek, size));
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			if (division == 6 && strBook[i] == '\0') {
				b_description = strBook.substr(chek, size);
				eraseSpace(b_description);
				chek = i + 1;
				division++;
				size = 0;
				i++;
			}
			size++;
		}


	}
	ostream& operator<<(ostream& ost, const Book& bk) {
		ost << setw(20) << bk.b_author << " | " << setw(22) << bk.b_title << " | " << setw(5) << bk.pb_country << " | " << setw(4) << bk.pb_year << " | " << setw(6) << fixed << setprecision(2) << bk.b_price << " | " << left << bk.b_description << right << endl;
		return ost;
	}
	void Book::eraseSpace(string& incstr) {
		bool space = false;

		for (int i = 0; i < int(incstr.length()) && space == false; i++) {
			if (incstr[i] == ' ') {
				incstr.erase(i, 1);
				i--;
			}
			else {
				space = true;
			}
		}
		space = false;

		for (int i = int(incstr.length()); i > 0 && space == false; i--) {
			if (incstr[i] == ' ') {
				incstr.erase(i, 1);
			}
			else if (incstr[i] != ' ' && incstr[i] != '\0') {
				space = true;
			}
		}
		space = false;
	}
}