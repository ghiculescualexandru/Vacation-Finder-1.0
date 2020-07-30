#ifndef REGION_H
#define REGION_H

#include <cstring>
#include <list>
#include "Location.h"
using namespace std;

typedef Location* LocationSp;

class Region {
	
	string name;
		/* Name of this region. */
	list<LocationSp> locationsList;
		/* List with all locations from this region. */
	int locationsNum;
		/* Number of all locations from this region. */
		
	public:
		/* Constructors. */
		Region (void) {
			name = "no name";
			locationsNum = 0;
			/* cout << "Region with no locations creating..." << endl;
			**/	
		}	
		
		Region (string _name) {
			name = _name;
			locationsNum = 0;
			/* cout << "Region '" << name << " with no locations yet added creating..." << endl;
			**/	
		}
		
		Region (string _name, list<LocationSp> _locationsList, int _locationsNum) {
			name = _name;
			locationsNum = _locationsNum;
			locationsList = _locationsList;
			/* cout << "Region '" << name << "' with " << locationsNum << " locations creating..." << endl;
			**/	
		}
		
		/* Destructor. */
		~Region () {
			/* cout << "Region being deleted..." << endl;
			**/	
		}
		
		/* Getters and setters. */
		void setName (string _name) {
			name = _name;
		}
		void setLocationsList (list<LocationSp> _locationsList) {
			locationsList = _locationsList;
		}
		void setLocationsNum (int _locationsNum) {
			locationsNum = _locationsNum;
		}
		string getName (void) {
			return name;
		}
		list<LocationSp> getLocationsList (void) {
			return locationsList;
		}
		int getLocationsNum (void) {
			return locationsNum;
		}
		
		/* Add location. */
		void addLocation (LocationSp location) {
			locationsList.push_back(location);
			locationsNum++;
		}
		
		/**/
		LocationSp getLocation (string _location) {
			list<LocationSp>::iterator location = locationsList.begin();
			for (; location != locationsList.end(); ++location) {
				if ((*location)->getName() == _location) {
					return *location;
				}
			}
			
			return NULL;
		}
		
		/* Returns a desired location. */
		bool hasLocation (string _location) {
			list<LocationSp>::iterator location = locationsList.begin();
			for (; location != locationsList.end(); ++location) {
				if ((*location)->getName() == _location) {
					return true;
				}
			}
			
			return false;
		}
		
		/* Overload output operator. */
		friend ostream &operator<< (ostream &output, const Region &region) {
			output << "Region '" << region.name << "' with " << region.locationsNum << " locations: ";
		}
		
		/* Display region. */
		void display (void) {
			cout << "Region '" << name << "' with " << locationsNum << " locations. ";
			if (locationsNum) {
				cout << "It has the following locations: " << endl;
				displayLocations();
			} else {
				cout << endl;
			}
		}
		 
		/* Display locations. */
		void displayLocations (void) {
			list<LocationSp>::iterator iter = this->locationsList.begin();
			for (int i = 0; iter != this->locationsList.end(); ++iter, ++i) {
				cout << "--------- ";
				(*iter)->display();
 			}
		}
};

#endif
