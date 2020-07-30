#ifndef ZONE_H
#define ZONE_H

#include <cstring>
#include <list>
#include "Country.h"
using namespace std;

typedef Country* CountrySp;

class Zone {
	
	string name;
		/* Name of this zone. */
	list<CountrySp> countriesList;
		/* List with countries with type of zone. */
 	int countriesNum;
 		/* Number of countries with type of zone. */
 		
	public:
		/* Constructors. */
		Zone (void) {
			name = "no name";
		 	countriesNum = 0;
			/* cout << "Zone with no countries creating..." << endl;
			**/
		}
		
		Zone (string _name) {
			name = _name;
			countriesNum = 0;
			/* cout << "Zone '" << name << " with no countries yet added creating..." << endl; 
			**/
		}
		
		Zone (string _name, list<CountrySp> _countriesList, int _countriesNum) {
			name = _name;
			countriesList = _countriesList;
			countriesNum = _countriesNum;
			/* cout << "Zone '" << name << "' with " << countriesNum << " countries creating..." << endl;
			**/
		}
		
		/* Destructor. */
		~Zone (void) {
			/* cout << "Zone being deleted..." << endl;
			**/
		}
		/* Getters and setters. */
		void setName (string _name) {
			name = _name;
		}
		void setCountriesList (list<CountrySp> _countriesList) {
			countriesList = _countriesList;
		}
		void setCountriesNum (int _countriesNum) {
			countriesNum = _countriesNum;
		}
		string getName (void) {
			return name;
		}
		list<CountrySp> getCountriesList (void) {
			return countriesList;
		}
		int getCountriesNum (void) {
			return countriesNum;
		} 
		
		/* Add country. */
		void addCountry (CountrySp country) {
			countriesList.push_back(country);
			countriesNum++;
		}
		
		/* Returns the country desired. */
		CountrySp getCountry (string _country) {
			list<CountrySp>::iterator country = countriesList.begin();
			for (; country != countriesList.end(); ++country) {
				if ((*country)->getName() == _country) {
					return *country;
				}
			}
			
			return NULL;
		}
		
		/* Check for existing country. */
		bool hasCountry (string _country) {
			list<CountrySp>::iterator iter = countriesList.begin();
			for (; iter != countriesList.end(); ++iter) {
				if ((*iter)->getName() == _country) {
					return true;
				}
			}
			
			return false;
		}
		
		/* Overload output operator. */
		friend ostream &operator<< (ostream &output, const Zone &zone) {
			output << "Zone '" << zone.name << "' with " << zone.countriesNum << " countries: ";
		}
		
		/* Display zone. */
		void display (void) {
			cout << "Zone '" << name << "' with " << countriesNum << " countries. ";
			if (countriesNum) {
				cout << "It has the following countries: " << endl;
				displayCountries();	
			} else {
				cout << endl;
			}
		}
		
		/* Display countries. */
		void displayCountries (void) {
			list<CountrySp>::iterator iter = countriesList.begin();
			for (int i = 0; iter != countriesList.end(); ++iter, ++i) {
				cout << "--- ";
				(*iter)->display();
			}
		}
};

#endif
