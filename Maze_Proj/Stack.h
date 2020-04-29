#pragma once
#ifndef __STACK__
#define __STACK__

class Cube;
class Node;

class Stack
{
private:
	Node* top;  //top of the stack

public:
	Stack();//constructor
	~Stack();//destructor
	void MakeEmpty();
	bool IsEmpty();
	void Push(Cube& cb);
	Cube Pop();
	Cube Top();

};








#endif