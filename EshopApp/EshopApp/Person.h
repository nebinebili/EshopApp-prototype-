#pragma once
#include"Exception.h"
#include<iostream>
using namespace std;
using namespace ExceptionNamespace;

namespace Persons {
	class Person {
		int id;
		string username;
		string password;
	public:
		Person(const int id,const string& username,const string& password)
		{
			SetId(id);
			SetUsername(username);
			SetPassword(password);
		}
		int GetId()const {
			return id;
		}
		string GetUsername()const {
			return username;
		}
		string GetPassword()const {
			return password;
		}
		void SetUsername(const string username) {
			if (username == " ") {
				throw NullException(" Username is Empty", __LINE__, __FILE__, __TIME__);
			}
			this->username = username;
		}
		void SetPassword(const string password) {
			if (password == " ") {
				throw NullException("Password is Empty", __LINE__, __FILE__, __TIME__);
			}
			this->password = password;
		}
		void SetId(const int id) {
			if (id < 0) {
				throw InvalidArgumentException("Id is smaller than 0", __LINE__, __FILE__, __TIME__);
			}
			this->id = id;
		}

	    virtual void Show(){
			cout << "Id->" << id << endl;
			cout << "Username->" << username << endl;
			cout << "Password->" << password << endl;
		}
	};
}