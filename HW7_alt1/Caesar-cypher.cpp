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
		if (i + value < 91) {
			i = i + value;
		}
		else if (i + value > 91) {
			i = i + value - 26;
		}
		else if (i + value < 123) {
			i = i + value;
		}
		else if (i + value > 123) {
			i = i + value - 26;
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