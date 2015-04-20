#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a[3], string b[3]) {
	return a[0] < b[0];
}

int main() {
	ifstream fin("names.in");
	ofstream fout("names.out");
	int n;
	fin >> n;
	string names[1000][3];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			fin >> names[i][j];
	string words[3000];
	int count[3000];
	int unique_words = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 3; j++) {
			bool familiar = false;
			for (int k = 0; k < unique_words; k++) {
				if (names[i][j] == words[k]) {
				    count[k]++;
			    	familiar = true;
				}
		    }
			if (!familiar) {
				words[unique_words] = names[i][j];
				count[unique_words] = 1;
				unique_words++;
            }    
		}
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (words[j] != names[i][0]) {
			j++;
		}
		if (count[j] > 1) {
			string temp = names[i][2];
			for (int j = 1; j >= 0; j--) {
				names[i][j + 1] = names[i][j];
			}
			names[i][0] = temp;
		}
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (names[j][0] > names[j + 1][0])
				swap(names[j], names[j + 1]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			fout << names[i][j] << ' ';
		}
		fout << '\n';
	}

	return 0;
}