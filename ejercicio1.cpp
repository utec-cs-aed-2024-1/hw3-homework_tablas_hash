#include <iostream>
#include <string>

using namespace std;

int maxNumberOfBalloons(string text) {
	int freq[26] = {0};

	for (char c : text) {
		freq[c - 'a']++;
	}

	int minCount = min(freq['b' - 'a'], min(freq['a' - 'a'], min(freq['l' - 'a'] / 2, min(freq['o' - 'a'] / 2, freq['n' - 'a']))));

	return minCount;
}

int main() {
	string text = "nlaebolko";
	//string text = "loonloonbalxballpoonbalxballpoonloonbloonbalxballpoonalxballpoon";

	cout << maxNumberOfBalloons(text) << endl;
	//cout << maxNumberOfBalloons(text) << endl;

	return 0;
}