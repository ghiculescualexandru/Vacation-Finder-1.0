#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstring>
#include <list>
using namespace std;

namespace handler {
	ifstream databaseFile;

	void dbRead (list<list<string> > *database) {
		databaseFile.open("database.txt");
		string line;
		if (databaseFile.is_open()) {
			while (getline(databaseFile, line)) {
				istringstream iss(line);
				list<string> results(istream_iterator<string>{iss},
                                	 istream_iterator<string>());

				(*database).push_back(results);

			}
			
			databaseFile.close();
		}
	}
	
	void dbDisplay (list<list<string> > database) {
		list<list<string> >::iterator line = database.begin();
		for (; line != database.end(); ++line) {
			list<string>::iterator el = (*line).begin();
			for (; el != (*line).end(); ++el) {
				cout << *el << " ";
			}
			cout << endl;
		}
		
		cout << endl;
	}
}


#endif
