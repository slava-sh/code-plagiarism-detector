#include <fstream>

using namespace std;

int main() {
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n, m;
	fin >> n >> m;
	int heights[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
		fin >> heights[i][j];
		}
	int common = 0;
	int privat[2] = { 0, 0 };
	for (int i = 0; i < n; i++) {
		int cur;
		fin >> cur;
		bool petya, vasya;
		if ((cur >= heights[0][0]) && (cur <= heights[0][1]))
			petya = true;
		else
			petya = false;
		if ((cur >= heights[1][0]) && (cur <= heights[1][1]))
			vasya = true;
		else
			vasya = false;
		if ((petya) && (vasya))
			common++;
		else {
			if (petya)
				privat[0]++;
			if (vasya)
				privat[1]++;
		}
	}
	int score[2] = { 0, 0 };
	for (int i = 0; i < m; i++) {
		int player = i % 2;
		if (common) {
			common--;
			score[player]++;
		}
		else if (privat[player]) {
			privat[player]--;
			score[player]++;
		}
	}
	if (score[0] == score[1])
		fout << "Draw";
	else if (score[0] > score[1])
		fout << "Petya";
	else
		fout << "Vasya";

	return 0;
}