//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "Movie.h"

namespace sdds
{
	void Movie::setEmpty()
	{
		c_title = "";
		c_yearofRel = 0;
		c_description = "";
	}

	Movie::Movie()
	{
		setEmpty();
	}

	Movie::Movie(const string& strMovie)
	{
		setEmpty();

		int check = 0;
		int row = 1;
		int length = 0;

		for (int i = 0; i <= int(strMovie.length()); i++) {
			if (row == 1 && strMovie[i] == ',') {
				c_title = strMovie.substr(check, length);
				eraseSpace(c_title);
				check = i + 1;
				row++;
				length = 0;
				i++;
			}

			if (row == 2 && strMovie[i] == ',') {
				c_yearofRel = stod(strMovie.substr(check, length));
				check = i + 1;
				row++;
				length = 0;
				i++;
			}
			if (row == 3 && strMovie[i] == '\0') {
				c_description = strMovie.substr(check, length);
				eraseSpace(c_description);
				check = i + 1;
				row++;
				length = 0;
				i++;
			}
			length++;
		}

	}

	void Movie::eraseSpace(string& incstr) {
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

	const string& Movie::title() const
	{
		return c_title;
	}
	ostream& operator<<(ostream& ost, const Movie& mv)
	{
		ost << setw(40) << mv.c_title << " | " << setw(4) << mv.c_yearofRel << " | " << left << mv.c_description << right << endl;
		return ost;
	}
}