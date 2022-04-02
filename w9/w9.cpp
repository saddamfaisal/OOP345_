//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           28/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	char key = argv[3][0];

	try {
		w9::SecureData sd(argv[1], key, &cout);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << std::endl;

	}
	catch (const std::string & msg) {
		cout << msg << std::endl;
	}

	return 0;
}
