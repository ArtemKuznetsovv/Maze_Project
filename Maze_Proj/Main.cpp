#include <iostream>
using namespace std;
#include "Maze.h"
#include "Queue.h"
#include "Cube.h"
#include "Stack.h"
#include <stdlib.h> 
#include<time.h> 
const int MAX_ROW_SIZE = 25;
const int MAX_COL_SIZE = 80;
int main()
{
	srand(time(0));

	char choice;

	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> choice;
	cin.ignore();
	int row, col;

	cout << "enter row number followed by col number " << endl;
	cin >> row >> col;

	cout << " ***Information***\n";
	cout << " Point that was visited will be marked as '$'";
	cout<<" Walls are marked as *\n";
	if (row > MAX_ROW_SIZE || col > MAX_COL_SIZE) {
		cout << "Invalid input";
		exit(1);
	}

	Maze NewMaze(row, col);
	if (choice == '1') {

		NewMaze.ManualMazeCreator();

	}
	else if (choice == '2') {
		if (row % 2 == 0 || col % 2 == 0) {
			cout << "Input rows should be odd numbers";
			exit(1);
		}
		NewMaze.RandomMazeCreator();




	}
	bool solved;
	solved = NewMaze.SolveMaze();
	if (solved == true)
		NewMaze.PrintMaze();
	else {
		cout << "no solution";
	}




}

