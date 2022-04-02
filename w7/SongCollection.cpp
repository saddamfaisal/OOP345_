
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           15/11/2020
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/


#define _CTR_SECURE_NO_WARNINGS_
#include "SongCollection.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <list>
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds {
	string& SongCollection::trim(string& obt) {
		while (obt.length() > 0 && obt[0] == ' ')
			obt.erase(0, 1);
		while (obt.length() > 0 && obt[obt.length() - 1] == ' ')
			obt.erase(obt.length() - 1, 1);
		return obt;
	}

	SongCollection::SongCollection(const char* filename) {
		ifstream fl(filename);
		if (!fl) {
			throw "The filename is incorrect!";
			return;
		}
		while (fl) {
			string str = "";
			getline(fl, str);
			if (fl) {
				Song object;
				trim(object.title = str.substr(0, 25));
				trim(object.artist = str.substr(25, 25));
				trim(object.album = str.substr(50, 25));
				try {
					object.release = stoi(str.substr(75, 5));
				}
				catch (...) {
					object.release = 0;
				}
				object.length = stoi(str.substr(80, 5));
				object.m_price = stod(str.substr(85));
				m_songs.push_back(object);
			}
		}
		fl.close();
	}

	  void SongCollection::display(ostream& out) const {
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& str) { out << str << endl; });
		size_t allsongs = 0;
		for_each(m_songs.begin(), m_songs.end(), [&](const Song& str) { allsongs += str.length; });
		out << "----------------------------------------------------------------------------------------\n";
		string str = "Total Listening Time: ";
		str += to_string(allsongs / 3600);
		str += ":";
		str += to_string(allsongs % 3600 / 60);
		str += ":";
		str += to_string(allsongs % 3600 % 60);
		out << "| " << setw(84) << str << " |" << endl;
	}

	
	 

	ostream& operator<<(ostream& ost, const Song& song) {
		ost << "| " << left << setw(20) << song.title
			<< " | " << left << setw(15) << song.artist
			<< " | " << left << setw(20) << song.album
			<< " | " << right << setw(6) << (song.release > 0 ? to_string(song.release) : "")
			<< " | " << song.length / 60 << ":" << setw(2) << setfill('0') << song.length % 60 << setfill(' ')
			<< " | " << setprecision(2) << fixed << song.m_price << " |";
		return ost;
	}

	void SongCollection::sort(string field_name) {
		if (field_name == "title") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& part1, const Song& part2) { return part1.title < part2.title; });
		}
		else if (field_name == "album") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& part1, const Song& part2) { return part1.album < part2.album; });
		}
		else if (field_name == "length") {
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& part1, const Song& part2) { return part1.length < part2.length; });
		}
	}

	void SongCollection::cleanAlbum() {
		for_each(m_songs.begin(), m_songs.end(), [](Song& sg) {
			if (sg.album == "[None]") {
				sg.album = " ";
			}
			});

	}

	bool SongCollection::inCollection(string artist) const {
		return any_of(m_songs.begin(), m_songs.end(), [&artist](const Song& song) {return song.artist == artist ? true : false; });
	}

	list<Song> SongCollection::getSongsForArtist(string artist) const {
		auto count = count_if(m_songs.begin(), m_songs.end(), [&artist](const Song& sg) {return sg.artist == artist; });
		list<Song> songs(count);
		copy_if(m_songs.begin(), m_songs.end(), songs.begin(), [&artist](const Song& sg) {return sg.artist == artist; });
		return songs;
	}
}