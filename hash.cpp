/* Hash.cpp
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *	 Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "hash.h"

static NListPtr hashTable[HASH_TABLE_SIZE];

static char* Strdup(const char* );

unsigned Hash(const char* s) {
	unsigned hashVal;
	
	for(hashVal = 0; *s != '\0'; s++) {
		hashVal = *s + 31 * hashVal;
	}
		
	return  hashVal % HASH_TABLE_SIZE;
}

int BucketSize(int index) {
	int size;
	NListPtr tmp;

	tmp = hashTable[index];

	size = 0;
	while(tmp != NULL) {
		size++;
		tmp = tmp->next;
	}

	return size;
}

NListPtr Lookup(const char* s) {
	NListPtr np;
	
	for(np = hashTable[Hash(s)]; np != NULL; np = np->next) {
		if(strcmp(s, np->name) == 0) {
			return np;
		}
	}
	
	return NULL;
}

NListPtr Insert(const char* name) {
	unsigned hashVal;
	NListPtr np;
	
	if((np = Lookup(name)) == NULL) {
		np = (NListPtr) malloc(sizeof(*np));
		if(np == NULL || (np->name = Strdup(name)) == NULL) {
			return NULL;
		}
		hashVal = Hash(name);
		np->next = hashTable[hashVal];
		hashTable[hashVal] = np;
	}
	
	return np;
}

void PrintHashTable() {
	NListPtr np;

	cout << "Hash table contents:" << endl;
	cout << "--------------------" << endl;

	for(int i = 0; i < HASH_TABLE_SIZE; i++) {
		np = hashTable[i];
		while(np != NULL) {
			 cout << setw(3) << i << ":	";
			 cout << np->name << endl;
			 np = np->next;
		}
	}

	return;
}

void PrintBucketSize(void) {
	int i;

	cout << "Hash table bucket sizes:" << endl;
	cout << "------------------------" << endl;

	for(i = 0; i < HASH_TABLE_SIZE; i++) {
		cout << setw(3) << i << ": ";
		cout << BucketSize(i) << endl;
	}

	return;
}

void PrintBucketMinMax(void) {
	int i;
	int tmp;
	int min;
	int max;

	min = BucketSize(i);
	max = BucketSize(i);

	for(i = 0; i < HASH_TABLE_SIZE; i++) {
		tmp = BucketSize(i);
		min = tmp < min ? tmp : min;
		max = tmp > max ? tmp : max;
	}

	cout << "Minimum bucket size: " << setw(4) << min << endl;
	cout << "Maximum bucket size: " << setw(4) << max << endl;

	return;
}

static char* Strdup(const char* s) {
	char* p;
	
	p = (char*) malloc(strlen(s) + 1);
	if(p != NULL) {
		strcpy(p, s);
	}

	return p;
}
