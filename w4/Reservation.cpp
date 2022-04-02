

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/10/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include <iomanip>
#include "Reservation.h"

namespace sdds
{
   Reservation::Reservation()
   {
      r_id = "";
      r_name = "";
      r_email = "";
      r_peopleNum = 0;
      r_day = 0;
      r_hour = 0;
   }

   Reservation::Reservation(const string& incStr)
   {
      string identity, name, email, persons, day, hour;
      string array = incStr;

      identity = array.substr(0, array.find(':'));

      array.erase(0, array.find(':') + 1);
      name = array.substr(0, array.find(','));

      array.erase(0, array.find(',') + 1);
      email = array.substr(0, array.find(','));

      array.erase(0, array.find(',') + 1);
      persons = array.substr(0, array.find(','));

      array.erase(0, array.find(',') + 1);
      day = array.substr(0, array.find(','));

      array.erase(0, array.find(',') + 1);
      hour = array.substr(0, array.find(','));

      identity.erase(identity.find_last_not_of(' ') + 1);
      identity.erase(0, identity.find_first_not_of(' '));

      name.erase(name.find_last_not_of(' ') + 1);
      name.erase(0, name.find_first_not_of(' '));

      email.erase(email.find_last_not_of(' ') + 1);
      email.erase(0, email.find_first_not_of(' '));

      email = "<" + email + ">";

      r_id = identity;
      r_name = name;
      r_email = email;
      r_peopleNum = stoi(persons);
      r_day = stoi(day);
      r_hour = stoi(hour);
   }

   ostream& operator<<(ostream& out, Reservation& incstr)
   {
      string menu[4] = { "Breakfast", "Lunch", "Dinner", "Drinks" };
      int code = 0;
      if (incstr.r_hour >= 6 && incstr.r_hour <= 9)
      {
         code = 0;
      }
      else if (incstr.r_hour >= 11 && incstr.r_hour <= 15)
      {
         code = 1;
      }
      else if (incstr.r_hour >= 17 && incstr.r_hour <= 21)
      {
         code = 2;
      }
      else
      {
         code = 3;
      }

      out << "Reservation " << incstr.r_id << ": ";
      out << setw(10) << setfill(' ') << right << incstr.r_name << "  ";
      out << setw(20) << setfill(' ') << left << incstr.r_email;
      out << menu[code] << " on day " << incstr.r_day << " @ " << incstr.r_hour << ":00"
         << " for " << incstr.r_peopleNum
         << " people." << '\n';
      return out;
   }
} 
