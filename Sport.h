#ifndef SPORT_H
#define SPORT_H

#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;

class Sport {
	
	string name;
		/* Name of this sport. */
	int costPerDay;
		/* Cost for one day for this sport. */
	Date start, finish;
		/* timeline[0] - first day
		 * timeline[1] - last day 
		**/
	
	public:
		/* Constructors. */
		Sport (void) {
			name = "no name";
			costPerDay = 0;
			start = Date();
			finish = Date();
			/* cout << "Sport with no parameters creating..." << endl;
			 */
		}
		
		Sport (string _name, int _costPerDay, string _start, string _finish) {
			name = _name;
			costPerDay = _costPerDay;
			start = Date(_start);
			finish = Date(_finish);
			/*	cout << "Sport '" << name << "' creating with: costPerDay = " << costPerDay;
			 *	cout << ", period = " << timeline[0] << "-" << timeline[1] << endl; 
			**/
		}
		
		/* Destructor. */
		~Sport () {
			/* cout << "Sport being deleted..." << endl;
			 */
		}
			
		/* Getters and setters. */ 
		void setName (string _name) {
			name = _name;
		}
		void setCostPerDay (int _costPerDay) {
			costPerDay = _costPerDay;
		}
		
		string getName (void) {
			return name;
		}
		int getCostPerDay (void) {
			return costPerDay;
		}
		string getTimeline (void) {
			return start.toString() + "-" + finish.toString();
		}
		Date getStart (void) {
			return start;
		}
		Date getFinish (void) {
			return finish;
		}
		 
		
		/* Overloading output operator. */
		/*
		friend ostream &operator<< (ostream &output, const Sport &sport) {
			if (!sport.start.available()) {
				output << "Sport has no details about timeline or cost.";
			} else {
				output << "Sport '" << sport.name << "' with: costPerDay = " << sport.costPerDay;
				output << ", period = " << sport.start.toString() << "-" << sport.finish.toString();
			}
			
			return output;
		}
		*/
		
		/* Overloading operators: < >*/
		bool operator< (const Sport& sport) {
			if (this->costPerDay > sport.costPerDay) {
				return true;
			}
			
			return false;
		}
		
		bool operator> (const Sport& sport) {
			if (this->costPerDay < sport.costPerDay) {
				return true;
			}
			
			return false;
		}
		
		/* Method to print details (same as <<). */
		void display (void) {
			if (!start.available() || !finish.available()) {
				cout << "Sport has no details about timeline or cost." << endl;
			} else {
				cout << "Sport '" << name << "' with: costPerDay = " << costPerDay;
				cout << ", period = " << start.toString() << "-" << finish.toString() << endl;
			}
		}
		
		/* Virtual method to be inherited by derived. */
		virtual void getInfo (void) = 0;

};

#endif
