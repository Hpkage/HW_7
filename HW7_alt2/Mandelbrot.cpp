#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

float width = 600;
float height = 600;

int value(int x, int y) {
    complex<float> point((float)x / width - 1.5, (float)y / height - 0.5);
    complex<float> z(0, 0);
    int nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 20) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 20)
        return (255 * nb_iter) / 20;
    else
        return 0;
}

int main() {
	ifstream fin("mandelbrot.ppm");
	if (!fin) {
		cout << "Error opening mandelbrot.ppm" << endl;
		exit(1);
	}
	cout << "Oppened mandelbrot.ppm" << endl;

	std::string line;
	getline(fin, line);
	if (line[0] == 'P' && line[1] == '3') {
		cout << "Found ppm (text)" << endl;
	}
	else {
		cout << "Unable to read magic number P3" << endl;
		exit(2);
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

		const char values[] = " .,*^;!+=?/{#%$&@";
		int val_map = y / 16;
		cout << values[val_map];
		if (i % 600 == 599) {
			cout << endl;
		}

	}

}