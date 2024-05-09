#include<iostream>
#include<fstream>
#include<map>
#include<cctype>
#include<string>
#include<iomanip>

using namespace std;

void pressEnterToContinue();

int main() {
	map<char, int> letterFrequency;

	ifstream file;
	string fileName;
	cout << "Enter File name: ";
	getline(cin, fileName);
	
	file.open(fileName);

	if (!file) {
		cerr << "Error, unable to open this file..." << endl;
		return 1;
	}

	char ch;
	int totalLetters = 0;
	while (file.get(ch)) {
		if (isalpha(ch)) {
			ch = toupper(ch);

			letterFrequency[ch]++;
			totalLetters++;
		}
	}

	file.close();

	cout << "Total number of letters: " << totalLetters << endl;

	cout << "Frequency: " << endl;
	cout << fixed << setprecision(3);
	double frequency;
	for (char letter = 'A'; letter <= 'Z'; letter++) {
		frequency = static_cast<double>(letterFrequency[letter]) / totalLetters * 100;
		cout << "'" << letter << "': " << frequency << endl;
	}

	pressEnterToContinue();
	return 0;

}

void pressEnterToContinue() {
	char c;
	cout << "Press enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}