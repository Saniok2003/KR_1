#include "Class.h"

Pen :: Pen()
{
	name = nullptr;
	color = "";
	working = false;
	ink = 0;
	type = "";

}
Pen :: Pen(const char* name, string color, bool working, float ink, string type)
{
	SetName(name);
	this->color = color;
	this->working = working;
	this->ink = ink;
	this->type = type;
	++count;
}
Pen::Pen(const Pen& other)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = other.name;
	this->color = other.color;
	this->working = other.working;
	this->ink = other.ink;
	this->type = other.type;
	++count;
}
Pen::Pen(Pen&& other)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = other.name;
	this->color = other.color;
	this->working = other.working;
	this->ink = other.ink;
	this->type = other.type;

	name = nullptr;
	color = "";
	working = false;
	ink = 0;
	type = "";
}
Pen :: ~Pen()
{
	delete[]name;
}
Pen Pen :: operator=(const Pen& other)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = other.name;
	this->color = other.color;
	this->working = other.working;
	this->ink = other.ink;
	this->type = other.type;
	return *this;
}
Pen Pen ::  operator=(Pen&& other)
{
	if (this->name != nullptr)
	{
		delete[]this->name;
	}
	this->name = other.name;
	this->color = other.color;
	this->working = other.working;
	this->ink = other.ink;
	this->type = other.type;
	name = nullptr;
	color = "";
	working = false;
	ink = 0;
	type = "";
	return *this;
}
Pen Pen ::  operator++()
{
	this->ink = this->ink + 1; return *this;
}
Pen Pen ::  operator++(int)
{
	this->ink += 1; return *this;
}
Pen Pen ::  operator--()
{
	this->ink -= 1; return *this;
}
Pen Pen ::  operator--(int)
{
	this->ink -= 1; return *this;
}
void Pen ::  operator()(float ink)
{
	this->ink = this->ink + ink;
}
void Pen::SetName(const char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}
void Pen::Print() const
{
	cout << "Name: " << name << endl;
	cout << "Color: " << color << endl;
	cout << "Working: " << working << endl;
	cout << "Ink: " << ink << endl;
	cout << "Type: " << type << endl;
	cout << "Count: " << count << endl;
}

int Pen :: count = 0;

bool operator==(const Pen& other, const Pen& other_)
{
	return(other.name == other_.name &&
		other.color == other_.color &&
		other.working == other_.working &&
		other.ink == other_.ink &&
		other.type == other_.type);
}
bool operator!=(const Pen& other, const Pen& other_)
{
	return(other.name != other_.name ||
		other.color != other_.color ||
		other.working != other_.working ||
		other.ink != other_.ink ||
		other.type != other_.type);
}
bool operator>(const Pen& other, const Pen& other_)
{
	return(other.ink > other_.ink);
}
bool operator<(const Pen& other, const Pen& other_)
{
	return(other.ink < other_.ink);
}
ifstream& operator>>(ifstream& fit, Pen& other)
{
	fit >> other.name;
	fit >> other.color;
	fit >> other.working;
	fit >> other.ink;
	fit >> other.type;
	return fit;
}
ofstream& operator>>(ofstream& fout, const Pen& other)
{
	fout << other.name << endl;
	fout << other.color << endl;
	fout << other.working << endl;
	fout << other.ink << endl;
	fout << other.type << endl;
	return fout;
}