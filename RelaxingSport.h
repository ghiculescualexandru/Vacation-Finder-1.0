#ifndef RELAXINGSPORT_H
#define RELAXINGSPORT_H

#include "Sport.h"
using namespace std;

class RelaxingSport: public Sport {
	
	public:
		/* Calling super class constructors. */
		RelaxingSport (void)
		: Sport () {}
		RelaxingSport (string _name, int _costPerDay, string _start, string _finish)
		: Sport(_name, _costPerDay, _start, _finish) {}
		
		
		/* Override the virtual method from the inherited class. */
		void getInfo() {
			cout << "This is a relaxing sport called " << getName() << "."<< endl;
		}
};

#endif
