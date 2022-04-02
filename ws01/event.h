//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.



#ifndef ADD_H
#define ADD_H
extern unsigned int g_sysClock;

namespace sdds {
   class Event

   {
      char* description;

       unsigned int secondMidnight; 

   public:
      Event();
      void display();
      void setDescription(  char* des);
      ~Event();
   };

}
#endif