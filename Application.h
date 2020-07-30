#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstring>
#include <list>
#include "Zone.h"
using namespace std;

typedef Zone* ZoneSp;

class Application {
	static Application *instance;
	Application () {
		/* Singleton design pattern. */
		zonesNum = 0;
	}
	list<ZoneSp> zonesList;
		/* List with all zones for vacation. */
	int zonesNum;
		/* Number of all zones for vacation. */
	
	public:
		static Application *getInstance () {
			if (!instance) {
				instance = new Application;
			}
			
			return instance;
		}
		
		/* Getters and setters. */
		void setZonesList (list<ZoneSp> _zonesList) {
			this->zonesList = _zonesList;
		}
		void setZonesNum (int _zonesNum) {
			this->zonesNum = _zonesNum;
		}
		list<ZoneSp> getZonesList (void) {
			return this->zonesList;
		}
		int getZonesNum (void) {
			return this->zonesNum;
		}
		
		/* Add zone. */
		void addZone (ZoneSp zone) {
			this->zonesList.push_back(zone);
			this->zonesNum++;
		}
		
		void addZone (string _zone) {
			if (!hasZone(_zone)) {
				ZoneSp newZone = new Zone(_zone);
				this->addZone(newZone);	
			}
		}
		
		/* Check for existing zone. */
		bool hasZone (string _zone) {
			list<ZoneSp>::iterator iter = zonesList.begin();
			for (; iter != zonesList.end(); ++iter) {
				if ((*iter)->getName() == _zone) {
					return true;
				}
			}
			
			return false;
		}
		
		/* Add country in a zone. */
		void addCountry (string _country, string _zone) {
			bool found = false;
			
			list<ZoneSp>::iterator iter = this->zonesList.begin();
			for (; iter != this->zonesList.end(); ++iter) {
				string zoneTemp = (*iter)->getName();
				if (zoneTemp == _zone) {
					if (!(*iter)->hasCountry(_country)) {
						Country *temp = new Country(_country);
						(*iter)->addCountry(temp);
					} 
							
					found = true;
				}
			}
			
			if (!found) {
				ZoneSp temp = new Zone(_zone);
				addZone(temp);
				addCountry(_country, _zone);
			}
		}
		
		/* Add region to a country. */
		void addRegion (string _region, string _country, string _zone) {			
			if (!hasZone(_zone)) {
				ZoneSp temp = new Zone(_zone);
				addZone(temp);
				addRegion(_region, _country, _zone);
			}
			
			list<ZoneSp>::iterator zone = this->zonesList.begin();
			for (; zone != this->zonesList.end(); ++zone) {
				string zoneTemp = (*zone)->getName();
				if (zoneTemp == _zone) {
					if((*zone)->hasCountry(_country)) {
						Region *temp = new Region(_region);
						Country *countryTemp = (*zone)->getCountry(_country);
						if (!countryTemp->hasRegion(_region)) {
							countryTemp->addRegion(temp);
						}
					} else {
						addCountry(_country, _zone);
						addRegion(_region, _country, _zone);
					}
				}
			}
		}
		
		/* Add location to a region. */
		void addLocation (string _location, string _region, string _country, string _zone) {
			if (!hasZone(_zone)) {
				ZoneSp temp = new Zone(_zone);
				addZone(temp);
				addLocation(_location, _region, _country, _zone);
			}
			
			list<ZoneSp>::iterator zone = this->zonesList.begin();
			for (; zone != this->zonesList.end(); ++zone) {
				string zoneTemp = (*zone)->getName();
				if (zoneTemp == _zone) {
					if((*zone)->hasCountry(_country)) {
						Country *countryTemp = (*zone)->getCountry(_country);
						if (countryTemp->hasRegion(_region)) {
							Location *temp = new Location(_location);
							Region *regionTemp = countryTemp->getRegion(_region);
							if (!regionTemp->hasLocation(_location)) {
								regionTemp->addLocation(temp);
							}
						} else {
							addRegion(_region, _country, _zone);
							addLocation(_location, _region, _country, _zone);
						}
					} else {
						addCountry(_country, _zone);
						addLocation(_location, _region, _country, _zone);
					}
				}
			}
		}
		
		/* Add sport to a location. */
		void addSport (string _sport, string _type, int _cost, string _start, string _finish, 
		string _location, string _region, string _country, string _zone) {
			if (!hasZone(_zone)) {
				ZoneSp temp = new Zone(_zone);
				addZone(temp);
				addSport(_sport, _type, _cost, _start, _finish,  _location, _region, _country, _zone);
			}
			
			list<ZoneSp>::iterator zone = this->zonesList.begin();
			for (; zone != zonesList.end(); ++zone) {
				string zoneTemp = (*zone)->getName();
				if (zoneTemp == _zone) {
					if ((*zone)->hasCountry(_country)) {
						Country *countryTemp = (*zone)->getCountry(_country);
						if (countryTemp->hasRegion(_region)) {
							Region* regionTemp = countryTemp->getRegion(_region);
							if (regionTemp->hasLocation(_location)) {
								Location* locationTemp = regionTemp->getLocation(_location);
								
								if (_type == "extreme") {
									ExtremeSport *newSport = new ExtremeSport(_sport, _cost, _start, _finish);
									locationTemp->addSport(newSport);
								} else if (_type == "ball") {
									BallSport *newSport = new BallSport(_sport, _cost, _start, _finish);
									locationTemp->addSport(newSport);
								} else if (_type == "relaxing") {
									RelaxingSport *newSport = new RelaxingSport(_sport, _cost, _start, _finish);
									locationTemp->addSport(newSport);
								} else {
									cout << "There is no such sport yet. " << endl;
								}		
							} else {
								addLocation(_location, _region, _country, _zone);
								addSport(_sport, _type, _cost, _start, _finish, _location, _region, _country, _zone);
							}
						} else {
							addRegion(_region, _country, _zone);
							addSport(_sport, _type, _cost, _start, _finish, _location, _region, _country, _zone);
						}
					} else {
						addCountry(_country, _zone);
						addSport(_sport, _type, _cost, _start, _finish, _location, _region, _country, _zone);
					}
				}
			}
		}
		
		/* Display zones. */
		void displayZones (void) {
			list<ZoneSp>::iterator zone = this->zonesList.begin();
			for (; zone != this->zonesList.end(); ++zone) {
				(*zone)->display();
			}
		}
		
};

Application *Application::instance = 0;

#endif
