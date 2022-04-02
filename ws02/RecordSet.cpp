//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include "RecordSet.h"

namespace sdds
{
   RecordSet::RecordSet()
   {
      rcord_Strings = nullptr;
      rcd_StrCount = 0;
   }

   RecordSet::~RecordSet()
   {
      delete[] rcord_Strings;
      rcord_Strings = nullptr;
   }

   RecordSet::RecordSet(char* incoming_rcd)
   {
      string space;
      ifstream file(incoming_rcd);
      int i = 0;
      while (!file.eof())
      {
         getline(file, space, ' ');
         ++i;
      }




      rcord_Strings = new string[i + 1];
      space = {};
      file.close();
      file.open(incoming_rcd);
      i = 0;
      while (getline(file, space, ' '))
      {
         rcord_Strings[i] = space;
         ++i;
      }
      rcd_StrCount = i;
   }

   RecordSet::RecordSet(const RecordSet& incoming_rcd)
   {
      *this = incoming_rcd;
   }

   RecordSet& RecordSet::operator=(const RecordSet& incoming_rcd)
   {
      rcd_StrCount = incoming_rcd.rcd_StrCount;
      rcord_Strings = new string[rcd_StrCount];
      for (int index = 0; index < rcd_StrCount; ++index)
      {
         rcord_Strings[index] = incoming_rcd.rcord_Strings[index];
      }
      return *this;
   }

   size_t RecordSet::size()
   {
      return rcd_StrCount;
   }

   string RecordSet::getRecord(int str_time)
   {
      if (rcord_Strings != nullptr)
      {
         return string(rcord_Strings[str_time]);
      }
      else
      {
         return "";
      }
   }

   RecordSet::RecordSet(RecordSet&& incoming_rcd)
   {
      *this = move(incoming_rcd);
   }

   RecordSet& RecordSet::operator=(RecordSet&& incoming_rcd)
   {
      if (this != &incoming_rcd)
      {
         rcd_StrCount = incoming_rcd.rcd_StrCount;
         rcord_Strings = new string[rcd_StrCount];
         for (int index = 0; index < rcd_StrCount; ++index)
         {
            rcord_Strings[index] = incoming_rcd.rcord_Strings[index];
         }
         delete[] incoming_rcd.rcord_Strings;
         incoming_rcd.rcord_Strings = nullptr;
         incoming_rcd.rcd_StrCount = 0;
      }
      return *this;
   }
} 