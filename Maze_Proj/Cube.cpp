
#include <iostream>
using namespace std;
#include "Cube.h"



Cube::Cube(const int x, const int y) : row(x), col(y) {};


const Cube& Cube::operator=(const Cube& other)
{
	if (this != &other) {
		row = (other.get_row());
		col = (other.get_col());
	}
	return *this;
}


void Cube::set_row(int x)
{
	row = x;
}

void Cube::set_col(int y)
{
	col = y;
}

int Cube::get_row() const
{
	return row;
}

int Cube::get_col() const
{
	return col;
}
