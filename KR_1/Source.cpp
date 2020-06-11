#include "Class.h"



int main()
{
	Pen pen1("Filiola", "black", true, 100, "ballpoint");
	pen1.Print();
	Pen pen2("Oxela", "red", true, 13, "point");
	cout << "Operator(pen1, pen2) == " << operator==(pen1, pen2) << endl;
	cout << "Operator(pen1, pen2) != " << operator!=(pen1, pen2) << endl;
	return 0;
}