#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, char** argv) {
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

	PrintBucketSize();
	PrintBucketMinMax();

	Print(Lookup("cat"));
	Print(Lookup("asdf"));

	exit(0);
}
