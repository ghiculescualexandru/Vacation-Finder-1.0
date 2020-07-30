#ifndef BALLSPORT_H
#define BALLSPORT_H

#include "Sport.h"
using namespace std;

class BallSport: public Sport {
	
	public:
		/* Calling super class constructors. */
		BallSport (void)
		: Sport () {}
		BallSport (string _name, int _costPerDay, string _start, string _finish)
		: Sport(_name, _costPerDay, _start, _finish) {}
		
		/* Override the virtual method from the inherited class. */
		void getInfo() {
			cout << "This is a ball sport called " << getName() << "."<< endl;
		}
};

#endif
