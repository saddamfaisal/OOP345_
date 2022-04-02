//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.



#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_NRECORDS = 7;
	class TimedEvents {
		int rc_num;

		std::chrono::steady_clock::time_point stm;
		std::chrono::steady_clock::time_point etm;

		struct {
			std::string event_name{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_NRECORDS];


	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}
#endif