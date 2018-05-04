
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace::std;

int main() {
	vector<string> dictionary(500001);
	ifstream dic("justPasswords.txt");
	ifstream passwords("randomPasswords.txt");
	ofstream out("passwordData.txt");
	string buffer;
	int count = 0;

	while (getline(dic, buffer)) {
		dictionary[count] = buffer;
		count++;
	}

	int size = dictionary.size();
	int c = 1;

	while (getline(passwords, buffer)) {
		/* The format for the data output is the password tested
		followed by true or false then the length of the string
		false if the password wasn't found by the dictionary
		true if the password was found*/
		cout << c << "\n";
		c++;
		bool captured = false;
		out << buffer << "\t";
		for (int i = 0; i < size; i++) {
			if (buffer == dictionary[i]) {
				out << "true" << "\t";
				captured = true;
				break;
			}
		}
		if (!captured) {
			out << "false" << "\t";
		}
		out << buffer.length() << "\n";
	}

	out.close();
	return 0;
}