#include <fstream>

using namespace std;

int main() {
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int n;
	fin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cur;
		fin >> cur;
		if (cur >= i)
			ans++;
	}
	fout << ans;
	for (int i = 0; i < ans; i++)
		fout << '\n' << i + 1 << ' ' << i + 1;

	return 0;
}