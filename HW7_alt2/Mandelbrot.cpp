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



}