
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           15/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds {
	struct Song {
		std::string artist{ "" };
		std::string title{ "" };
		std::string album{ "" };
		double m_price{ 0.0 };
		size_t release{ 0 };
		size_t length{ 0 };
	};

	class SongCollection {
		std::vector<Song> m_songs;
		std::string& trim(std::string&);
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

	std::ostream& operator<<(std::ostream& ost, const Song& song);
}
#endif 