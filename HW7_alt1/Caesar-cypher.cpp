// Caesar-cypher.cpp Hiromi Kageyama Nov. 23, 2020
// Write a c++ program that shifts the letters by a certain number

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cin;
using std::cout;

void shift(string& caesar, int value) {
	for (auto& i: caesar) {
		if (i < 65) {
			continue;
		}
		else if (isupper(i)) {
			 if (i + value < 91 && i + value > 64){
				 i = i + value;
			 }
			 else {
				 i = i + value - 26 * (value / 26);
			 }
		}
		else {
			if (i + value < 123 && i + value > 96) {
				i = i + value;
			}
			else {
				i = i + value - 26 * (value / 26);
			}
		}
	}
}

int main() {
	string input;
	int num;
	cout << "Type anything in: ";
	cin >> input;
	cout << endl;
	cout << "Enter a number :";
	cin >> num;
	cout << endl;

	shift(input, num);
	cout << input << endl;
	
	
	return 0;
}