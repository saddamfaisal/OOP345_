
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/10/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include <iostream>
#include "Restaurant.h"


namespace sdds
{
   Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
   {
      r_size = cnt;
      if (reservations != nullptr)
      {
         objectRes = new Reservation * [cnt];
         for (size_t i = 0; i < cnt; i++)
         {
            objectRes[i] = reservations[i];
         }
      }
      else
      {
         objectRes = nullptr;
      }

   }

   size_t Restaurant::size() const
   {
      return r_size;
   }

   std::ostream& operator<<(std::ostream& out, const Restaurant& incStr)
   {
      out << "--------------------------" << std::endl;
      out << "Fancy Restaurant" << std::endl;
      out << "--------------------------" << std::endl;

      if (incStr.size() == 0)
      {
         out << "The object is empty!" << std::endl;
      }
      else
      {
         for (size_t i = 0; i < incStr.size(); i++)
         {
            out << *(incStr.objectRes[i]);
         }
      }

      out << "--------------------------" << std::endl;
      return out;
   }


   // constructor thingie


   Restaurant::Restaurant(Restaurant&& str)
   {
      *this = std::move(str);
   }

   Restaurant& Restaurant::operator=(Restaurant&& incStr)
   {
      if (this != &incStr)
      {
         delete[] objectRes;
         objectRes = incStr.objectRes;
         r_size = incStr.r_size;
         incStr.objectRes = nullptr;
         incStr.r_size = 0;
      }
      return *this;
   }


   Restaurant::Restaurant(const Restaurant& str)
   {
      *this = str;
   }

   Restaurant& Restaurant::operator=(const Restaurant& incstr)
   {
      if (this != &incstr)
      {
         r_size = incstr.r_size;

         if (incstr.objectRes != nullptr)
         {
            objectRes = new Reservation * [r_size];

            for (size_t i = 0; i < r_size; i++)
            {
               objectRes[i] = incstr.objectRes[i];
            }
         }
         else
         {
            objectRes = nullptr;
         }

      }
      return *this;
   }



}
