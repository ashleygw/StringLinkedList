#ifndef NODE_H
#define NODE_H

class Node {
public:
	//Default constructor, set next to NULL
	Node();

	//2 arg constructor, sets char and next
	Node(char, Node*);

	char &get_data();
	void set_data(char);
	Node*&get_next();
	void set_next(Node*);

private:
	char c;
	Node* next;
	friend class String;
};


#endif
