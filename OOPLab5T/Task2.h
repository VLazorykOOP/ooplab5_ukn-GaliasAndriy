#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <iomanip>
#include <locale>

using namespace std;

class Wheel {
private: 
	float wheelSize;
	string wheelThiñkness;
	string wheelType; // for car or a car
	float wheelPrice;
	string wheelBrand;
public:
	Wheel() {
		wheelSize = NULL; wheelThiñkness = "no data";
		wheelType = "no data"; wheelBrand = "no data";
		wheelPrice = NULL;
		cout << "	Default wheel constructor" << endl;
	}
	Wheel(float size, string thick, float price, string type, string brand) {
		wheelSize = size;
		wheelThiñkness = thick;
		wheelPrice = price;
		wheelType = type;
		wheelBrand = brand;
		cout << "	Wheel(size, thick, price, type, brand)" << endl;
	}
	Wheel(const Wheel& s) {
		wheelSize = s.wheelSize;
		wheelThiñkness = s.wheelThiñkness;
		wheelPrice = s.wheelPrice;
		wheelType = s.wheelType;
		wheelBrand = s.wheelBrand;
		cout << "	Constr copy Wheel(const Wheel& s)" << endl;
	}
	Wheel& operator=(const Wheel& s) {
		wheelSize = s.wheelSize;
		wheelThiñkness = s.wheelThiñkness;
		wheelPrice = s.wheelPrice;
		wheelType = s.wheelType;
		wheelBrand = s.wheelBrand;
		cout << "	operator=(const Wheel& s)" << endl;
		return *this;
	}
	~Wheel() {
		cout << "Destructor Wheel\n";
	}
	void setPrice(float price) {
		wheelPrice = price;
	}
	string toString() {
		string price, thick, size, result;
		price = to_string(wheelPrice);
		size = to_string(wheelSize);
		result = "\n-----Info about wheel-----\n Brand: " + wheelBrand + "\n Type: " + wheelType 
			+ "\n Size: " + size + "\n Thickness: " + wheelThiñkness + "\n Price: " + price + "$\n--------------------------\n";
		return result;
	}
	void Input() {
		cout << "\n Enter next data about a wheel: " << endl;
		cout << " Enter brand or manufacturer: "; cin >> wheelBrand;
		cout << " Enter type: "; cin >> wheelType;
		cout << " Enter size: "; while (!(cin >> wheelSize) || (wheelSize < 5 || wheelSize > 100)) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << " Bad entered wheelSize is 5 to 100 \n";
		};
		cout << " Enter thickness: "; cin >> wheelType;
		cout << " Enter price: "; while (!(cin >> wheelPrice) || (wheelSize < 2 || wheelSize > 90000)) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << " Bad entered wheelPrice is 2$ to 90000$ \n";
		};
	}
};

class Bike : public Wheel {
protected: 
	string frameSize;
	string bikeType;
	string brakeType;
	string frontDerailleur;
	string backDerailleur;
	string fork;
	string manufacturer; // *
	float bikePrice;
public: 
	Bike() {
		bikePrice = NULL;
		frameSize = "no data";
		brakeType = "no data"; frontDerailleur = "no data"; backDerailleur = "no data";
		manufacturer = "default"; fork = "no data"; bikeType = "no data";
		cout << " Default constructor Bike" << endl;
	}
	Bike(float whSize, string thick, float price, string type, string brand,
		string size, string bikType, string brType, string fDer, string bDer, string f, string manuf, float pr) 
		: Wheel(whSize, thick, price, type, brand) {
		frameSize = size; bikeType = bikType; brakeType = brType; frontDerailleur = fDer; backDerailleur = bDer;
		fork = f; manufacturer = manuf; bikePrice = pr;
		cout << " Bike(whSize, ..., params) : Wheel(whSize, ...)" << endl;
	}
	Bike(const Bike& s) : Wheel(s) {
		frameSize = s.frameSize; bikeType = s.bikeType; brakeType = s.brakeType;
		frontDerailleur = s.frontDerailleur; backDerailleur = s.backDerailleur;
		fork = s.fork; manufacturer = s.manufacturer; bikePrice = s.bikePrice;
		cout << " Constr copy Bike(const Bike& s) : Wheel(s)" << endl;
	}
	~Bike() {
		cout << " Destructor Bike" << endl;
	}
	Bike& operator=(const Bike& s) {
		this->Wheel::operator=(s);
		frameSize = s.frameSize; bikeType = s.bikeType; brakeType = s.brakeType;
		frontDerailleur = s.frontDerailleur; backDerailleur = s.backDerailleur;
		fork = s.fork; manufacturer = s.manufacturer; bikePrice = s.bikePrice;
		cout << " Bike& operator=(const Bike& s)" << endl;
		return* this;
	}
	void setDerailleurs(string fDer, string bDer) {
		frontDerailleur = fDer;
		backDerailleur = bDer;	
	}
	string formatWithCommas(long long number) {
		string number_str = to_string(number);

		for (int i = number_str.length() - 3; i > 0; i -= 3)
			number_str.insert(i, ",");
		return number_str;
	}
	string toString() {
		string bPrice, result;
		//bPrice = to_string(bikePrice);
		cout << "\n----------Information about bike----------" << endl;
		result = Wheel::toString() + "\n Manufacturer: " + manufacturer + "\n Bike type: " + bikeType
			+ "\n Frame size: " + frameSize + "\n Fork: " + fork + "\n Brake type: " + brakeType
			+ "\n Front derailleur: " + frontDerailleur + "\n Back derailleur: " + backDerailleur + "\n"
			+ "\n Total price: " + formatWithCommas(bikePrice) + "$\n\n";
		return result;
	}
	string toStringOnlyBrakes() {
		string result;
		cout << "\n------------------------------------------" << endl;
		result = Wheel::toString();
		return result;
	}
	void Input() {
		Wheel::Input();
		cout << "\n Pass next data about a bike: " << endl;
		cout << " Manufacturer: "; cin >> manufacturer;
		cout << " Bike type: "; cin >> bikeType;
		do {
			cout << " Frame size (XXS/XS/S/M/L/XL): ";
			cin >> frameSize;
		} while (frameSize.length() >= 4 && frameSize.length() <= 0);
		cout << " Fork: "; cin >> fork;
		cout << " Brake type: "; cin >> brakeType;
		cout << " Front derailleur: "; cin >> frontDerailleur;
		cout << " Back derailleur: "; cin >> backDerailleur;
		cout << " Bike price: "; cin >> bikePrice;
	}	
	void InputOnlyBrakes() {
		Wheel::Input();
	}
	void Output() {
		cout << toString() << endl;
	}
	Bike(string brType, float whSize, string thick, float price, string type, string brand) 
		: Wheel(whSize, thick, price, type, brand){
		bikePrice = NULL;
		brakeType = brType;
		frameSize = "no data";
		frontDerailleur = "no data"; backDerailleur = "no data";
		manufacturer = "default"; fork = "no data"; bikeType = "no data";
		cout << " Bike(string brakeType) for filling data about car" << endl;
	}
};

class Car : public Bike {
private: 
	string carBrand;
	string model;
	string typeCar;
	int HP;
	int weight;
	int carPrice;
public:
	Car() {
		carBrand = "default"; model = ""; typeCar = ""; HP = NULL; weight = NULL; carPrice = NULL;
		cout << " Default constructor" << endl;
	}
	Car(string brType, float whSize, string thick, float price, string type, string brand, 
		string c_brand, string m, string t, int hp, int w, int pr)
		: Bike(brType, whSize, thick, price, type, brand) {
		carBrand = c_brand; model = m; typeCar = t; HP = hp; weight = w; carPrice = pr;
		cout << " Car(carBrand, ..., params) : Wheel(whSize, ...)" << endl;
	}
	Car(const Car& s) : Bike(s) {
		carBrand = s.carBrand; model = s.model; typeCar = s.typeCar;
		HP = s.HP; weight = s.weight; carPrice = s.carPrice;
		cout << " Constr copy Car(const Car& s) : Wheel(s)" << endl;
	}
	~Car() {
		cout << " Destructor Car" << endl;
	}
	Car& operator=(const Car& s) {
		this->Bike::operator=(s);
		carBrand = s.carBrand; model = s.model; typeCar = s.typeCar;
		HP = s.HP; weight = s.weight; carPrice = s.carPrice;
		cout << " Car& operator=(const Car& s)" << endl;
		return *this;
	}
	void setPrice(int pr) {
		if (pr > 120 && pr < 2000000) carPrice = pr;
		else carPrice = 1000;
	}
	string formatWithCommas(long long number) {
		string number_str = to_string(number);

		for (int i = number_str.length() - 3; i > 0; i -= 3)
			number_str.insert(i, ",");
		return number_str;
	}
	string toString() {
		string hp, wei, pr, br, result;
		hp = to_string(HP);
		wei = to_string(weight);
		cout << "\n----------Information about a car----------" << endl;
		result = Wheel::toString() + "\n Brand: " + carBrand + "\n Model: " + model
			+ "\n Type: " + typeCar + "\n HP: " + hp + "\n Weight: " + wei + "\n Brakes: " + brakeType // brakes was taken from Bike class
			+ "\n Total price: " + formatWithCommas(carPrice) + "$\n\n";
		return result;
	}
	void Input() {
		Bike::InputOnlyBrakes();
		cout << "\n Pass next data about a car: " << endl;
		cout << " Brand: "; cin >> carBrand;
		cout << " Model: "; cin >> model;
		cout << " Type: "; cin >> typeCar;
		cout << " Brakes: "; cin >> brakeType;
		do {
			cout << " HP (35 < HP < 1200): "; 
			cin >> HP;
		} while (HP < 35 && HP > 1200);
		do {
			cout << " Weight (520 < weight < 10000): ";
			cin >> weight;
		} while (weight < 520 && weight > 10000);
		do {
			cout << " Price (120 < price < 2000000): ";
			cin >> carPrice;
		} while (carPrice < 120 && carPrice > 2000000);
	}
	void Output() {
		cout << toString() << endl;
	}
};

