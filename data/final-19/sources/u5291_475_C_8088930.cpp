#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int solve(const vector<string> &field){
	const int n = field.size(), m = field[0].size();
	int left = -1, top = -1;
	for(int i = 0; left < 0 && i < n; ++i){
		for(int j = 0; left < 0 && j < m; ++j){
			if(field[i][j] == 'X'){ left = j; top = i; }
		}
	}
	int width = 0;
	while(left + width < m){
		if(field[top][left + width] != 'X'){ break; }
		++width;
	}
	int left_length = 0, right_length = 0;
	while(top + left_length < n){
		if(field[top + left_length][left] != 'X'){ break; }
		++left_length;
	}
	while(top + right_length < n){
		if(field[top + right_length][left + width - 1] != 'X'){ break; }
		if(left + width < m && field[top + right_length][left + width] != '.'){ break; }
		++right_length;
	}
	if(left_length < right_length){ return INF; }
	const int height = max(1, left_length - right_length);
	vector< vector<int> > integral(n + 1, vector<int>(m + 1));
	int x = left, y = top;
	while(true){
		++integral[y][x];
		--integral[y][x + width];
		--integral[y + height][x];
		++integral[y + height][x + width];
		if(x + width < m && field[y][x + width] == 'X'){
			++x;
		}else if(y + height < n && field[y + height][x] == 'X'){
			++y;
		}else{
			break;
		}
	}
	for(int i = 0; i <= n; ++i){
		for(int j = 0, s = 0; j <= m; ++j){
			s += integral[i][j];
			integral[i][j] = s;
		}
	}
	for(int j = 0; j <= m; ++j){
		for(int i = 0, s = 0; i <= n; ++i){
			s += integral[i][j];
			integral[i][j] = s;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			const char c = (integral[i][j] ? 'X' : '.');
			if(c != field[i][j]){ return INF; }
		}
	}
	return width * height;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> field(n);
	for(int i = 0; i < n; ++i){ cin >> field[i]; }
	vector<string> trans_field(m, string(n, ' '));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){ trans_field[j][i] = field[i][j]; }
	}
	int answer = min(solve(field), solve(trans_field));
	if(answer >= INF){ answer = -1; }
	cout << answer << endl;
	return 0;
}
