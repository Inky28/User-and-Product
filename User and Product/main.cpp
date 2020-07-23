/*
Реалізувати програму для отримання даних про користувачів та продукти
Створити інтерфейс за допомогою якого можна буде отримувати дані та додавати дані
	Реалізувати два класа:
		1)Перший клас буде працювати з обєктом Database в якому будуть статичні 5 продуктів та 2 користувача
		2)Другий клас буде працювати з двама txt файлами в яких будуть знаходитись дані
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class User
{
private:
	string name;

public:
	User()
	{
		//EMPTY
	}

	User(string name)
	{
		SetName(name);
	}

	void SetName(string name)
	{
		if (!name.empty())
			this->name = name;
	}

	string GetName()
	{
		return name;
	}
};

class Product
{
private:
	string name;
	float price;
public:
	Product()
	{
		//EMPTY
	}

	Product(string name, float price)
	{
		SetName(name);
		SetPrice(price);
	}

	void SetName(string name)
	{
		if (!name.empty())
			this->name = name;
	}

	void SetPrice(float price)
	{
		if (price > 0 && price < 1000)
			this->price = price;
	}

	string GetName()
	{
		return name;
	}

	float GetPrice()
	{
		return price;
	}
};

class Database
{
private:
	vector<Product> products;
	vector<User> users;
public:
	Database()
	{
		Product prod1("Laptop", 400);
		Product prod2("Computer", 800);
		Product prod3("Phone", 200);
		Product prod4("Headphones", 50.99);
		Product prod5("Watch", 300);

		products.push_back(prod1);
		products.push_back(prod2);
		products.push_back(prod3);
		products.push_back(prod4);
		products.push_back(prod5);

		User user1("Igor");
		User user2("Taras");

		users.push_back(user1);
		users.push_back(user2);
	}

	void AddProduct(Product& product)
	{
		products.push_back(product);
	}

	void AddUser(User& user)
	{
		users.push_back(user);
	}

	Product& GetProduct(int index)
	{
		if (index >= 0 && index < products.size())
			return products[index];
	}

	User& GetUser(int index)
	{
		if (index >= 0 && index < users.size())
			return users[index];
	}

	vector<Product>& GetProducts()
	{
		return products;
	}

	vector<User>& GetUsers()
	{
		return users;
	}
};

class FyleSystem
{
public:
	virtual void WriteProduct(Product& prod) = 0;
	virtual void WriteUser(User& user) = 0;
	virtual vector<Product> ReadProductFromFile() = 0;
	virtual vector<User> ReadUserFromFile() = 0;
};

class FileSystemDatabase : FyleSystem
{
public:
	void WriteProduct(Product& prod) override
	{
		ofstream fout;
		fout.open("products.txt", ofstream::app);

		if (fout.is_open())
			fout.write((char*)&prod, sizeof(Product));
		else
			cout << "Error\n";
		fout.close();
	}

	void WriteUser(User& user) override
	{
		ofstream fout;
		fout.open("users.txt", ofstream::app);

		if (fout.is_open())
			fout.write((char*)&user, sizeof(User));
		else
			cout << "Error\n";

		fout.close();
	}

	vector<Product> ReadProductFromFile() override
	{
		ifstream fin;
		fin.open("products.txt");
		if (fin.is_open())
		{
			vector<Product> products;
			Product product;
			while (fin.read((char*)&product, sizeof(Product)))
				products.push_back(product);
		}
		else
			cout << "Error\n";

		fin.close();
	}

	vector <User> ReadUserFromFile() override
	{
		ifstream fin;
		fin.open("users.txt");
		if (fin.is_open())
		{
			vector<User> users;
			User user;
			while (fin.read((char*)&user, sizeof(User)))
				users.push_back(user);
		}
		else
			cout << "Error\n";
		fin.close();
	}
};

int main()
{


	return 0;
}