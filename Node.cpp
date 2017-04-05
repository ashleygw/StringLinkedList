#include "Node.h"
#include <cstdlib>

using namespace std;

//Default constructor, set next to NULL
Node::Node(): next(NULL) {}

//2 arg constructor, sets char and next
Node::Node(char _c, Node* _next): c(_c),next(_next){}

char & Node::get_data() { return c; }
void Node::set_data(char _c) { c = _c; }
Node* & Node::get_next() { return next; }
void Node::set_next(Node* _next) { next = _next; }