#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hash.h"

using namespace std;

int main(int argc, char** argv) {
	ifstream dictionary;

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

	dictionary.close();

	exit(0);
}
