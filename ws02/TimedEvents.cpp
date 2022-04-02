//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           26/09/2020

//> I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.


#include "TimedEvents.h"
#include <iomanip>


namespace sdds
{
	

	TimedEvents::TimedEvents() {
		rc_num = 0;
		startClock();
		stopClock();

	}
	void TimedEvents::startClock()
	{
		stm = std::chrono::steady_clock::now();
	}

	
	
	void TimedEvents::stopClock()
	{
		etm = std::chrono::steady_clock::now();
	}

	
	
	void TimedEvents::recordEvent(const char* name)
	{
		auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(etm - stm);
		if (rc_num < MAX_NRECORDS)
		{
			this->events[rc_num].event_name = name;
			this->events[rc_num].units = "nanoseconds";
			this->events[rc_num].duration = time;
			rc_num++;
		}
	}

	
	
	std::ostream& operator<<(std::ostream& ot, const TimedEvents& events)
	{
		ot << "--------------------------\n";
		ot << "Execution Times:\n";
		ot << "--------------------------\n";
		for (int index = 0; index < events.rc_num; index++)
			ot << std::setw(20) << std::left
			<< events.events[index].event_name << ' ' << std::setw(12) << std::right
			<< events.events[index].duration.count() << ' '
			<< events.events[index].units << '\n';
		ot << "--------------------------\n";
		return ot;
	}
}
