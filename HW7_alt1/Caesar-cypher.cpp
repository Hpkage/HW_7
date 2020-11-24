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
		int num;

		// string to shift
		cout << "Type anything in (Enter nothing to exit): ";
		getline(cin, input);
		cout << endl;

		// Press enter to quit
		if (input == "") {
			cout << "Terminating program..." << endl;
			break;
		}

		cin.ignore();

		while (true) {
			// value of the shift
			cout << "Enter a number :";
			cin >> num;
			cout << endl;
			if (!isdigit(num)) {
				break;
			}
			else {
				cout << "Error, please enter a number" << endl;
			}
		}

		cin.clear();
		cin.ignore();

		shift(input, num);
		cout << input << endl;

	}
	return 0;
}