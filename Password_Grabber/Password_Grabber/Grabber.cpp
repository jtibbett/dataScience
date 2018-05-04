#include <regex>
#include <fstream>
#include <string>

using namespace::std;

int main() {
	string buffer;
	match_results<string::const_iterator> result;
	int count = 0;

	ifstream in("10-million-combos.txt");
	ofstream out("justPasswords.txt");

	while (getline(in, buffer) && count <= 1000000) {
		regex_search(buffer, result, regex("(.*)\\t(.*)"));
		string temp = result[1];
		out << result[2] << "\n";
		count++;
	}

	out.close();
	return 0;
}
