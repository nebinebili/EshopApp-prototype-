#pragma once

#include<iostream>
#include<ctime>
#include "Person.h"
using namespace std;
using namespace Persons;

namespace Guests {
	class Guest :public Person {
		string fullname;
		string connected_date;
	public:
		Guest(const int id,const string& username,const string& password,const string& fullname, const string& connected_date)
			:Person(id,username,password)
		{
			SetFullname(fullname);
			SetConnectedDate(connected_date);
		}
		string GetFullname()const {
			return fullname;
		}
		string GetConnentedDate()const {
			return connected_date;
		}
		void SetConnectedDate(const string connected_date) {
			if (connected_date.empty()) return;

			time_t currently = time(0);
			char dt[30]{};
			ctime_s(dt, sizeof dt, &currently);
			string time = dt;

			this->connected_date = dt;
		}
		void SetFullname(const string fullname) {
			if (fullname == " ") {
				throw NullException("Fullname is Empty", __LINE__, __FILE__, __TIME__);
			}
			this->fullname = fullname;
		}
		void Show()override{
			Person::Show();
			cout << "Fullname->" << fullname << endl;
			cout << "Connented Date->" << connected_date << endl;
		}
	};
}