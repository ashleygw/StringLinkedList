//George Ashley and Melissa Kohl
//Above and beyond: implementation of -= operator, .lower() , push front and remove first
#include "String.h"


String::String()
{
	head = 0;
	size = 0;
}


String::String(const char *c, unsigned _size)
{
	Node** cursor = &head;
	size = _size;
	for (unsigned x = 0; x < size; x++)
	{
		*cursor = new Node(c[x],0);
		cursor = &(*cursor)->get_next();
	}
}

//Copy Constructor
String::String(const String& cawpo)
{	
	size = cawpo.size;
	head = 0;
	*this += cawpo;
}

//Destructor. Deletes allocated memory.
String::~String()
{
	killme();
}

void String::killme()
{
	Node* cursor = head;
	while (cursor) {
		Node* temp = cursor;
		cursor = cursor->get_next();
		delete temp;
	}
}

// Assignment operator overload.
String & String::operator=(const String& pizza)
{
	if (*this == pizza) return *this;
	killme();
	head = 0;
	size = 0;
	*this += pizza;
	return *this;
}

// return/set char at index
// [] Does not throw an exception... at() does
char & String::operator[](unsigned int index)
{
	unsigned counter = 0;
	Node* cursor = head;
	while (counter != index)
	{
		cursor = cursor->get_next();
		counter++;
	}
	return cursor->get_data();
}

// returns the number of chars, size, in the String
unsigned int String::length() const
{
	return size;
}

// Starting at index location indicated by first arg, insert the String
// specified by the second argument
//not a great function
void String::insert(unsigned int location, const String &rh)
{
	if (location >= size)
	{
		return;
	}
	Node** cursor = &head;
	for (unsigned i = 0; i < location; i++)
	{
		cursor = &(*cursor)->get_next();
	}
	Node* temp = *cursor;
	*cursor = 0;
	*this += rh;
	cursor = &head;
	while (*cursor)
	{
		cursor = &(*cursor)->get_next();
	}
	*cursor = temp;
}



// Return the starting index of the first case-sensitive match of the
// provided String inside the larger string. If no match, return -1.
int String::find(const String &waldo)
{
	if (waldo.head) {
		int counter = 0, anothercounter = 0;
		Node* cursor = head;
		Node* anothercursor = waldo.head;
		while (cursor) {
			if (cursor->get_data() == anothercursor->get_data()) {
				while (anothercursor&&cursor) {
					if (cursor->get_data() != anothercursor->get_data())
						break;
					cursor = cursor->get_next();
					anothercursor = anothercursor->get_next();
					anothercounter++;
				}
				if(anothercounter == waldo.size)
					return counter;
				anothercursor = waldo.head;
			}
			if (!cursor)
				return -1;
			cursor = cursor->get_next();
			counter++;
		}
	}
	return -1;
}

//removes second argument, string, from the set in the first argument
void String::operator-=(const String& sub)
{
	//size -= spgahtei2.length();
	int die = find(sub);
	if (die != -1)
	{
		remove(die, sub.length());
	}
}
// Starting at index location indicated by first arg, remove number of
// chars specified by the second argument, return the deleted section as a
// new String
String String::remove(unsigned int location, unsigned int length)
{
	size -= length;
	int counter = 0;
	String new_string = String("",0);
	Node* cursor = head;
	while (counter < location)
	{
		new_string += cursor->get_data();
		cursor = cursor->get_next();
		counter++;
	}
	for (int i = 0; i < length; i++) {
		cursor = cursor->get_next();
		counter++;
	}
	while (cursor)
	{
		new_string += cursor->get_data();
		cursor = cursor->get_next();
	}
	*this = new_string;
	return *this;
}

// returns a String object representing the concatenation
// of its two arguments
String String::operator+(const String& dos) const
{
	String result = *this;
	result += dos;
	result.size = size + dos.size;
	return result;
}

// appends second argument, char, to the set in the first argument
void String::operator+=(const char football)
{
	size += 1;
	Node *new_node, *cursor;
	new_node = new Node(football, NULL);
	if (!head) {
		head = new_node;
	}
	else {
		cursor = head;
		while (cursor->get_next()) { 
			cursor = cursor->get_next();
		}
		cursor->set_next(new_node);
	}
}

// appends second argument, string, to the set in the first argument
void String::operator+=(const String& rhs)
{
	size += rhs.size;
	Node** cursor = &head;
	while(*cursor)
	{
		cursor = &(*cursor)->get_next();
	}
	Node* cursor2 = rhs.head;
	while (cursor2)
	{
		*cursor = new Node(cursor2->get_data(), 0);
		cursor2 = cursor2->get_next();
		cursor = &(*cursor)->get_next();
	}
}




// prints out the String to the terminal, no new line
ostream& operator<<(ostream& out, const String& bloof)
{
	Node* cursor;
	for (cursor = bloof.head; cursor != NULL; cursor = cursor->get_next())
		out << cursor->get_data();
	return out;
}

// returns true if the strings are equal char-by-char, false otherwise.
bool operator==(const String& shirt, const String& pants)
{
	Node* cursor1 = shirt.head;
	Node* cursor2 = pants.head;
	while (cursor1&&cursor2)
	{
		if (cursor1->get_data() != cursor2->get_data())
			return false;
		else
		{
			cursor1 = cursor1->get_next();
			cursor2 = cursor2->get_next();
		}
	}
	return (!cursor1&&!cursor2);
}

// Makes all the letters in the string lowercase
void String::lower()
{
	Node * cursor = head;
	while (cursor)
	{
		if ('A' <= cursor->get_data() && cursor->get_data() <= 'Z')
		{
			cursor->set_data(cursor->get_data() + 32);
		}
		cursor = cursor->get_next();
	}
}


//Removes first node from String
void String::remove_first()
{
	if (!head)
		return;
	Node* temp = head;
	head = head->get_next();
	delete temp;
}
void String::push_front(char push) 
{
	Node **cursor = &head;
	Node *node = new Node(push,NULL);
	node->next = *cursor;
	*cursor = node;
	size++;
}
