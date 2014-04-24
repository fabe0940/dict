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

const int HASH_TABLE_SIZE = 101;
static NListPtr hashTable[HASH_TABLE_SIZE];

static char *Strdup(const char *);

unsigned Hash(char *s) {
	unsigned hashVal;
	
	for(hashVal = 0 ; *s != '\0' ; s++) {
		hashVal = *s + 31 * hashVal;
	}
		
	return  hashVal % HASH_TABLE_SIZE;
}

NListPtr Lookup(char *s) {
	NListPtr np;
	
	for(np = hashTable[Hash(s)] ; np != NULL ; np = np->next) {
		if(strcmp(s, np->name) == 0) {
			return np;
		}
	}
	
	return NULL;
}

NListPtr Insert(char *name, char *defn) {
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
	} else {
		free((void *)np->defn);
	}
	
	if((np->defn = Strdup(defn)) == NULL) {
		return NULL;
	}
	
	return np;
}

void PrintHashTable() {
	NListPtr np;

	cout << "Hash table contents:" << endl;
	cout << "--------------------\n" << endl;

	for(int i = 0 ; i < HASH_TABLE_SIZE ; i++) {
		np = hashTable[i];
		while(np != NULL) {
			 cout << setw(3) << i << ":	";
			 cout << np->name << ", " << np->defn;
			 cout << endl;
			 np = np->next;
		}
	}
}

static char *Strdup(const char *s) {
	char *p;
	
	p = (char *) malloc(strlen(s) + 1);
	if(p != NULL) {
		strcpy(p,s);
	}

	return p;
}
