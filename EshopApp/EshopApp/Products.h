#pragma once
#include"Exception.h"
#include<iostream>
using namespace std;
using namespace ExceptionNamespace;

namespace Products {
	class Product {
		int id; //avtomatik
		string name;
		string description;
		double price;
		double discount;
		double tax; //vergi faizi
		int quantity;
	public:
		Product() :id(), name(), description(), price(), discount(), tax(),quantity() {};
		
		Product(const int id,const string name,const string description,const double price,const double discount,const double tax,
			const int quantity)
		{
		  SetId(id);
		  SetName(name);
		  SetDescription(description);
		  SetPrice(price);
		  SetDiscount(discount);
		  SetTax(tax);
		  SetQuantity(quantity);
		}
		int GetId()const{
			return id;
		}
		string GetName()const{
			return name;
		}
		string GetDescription()const{
			return description;
		}
		double GetPrice()const{
			return price;
		}
		double GetDiscount()const{
			return discount;
		}
		double GetTax()const{
			return tax;
		}
		int GetQuantity()const{
			return quantity;
		}

		void SetId(const int id) {
			if (id < 0) {
				throw InvalidArgumentException("Id smaller than zero",__LINE__,__FILE__,__TIME__);
			}
			this->id = id;
		}
		void SetName(const string name) {
			if (name == " ") {
				throw NullException("Name is NUll", __LINE__, __FILE__, __TIME__);
			}
			this->name = name;
		}
		void SetDescription(const string description) {
			if (description == " ") {
				throw NullException("Description is NUll", __LINE__, __FILE__, __TIME__);
			}
			this->description = description;
		}
		void SetPrice(const double price) {
			if (price < 0) {
				throw InvalidArgumentException("Price smaller than 0", __LINE__, __FILE__, __TIME__);
			}
			this->price = price;
		}
		void SetDiscount(const double discount) {
			if (discount < 0) {
				throw InvalidArgumentException("Discount smaller than 0", __LINE__, __FILE__, __TIME__);
			}
			this->discount = discount;
		}
		void SetTax(const double tax) {
			if (tax < 0) {
				throw InvalidArgumentException("Tax smaller than 0", __LINE__, __FILE__, __TIME__);
			}
			this->tax = tax;
		}
		void SetQuantity(const int quantity) {
			if (quantity < 0) {
				throw InvalidArgumentException("Quantity smaller than 0", __LINE__, __FILE__, __TIME__);
			}
			this->quantity = quantity;
		}

		void ShowProduct() {
			cout << "Id->" << GetId() << endl;
			cout << "Name->" << GetName() << endl;
			cout << "Description->" << GetDescription() << endl;
			cout << "Price->" << GetPrice() << endl;
			cout << "Discount->" << GetDiscount() << endl;
			cout << "Tax->" << GetTax() << endl;
			cout << "Quantity->" << GetQuantity() << endl;
		}
	};
	
}