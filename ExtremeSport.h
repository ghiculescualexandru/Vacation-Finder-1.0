#ifndef EXTREMESPORT_H
#define EXTREMESPORT_H

#include "Sport.h"
using namespace std; 

class ExtremeSport: public Sport {
	
	public:
		/* Calling super class constructors. */
		ExtremeSport (void)
		: Sport() {}
		ExtremeSport (string _name, int _costPerDay, string _start, string _finish)
		: Sport(_name, _costPerDay, _start, _finish) {}
		
		/* Override the virtual method from the inherited class. */
		void getInfo (void) {
			cout << "This is an extreme sport called " << getName() << "."<< endl;
		}
};

#endif
