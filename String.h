#ifndef STRING_H
#define STRING_H
#include <iostream>
#include "Node.h"

using namespace std;

//Above and beyond: implementation of -= operator

class String {

	// prints out the String to the terminal, no new line
	friend ostream& operator<<(ostream&, const String&);

	// returns true if the strings are equal char-by-char, false otherwise.
	friend bool operator==(const String&, const String&);

public:

	// Constructor, sets size to zero, allocates array of size 10,
	// sets array_size to 10
	String();

	// Constructor, builds a String containing the chars in the array
	// referenced by the first argument, with length indicated by the second
	// argument
	String(const char*,unsigned);

	// Copy constructor.
	String(const String&);

	// Destructor.  Deletes allocated memory.
	~String();

	// not Friend declarations: Programmers are not supposed to have friends
	//
	// returns a String object representing the concatenation
	// of its two arguments
	String operator+(const String&) const;

	// appends second argument, char, to the set in the first argument
	void operator+=(const char);

	// appends second argument, string, to the set in the first argument
	void operator+=(const String&);

	//removes second argument, string, from the set in the first argument
	void operator-=(const String&);

	//Not our friends --------
	// Assignment operator overload.
	String& operator=(const String&);

	// return/set char at index
	char& operator[](unsigned int);

	// returns the number of chars, size, in the String
	unsigned int length() const;

	// Starting at index location indicated by first arg, insert the String
	// specified by the second argument
	void insert(unsigned int, const String&);

	// Starting at index location indicated by first arg, remove number of
	// chars specified by the second argument, return the deleted section as a
	// new String
	String remove(unsigned int, unsigned int);

	// Return the starting index of the first case-sensitive match of the
	// provided String inside the larger string. If no match, return -1.
	int find(const String&);

	// Makes all the letters in the string lowercase
	void lower();

	//Reverses the String
	//void reverse();

	//Removes first node from String
	void remove_first();

	//Adds to front
	void push_front(char);
	
	//clears
	void killme();
private:

	// reference to an array holding the chars of the String
	Node *head;
	unsigned size;

};
#endif
