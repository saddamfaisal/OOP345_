//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"
#include <cstring>
//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


using namespace std;
extern unsigned int g_sysClock = 0;

namespace sdds
{




   Event::Event() {


      secondMidnight = 0;
      description = nullptr;

   }



   void Event::display() {
   
      static int counter = 1;


       

    
     // minute = secondMidnight / 60 % 60;
      //second = secondMidnight % 60;


      if (description != nullptr && description[0] != '\0' ) {
        
         int hour = 0;
         int minute = 0;
         int second = 0;


         hour = secondMidnight / 3600;
         minute = (secondMidnight - (hour * 3600)) / 60;
         second = (secondMidnight - (hour * 3600) - (minute * 60));

         cout << setw(3) << setfill(' ') << hour << ". " << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << "->" << description << endl;
      }
      else {
         cout << setw(3) << setfill(' ') << count << ". " << "[ No Event ]" << endl;
         
         
      }

    

      








   }

   void Event::setDescription(char* des)
   {
      if (des != nullptr && des[0]!= '\0'  ) {

         description = new char[strlen(des) + 1];
         strcpy(description, des);
         secondMidnight = g_sysClock;

      }
      else {
        description = nullptr;
         secondMidnight = 0;

      }

   }

   Event::~Event()
   {
      delete[]description;

   }


































}
