// Caesar-cypher.cpp Hiromi Kageyama Nov. 23, 2020
// Write a c++ program that shifts the letters by a certain number

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::endl;
using std::cin;
using std::cout;

void shift(string& caesar, int value) {
	for (auto& i: caesar) {
		if (i < 65) {
			continue;
		}
		if (i >= 'a' && i <= 'z') {
			i = 'a' + ((i - 'a' + value) % 26);
		}
		else if (i >= 'A' && i <= 'Z') {
			i = 'A' + ((i - 'A' + value) % 26);
		}
		else i = i;
	}
}

int main() {
	while (true) {
		string input;
		string num;
		int value;

		// string to shift
		cout << "Type anything in (Enter nothing to exit): ";
		getline(cin, input);
		cout << endl;

		while (true) {
			bool end = false;
			if (input == "") {
				cout << "Terminating program..." << endl;
				return 0;
			}
			// value of the shift
			cout << "Enter a number: ";
			getline(cin, num);
			cout << endl;
			std::stringstream con(num);

			for (auto i : num) {
				if (!isdigit(i) && i != '-') {
					cout << "Error, please enter a number" << endl;
				}
				else {
					con >> value;
					end = true;
				}
			}
			if (end) {
				break;
			}
		}

		shift(input, value);
		cout << "Result: " << input << endl << endl;
	}
	return 0;
}