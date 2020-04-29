#include <iostream>
using namespace std;

#include "Cube.h"
#include "Stack.h"
#include "Node.h"

Node::Node() {
	next = NULL;
}
Node::Node(Cube& cb, Node* ptr)
{
	pos = cb;
	next = ptr;
}
