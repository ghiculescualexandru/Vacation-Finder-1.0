#include "Main.h"

using namespace std;

/* Welcome message.
**/
void displayWelcome() {
	cout << "Welcome!" << endl;
	cout << "At any time you want to exit the application, just type 'quit'." << endl;
}
/* Instructions before choosing admin or user.
**/
void displayInstructions() {
	cout << "Choose your position for the application: 'admin'/'user' (write it down). " << endl;
}

/* This function uses a list of lists with strings and based on it
 * calls app's functions to add sports, locations and so on. It basically
 * is a database from the textfile. 
**/
void dbAddToApp(Application *app, list<list<string> > database) {
	list<list<string> >::iterator line = database.begin();
	for (; line != database.end(); ++line) {
		list<string>::iterator el = (*line).begin();
		if ((*el) == "add") {
			advance(el, 1);
			
			if ((*el) == "zone") {
				advance(el, 1);
				string zone = *el;
				app->addZone(zone);
				
			} else if ((*el) == "country") {
				advance(el, 1);
				string country = *el;
				advance(el, 1);
				string zone = *el;
				app->addCountry(country, zone);
				
			} else if ((*el) == "region") {
				advance(el, 1);
				string region = *el;
				advance(el, 1);
				string country = *el;
				advance(el, 1);
				string zone = *el;
				app->addRegion(region, country, zone);
			
			} else if ((*el) == "location") {
				advance(el, 1);
				string location = *el;
				advance(el, 1);
				string region = *el;
				advance(el, 1);
				string country = *el;
				advance(el, 1);
				string zone = *el;
				app->addLocation(location, region, country, zone);
			
			} else if ((*el) == "sport") {
				advance(el, 1);
				string name = *el;
				advance(el, 1);
				string type = *el;
				
				advance(el, 1);
				string tmp = *el;
				stringstream aux(tmp);
				int cost = 0;
				aux >> cost;
				
				advance(el, 1);
				string start = *el;
				advance(el, 1);
				string finish = *el;
				advance(el, 1);
				string location = *el;
				advance(el, 1);
				string region = *el;
				advance(el, 1);
				string country = *el;
				advance(el, 1);
				string zone = *el;
				app->addSport(name, type, cost, start, finish, location, region, country, zone);
				
			}
		}
	}
}

/* This function writes an output to the database.
**/
void dbWrite(string _output) {
	ofstream databaseFile("database.txt", ios_base::app);	
	databaseFile << endl << _output;
}

void handleAddSport(Application *app, list<list<string> > database) {
	cout << "You must fill the information as following: " << endl;
	cout << "name-of-sport type-of-sport cost period location region country zone" << endl;
	cout << "Pay attention!" << endl;
	cout << "- cost must be a number;" << endl;
	cout << "- period is ignored for the moment;" << endl;
	cout << "- the other must be written in one word, for example: 'city' or 'city-of-silver'." << endl;
	cout << "Nou you are free to complete as following:" << endl;
	cout << "name-of-sport type-of-sport cost period location region country zone" << endl;
	
	string input, sport, type, tmpCost, start, finish, location, region, country, zone;
	getline(cin, input);

	istringstream iss(input);
	list<string> split(istream_iterator<string>{iss},
                    	 istream_iterator<string>());
    	   	 
    list<string>::iterator el = split.begin();
    sport = *el; advance(el, 1);
    type = *el; advance(el, 1);
    
	tmpCost = *el;
	stringstream aux(tmpCost);
	int cost = 0;
	aux >> cost;
	advance(el, 1);
	
	start = *el; advance(el, 1);
	finish = *el; advance(el, 1);
	region = *el; advance(el, 1);
	country = *el; advance(el, 1);
	zone = *el; advance(el, 1);

    int period[2] = {1,2};
    app->addSport(sport, type, cost, start, finish, location, region, country, zone);
    
    int length = input.length();
    char buffer[length + 1];
    strcpy(buffer, input.c_str());
    
    char *output = (char*)malloc(10 + length);
    sprintf(output, "add sport %s", buffer);
    
    dbWrite(output);
}

void handleAddLocation(Application *app, list<list<string> > database) {
	cout << "You must fill the information as following: " << endl;
	cout << "location region country zone" << endl;
	cout << "Pay attention! ";
	cout << "Words must be written in one word, for example: 'city' or 'city-of-silver'." << endl;
	cout << "Nou you are free to complete as following:" << endl;
	cout << "location region country zone" << endl;
	
	string input, location, region, country, zone;
	getline(cin, input);
	
	istringstream iss(input);
	list<string> split(istream_iterator<string>{iss},
                    	 istream_iterator<string>());
                    	 
    list<string>::iterator el = split.begin();
    location = *el; advance(el, 1);
    region = *el; advance(el, 1);
    country = *el; advance(el, 1);
    zone = *el; advance(el, 1);
    
    app->addLocation(location, region, country, zone);
    
    
    int length = input.length();
    char buffer[length + 1];
    strcpy(buffer, input.c_str());
    
    char *output = (char*)malloc(10 + length);
    sprintf(output, "add location %s", buffer);
    
    dbWrite(output);
}

void handleAddRegion(Application *app, list<list<string> > database) {
	cout << "You must fill the information as following: " << endl;
	cout << "region country zone" << endl;
	cout << "Pay attention! ";
	cout << "Words must be written in one word, for example: 'city' or 'city-of-silver'." << endl;
	cout << "Nou you are free to complete as following:" << endl;
	cout << "region country zone" << endl;
	
	string input, region, country, zone;
	getline(cin, input);
	
	istringstream iss(input);
	list<string> split(istream_iterator<string>{iss},
                    	 istream_iterator<string>());
                    	 
    list<string>::iterator el = split.begin();
    region = *el; advance(el, 1);
    country = *el; advance(el, 1);
    zone = *el; advance(el, 1);
    
    app->addRegion(region, country, zone);
      
    int length = input.length();
    char buffer[length + 1];
    strcpy(buffer, input.c_str());
    
    char *output = (char*)malloc(10 + length);
    sprintf(output, "add region %s", buffer);
    
    dbWrite(output);
}

void handleAddCountry(Application *app, list<list<string> > database) {
	cout << "You must fill the information as following: " << endl;
	cout << "country zone" << endl;
	cout << "Pay attention! ";
	cout << "Words must be written in one word, for example: 'usa' or 'united-states'." << endl;
	cout << "Nou you are free to complete as following:" << endl;
	cout << "country zone" << endl;
	
	string input, country, zone;
	getline(cin, input);
	
	istringstream iss(input);
	list<string> split(istream_iterator<string>{iss},
                    	 istream_iterator<string>());
                    	 
    list<string>::iterator el = split.begin();
    country = *el; advance(el, 1);
    zone = *el; advance(el, 1);
    
    app->addCountry(country, zone);

    int length = input.length();
    char buffer[length + 1];
    strcpy(buffer, input.c_str());
    
    char *output = (char*)malloc(10 + length);
    sprintf(output, "add country %s", buffer);
    
    dbWrite(output);
}

void handleAddZone(Application *app, list<list<string> > database) {
	cout << "You must fill the information as following: " << endl;
	cout << "zone" << endl;
	cout << "Pay attention! ";
	cout << "Words must be written in one word, for example: 'mountain' or 'urban-teritory'." << endl;
	cout << "Nou you are free to complete as following:" << endl;
	cout << "zone" << endl;
	
	string input, zone;
	getline(cin, input);
	
	istringstream iss(input);
	list<string> split(istream_iterator<string>{iss},
                    	 istream_iterator<string>());
                    	 
    list<string>::iterator el = split.begin();
    zone = *el;
    
    app->addZone(zone);

    int length = input.length();
    char buffer[length + 1];
    strcpy(buffer, input.c_str());
    
    char *output = (char*)malloc(10 + length);
    sprintf(output, "add zone %s", buffer);
    
    dbWrite(output);
}

void searchSport(Application *app, string _sport) {
	int cnt = 1;
		
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		list<Country*> countries = (*zone)->getCountriesList();
		list<Country*>::iterator country = countries.begin();
		for (; country != countries.end(); ++country) {
			list<Region*> regions = (*country)->getRegionsList();
			list<Region*>::iterator region = regions.begin();
			for (; region != regions.end(); ++region) {
				list<Location*> locations = (*region)->getLocationsList();
				list<Location*>::iterator location = locations.begin();
				for (; location != locations.end(); ++location) {
					list<Sport*> sports = (*location)->getSportsList();
					list<Sport*>::iterator sport = sports.begin();
					for (; sport != sports.end(); ++sport) {
						if ((*sport)->getName() == _sport) {
							
							if (cnt == 1) {
								cout << "You searched for " << _sport << ". Here are the results: " << endl;
							}
							
							cout << cnt++ << ". ---------------------------------------------" << endl;
							cout << "Cost per day: " << (*sport)->getCostPerDay() << endl;
							cout << "Period: " << (*sport)->getTimeline() << endl;					
							cout << "Location: " << (*location)->getName() << endl;
							cout << "Region: " << (*region)->getName() << endl;
							cout << "Country: " << (*country)->getName() << endl;
							cout << "Zone: " << (*zone)->getName() << endl;
						}
					}
				}
			}
		}
	}
	
	if (cnt == 1) {
		cout << "No information about this sport found." << endl;
	}
}

void searchLocation(Application *app, string _location) {
	bool found = false;
	
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		list<Country*> countries = (*zone)->getCountriesList();
		list<Country*>::iterator country = countries.begin();
		for (; country != countries.end(); ++country) {
			list<Region*> regions = (*country)->getRegionsList();
			list<Region*>::iterator region = regions.begin();
			for (; region != regions.end(); ++region) {
				list<Location*> locations = (*region)->getLocationsList();
				list<Location*>::iterator location = locations.begin();
				for(; location != locations.end(); ++location) {
					if ((*location)->getName() == _location) {
						if (!found) {
							cout << "Informations about the location: " << endl;
							found = true;
						}						
											
						cout << "In zone category: " << (*zone)->getName();
						cout << ", in country: " << (*country)->getName();
						cout << ", in region: " << (*region)->getName();
						(*location)->display();
 					}
				}
			}
		} 
	}
	
	if (!found) {
		cout << "The location you are looking for doesn't exist in our database. " << endl;
	}
}

void searchRegion(Application *app, string _region) {
	bool found = false;
	
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		list<Country*> countries = (*zone)->getCountriesList();
		list<Country*>::iterator country = countries.begin();
		for (; country != countries.end(); ++country) {
			list<Region*> regions = (*country)->getRegionsList();
			list<Region*>::iterator region = regions.begin();
			for (; region != regions.end(); ++region) {
				if ((*region)->getName() == _region) {
					if (!found) {
						cout << "Information about this region: " << endl;
						found = true;
					}
					
					cout << "In zone: " << (*zone)->getName();
					cout << ", in country: " << (*country)->getName();
					(*region)->display();
				}
			}
		}
	}
	
	if (!found) {
		cout << "The region you are looking for doesn't exist in our database." << endl; 
	}
}

void searchCountry(Application *app, string _country) {
	bool found = false;
	
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		list<Country*> countries = (*zone)->getCountriesList();
		list<Country*>::iterator country = countries.begin();
		for (; country != countries.end(); ++country) {
			if ((*country)->getName() == _country) {
				if (!found) {
					cout << "Information about the country: " << endl;
					found = true;
				}
				
				cout << "In zone: " << (*zone)->getName();
				(*country)->display();
			}
		}
	}
	
	if (!found) {
		cout << "The country you are looking for deosn't exist in our database. " << endl;
	}
}

void searchZone(Application *app, string _zone) {
	bool found = false;
	
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		if ((*zone)->getName() == _zone) {
			if (!found) {
				cout << "Information about this zone: " << endl;
				found = true;
			}
			
			(*zone)->display();
		}
	}
	
	if (!found) {
		cout << "The zone you are looking for doesn't exist in our database. " << endl;
	}
}

list<Sport*> searchPeriod(Application *app, string _start, string _finish) {
	list<Sport*> result;
	Date start(_start);
	Date finish(_finish);
	
	cout << start.toString() << endl;
	cout << finish.toString() << endl;
	
	int cnt = 1;
	
	list<Zone*> zones = app->getZonesList();
	list<Zone*>::iterator zone = zones.begin();
	for (; zone != zones.end(); ++zone) {
		list<Country*> countries = (*zone)->getCountriesList();
		list<Country*>::iterator country = countries.begin();
		for (; country != countries.end(); ++country) {
			list<Region*> regions = (*country)->getRegionsList();
			list<Region*>::iterator region = regions.begin();
			for (; region != regions.end(); ++region) {
				list<Location*> locations = (*region)->getLocationsList();
				list<Location*>::iterator location = locations.begin();
				for (; location != locations.end(); ++location) {
					list<Sport*> sports = (*location)->getSportsList();
					list<Sport*>::iterator sport = sports.begin();
					for (; sport != sports.end(); ++sport) {
						if ((*sport)->getStart() > start && (*sport)->getStart() < finish) {
							result.push_back(*sport);
							cout << cnt++ << ". ---------------------------------------------" << endl;
							cout << "Cost per day: " << (*sport)->getCostPerDay() << endl;
							cout << "Period: " << (*sport)->getTimeline() << endl;					
							cout << "Location: " << (*location)->getName() << endl;
							cout << "Region: " << (*region)->getName() << endl;
							cout << "Country: " << (*country)->getName() << endl;
							cout << "Zone: " << (*zone)->getName() << endl;
						}
						
					}
				}
			}
		}
	}
	
	return result;
}

void searchPeriodPrice(Application *app, string _start, string _finish, string _byPrice) {
	list<Sport*> sports = searchPeriod(app, _start, _finish);
	sports.sort();
	
	if (_byPrice == "higher") {
		sports.reverse();
	}
	
	list<Sport*>::iterator sport = sports.begin();
	for (int cnt = 1; sport != sports.end(); ++ sport) {
		cout << cnt++ << ". ---------------------------------------------" << endl;
		cout << "Name of sport: " << (*sport)->getName() << endl;
		cout << "Cost per day: " << (*sport)->getCostPerDay() << endl;
		cout << "Period: " << (*sport)->getTimeline() << endl;					
	}
}

void handleSearchSport(Application *app, list<list<string> > database) {
	cout << "Enter the name of the sport to find out locations and information about it." << endl;
	string sport;
	cin >> sport;
	searchSport(app, sport);
}

void handleSearchLocation(Application *app, list<list<string> > database) {
	cout << "Enter the name of the location you want to find information about." << endl;
	string location;
	cin >> location;
	searchLocation(app, location);
}

void handleSearchRegion(Application *app, list<list<string> > database) {
	cout << "Enter the name of the region you want to find information about." << endl;
	string region;
	cin >> region;
	searchRegion(app, region);
}

void handleSearchCountry(Application *app, list<list<string> > database) {
	cout << "Enter the name of the country you want to find information about." << endl;
	string country;
	cin >> country;
	searchCountry(app, country);
}

void handleSearchZone(Application *app, list<list<string> > database) {
	cout << "Enter the name of the zone you want to find information about." << endl;
	string zone;
	cin >> zone;
	searchZone(app, zone);
}

void handleSearchPeriod(Application *app, list<list<string> > database) {
	cout << "Enter the period you want to search for." << endl;
	cout << "Pay attention! You must enter as following:" << endl;
	cout << "dd/mm/yyyy" << endl;
	string start, finish;
	cout << "start: "; 
	cin >> start;
	cout << "finish: ";
	cin >> finish;
	searchPeriod(app, start, finish);
} 

void handlePeriodPrice(Application *app, list<list<string> > database) {
	cout << "Enter the period you want to search for." << endl;
	cout << "dd/mm/yyyy" << endl;
	string start, finish;
	cout << "start: "; 
	cin >> start;
	cout << "finish: ";
	cin >> finish;
	
	string byPrice;
	cout << "Do you want 'lower' or 'higher' first? Write down 'lower' or 'higher'." << endl;
	cin >> byPrice;
	searchPeriodPrice(app, start, finish, byPrice);	
}

void handleAllInformation(Application *app, list<list<string> > database) {
	cout << "Here is our database: " << endl;
	app->displayZones();
}

void handleAdmin(Application *app, list<list<string> > database) {
	cout << "You are now admin. Use following commands: " << endl;
	cout << "1. add sport" << endl;
	cout << "2. add location" << endl;
	cout << "3. add region" << endl;
	cout << "4. add country" << endl;
	cout << "5. add zone" << endl;
	cout << "6. all information" << endl;
	cout << "7. search sport" << endl;
	cout << "8. search location" << endl;
	cout << "9. search region" << endl;
	cout << "10. search country" << endl;
	cout << "11. search zone" << endl;
	
	string input;
	while (getline(cin, input)) {
		if (input == "add sport") {
			handleAddSport(app, database);
		} else if (input == "add location") {
			handleAddLocation(app, database);
		} else if (input == "add region") {
			handleAddRegion(app, database);
		} else if (input == "add country") {
			handleAddCountry(app, database);
		} else if (input == "add zone") {
			handleAddZone(app, database);
		} else if (input == "all information") {
			handleAllInformation(app, database);
		} else if (input == "search sport") {
			handleSearchSport(app, database);
		} else if (input == "search location") {
			handleSearchLocation(app, database);
		} else if (input == "search region") {
			handleSearchRegion(app, database);
		} else if (input == "search country") {
			handleSearchCountry(app, database);
		} else if (input == "search zone") {
			handleSearchZone(app, database);
		} else if (input == "quit") {
			displayInstructions();
			return;
		}
	}
}

void handleUser(Application *app, list<list<string> > database) {
	cout << "You are now user. Use following commands: " << endl;
	cout << "1. search sport" << endl;
	cout << "2. search location" << endl;
	cout << "3. search region" << endl;
	cout << "4. search country" << endl;
	cout << "5. search zone" << endl;
	cout << "6. all information" << endl;
	cout << "7. search period" << endl;
	cout << "8. period and price" << endl;
	
	string input;
	while (getline(cin, input)) {
		if (input == "search sport") {
			handleSearchSport(app, database);
		} else if (input == "search location") {
			handleSearchLocation(app, database);
		} else if (input == "search region") {
			handleSearchRegion(app, database);
		} else if (input == "search country") {
			handleSearchCountry(app, database);
		} else if (input == "search zone") {
			handleSearchZone(app, database);
		} else if (input == "all information") {
			handleAllInformation(app, database);
		} else if (input == "search period") {
			handleSearchPeriod(app, database);
		} else if (input == "period and price") {
			handlePeriodPrice(app, database);
		}else if (input == "quit") {
			displayInstructions();
			return;
		}
	}
}

int main () {
	/* cout << "Test starting..." << endl; */
	
	Application *app = app->getInstance();	
	list<list<string> > database;		
	handler::dbRead(&database);
	/* handler::dbDisplay(database); */
	
	dbAddToApp(app, database);	
	/* app->displayZones(); */
	
	displayWelcome();
	displayInstructions();
	
	string input;
	while (getline(cin, input)) {
		if (input == "user") {
			handleUser(app, database);
		} else if (input == "admin") {
			handleAdmin(app, database);
		} else if (input == "quit") {
			return 0;
		}
	}
}


