#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool compare(pair<string,int> a, pair<string,int> b) {
	return a.second>b.second;
}

int main(int argc, char** argv) {
	string line;
	ifstream file;
	map<string, int> wordcount;

	file.open(argv[1]);
	while (file.good()) {
		getline(file, line);
		transform(line.begin(), line.end(), line.begin(), ::tolower);

		string word;
		for (int i=0; i<line.length(); i++) {
			char c = line[i];
			if (c >= 'a' && c <= 'z') word += c;

			if (word.length() > 0 && ((c < 'a' || c > 'z') || i == line.length()-1)) {
				wordcount[word]++;
				word.clear();
			}
		}
	}
	file.close();

	vector< pair<string,int> > wordlist;
	for (map<string,int>::iterator it=wordcount.begin(); it != wordcount.end(); it++)
		wordlist.push_back(pair<string,int>(it->first, it->second));
	sort(wordlist.begin(), wordlist.end(), compare);

	printf("%-20s%s\n", "Word", "Freq");
	for (vector< pair<string,int> >::iterator it=wordlist.begin(); it != wordlist.end(); it++)
		printf("%-20s%d\n", (it->first).c_str(), it->second);

	return 0;
}
