#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <stdlib.h>
using namespace std;

class Date {
	int day, month, year;
	bool noDate;
	
	public:
		/* Constructors. */
		Date (void) {
			day = month = year = -1;
			noDate = true;
		} 
		
		Date (string date) {
			list<string> res = split(date, '/');
			list<string>::iterator it = res.begin();
			string dayStr = *it; advance(it,1);
			string monthStr = *it; advance(it,1);
			string yearStr = *it;
			
			stringstream dayTmp(dayStr);
			stringstream monthTmp(monthStr);
			stringstream yearTmp(yearStr);
			
			dayTmp >> day;
			monthTmp >> month;
			yearTmp >> year;
			noDate = false;
		}
		
		/* Destrcutor. */
		~Date (void) {
			/* cout << "Date being deleted..." << endl;
			**/
		}
		
		/* Returns true if a date is right, false otherwise. */
		bool available (void) {
			return noDate;
		}
		
		/* Returns a string with the format dd/mm/yyyy. */
		string toString (void) {
			char *result = (char*)malloc(11);
			sprintf(result, "%d/%d/%d", day, month, year);
			return result;
		}
		
		/* Overloading operators: < > =. */
		bool operator=(const Date& date) {
			this->day = date.day;
			this->month = date.month;
			this->year = date.year;
		}
		
		bool operator<(const Date& date) {
			if (this->year <= date.year) {
				if (this->month <= date.month) {
					if (this->day <= date.day) {
						return true;
					}
				} 
			}
			
			return false;
		}
		
		bool operator>(const Date& date) {
			if (this->year >= date.year) {
				if (this->month >= date.month) {
					if (this->day >= date.month) {
						return true;
					}
				}
			}
			
			return false;
		}
		
		/* Returns the difference in days between two dates. */
		int diff(Date* date) {
			int res = (date->year - this->year) * 365;
			cout << "step 1: "<<res << endl;
			res += (date->month - this->month) * 30;
			cout << "step 2 "<<res << endl;
			res += (date->day - this->day);
			
			return res;
		}
		
		/* Function to split a string by a specified delimiter. */
		std::list<std::string> split(const std::string& s, char delimiter) {
			std::list<std::string> tokens;
			std::string token;
			std::istringstream tokenStream(s);
			while (std::getline(tokenStream, token, delimiter)) {
				tokens.push_back(token);
			}
			return tokens;
		}
};

#endif
