

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/10/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.



#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds
{
   class ConfirmationSender
   {
      Reservation** res_object;
      int num;

   public:
      int size() const;

      ConfirmationSender();



      ConfirmationSender(ConfirmationSender&);

      ConfirmationSender(ConfirmationSender&& strarr);

      ConfirmationSender& operator+=(Reservation& res);



      ConfirmationSender& operator-=(Reservation&);

      ~ConfirmationSender();

      friend ostream& operator<<(ostream&, ConfirmationSender&);
   };
}

#endif 