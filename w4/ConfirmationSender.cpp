
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/10/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include "ConfirmationSender.h"

namespace sdds
{
   ConfirmationSender::ConfirmationSender()
   {
      res_object = nullptr;
      num = 0;
   }

   ConfirmationSender::~ConfirmationSender()
   {
      delete[] res_object;
      res_object = nullptr;
   }

   int ConfirmationSender::size() const
   {
      return num;
   }

   ConfirmationSender& ConfirmationSender::operator+=(Reservation& res)
   {
      bool check = false;
      if (num <= 0)
      {
         num++;
         res_object = new Reservation * [1];
         res_object[0] = &res;
      }
      else
      {
         for (int i = 0; i < num; i++)
         {
            check = (&res == res_object[i]);
         }
         if (!check)
         {
            Reservation* m_array[10];
            for (int i = 0; i < num; i++)
            {
               m_array[i] = res_object[i];
            }
            num++;
            delete[] res_object;
            res_object = nullptr;
            res_object = new Reservation * [num];
            for (int i = 0; i < num - 1; i++)
            {
               res_object[i] = m_array[i];
            }
            res_object[num - 1] = &res;
         }
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(Reservation& res)
   {
      bool check = false;

      if (res_object != nullptr)
      {

         int i = 0;
         while (i < num && !check)
         {
            check = (&res == res_object[i++]);
         }
         if (check)
         {
            res_object[i - 1] = nullptr;
         }
      }
      return *this;
   }

   ostream& operator<<(ostream& out, ConfirmationSender& incomingStr)
   {
      if (incomingStr.num == 0)
      {
         out << "--------------------------\n";
         out << "Confirmations to Send\n";
         out << "--------------------------\n";
         out << "The object is empty!\n";
         out << "--------------------------\n";
      }
      else
      {
         out << "--------------------------\n";
         out << "Confirmations to Send\n";
         out << "--------------------------\n";
         for (int i = 0; i < incomingStr.size(); i++)
         {
            if (incomingStr.res_object[i] != nullptr)
            {
               out << *incomingStr.res_object[i];
            }
         }
         out << "--------------------------\n";
      }
      return out;
   }

   ConfirmationSender::ConfirmationSender(ConfirmationSender& incstr)
   {
      if (incstr.res_object != nullptr)
      {
         res_object = new Reservation * [incstr.size()];
         for (int i = 0; i < incstr.size(); ++i)
         {
            res_object[i] = incstr.res_object[i];
         }
         num = incstr.num;
      }
   }

   ConfirmationSender::ConfirmationSender(ConfirmationSender&& strarr)
   {
      if (strarr.res_object != nullptr)
      {
         swap(res_object, strarr.res_object);
         num = strarr.num;
         strarr.num = 0;
         strarr.res_object = nullptr;
      }
   }
}
