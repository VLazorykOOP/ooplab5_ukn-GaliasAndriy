#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <iomanip>
#include <locale>
#include <future>

using namespace std;

struct fullName {
	string firstName;
	string lastName;
	string middleName;

	fullName() {
		firstName = "No firstName";
		lastName = "No lastName";
		middleName = "No middleName";
	}
	fullName(string fn) {
		firstName = fn;
		lastName = ".";
		middleName = ".";
		cout << "firstName constructor" << endl;
	}
	fullName(string n[3]) {
		firstName = n[0];
		lastName = n[1];
		middleName = n[2];
		cout << "Full name in array constructor" << endl;
	}
	fullName(const fullName& s) {
		firstName = s.firstName;
		lastName = s.lastName;
		middleName = s.middleName;
		cout << "Constructor of copying fullName(const fullName &) \n";
	}
	fullName(fullName&& s) {
		firstName = s.firstName;
		lastName = s.lastName;
		middleName = s.middleName;
		cout << " fullName(fullName &&) \n";
		s.firstName = "No firstName";
		s.middleName = "No middleName";
		s.lastName = "No lastName";
	}
	fullName(const char* fn, const char* mn, const char* ln) {
		firstName = fn;
		middleName = mn;
		lastName = ln;
		cout << " Constructor fullName(const char * ) \n";
	}
	~fullName() {
		cout << "\n Destructor ~fullName() \n";
	}
	fullName& operator=(const fullName& s)
	{
		firstName = s.firstName;
		middleName = s.middleName;
		lastName = s.lastName;
		cout << " fullName operator=(PIB &) \n";
	}
	string toString() {
		string ts = " Full name: " + firstName + " " + middleName + " " + lastName + " ";
		return ts;
	}
	void Input() {
		cout << " Enter first name: "; cin >> firstName;
		cout << " Enter last name: "; cin >> lastName;
		cout << " Enter middle name: "; cin >> middleName;
	}
	friend ostream& operator<<(ostream& os, fullName& a);
	friend istream& operator>>(istream& is, fullName& a);
};

class Lecturer {
protected:
	int age;
	string specialty;
	fullName* name;
public:
	Lecturer() {
		age = 0;
		specialty = "undefined";
		name = nullptr;
		cout << "Empty Lecturer constructor" << endl;
	}
	Lecturer(int a, string sp, string n) {
		age = a;
		specialty = sp;
		name = new fullName;
		name->firstName = n;
		cout << " Constructor Lecturer with params and firstName" << endl;
	}
	Lecturer(int a, string sp, fullName& n) {
		age = a;
		specialty = sp;
		name = new fullName;
		name->firstName = n.firstName;
		name->lastName = n.lastName;
		name->middleName = n.middleName;
		cout << " Constructor Lecturer with all params" << endl;
	}
	Lecturer(const Lecturer& n) {
		age = n.age;
		specialty = n.specialty;
		name = new fullName;
		name->firstName = n.name->firstName;
		name->lastName = n.name->lastName;
		name->middleName = n.name->middleName;
		cout << " Constructor of copying Lecturer(const Lecturer& n) \n";
	}
	Lecturer(Lecturer&& n) {
		age = n.age;
		specialty = n.specialty;
		name = n.name;
		n.name = nullptr;
		n.age = 0;
		n.specialty = "no data";
		cout << " Constructor of moving Lecturer(Lecturer&& n) \n";
	}
	Lecturer& operator=(const Lecturer& s) {
		age = s.age;
		specialty = s.specialty;
		name = new fullName;
		name->firstName = s.name->firstName;
		name->lastName = s.name->lastName;
		name->middleName = s.name->middleName;
		cout << " operator=(const Lecturer& s)" << endl;

		return *this;
	}
	Lecturer& operator=(Lecturer&& s) {
		age = s.age;
		specialty = s.specialty;
		name = s.name;
		s.name = nullptr;
		s.age = 0;
		s.specialty = "no data";
		cout << " operator=(Lecturer&& s)\n";

		return *this;
	}
	~Lecturer() {
		if (name != nullptr) delete name;
		cout << " Destructor Lecturer" << endl;
		cout << "------------------------" << endl;
	}

	string toString() {
		string result, a;
		a = to_string(age);
		if (name == nullptr) {
			cout << "\n\n Data about a lecturer: " << endl;
			cout << "------------------------" << endl;
			result = " Full name: " + a + "\n Specialty: " + specialty;
		}
		else {
			cout << "\n\n Data about a lecturer: " << endl;
			cout << "------------------------" << endl;
			result = name->toString() + "\n Age: " + a + "\n Specialty: " + specialty;
		}

		return result;
	}

	void Input() {
		cout << " \n Enter next data about lecturer: " << endl;
		if (name == nullptr) {
			name = new fullName;
		}
		name->Input();
		cout << " Enter age: ";
		while (!(cin >> age) || (age < 18 || age > 100)) {
			cin.clear(); // Sometimes for some reasons some error flags are set. Cin will not accept any input data. So if we clear the cin, then the error flags are reset	
			cin.ignore(MAXSHORT, '\n');	// clear the buffer, clear previous variable
			fflush(stdin); // buffer for temporary storing of information
			cout << " Entered wrong format of age. Age is 19 to 110" << endl;
		}
		cout << " Enter main specialty of lecturer: "; cin >> specialty;
	}

	friend ostream& operator<<(ostream& os, Lecturer& a);
	friend istream& operator>>(istream& is, Lecturer& a);
};

class People : public Lecturer {
protected:
	int group;
	fullName* pName;
	string department;
public:
	People() {
		pName = nullptr;
		group = 0;
		department = "default";
		cout << " Default People constructor" << endl;
	}
	People(int a, string sp, fullName &fn, int gr, string depar, fullName &people) 
		: Lecturer(a, sp, fn) {
		pName = new fullName;
		pName->firstName = people.firstName;
		pName->lastName = people.lastName;
		pName->middleName = people.middleName;
		if (gr >= 100 && gr <= 699) {
			group = gr;
		}
		department = depar;
	}

	People(const People& s) : Lecturer(s) {
		if (s.group >= 100 && s.group <= 699) {
			group = s.group;
		}
		else {
			cout << " Invalid entered group" << endl;
			group;
		}
		department = s.department;
		cout << " People(const People& s) : Lecturer(s)" << endl;
	}
	People& operator=(const People& s) {
		this->Lecturer::operator=(s);
		group = s.group;
		department = s.department;
		cout << " People& operator=(const People& s)" << endl;
		return *this;
	}
	People(People&& s) {
		age = s.age;
		specialty = s.specialty;
		name = s.name;
		s.name = nullptr;
		s.age = 0;
		s.specialty = "no data";
		group = s.group;
		department = s.department;
		pName = s.pName;
		s.group = 0;
		s.pName = nullptr;
		s.department = "no data";	
		cout << " Contstructor People(People && s)" << endl;
	}
	~People() {
		if (pName != nullptr) delete[] pName;
		cout << " People destructor" << endl;
	}
	People& operator=(People&& s) {
		age = s.age;
		specialty = s.specialty;
		if (name) delete name;
		name = s.name;
		s.name = nullptr;
		s.age = 0;
		s.specialty = "no data";
		group = s.group;
		department = s.department;
		if (pName) delete pName;
		pName = s.pName;
		s.group = 0;
		s.department = "no data";
		s.pName = nullptr;
		cout << " People& operator=(People && s)" << endl;
		return *this;
	}

	void changeLecturer(int a, string sp, fullName &fn) {
		age = a;
		specialty = sp;
		name = new fullName;
		name->firstName = fn.firstName;
		name->lastName = fn.lastName;
		name->middleName = fn.middleName;
	}

	void Input() {
		Lecturer::Input();
		pName = new fullName;
		cout << "\n Enter next data about people: ";
		cout << "\n Enter your first name: "; cin >> pName->firstName;
		cout << " Enter your last name: "; cin >> pName->lastName;
		cout << " Enter your middle name: "; cin >> pName->middleName;
		do {
			cout << " Enter a group: ";
			cin >> group;
		} while (group <= 100 && group >= 699);
		cout << " Enter your department: "; cin >> department;
	}
	People(int gr, string depar, fullName& people) {
		pName = new fullName;
		pName->firstName = people.firstName;
		pName->lastName = people.lastName;
		pName->middleName = people.middleName;
		if (gr >= 100 && gr <= 699) {
			group = gr;
		}
		department = depar;
	}

	string toStringOnlyPeople() {
		string gr;
		gr = to_string(group);
		string result = "\n\n First name: " + pName->firstName
			+ "\n Middle name: " + pName->middleName + "\n Last name: " + pName->lastName + "\n Group: " + gr + "\n Department: " 
			+ department;
		return result;
	}
	string toString() {
		string gr;
		gr = to_string(group);
		string res = Lecturer::toString() + "\n\n Info about people" + "\n------------------------\n"
			+ " First name: " + pName->firstName + "\n Middle name: " + pName->middleName +
			"\n Last name: " + pName->lastName + "\n Group: " + gr + "\n Department: " + department;
		return res;
	}

	friend ostream& operator<<(ostream& os, People& a);
	friend istream& operator>>(istream& is, People& a);
}; 
