#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
   class Reservation
   {
      // protected:
      string r_id;
      string r_name;
      string r_email;
      int r_peopleNum;
      int r_day;
      int r_hour;

   public:
      Reservation();

      Reservation(const string& incStr);

      friend ostream& operator<<(ostream& os, Reservation& res);
   };
}

#endif