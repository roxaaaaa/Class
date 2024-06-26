#include "Room.h"
#include <fstream>
#include <vector>
#include <map>
vector<int> floorwmulty;
map<int, int> mapa;
template <typename T>
void fillmap_print(list<T>& a) {
	// Clear the map to ensure it's empty before filling
	mapa.clear();

	// Fill the map with floor counts
	for (const auto& i : a) {
		int floor = i.find_floor();
		mapa[floor]++;
	}

	// Print the results
	for (auto i = mapa.begin(); i != mapa.end(); ++i) {
		cout << "At floor " << i->first << ", there are " << i->second << " rooms." << endl;
	}
}

template<typename T>
void add2list(list<T>& ab) {
	T a;
	a.create();
	ab.push_back(a);
}

template<typename T>
void print_list(list<T>& r) {
	for (const auto& i : r) {
		i.print();
	}
}

template<typename T>
int find_rooms2(list<T>& a) {
	int totalroom = 0;
	for (const auto& i : a) {
		if (i.find_floor() == 2) totalroom++;
	}
	return totalroom;
}

int totalroom2(list<Room>& r, list<Multy>& m) {
	int total = find_rooms2<Room>(r) + find_rooms2<Multy>(m);
	cout << "Total rooms on the 1st floor: " << total << endl;
	return total;
}

template<typename T>
int find_s(list<T>& a) {
	int totalarea= 0;
	for (const auto& i : a) {
		totalarea += i.get_s();
	}
	return totalarea;
}

template<typename T>
T find_more_seats(list<T>& a) {
	if (a.empty()) {
		throw runtime_error("List is empty");
	}
	auto largest = a.begin();

	for (auto i = a.begin(); i != a.end(); ++i) {
		if (i->get_seats() > largest->get_seats()) largest = i;
	}
	return *largest;
}

void find_seats_print(list<Room>& r, list<Multy>& m) {
	Room r1 = find_more_seats<Room>(r);
	Multy r2 = find_more_seats<Multy>(m);

	if (r1.get_seats() > r2.get_seats()) cout << r1.get_number() << " has the biggest amount of seats" << endl;
	else if (r1.get_seats() < r2.get_seats()) cout << r2.get_number() << " has the biggest amount of seats" << endl;
}

template <typename T>
bool compare_seats(T& a, T& b) {
	return a.get_seats() > b.get_seats();
}

void compare_by_seats(list<Room>& r, list<Multy>& m) {
	r.sort(compare_seats<Room>);
	m.sort(compare_seats<Multy>);
	print_list<Room>(r);
	print_list<Multy>(m);
}

template<typename T>
T find_more_s(list<T>& a) {
	auto largest = a.begin();
	for (auto i = a.begin(); i != a.end(); ++i) {
		if (i->get_s() > largest->get_s()) largest = i;
	}
	return *largest;
}

void find_s_print(list<Room>& r, list<Multy>& m) {
	Room r1 = find_more_s<Room>(r);
	Multy r2 = find_more_s<Multy>(m);

	if (r1.get_s() > r2.get_s()) cout << r1.get_number() << " has the biggest area" << endl;
	else if (r1.get_s() < r2.get_s()) cout << r2.get_number() << " has the biggest area" << endl;
}

void enter(list<Room>& r, list<Multy>& m) {
	cout << "Enter the number of rooms u want to add:";
	int n;
	cin >> n;
	for (int i(0); i < n; i++) {
		cout << "enter 1-room, 2-multyroom:";
		int l;
		cin >> l;
		switch (l)
		{
		case 1:
			add2list<Room>(r);
			break;
		case 2:
			add2list<Multy>(m);
			break;
		}
	}
	print_list<Room>(r);
	print_list<Multy>(m);
}

int main() {
	ifstream file("file.txt");
	list<Room> r;
	list<Multy> m;
	char x;
	Room y1;
	Multy y2;
	while (file >> x) {
		
		switch (x)
		{
		case '1': {
			file >> y1;
			r.push_back(y1);
			break;

		}
		case '2': {
			file >> y2;
			m.push_back(y2);
			break;

		}
		}

	}
	print_list<Room>(r);
	print_list<Multy>(m);
	cout << endl;
	compare_by_seats(r, m);
	int total = find_s<Room>(r) + find_s<Multy>(m);
	cout << "Total s: " << total << endl;
	fillmap_print<Room>(r);
	/*Room m(102, 12, 4, 6);
	m.print();
	list<string> eq1;
	eq1.push_back("computer");
	eq1.push_back("multydesk");
	eq1.push_back("camera");
	Multy m2(303, 14, 5, 8, eq1);
	m2.print();
	list<Room> r1;
	list<Multy> r2;
	enter(r1, r2);
	find_seats_print(r1, r2);
	find_s_print(r1, r2);
	totalroom2(r1, r2);
	*/

	return 0;
}