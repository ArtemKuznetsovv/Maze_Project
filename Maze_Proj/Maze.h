#pragma once
#ifndef __MAZE__
#define __MAZE__

class Maze
{
private:
	int row_num, col_num;
	char **TheMaze;


public:
	Maze(int row, int col);//constructor
	Maze();//default constructor
	~Maze();//destructor

	bool SetMaze(int r, int c);
	bool SetRow(int r);
	bool SetCol(int c);



	void PrintMaze();
	bool CheckMazeValidity();//returns true if maze valid
	void ManualMazeCreator();//creating the maze with users input
	void RandomMazeCreator();//creating the maze randomly
	bool SolveMaze();//solves any maze(if valid),returns true if maze is solvable , else false


	char** GetMaze() const;
	int GetRowNum() const;
	int GetColNum() const;


};









#endif