#pragma once
#ifndef __CUBE__
#define __CUBE__


class Cube
{
private:
	int row, col;


public:
	Cube(const int x, const int y);
	Cube() = default;
	const Cube& operator=(const Cube& other);


	void set_row(int x);
	void set_col(int y);
	int get_row() const;
	int get_col() const;


};


#endif

