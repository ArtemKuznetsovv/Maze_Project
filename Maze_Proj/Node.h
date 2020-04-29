#pragma once
#ifndef __NODE__
#define __NODE__

class Cube;

class Node
{
private:
	Cube pos;
	Node* next;
public:
	Node();//default node ctor
	Node(Cube& cb, Node* ptr);//ctor

	Cube getPos() { return pos; };
	Node* getNext() { return next; };


};







#endif

