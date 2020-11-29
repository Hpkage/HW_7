#include <iostream>
#include <fstream>
#include <string>
#include "Image3.hpp"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

ifstream fin("parrot.ppm");

int main() {
	if (!fin) {
		cout << "Error opening parrot.ppm" << endl;
		exit(1);
	}
	cout << "Oppened parrot.ppm" << endl;

	string line;
	getline(fin, line);
	if (line[0] == 'P' && line[1] == '3') {
		cout << "Found ppm (text)" << endl;
	}
	else {
		cout << "Unable to read magic number P3" << endl;
		exit(2);
	}

	getline(fin, line);
	if (line[0] == '#') {
		cout << "Ignoring comment" << endl;
	}

	int xres, yres, maxval;
	fin >> xres >> yres >> maxval;
	if (!fin) {
		cout << "Error reading res" << endl;
		exit(3);
	}
	cout << "Image size" << xres << "x" << yres << endl;
	cout << "Maxval = " << maxval << endl;

	int r, g, b, y;
	int pixel2read = xres * yres;
	for (int i = 0; i < pixel2read; i++) {
		if (!fin) {
			cout << "Error reading pixels" << endl;
			exit(4);
		}

	}

}