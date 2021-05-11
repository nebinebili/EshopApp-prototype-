#pragma once

#include<iostream>
#include "Admin.h"
#include "Products.h"
#include "Guest.h"

using namespace std;
using namespace Admins;
using namespace Guests;
using namespace Products;

namespace Databases {

	template<typename T>
	class DbSet {
		T** items = NULL;
		int count = 0;
	public:
		int GetCount()const{
			return count;
		}
		T** GetItems()const{
			return items;
		}
		void add(T* item) {
			T** newitems = new T * [count + 1];
			for (int i = 0; i < count; i++)
			{
				newitems[i] = items[i];
			}
			newitems[count] = item;

			delete[] items;
			items = newitems;
			newitems = nullptr;
			count++;
		}
		void deleteByid(const int& id) {
			for (int i = 0; i < count; i++)
			{
				if (items[i]->GetId() == id) {
					auto newitems = new T * [count - 1];

					for (int k = 0, j = 0; j <count; j++)
					{
						if (j != i)
							newitems[k++] = items[j];
					}

					delete[] items;
					items=newitems;
					newitems = nullptr;
					count--;

					
				}
			}
		}

		T* getItem(const int& id) {
			for (int i = 0; i < count; i++)
			{
				if (items[i]->GetId() == id) {
					return items[i];
				}
			}
		}
		void UpdateProduct(const int& id,const string& newname,const string& newdecription,
			const double& newprice,const double& newdiscount,const double& newtax,const int& newquantity) {
			for (int i = 0; i < count; i++)
			{
				if (items[i]->GetId() == id) {
					items[i]->SetName(newname);
					items[i]->SetDescription(newdecription);
					items[i]->SetPrice(newprice);
					items[i]->SetDiscount(newdiscount);
					items[i]->SetTax(newtax);
					items[i]->SetQuantity(newquantity);
					return;
				}
			}
		}
		void show() {
			cout << "----------- Products Info -------------" << endl;
			for (int i = 0; i < count; i++)
			{
				items[i]->ShowProduct();
				cout << endl;
			}
		}
	};

	class Database {
	public:
		DbSet<Admin>* admins;
		DbSet<Product>* products;
		DbSet<Guest>* guests;
		
		Database() :products(), admins(), guests(){};
		
		Database(DbSet<Admin>* admins, DbSet<Guest>* guests, DbSet<Product>* products)
		{
			this->admins = admins;
			this->guests = guests;
			this->products = products;
		}
	};
}