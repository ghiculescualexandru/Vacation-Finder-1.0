#ifndef COUNTRY_H
#define COUNTRY_H

#include <cstring>
#include <list>
#include "Region.h"
using namespace std;

typedef Region* RegionSp;

class Country {
	string name;
		/* Name of this country. */
	list<RegionSp> regionsList;
		/* List with regions of this country. */
 	int regionsNum;
 		/* Number of regions of this country. */
 		
	public:
		/* Constructors. */
		Country (void) {
			name = "no name";
			regionsNum = 0;
			/* cout << "Country with no regions creating..." << endl;
			**/	
		}
		
		Country (string _name) {
			name = _name;
			regionsNum = 0;
			/* cout << "Country '" << name << "' with no regions yet added creating..." << endl;
			**/	
		}
		
		Country (string _name, list<RegionSp> _regionsList, int _regionsNum) {
			name = _name;
			regionsList = _regionsList;
			regionsNum = _regionsNum;
			/* cout << "Country '" << name << "' with " << regionsNum << " regions creating..." << endl;
			**/		
		}
		
		/* Destructor. */
		~Country (void) {
			/* cout << "Country being deleted..." << endl;
		    **/	
		}
		/* Getters and setters. */
		void setName (string _name) {
			name = _name;
		}
		void setRegionsList (list<RegionSp> _regionsList) {
			regionsList = _regionsList;
		}
		void setRegionsNum (int _regionsNum) {
			regionsNum = _regionsNum;
		}
		string getName (void) {
			return name;
		}
		list<RegionSp> getRegionsList (void) {
			return regionsList;
		}
		int getRegionsNum (void) {
			return regionsNum;
		} 
		
		/* Add region. */
		void addRegion (RegionSp region) {
			regionsList.push_back(region);
			regionsNum++;
		}
		
		/* Returns a desired region. */
		RegionSp getRegion (string _region) {
			list<RegionSp>::iterator region = regionsList.begin();
			for (; region != regionsList.end(); ++region) {
				if ((*region)->getName() == _region) {
					return *region;
				}
			}
			
			return NULL;
		}
		
		/* Check if a region exists. */
		bool hasRegion (string _region) {
			list<RegionSp>::iterator region = regionsList.begin();
			for (; region != regionsList.end(); ++region) {
				if ((*region)->getName() == _region) {
					return true;
				}
			}
			
			return false;
		}
		
		/* Overload output operator. */
		friend ostream &operator<< (ostream &output, const Country &country) {
			output << "Country '" << country.name << "' with " << country.regionsNum << " regions: ";
		}
		
		/* Display country. */
		void display (void) {
			cout << "Country '" << name << "' with " << regionsNum << " regions. ";
			if (regionsNum) {
				cout << "It has the following regions: " << endl;
				displayRegions();
			} else {
				cout << endl;
			}
		}
		
		/* Display regions. */
		void displayRegions (void) {
			list<RegionSp>::iterator iter = regionsList.begin();
			for (int i = 0; iter != regionsList.end(); ++iter, ++i) {
				cout << "------ ";
				(*iter)->display();
			}
		}


};

#endif
