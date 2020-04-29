#include <iostream>
using namespace std;


#include "Maze.h"
#include "Cube.h"
#include "Stack.h"
#include "Queue.h"


const int MAX_ROW_SIZE = 25;
const int MAX_COL_SIZE = 80;

Maze::Maze(int row, int col)//constructor
{
	SetRow(row);
	SetCol(col);
	SetMaze(row, col);
}


Maze::Maze()
{
	row_num = 0;
	col_num = 0;
	TheMaze = nullptr;
}

Maze::~Maze()//destructor
{
	for (int i = 0; i < row_num; i++)
	{
		delete[] TheMaze[i];
	}
	delete TheMaze;
}


bool Maze::SetMaze(int r, int c)
{
	TheMaze = new char*[r];

	for (int i = 0; i < r; i++) {
		TheMaze[i] = new char[c + 1];
		TheMaze[i][c] = '\0';
	}
	if (TheMaze == nullptr)
		return false;

	return true;
}


bool Maze::SetRow(int r)
{
	if (r > MAX_ROW_SIZE) {
		cout << "Maze is too long (Too many rows)\n";
		return false;
	}

	row_num = r;
	return true;
}


bool Maze::SetCol(int c)
{
	if (c > MAX_COL_SIZE) {
		cout << "Maze is too wide (Too many cols)\n";
		return false;
	}
	col_num = c;
	return true;
}


char** Maze::GetMaze()  const
{
	return TheMaze;
}

int Maze::GetRowNum()  const
{
	return row_num;
}
int Maze::GetColNum()  const
{
	return col_num;
}








void Maze::RandomMazeCreator()
{


	//Random Maze Creation

	for (int i = 0; i < row_num; i++) {     // default maze creation
		for (int j = 0; j < col_num; j++) {
			if (i % 2 == 0 || j % 2 == 0) {
				TheMaze[i][j] = '*';


			}

			else
				TheMaze[i][j] = ' ';

		}


	}

	TheMaze[1][0] = ' ';//Entrance
	TheMaze[row_num - 2][col_num - 1] = ' '; //Exit

	Stack stk;
	stk.MakeEmpty();

	int rowindex = 1;//Entrance
	int colindex = 1;
	Cube c(rowindex, colindex);
	stk.Push(c);


	while (!(stk.IsEmpty())) // while stack is not empty
	{
		Cube Position = stk.Top();

		stk.Pop();
		TheMaze[Position.get_row()][Position.get_col()] = '$';//marking we visited the checker

		Cube *Possible_moves = new Cube[4];


		int index = 0;
		if (Position.get_col() + 2 != col_num && TheMaze[Position.get_row()][Position.get_col() + 2] != '$') {//right
			if (TheMaze[Position.get_row()][Position.get_col() + 2] == ' ') {
				Possible_moves[index].set_row(Position.get_row());
				Possible_moves[index].set_col(Position.get_col() + 2);
				index++;

			}
		}
		if (Position.get_col() != 1 && TheMaze[Position.get_row()][Position.get_col() - 2] != '$') {//left
			if (TheMaze[Position.get_row()][Position.get_col() - 2] == ' ') {
				Possible_moves[index].set_row(Position.get_row());
				Possible_moves[index].set_col(Position.get_col() - 2);
				index++;

			}
		}
		if (Position.get_row() != 1 && TheMaze[Position.get_row() - 2][Position.get_col()] != '$') {//top
			if (TheMaze[Position.get_row() - 2][Position.get_col()] == ' ') {
				Possible_moves[index].set_row(Position.get_row() - 2);
				Possible_moves[index].set_col(Position.get_col());
				index++;

			}
		}
		if (Position.get_row() + 2 != row_num && TheMaze[Position.get_row() + 2][Position.get_col()] != '$') {//bottom
			if (TheMaze[Position.get_row() + 2][Position.get_col()] == ' ') {
				Possible_moves[index].set_row(Position.get_row() + 2);
				Possible_moves[index].set_col(Position.get_col());
				index++;
			}
		}

		if (index != 0) {
			int randindex = rand() % index;//Next move is chosen randmoly
			Cube choosen = Possible_moves[randindex];

			if (choosen.get_row() + 2 == Position.get_row()) {
				TheMaze[Position.get_row() - 1][Position.get_col()] = ' '; //break wall between two neighbors
			}
			if (choosen.get_row() - 2 == Position.get_row()) {
				TheMaze[Position.get_row() + 1][Position.get_col()] = ' ';
			}
			if (choosen.get_col() + 2 == Position.get_col()) {
				TheMaze[Position.get_row()][Position.get_col() - 1] = ' ';
			}
			if (choosen.get_col() - 2 == Position.get_col()) {
				TheMaze[Position.get_row()][Position.get_col() + 1] = ' ';
			}
			stk.Push(Position);
			stk.Push(choosen);
			cout << endl;

		}
		delete[]Possible_moves;


	}

	for (int i = 0; i < row_num; i++) {//deleting visited checkers
		for (int j = 0; j < col_num; j++) {
			if (TheMaze[i][j] == '$')
				TheMaze[i][j] = ' ';
		}
	}




}



bool Maze::CheckMazeValidity()
{
	if (TheMaze[1][0] != ' ') {
		return false;//no entrance or exit
	}

	if (TheMaze[row_num - 2][col_num - 1] != ' ') {
		return false;//no entrance or exit
	}


	for (int i = 0; i < col_num; i++)// check maze outside walls
	{
		if (TheMaze[0][i] != '*' || TheMaze[row_num - 1][i] != '*') {
			return false;
		}
	}

	for (int i = 0; i < row_num; i++) {
		if ((TheMaze[i][0] != '*' && i != 1) || (TheMaze[i][col_num - 1] != '*' && i != row_num - 2))
		{
			return false;
		}
	}
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			if (TheMaze[i][j] != ' ' && TheMaze[i][j] != '*')
				return false;
		}
	}

	return true;

}

void Maze::PrintMaze()  // print the maze
{
	if (TheMaze != nullptr)
	{
		for (int i = 0; i < row_num; i++)
		{
			cout << TheMaze[i] << endl;

		}
	}
}




void Maze::ManualMazeCreator()
{
	cin.ignore();
	cout << "Note , to write right input: " << endl;
	cout << " 1. row_number : 1 , col_number :0 has to be left blank so there will be a start point (numbering of rows and cols start from 0)" << endl;
	cout << " 2. At Row_number and col number as follows  :   " << row_num - 1 << "," << col_num << "leave a blank so there will be an exit " << endl;
	cout << " 3. Note that there has to be astrisk surrounding the board , row number 0 has to be all with astrisk , last row also ,aswell as first col,and last column  , except of course the points where there has to be blank as mentioned above \n";
	for (int i = 0; i < row_num; i++)
	{


		cout << "Enter  line " << i + 1 << endl;;
		cin.getline(TheMaze[i], col_num + 1);


	}




	if (!CheckMazeValidity())
	{
		cout << "invalid input";
		exit(1);
	}


}



bool Maze::SolveMaze()
{
	Queue Q((col_num) * (row_num));

	int row_index = 1, col_index = 0;

	Cube current(row_index, col_index);

	Q.EnQueue(current);

	while (!Q.IsEmpty())//while Queue is not empty
	{
		current = Q.Dequeue();
		row_index = current.get_row();
		col_index = current.get_col();

		TheMaze[row_index][col_index] = '$';//marked as visited

		if (current.get_row() == row_num - 2 && current.get_col() == col_num - 1)//maze is solved
		{

			return true;
		}


		if (TheMaze[row_index][col_index + 1] != '*' && TheMaze[row_index][col_index + 1] != '$')//right
		{
			Cube c1(row_index, col_index + 1);
			Q.EnQueue(c1);

		}
		if (TheMaze[row_index + 1][col_index] != '*' && TheMaze[row_index + 1][col_index] != '$')//down
		{
			Cube c2(row_index + 1, col_index);
			Q.EnQueue(c2);

		}



		if (TheMaze[row_index][col_index - 1] != '*' && TheMaze[row_index][col_index - 1] != '$')//left
		{
			if (col_index - 1 > 0) {
				Cube c3(row_index, col_index - 1);
				Q.EnQueue(c3);

			}

		}
		if (TheMaze[row_index - 1][col_index] != '*' && TheMaze[row_index - 1][col_index] != '$')//up
		{
			if (row_index - 1 > 0) {
				Cube c4(row_index - 1, col_index);
				Q.EnQueue(c4);
			}
		}


	}
	return false;

}
