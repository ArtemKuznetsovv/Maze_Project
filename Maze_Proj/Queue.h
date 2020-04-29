#pragma once
#ifndef __QUEUE__
#define __QUEUE__

class Cube;

static int MAX_SIZE = 25 * 80;
class Queue
{
private:
	int ARR_SIZE;
	int head, tail;
	Cube* Array;
	int AddOne(int x);//returns x + 1



public:
	Queue();//default constructor
	Queue(int arr_size);//constructor
	~Queue();//destructor
	void MakeEmpty();
	bool IsEmpty();
	Cube Front();
	void EnQueue(Cube& x);
	Cube Dequeue();

};







#endif //QUEUE