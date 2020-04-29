#include <iostream>
using namespace std;

#include "Cube.h"
#include "Stack.h"
#include "Node.h"


Stack::Stack()
{
	top = NULL;
}
Stack::~Stack()
{
	MakeEmpty();
}
void Stack::MakeEmpty()
{
	Node* temp;
	while (top != NULL) {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	return (top == NULL);
}


void Stack::Push(Cube& cb)
{
	top = new Node(cb, top);
}

Cube Stack::Pop()
{
	if (IsEmpty()) {
		cout << "Error:STACK UNDERFLOW\n"; exit(1);
	}
	Node* temp = top;
	Cube item = top->getPos();
	top = top->getNext();
	delete temp;
	return item;

}
Cube Stack::Top()
{
	Cube info = top->getPos();
	return info;
}
