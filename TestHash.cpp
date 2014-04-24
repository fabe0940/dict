#include <iostream>
#include <cstdlib>
#include "hash.h"

using namespace std;

int main() {  
	(void)Insert("One");
	(void)Insert("One");
	(void)Insert("Two");
	(void)Insert("Three");
	(void)Insert("Four");
	(void)Insert("Five");
	(void)Insert("Six");
	(void)Insert("Seven");
	(void)Insert("Eight");
	(void)Insert("Nine");
	(void)Insert("Ten");
	
	PrintHashTable();

	exit(0);
}
