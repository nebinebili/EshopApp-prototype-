#include<iostream>
#include<Windows.h>
#include "Database.h"
#include "Admin.h"
#include "Guest.h"
#include "Person.h"
#include "Products.h"

using namespace Databases;

namespace ECommerce {
	int choose;
	Database* db = new Database();

	void ProductsInDatabase(){
		Product* product1 = new Product(1, "Tv", "Samsung", 1200, 10, 3, 1);
		Product* product2 = new Product(2, "Phone", "Iphone", 1110, 15, 2, 3);
		db->products = new DbSet<Product>;
		db->products->add(product1);
		db->products->add(product2);
	}
	void Createadmin() {
		char* stringu = new char[10]{};
		char* stringp = new char[10]{};
		cout << "Enter username->";
		cin >> stringu;
		cout << "Enter Password->";
		cin >> stringp;

		Admin* admin = new Admin(1, stringu, stringp);
		db->admins = new DbSet<Admin>();
		db->admins->add(admin);
	}
	void UserInDatabase() {
		Guest* guest1 = new Guest(12, "kenan", "kenan123", "kenanidayetov", __TIME__);
		Guest* guest2 = new Guest(14, "emir", "emir123", "emiraslan", __TIME__);
		db->guests = new DbSet<Guest>();
		db->guests->add(guest1);
		db->guests->add(guest2);
	}
	void GuestSignUp() {
		int id;
		char* stringu = new char[10]{};
		char* stringp = new char[10]{};
		char* stringf = new char[10]{};
		cout << "Enter Id->";
		cin >>id;
		cout << "Enter Fullname->";
		cin >> stringf;
		cout << "Enter username->";
		cin >> stringu;
		cout << "Enter Password->";
		cin >> stringp;

		for (int i = 0; i < db->guests->GetCount(); i++)
		{
			if (db->guests->GetItems()[i]->GetUsername() == stringu) {
				throw DatabaseException("This username cannot be used", __LINE__, __FILE__, __TIME__);
				return;
			}
		}

		Guest* guest = new Guest(id, stringu, stringp, stringf, __TIME__);
		db->guests->add(guest);
		cout << "Sign up is successfully" << endl;
	}
	void GuestSignIN() {
		cout << "---------- Sign In ---------" << endl;
		char* stringu = new char[10]{};
		char* stringp = new char[10]{};
		cout << "Enter username->";
		cin >> stringu;
		cout << "Enter Password->";
		cin >> stringp;
		for (int i = 0; i < db->guests->GetCount(); i++)
		{
			if (db->guests->GetItems()[i]->GetUsername() == stringu && db->guests->GetItems()[i]->GetPassword() == stringp){
				Sleep(1000);
				cout << "User Sign In" << endl;
				return;
		    }
			else if (db->guests->GetItems()[i]->GetUsername() == stringu && db->guests->GetItems()[i]->GetPassword() != stringp) {
				throw DatabaseException("Password is wrong", __LINE__, __FILE__, __TIME__);
			}
		}
		throw DatabaseException("This user is not available", __LINE__, __FILE__, __TIME__);
	}
	void GuestDisplay() {
		cout << "----------- Products -----------" << endl;
		for (int i = 0; i < db->products->GetCount(); i++)
		{
			cout << "Id->" << db->products->GetItems()[i]->GetId() << endl;
			cout << "Name->" << db->products->GetItems()[i]->GetName() << endl << endl;
		}
		cout << "\t\t\tBuy[1]" << endl;
		cout << "\t\t\tShow Detail[2]" << endl;
		cout << "\t\t\tExit[3]" << endl;

		while (true)
		{
			int id, quantity;
			cout << "\nEnter option->";
			cin >> choose;
			if (choose == 1) {
				cout << "Enter buy product ID->";
				cin >> id;
				for (int i = 0; i < db->products->GetCount(); i++)
				{
					if (db->products->GetItems()[i]->GetId() == id) {
						cout << "-------- Product " << db->products->GetItems()[i]->GetName() << "------" << endl;
						cout << "Quantity->" << db->products->GetItems()[i]->GetQuantity() << endl;
						cout << "Enter buy product quantity->";
						cin >> quantity;
						cout << quantity << " " << db->products->GetItems()[i]->GetName() << " sold" << endl;
						int temp;
						temp = db->products->GetItems()[i]->GetQuantity() - quantity;
						if (temp == 0) {
							db->products->deleteByid(db->products->GetItems()[i]->GetId());
						}
						else if (temp != 0) {

						  db->products->GetItems()[i]->SetQuantity(temp);
						}
					}
				}
			}
			if (choose == 2) {
				cout << "Enter show info product ID->";
				cin >> id;
				cout << "------------ Product Info ------------" << endl;
				for (int i = 0; i < db->products->GetCount(); i++)
				{
					if (db->products->GetItems()[i]->GetId() == id) {
						db->products->GetItems()[i]->ShowProduct();
					}
				}
			}
			if (choose == 3) {
				break;
			}
		}

	}
	
	
	void start() {
		ProductsInDatabase();
		UserInDatabase();

		cout << "\t\t\tAdmin Click[1]" << endl;
		cout << "\t\t\tSign Up Guest Click[2]" << endl;
		cout << "\t\t\tSign In Guest Click[3]" << endl;
		
		cout << "Enter option->";
		cin >> choose;

		try
		{
			if (choose == 1) {

				Createadmin();

				cout << "\nExit[1]" << endl;
				cout << "Add Product[2]" << endl;
				cout << "Show All product[3]" << endl;
				cout << "Delete product[4]" << endl;
				cout << "Update Product[5]" << endl;

				while (true)
				{
					cout << "\nEnter choose->";
					cin >> choose;
					if (choose == 2) {
						cout << "----------- Add Product ------------" << endl;
						int id;
						char* name = new char[10]{};
						char* description = new char[20]{};
						double price, discount, tax, quantity;
						cout << "Enter Id->";
						cin >> id;
						cout << "Enter Product name->";
						cin.ignore();
						cin.getline(name, 10);
						cout << "Enter Product description->";
						cin.getline(description, 20);
						cout << "Enter Price->";
						cin >> price;
						cout << "Enter Discount->";
						cin >> discount;
						cout << "Enter Tax->";
						cin >> tax;
						cout << "Enter Quantity->";
						cin >> quantity;
						Product* product = new Product(id, name, description, price, discount, tax, quantity);
						db->products->add(product);
						cout << "Products adding...." << endl;
						Sleep(1000);
						cout << "Products added" << endl;
						delete[]name;
						delete[] description;
					}
					if (choose == 3) {
						db->products->show();
					}
					if (choose == 4) {
						cout << "---------- Delete Product -----------" << endl;
						int id;
						cout << "Enter delete product by Id->";
						cin >> id;
						db->products->deleteByid(id);
						cout << "Product deleting...." << endl;
						Sleep(1000);
						cout << "Product deleted" << endl;
					}
					if (choose == 5) {
						cout << "------------ Update Product -------------" << endl;
						int id;
						char* newname = new char[10]{};
						char* newdescription = new char[20]{};
						double newprice, newdiscount, newtax, newquantity;
						cout << "Enter Update Product Id->";
						cin >> id;
						cout << "Enter new name->";
						cin.ignore();
						cin.getline(newname, 10);
						cout << "Enter new description->";
						cin.getline(newdescription, 20);
						cout << "Enter new price->";
						cin >> newprice;
						cout << "Enter new discount->";
						cin >> newdiscount;
						cout << "Enter new tax->";
						cin >> newtax;
						cout << "Enter new quantity->";
						cin >> newquantity;

						db->products->UpdateProduct(id, newname, newdescription, newprice, newdiscount, newtax, newquantity);
						cout << "Products updating...." << endl;
						Sleep(1000);
						cout << "Products updated" << endl;
						delete[]newname;
						delete[]newdescription;
					}
					if (choose == 1) {
						break;
					}
				}
			}
			if (choose == 2) {
				GuestSignUp();
				GuestSignIN();
				GuestDisplay();
			}
			if (choose == 3) {
				GuestSignIN();
				GuestDisplay();
			}
		}
		catch (InvalidArgumentException ex)
		{
			ex.PrintMsg();
		}
		catch (DatabaseException ex)
		{
			ex.PrintMsg();
		}
		catch (NullException ex)
		{
			ex.PrintMsg();
		}
		
	}
	
};

void main() {
	ECommerce::start();
}