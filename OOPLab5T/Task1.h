#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Liquid {
private:
	string title;
	float densities;
public:
	Liquid() {
		title = "default";
		densities = NULL;
		cout << "	Liquid() default constructor " << endl;
	}
	Liquid(string name, float dens) {
		title = name;
		densities = dens;
		cout << "	Liquid with both parameters " << endl;
	}
	Liquid(const Liquid& s) {
		title = s.title;
		densities = s.densities;
		cout << "	Liquid copy parent " << endl;
	}
	Liquid(Liquid&& s) {
		title = s.title;
		densities = s.densities;
		cout << " Constructor move Liquid \n";
		s.title = "NoTitle";
		s.densities = NULL;
	}
	Liquid& operator=(const Liquid& s) {
		title = s.title;
		densities = s.densities;
		cout << " Liquid operator=(Liquid &) \n";
	}
	bool operator==(Liquid& b) {
		return title == b.title && densities == b.densities ? true : false;
	}

	string toString() {
		string dens, result;
		dens = to_string(densities);
		result = "	Name: " + title + "\n	densities: " + dens;
		return result;
	}
	~Liquid() {
		cout << "	Liquid destructor " << endl;
	}
	void Output() {
		cout << toString() << endl;
	}
	void setDensities(float dens) {
		if (dens >= 0.0010 && dens <= 1.3) {
			densities = dens;
		}
		else {
			cout << "	Densities " << dens << " is a wrong data, densities is " << densities << endl;
		}
	}
};

class AlcoholDrinks : public Liquid {
private:
	float strength;
public:
	AlcoholDrinks() {
		strength = NULL;
		cout << "	Child class AlcoholDrinks " << endl;
	}
	AlcoholDrinks(string name, float dens, float stren) : Liquid(name,dens) {
		strength = stren;
		cout << "	Constructor Alcohol(string name, double dens, double stren) " << endl;
	}

	AlcoholDrinks(const AlcoholDrinks& s) : Liquid(s) {
		strength = s.strength;
		cout << "	Derived copy class(reference) " << endl;
	}
	AlcoholDrinks& operator=(const AlcoholDrinks& s) {
		this->Liquid::operator=(s);
		strength = s.strength;
		cout << " AlcoholDrinks& operator =(const AlcoholDrinks&s) \n";
		return *this;
	}
	~AlcoholDrinks() {
		cout << "	AlcoholDrinks destructor " << endl;
	}
	string toString() {
		string stren;
		stren = to_string(strength);
		string result = Liquid::toString() + "\n	Strength:" + stren + " \n";
		return result;
	}
	void Output() {
		cout << toString() << endl;
	}
	void setStrength(float stren) {
		if (stren >= 0.5 && stren <= 65) {
			strength = stren;
		}
		else {
			cout << "	Strength " << stren << " is a wrong data" << endl;
		}
	}
};