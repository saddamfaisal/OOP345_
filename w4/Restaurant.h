
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/10/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef SDDS_REST_H
#define SDDS_REST_H


#include <iostream>

#include "Reservation.h"


namespace sdds
{
   class Restaurant
   {
      Reservation** objectRes = nullptr;
      size_t r_size = 0;
   public:
      Restaurant(Reservation* reservations[], size_t cnt);
      size_t size() const;

      Restaurant(const Restaurant& str);
      Restaurant(Restaurant&& str);
      Restaurant& operator=(const Restaurant& incstr);
      Restaurant& operator=(Restaurant&& incstr);
      friend std::ostream& operator<<(std::ostream& out, const Restaurant& incStr);
   };
}

#endif 