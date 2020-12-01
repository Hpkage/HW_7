#include <iostream>
#include <fstream>
#include <string>
#include "Image3.hpp"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main() {
	ifstream fin("parrot.ppm");
	if (!fin) {
		cout << "Error opening parrot.ppm" << endl;
		exit(1);
	}
	cout << "Oppened parrot.ppm" << endl;

	std::string line;
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
	cout << "Image size " << xres << "x" << yres << endl;
	cout << "Maxval = " << maxval << endl;

	int r, g, b, y;
	int pixel2read = xres * yres;
	for (int i = 0; i < pixel2read; i++) {
		if (!fin) {
			cout << "Error reading pixels" << endl;
			exit(4);
		}
		fin >> r >> g >> b;
		y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
		if (y < 0 || y > 255) {
			cout << "Error: y out of range" << endl;
			exit(5);
		}

		const char values[] = " .,-+~^*=/{#%$&@";
		int val_map = y / 16;
		cout << values[val_map];
		if (i % 80 == 78) {
			cout << endl;
		}

	}

}