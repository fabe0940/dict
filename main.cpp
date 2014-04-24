#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, char** argv) {
	int running;
	ifstream dictionary;
	string buffer;

	if(argc != 2) {
		cerr << "invalid arguments" << endl;
		cerr << "usage: " << argv[0] << " <filename>" << endl;
		exit(0);
	}

	dictionary.open(argv[1]);

	if(dictionary.fail()) {
		cerr << "unable to open file " << argv[1] << endl;
		exit(0);
	}

	while(!dictionary.eof()) {
		dictionary >> buffer;
		(void) Insert(buffer.c_str());
		
	}

	dictionary.close();

	running = 1;
	cout << "Hash Table [" << HASH_TABLE_SIZE << "]" << endl;
	cout << "Created by Mason Fabel on 24 April 2014" << endl;
	cout << "Enter \"help\" for a list of commands." << endl;
	cout << "-----" << endl;
	while(running) {
		cout << "> ";
		cin >> buffer;
		if(buffer == "quit") {
			running = 0;
		} else if(buffer == "help") {
			cout << "print:          print out the entire hash table"
				 << endl;
			cout << "size:           print out the size of the buckets"
				 << endl;
			cout << "minmax:         print out the minimum and maximum "
				 << "bucket sizes" << endl;
			cout << "search <word>:  search for <word> in the hash "
				 << "table" << endl;
			cout << "help:           print this help message" << endl;
			cout << "quit:           terminate the program" << endl;
		} else if(buffer == "print") {
			PrintHashTable();
		} else if(buffer == "size") {
			PrintBucketSize();
		} else if(buffer == "minmax") {
			PrintBucketMinMax();
		} else if(buffer == "search") {
			cin >> buffer;
			Print(Lookup(buffer.c_str()));
		} else {
			/* invalid command */
		}
	}

	exit(0);
}
