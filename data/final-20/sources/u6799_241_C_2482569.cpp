#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
const double EPS=1e-9;
const double INF=1e10;


struct Mirror{
	double left,right;
	int score;
};
bool operator<(const Mirror &a, const Mirror &b){
	return a.left<b.left;
}
vector<Mirror> mirrors[2];
int main(){
	int n;
	int hl,hr;
	cin>>hl>>hr>>n;
	REP(i,n){
		int v,a,b;
		string s;
		cin>>v>>s>>a>>b;
		int t = s[0] == 'T';
		mirrors[t].push_back((Mirror){a,b,v});
	}
	REP(i,2){
		sort(mirrors[i].begin(),mirrors[i].end());
	}
	int ans = 0;
	for(int target = -150; target <= 150; target++){
		double tr = target * 100;
		if(target % 2 != 0)tr += 100 - hr;
		else tr += hr;
		// y = ax + b
		// hr-hl = 10000a
		double b = hl, a = (tr-hl)/100000.0;
		// y = ax + b
		// -ax = -y + b
		// x = y/a - b/a
		int score = 0;
		set<int> disp[2];
		for(int i = -150; i <= 150; i++){
			double x = (i * 100 - b) / a;
			if(0 < x && x < 100000){
				int k = (i % 2 != 0);
				int tar = upper_bound(mirrors[k].begin(),mirrors[k].end(), (Mirror){x,0,0}) - mirrors[k].begin() - 1;
				if(tar == -1 || mirrors[k][tar].right < x){
					score = 0;
					goto exit;
				}
				score+=mirrors[k][tar].score;
				if(disp[k].count(tar)){
					score=0;
					goto exit;
				}
				disp[k].insert(tar);
			}
		}
		exit:
		ans = max(ans,score);
	}
	cout << ans << endl;
}
