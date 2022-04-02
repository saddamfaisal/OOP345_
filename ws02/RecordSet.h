//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds
{
   class RecordSet
   {
   public:
      string* rcord_Strings;
      int rcd_StrCount;

      RecordSet();

      ~RecordSet();

      RecordSet(char* incoming_str);

      RecordSet(const RecordSet& incoming_rcd);

      RecordSet(RecordSet&& incoming_rcd);

      RecordSet& operator=(RecordSet&& str_time);

      RecordSet& operator=(const RecordSet& incoming_rcd);

      size_t size();

      string getRecord(int given_t);
   };
} 

#endif