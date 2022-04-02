//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <istream>

using namespace std;

namespace sdds
{
   class SpellChecker
   {
      string m_badWords[5];
      string m_goodWords[5];
   public:
      SpellChecker(const char* filename);
      void operator()(string& text)const;
   };
}

#endif