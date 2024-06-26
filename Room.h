#pragma once
#include <iostream>
#include <list>
#include <istream>
using namespace std;
class Room {
protected:
	int number;
	float s;
	int desk2, desk3;
public:
	Room();
	Room(const Room& m);
	Room(int number, float s, int desk2, int desk3);
	virtual void print() const;
	int find_floor() const;
	virtual void create();
	int get_seats() const;
	float get_s() const;
	int get_number() const;
	friend istream& operator>>(istream& is, Room& r);

};

class Multy : public Room {
private:
	list<string> equipment;
public:
	Multy();
	Multy(const Multy& t);
	Multy(int number, float s, int desk2, int desk3, list<string> equipment);
	void print() const override;
	void create() override;
	friend istream& operator>>(istream& is, Multy& r);
};