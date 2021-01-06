#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

map<string, bool> hashWords;

vector<pair<string,string> > getAllSubWords(string word) {

	vector<pair<string,string> > output;

	if (word.size() == 1) {
		return output;
	}

	unsigned long wordLength = word.size();

	string wordSoFar = "";
	for (int i = 0; i < wordLength; i++) {

		wordSoFar+=word[i];
		string remainingWord = "";

		for (int j = i + 1; j < wordLength; j++) {
			remainingWord+=word[j];
		}

		if (remainingWord != "") {

			output.push_back(make_pair(wordSoFar, remainingWord));
		}
	}

	return output;
}

bool checkIfWordIsCompose(string word1, string word2) {

	if (hashWords[word1] && hashWords[word2]) {
		return true;
	}
	return false;
}


int main(int argc, char const *argv[]) {
	// cin slow. Sin usar esta porción de código, el problema arrojará TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> answer, possibleCompoundWords;
	string word;

	while(cin >> word) {

		hashWords[word] = true;
		possibleCompoundWords.push_back(word);
	}


	for (int i = 0; i < possibleCompoundWords.size(); i++) {
		vector<pair<string,string> > allSubWords = getAllSubWords(possibleCompoundWords[i]);

		for (int j = 0; j < allSubWords.size(); j++) {

			if (checkIfWordIsCompose(allSubWords[j].first, allSubWords[j].second)) {
				answer.push_back(possibleCompoundWords[i]);
				break;
			}
		}
	}

	// sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		printf("%s\n", answer[i].c_str());
	}

	return 0;
}
