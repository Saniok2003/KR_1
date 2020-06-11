#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

class Pen
{
private:
	char* name;
	string color;
	bool working;
	float ink;
	string type;
	static int count;
	friend bool operator>(const Pen& other, const Pen& other_);
	friend bool operator<(const Pen& other, const Pen& other_);
	friend bool operator==(const Pen& other, const Pen& other_);
	friend bool operator!=(const Pen& other, const Pen& other_);
	friend ifstream& operator>>(ifstream& fit, Pen& other);
	friend ofstream& operator>>(ofstream& fout, const Pen& other);
public:
	Pen();
	Pen(const char* name, string color, bool working, float ink, string type);
	Pen(const Pen& other);
	Pen(Pen&& other);
	~Pen();
	Pen operator=(const Pen& other);
	Pen operator=(Pen&& other);
	Pen operator++();
	Pen operator++(int);
	Pen operator--();
	Pen operator--(int);
	void operator()(float ink);
	void SetName(const char* name);
	void Print() const;
};

bool operator==(const Pen& other, const Pen& other_);
bool operator!=(const Pen& other, const Pen& other_);
bool operator>(const Pen& other, const Pen& other_);
bool operator<(const Pen& other, const Pen& other_);
ifstream& operator>>(ifstream& fit, Pen& other);
ofstream& operator>>(ofstream& fout, const Pen& other);