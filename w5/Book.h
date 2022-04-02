
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           27/10/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

namespace sdds {

   class Book
   {
      string b_author;
      string b_title;
      string pb_country;
      size_t pb_year;
      double b_price;
      string b_description;

   public:
      Book();
      void setEmpty();
      const string& title() const;

      const string& country() const;

      const size_t& year() const;
      double& price();
      Book(const string& strBook);
      friend ostream& operator<<(ostream& ost, const Book& bk);
      void eraseSpace(string& incstr);


      template<typename T>
      void fixSpelling(T spellChecker)
      {
         spellChecker(b_description);
      }

   };


}
#endif