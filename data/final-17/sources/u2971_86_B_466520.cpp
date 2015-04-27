#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
int N,M;
char mat[1024][1024];
int cnt[1024][1024];
int dx[] = {0,1,0,-1,0};
const int* const dy = dx+1;
bool used[10];
typedef pair<int,int> P;
vector<P> chs;
vector<P> ones;
void use(int x, int y) {
	chs.push_back(P(x,y));
	mat[y][x] = '!';
	for(int i=0; i<4; ++i) {
		int xx = x+dx[i], yy = y+dy[i];
		char c = mat[yy][xx];
		if (isdigit(c)) used[c-'0'] = 1;
		if (c=='.') {
			--cnt[yy][xx];
			if (cnt[yy][xx]==0) {
				use(xx,yy);
			} else if (cnt[yy][xx]==1) {
				ones.push_back(P(xx,yy));
			}
		}
	}
}
void fill(int x, int y) {
	memset(used,0,sizeof(used));
	chs.clear();
	use(x,y);

//	cout<<"filling "<<x<<' '<<y<<" : "<<chs.size()<<'\n';

	if (chs.size()==1) {
		for(int i=0; i<4; ++i) {
			int xx = x+dx[i], yy = y+dy[i];
			char c = mat[yy][xx];
			if (c=='.') {
				use(xx,yy);
				break;
			}
		}
	}
	if (chs.size()==1) {
		cout<<"-1\n";
		exit(0);
	}

	int c=0;
	while(used[c]) ++c;
	for(size_t i=0; i<chs.size(); ++i) {
		P p = chs[i];
//		cout<<"k "<<p.first<<' '<<p.second<<'\n';
		mat[p.second][p.first] = '0'+c;
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i) {
		cin>>&mat[i+1][1];
	}
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			int a=0;
			for(int k=0; k<4; ++k) {
				int x = j+dx[k], y = i+dy[k];
				a += mat[y][x]=='.';
			}
			cnt[i][j] = a;
			if (a==0 && mat[i][j]=='.') {
				cout<<"-1\n";
				return 0;
			}
			if (mat[i][j]=='.' && a==1) {
				ones.push_back(P(j,i));
			}
		}
	}
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			for(size_t k=0; k<ones.size(); ++k) {
				P p = ones[k];
				int x = p.first, y = p.second;
				if (mat[y][x]!='.') continue;
				fill(x,y);
			}
			ones.clear();
			if (mat[i][j]=='.') {
				fill(j,i);
			}
		}
	}
	for(int i=1; i<=N; ++i) {
		cout<<&mat[i][1]<<'\n';
	}
}
