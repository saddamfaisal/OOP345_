//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

namespace sdds
{
   class Movie
   {
      string c_title;
      size_t c_yearofRel;
      string c_description;
   public:
      void setEmpty();
      Movie();
      const string& title() const;
      Movie(const  string& strMovie);
      void eraseSpace(string& incstr);
    
      friend ostream& operator<<(ostream& ost, const Movie& mv);

      template<typename T>
      void fixSpelling(T spellChecker)
      {
         spellChecker(c_title);
         spellChecker(c_description);
      }
   };
}
#endif