#pragma once

#include<iostream>
#include"Person.h"
using namespace std;
using namespace Persons;

namespace Admins {
	class Admin :public Person {
	public:
		Admin(const int id, const string& username, const string& password)
			:Person(id,username,password)
		{
			
		}
	};
}