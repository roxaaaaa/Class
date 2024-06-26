#include "Room.h"

Room::Room()
{
	number = 100;
	s = 1.0;
	desk2 = 0;
	desk3 = 0;

}

Room::Room(const Room& m)
{
	number = m.number;
	s = m.s;
	desk2 = m.desk2;
	desk3 = m.desk3;
}

Room::Room(int number, float s, int desk2, int desk3) : number(number), s(s), desk2(desk2), desk3(desk3) {}

void Room::print() const {
	cout << "Number: " << number << endl;
	cout << "S: " << s << endl;
	cout << "Seats: " << desk2 * 2 + desk3 * 3 << endl;
	cout << "The room is on " << find_floor() << " floor;" << endl;
	cout << "------------" << endl;
}

int Room::find_floor() const
{
	int floor = number / 100;
	return floor;
}

void Room::create()
{
	cout << "Number: ";
	cin >> number;
	if (number < 100 ||  number > 999) {
		return;
	}
	cout << "S: ";
	cin >> s;
	cout << "Desks w 2 seats: ";
	cin >> desk2; 
	cout << "Desks w 3 seats: ";
	cin >> desk3;
}

int Room::get_seats() const
{
	return desk2*2+desk3*3;
}

float Room::get_s() const
{
	return s;
}

int Room::get_number() const
{
	return number;
}



Multy::Multy() : Room()
{
	equipment.push_back(" ");
}

Multy::Multy(const Multy& t) : Room(t)
{
	equipment = t.equipment;
}


Multy::Multy(int number, float s, int desk2, int desk3, list<string> equipment) : Room(number, s, desk2, desk3), equipment(equipment) {}

void Multy::print() const {
	cout << "Number: " << this->number << endl;
	cout << "S: " << s << endl;
	cout << "Seats: " << this->desk2*2 + this->desk3*3 << endl;
	cout << "The room is on " << find_floor() << " floor;" << endl;
	cout << "Equipments: ";
	for (const auto& i : equipment) {
		cout << i << " ";
	}
	cout << endl;
}

void Multy::create()
{
	cout << "Number: ";
	cin >> this->number;
	if (this->number < 100 || this->number > 999) {
		return;
	}
	cout << "S: ";
	cin >> this->s;
	cout << "Desks w 2 seats: ";
	cin >> this->desk2;
	cout << "Desks w 3 seats: ";
	cin >> this->desk3;
	cout << "enter the number of equpments: ";
	int n;
	cin >> n;
	for (int i(0); i < n; i++) {
		cout << i+1 << " :";
		string eq;
		cin >> eq;
		equipment.push_back(eq);
 	}
}

istream& operator>>(istream& is, Room& r)
{
	is >> r.number >> r.s >> r.desk2 >> r.desk3;
	return is;
}

istream& operator>>(istream& is, Multy& r)
{
	is >> r.number >> r.s >> r.desk2 >> r.desk3;

	int counter;
	is >> counter;
	for (int i(0); i < counter; i++) {
		string item;
		is >> item;
		r.equipment.push_back(item);
	}
	return is;
}
