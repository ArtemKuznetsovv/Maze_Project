
#include <iostream>
using namespace std;
#include "Queue.h"
#include "Cube.h"




Queue::Queue()
{
	this->head = 1;
	this->tail = 0;
	this->ARR_SIZE = MAX_SIZE;
	this->Array = nullptr;
}

Queue::Queue(int arr_size)
{
	this->head = 1;
	this->tail = 0;
	this->ARR_SIZE = arr_size;
	this->Array = new Cube[arr_size];
}

Queue::~Queue()
{
	delete[]Array;
}

void Queue::MakeEmpty()
{
	head = 1;
	tail = 0;
}


int Queue::AddOne(int x)
{
	return ((1 + x) % ARR_SIZE);
}



bool Queue::IsEmpty()
{
	return (AddOne(tail) == head);
}

Cube Queue::Front()
{
	if (IsEmpty()) {
		cout << "Error:QUEUE EMPTY\n"; exit(1);
	}
	return Array[head];
}


void Queue::EnQueue(Cube& x)
{
	if (AddOne(AddOne(tail)) == head)
	{
		cout << "Error: QUEUE FULL\n"; exit(1);
	}
	tail = AddOne(tail);
	Array[tail] = x;
}


Cube Queue::Dequeue()
{
	if (IsEmpty())
	{
		cout << "Error: QUEUE EMPTY\n"; exit(1);
	}
	Cube ret = Array[head];
	head = AddOne(head);
	return ret;
}



