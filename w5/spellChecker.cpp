//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "SpellChecker.h"

using namespace std;

namespace sdds {
   SpellChecker::SpellChecker(const char* filename) {
      int i = 0;
      ifstream m_file(filename);

      if (m_file) {
         while (i < 5 && !m_file.eof()) {
            string row;
            getline(m_file, row, '\n');

            m_badWords[i] = row.substr(0, row.find(" "));
            m_goodWords[i] = row.substr(row.find(" "), row.length());
            m_goodWords[i].erase(remove_if(m_goodWords[i].begin(), m_goodWords[i].end(), [](unsigned char x) {return isspace(x); }), m_goodWords[i].end());
            i++;
         }
      }
      else {
         throw "Bad file name!";
      }

   }

   void SpellChecker::operator()(string& text)const {
      for (int i = 0; i < 5; ++i) {
         size_t check = text.find(m_badWords[i]);
         while (check != string::npos) {
            text.replace(check, m_badWords[i].length(), m_goodWords[i]);
            check = text.find(m_badWords[i]);
         }
      }
   }
}
