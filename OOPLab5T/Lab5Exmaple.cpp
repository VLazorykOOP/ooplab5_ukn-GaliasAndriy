#include <fstream>
#include <iostream>
#include "Lab5Exmaple.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
using namespace std;

int mainTask1() {
	char Choice;
	do {
		cout << "\n---------| Main menu |--------\n";
		cout << "	1 - Default constructor Liquid \n";
		cout << "	2 - Default constructor AlcoholDrinks \n";
		cout << "	3 - Constructor AlcoholDrinks(string name, double dens, double stren) \n";
		cout << "	4 - Constuctor of copying (AlcoholDrinks& s) \n";
		cout << "	5 - Set densities \n";
		cout << "	6 - Set strength \n";

		cout << "	q - Quit \n\n";
		cout << "	Your choice: ";
		cin >> Choice;
		switch (Choice) {
			case '1': {
				Liquid test;
				cout << test.toString() << endl;
			} break; 
			case '2': {
				AlcoholDrinks alcohol;
				cout << alcohol.toString() << endl;
			} break; 
			case '3': {
				AlcoholDrinks shot("Jameson whiskey", 0.9408, 40);
				string res = shot.toString();
				cout << res << endl;
			} break;
			case '4': {
				AlcoholDrinks shot("Captain Morgan", 0.9901, 40);
				string res = shot.toString();
				cout << res << endl;
				AlcoholDrinks copyShot(shot);
				string copyRes = copyShot.toString();
				cout << copyRes << endl;
			} break;
			case '5': {
				AlcoholDrinks shot("Jagermeister", 1.0072, 40);
				shot.toString();
				cout << shot.toString() << endl;
				cout << " Change densities: ";
				float dens;
				while (!(cin >> dens)) {
					cin.clear();
					cin.ignore(MAXSHORT, '\n');
					cout << "bad input \n";
				};
				shot.setDensities(dens);
				cout << "\n    New record " << shot.toString() << endl;
			} break;
			case '6': {
				AlcoholDrinks shot("Oakheart", 0.9500, 35);
				shot.toString();
				cout << shot.toString() << endl;
				cout << " Change strength: ";
				float stren;
				while (!(cin >> stren)) {
					cin.clear();
					cin.ignore(MAXSHORT, '\n');
					cout << "bad input \n";
				};
				shot.setStrength(stren);
				cout << "\n    New record " << shot.toString() << endl;
			} 
			case 'q': break;
			default: cout << "	Make a choice from 1 to 6, or just quit... \n ";
		}

	} while (Choice != 'q');
	cout << " Exit from testing! " << endl;
	return 6;
}

int mainTask2() {
	char Choice;
	do {
		cout << "\n---------| Main menu |--------\n";
		cout << "	1 - Default constructor Wheel \n";
		cout << "	2 - Default constructor Bike \n";
		cout << "	3 - Wheel(float size, float thick, float price, string type, string brand) \n";
		cout << "	4 - Bike(float whSize, float thick, float price, string type, string brand,\n            float size, string bikType, string brType, string fDer, string bDer,\n            string f, string manuf) : Wheel(whSize, thick, price, type, brand) \n\n";
		cout << "	5 - Enter data about a bike, using function Input()\n";
		cout << "	6 - Constructor of copying for a Bike class\n";
		cout << "	7 - Constructor for a Car with params Bike(brakeType) and Wheel(...)\n";
		cout << "	8 - Input data about a car\n";

		cout << "	q - Quit \n\n";
		cout << "	Your choice: ";
		cin >> Choice;
		switch (Choice) {
			case '1': {
				Wheel test;
				cout << test.toString() << endl;
			} break;
			case '2': {
				Bike test;
				cout << test.toString() << endl;
			} break;
			case '3': {
				Wheel shimOffWheel(27.5, "2.2", 35, "off-road", "Shimano");
				cout << shimOffWheel.toString();
				Wheel shimRoadWheel(29, "1.5", 70.49, "road", "Shimano");
				cout << shimRoadWheel.toString();
			} break;
			case '4': {
				Bike expensiveBike(26, "2.1", 215.90, "off-road", "Swiss", "XL", "mountain bike",
					"hydraulic", "shimano XT", "shimano XT", "Rock Shock", "BMC Switzerland", 3149.00);
				cout << expensiveBike.toString();
			} break;
			case '5': {
				Bike test;
				cout << "\n\n Enter data about a bike: " << endl;
				test.Input();
				cout << "\n Entered data:\n" << test.toString() << endl;
			} break;
			case '6': {
				Bike expensiveBike(26, "2.1", 215.90, "off-road", "Swiss", "XL", "mountain bike",
					"hydraulic", "shimano XT", "shimano XT", "Rock Shock", "BMC Switzerland", 3149.00);
				cout << expensiveBike.toString();
				Bike theSameBike(expensiveBike);
				cout << "theSameBike(expensiveBike) " << endl;
				cout << theSameBike.toString() << endl;
			} break;
			case '7': {
				Car bmwCar("disc", 17, "275/35", 1000, "road", "Michelin", "BMW", "M850i", "sport car", 460, 2440, 100000);
				cout << bmwCar.toString() << endl;
			} break;
			case '8': {
				Car test;
				cout << "\n\n Enter data about a car: " << endl;
				test.Input();
				cout << "\n Entered data:\n" << test.toString() << endl;
			} break;
			case 'q': break;
			default: cout << "	Make a choice from 1 to 6, or just quit... \n ";

		}

	} while (Choice != 'q');
	cout << " Exit from testing! " << endl;
	return 77;
}

int mainTask3() {
	char Choice;
	do {
		cout << "\n---------| Main menu |--------\n";
		cout << " 1. Empty Lecturer class" << endl;
		cout << " 2. Enter information about a lecturer and people" << endl;
		cout << " 3. Constructor People(age, specialty, lecturerFullName, group, department, peopleFN)" << endl;
		cout << " 4. Constructor Lecturer(age, specialty, fullName &n)" << endl;
		cout << " 5. Read object from file" << endl;
		cout << " 6. Enter object and save it" << endl;
		cout << " 7. Constructor of move && forward" << endl;

		cout << "	q - Quit \n\n";
		cout << "	Your choice: ";
		cin >> Choice;
		switch (Choice) {
		case '1': {
			Lecturer test;
			cout << test.toString() << endl;
		} break;
		case '2': {
			People obj;
			obj.Input();
			cout << obj.toString() << endl;
		} break;
		case '3': {
			fullName fn("Jeanes", "Kovalyk", "Vasylivna");
			fullName peopleFN("Andriy", "Galias", "Vasylovych");
			People obj(35, "maths, DB", fn, 241, "Algorithmization&programming", peopleFN);

			fullName student1("Oleh", "Vaskiv", "Andriyovych");
			fullName student2("Alex", "Kodovbetskii", "Dmytrovych");
			People student11(241, "Algorithmization & programming", student1);
			People student22(241, "Algorithmization & programming", student2);
			cout << obj.toString() + student11.toStringOnlyPeople() + student22.toStringOnlyPeople() << endl;
		} break;
		case '4': {
			fullName fn("Jeanes", "Kovalyk", "Vasylivna");
			Lecturer lect(35, "maths, DB", fn);
			cout << lect.toString() << endl;
		} break;
		case '5': {
			ifstream fileObj("fileObj.txt");
			int n;
			fileObj >> n;
			if (n > 0) {
				People* obj;
				obj = new People[n];
				for (int i = 0; i < n; i++) {
					fileObj >> obj[i];
				}
				for (int i = 0; i < n; i++) {
					cout << obj[i].toString() << endl;
				}
				cout << "\n\n Then we'll delete this readed object" << endl;
				delete[] obj;
			}
		} break;
		case '6': {
			ofstream fileObj("fileObjSave.txt");
			int n = 0;
			People* newObj;
			n++;
			newObj = new People[1];
			for (int i = 0; i < 1; i++) {
				newObj[i].Input();
			}
			for (int i = 0; i < 1; i++) {
				cout << newObj[i].toString();
			}
			fileObj << n << endl;
			for (int i = 0; i < 1; i++) {
				fileObj << newObj[i];
			}
			cout << " \n\n New object was succesfully saved into a file" << endl;
			cout << " Deleting..." << endl;
			delete[] newObj;
		} break;
		case '7': {
			fullName fn("Vasyl", "Lazoryk", "Vasylovych");
			fullName peopleFN("Andriy", "Galias", "Vasylovych");
			People obj(55, "OOP/Java/Web-design", fn, 241, "MPUIK", peopleFN);
			cout << obj.toString() << endl;
			People mObj;
			cout << " Move constructor" << endl;
			mObj = (People)obj;
			cout << mObj.toString() << endl;
		} break;

		case 'q': break;
		default: cout << "	Make a choice from 1 to 6, or just quit... \n ";

		}
	} while (Choice != 'q');

	cout << " Exit from testing! " << endl;
	return 33;
}

ostream& operator<<(ostream& os, fullName& a) {
	os << a.firstName << endl;
	os << a.middleName << endl;
	os << a.lastName << endl;
	return os;
}
istream& operator>>(istream& is, fullName& a) {
	is >> a.firstName;
	is >> a.middleName;
	is >> a.lastName;
	return is;
}

istream& operator>>(istream& is, Lecturer& a) {
	if (a.name == nullptr) a.name = new fullName;
	is >> *(a.name);
	is >> a.age;
	is >> a.specialty;
	return is;
}
ostream& operator<<(ostream& os, Lecturer& a) {
	os << a.name;
	os << a.age << endl;
	os << a.specialty;
	return os;
}

istream& operator>>(istream& is, People& a) {
	if (a.name == nullptr) a.name = new fullName;
	is >> *(a.name);
	is >> a.age;
	is >> a.specialty;
	if (a.pName == nullptr) a.pName = new fullName;
	is >> *(a.pName);
	//if (a.group >= 100 && a.group <= 699) {
		is >> a.group;
	//}
	is >> a.department;

	return is;
}
ostream& operator<<(ostream& os, People& a) {
	if (a.name == nullptr) os << " Empty data about full name! ";
	os << *(a.name);
	os << a.age << endl;
	os << a.specialty << endl;
	os << *(a.pName);
	//if (a.group >= 100 && a.group <= 699) {
		os << a.group;
	//}
	/*else {
		os << " Such a group doesn't exist! " << endl;
	}*/
	os << a.department;
	return os;
}


