#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>
#include <string>
#include <time.h>
#include <set>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#define mp(a,b) make_pair(a,b)

char buf[1005][1005];
int ans[1005][1005];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int cur = 1;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> buf[i];
	}
	// stage 1
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (buf[i][j] == '.' && buf[i][j+1] == '.' && !ans[i][j]){
				ans[i][j] = ans[i][j+1] = cur++;
			}
		}
	}

	// stage 2
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (buf[i][j] == '.' && buf[i+1][j] == '.' && !ans[i][j] && !ans[i+1][j]){
				ans[i][j] = ans[i+1][j] = cur++;
			}
		}
	}

	//no more than 5 can accure
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (buf[i][j] == '.' && !ans[i][j]){
				bool good = false;
				for (int k=0; k<4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny]){
						ans[i][j] = ans[nx][ny];
						good = true;
						break;
					}
				}
				if (!good){
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (buf[i][j] == '.'){
				bool can[10] = {};
				set<pair<int, int> > S;
				queue<pair<int, int> > Q;
				Q.push(mp(i,j));
				buf[i][j] = '#';
				while (!Q.empty()){
					pair<int, int> par = Q.front();
					S.insert(par);
					Q.pop();
					for (int k=0; k<4; k++){
						int nx = par.first + dx[k];
						int ny = par.second + dy[k];
						if (nx < n && nx >=0 && ny < m && ny >= 0){
							if (buf[nx][ny] != '#'){
								if (ans[i][j] != ans[nx][ny]){
									if (buf[nx][ny] != '.'){
										can[buf[nx][ny]-'0'] = true;
									}
								} else {
									Q.push(mp(nx, ny));
									buf[nx][ny] = '#';
								}
							}
						}
					}
				}
				int col = 0;
				for (col=0; can[col]; col++);
				for (set<pair<int, int> > :: iterator it = S.begin(); it != S.end(); ++it){
					buf[it->first][it->second] = col + '0';
				}
			}
		}
	}

/*	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (ans[i][j]){
				M[ans[i][j]];
				for (int k=0; k<4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && buf[nx][ny] == '.' && ans[nx][ny] != ans[i][j]){
						M[ans[i][j]].push_back(ans[nx][ny]);
					}
				}
			}
		}
	}

	for (map<int, list<int> > :: iterator it = M.begin(); it != M.end(); ++it){
		bool can[10] = {};
		for (list<int> :: iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
			map<int, char> :: iterator it3 = C.find(*it2);
			if (it3 != C.end()){
				can[it3->second - '0'] = true;
			}
		}
		for (int i=0; i<10; i++){
			if (!can[i]){
				C[it->first] = i+'0';
				break;
			}
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (buf[i][j] == '.'){
				buf[i][j] = C[ans[i][j]];
			}
		}
	}*/
	for (int i=0; i<n; i++){
		cout << buf[i] << endl;
	}
	return 0;
}