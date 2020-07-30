#ifndef LOCATION_H
#define LOCATION_H

#include <list>
#include <cstring>
#include "Sport.h"
using namespace std;

typedef Sport* SportSp;

class Location {
	
	string name;
		/* Name of this location. */
	list<SportSp> sportsList;
		/* List containing sports from this location. */
	int sportsNum;
		/* Total number of sports from this location.*/
	
	public:
		/* Constructors. */
		Location (void) {
			name = "no name";
			sportsNum = 0;
			/* cout << "Location with no sports creating..." << endl;
			 */
		}
		
		Location (string _name) {
			name = _name;
			sportsNum = 0;
			/* cout << "Location '" << name << " with no sports yet added creating..." << endl;
			 */
		}
		
		Location (string _name, int _sportsNum, list<SportSp> _sportsList) {
			name = _name;
			sportsNum = _sportsNum;
			sportsList = _sportsList;
			/* cout << "Location '" << name << "' with " << sportsNum << " sports creating..." << endl;
			 */
		}
		
		/* Destructor. */
		~Location () {
			cout << "Location being deleted..." << endl;
		}
		
		/* Getters and setters. */
		void setName (string _name) {
			name = _name;
		}
		void setSportsList (list <SportSp> _sportsList) {
			sportsList = _sportsList;
		}
		void setSportsNum (int _sportsNum) {
			sportsNum = _sportsNum;
		}
		string getName (void) {
			return name;
		}
		list <SportSp> getSportsList (void) {
			return sportsList;
		}
		int getSportsNum (void) {
			return sportsNum;
		}
		
		/* Add sport. */
		void addSport (SportSp sport) {
			sportsList.push_back(sport);
			sportsNum++;
		}
		
		/* Overload output operator. */
		friend ostream &operator<< (ostream &output, const Location &location) {
			output << "Location '" << location.name << "' with " << location.sportsNum << " sports: ";
		}
		
		/* Display location. */ 
		void display () {
			cout << "Location '" << name << "' with " << sportsNum << " sports.";
			if (sportsNum) {
				cout << " It has following sports: " << endl;
				displaySports();
			} else {
				cout << endl;
			}
		}
		
		/* Display sports. */
		void displaySports () {
			list<SportSp>::const_iterator iter = this->sportsList.begin();
			for (int i = 0; iter != this->sportsList.end(); ++iter, ++i) {
		    	cout << "----------- ";
				(*iter)->display();
			}
		}
};

#endif
