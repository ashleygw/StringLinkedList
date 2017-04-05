#include "vld.h"
//George Ashley and Melissa Kohl
//Above and beyond: implementation of -= operator, .lower()
#include <iostream>
#include "String.h"
#include <cassert>  //  assert functionality
using namespace std;
String fun(String bob)
{
	cout << "Address of String in function: " << &bob << endl;
	return bob;
}
int main()
{
	cout << "*******************" << endl;
	cout << "Test cases..." << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing default: default_String = String();" << endl;
	String default_String = String();
	cout << "Size of default = default_String.length: " << default_String.length() << " (0)" << endl;
	cout << "Contents of default = " << default_String << " ()" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Adding String to default String with += ..." << endl;
	default_String += String("abcde", 5);
	cout << "Default String now returns: " << default_String << " (abcde)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Adding a char to default String using += ..." << endl;
	default_String += 'f';
	cout << "Default String now returns: " << default_String << " (abcdef)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Adding two Strings with + ..." << endl;
	String a = String("abc", 3);
	String b = String("def", 3);
	cout << "String a: " << a << " (abc)" << endl;
	cout << "String b: " << b << " (def)" << endl;
	cout << "a+b: " << a + b << " (abcdef)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing copy constructor: fun(default_String)..." << endl;
	cout << "Address of default_String: " << &default_String << endl;
	fun(default_String);
	cout << "Two addresses above should be different." << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing insert: " << endl;
	cout << "default_String.insert(2,String(\"gfe\",3)..." << endl;
	default_String.insert(2, String("gfe", 3));
	cout << default_String << " (abgfecdef)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing remove = default_String.remove(2,3)..." << endl;
	default_String.remove(2, 3);
	cout << default_String << " (abcdef)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing non-default String:" << endl;
	cout << "String knot = String(\"hijklmnop\",9)..." << endl;
	String knot = String("hijklmnop", 9);
	cout << "Size of knot = knot.length: " << knot.length() << " (9)" << endl;
	cout << "Contents of knot = " << knot << " (hijklmnop)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing .find: knot.find(\"klm\"): " << knot.find(String("klm", 3)) << " (3)" << endl;
	cout << "Testing .find: knot.find(\"xyz\"): " << knot.find(String("xyz", 3)) << " (-1)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing [] functionality: knot[3] = '2'..." << endl;
	knot[3] = '2';
	cout << knot << " (hij2lmnop)" << endl;
	cout << "------------------------------------------------" << endl;
	//This breaks the program now: It is supposed to. 
	/*cout << "Testing [] functionality: knot[30] = 'x' : 0" << endl;
	knot[30] = 'x';
	cout << "knot[30]: " << knot[30] << " (0)" << endl;
	cout << "knot: " << knot << " (hij2lmnop)" << endl;
	cout << "------------------------------------------------" << endl;*/
	cout << "Testing == operator: " << (default_String == knot) << " (0)" << endl;
	String c = a + b;
	cout << "Testing == operator: " << (default_String == c) << " (1)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing -= operator: " << endl;
	cout << "default_String -= String(\"def\",3)..." << endl;
	default_String -= String("def", 3);
	cout << "Default String is now: " << default_String << " (abc)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Testing .lower()..." << endl;
	String f = String("ABCDEZ1", 7);
	cout << "Before .lower(): " << f << " (ABCDEZ1)" << endl;
	f.lower();
	cout << "After .lower(): " << f << " (abcdez1)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "End of test cases!" << endl;
	cout << "*******************" << endl;
}
