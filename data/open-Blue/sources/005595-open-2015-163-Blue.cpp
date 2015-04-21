#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

int l;
string s;

bool check1(){
	int ss = s.size();
	l = min(ss, l);
	vector<int> zfunc(s.size() + 1, 0);
	s.push_back('*');
	int border = 1, pborder = 0;
	for(int i = 1; i <= l; i++){
		border = max(border, i);
		zfunc[i] = min(border - i, zfunc[i - pborder]);
		if(zfunc[i] + i >= border){
			pborder = i;
			while(s[i + zfunc[i]] == s[zfunc[i]]){
				zfunc[i]++;
				border++;
			}
		}
		if(!(ss % i) && i + zfunc[i] >= ss){
			cout << "1\n" << s.substr(0, i);
			exit(0);
		}
	}
	s.pop_back();
	if(l > (int)s.size()){
		cout << "1\n" << s;
		exit(0);
	}
	return false;
}

typedef unsigned long long ull;

vector<ull> shash, pow5;

const ull MOD = 1000000007;
const ull MOD2 = MOD * MOD;

ull ahash, bhash;
int asize, bsize, pos, bb, ss;

inline bool cmp(bool is_a){
	if(is_a){
		if(ss - pos < asize){
			return false;
		}
		for(int i = 0; i < asize; i++){
			if(s[i] != s[i+pos]){
				return false;
			}
		}
		return true;
		//return ahash == (MOD2 + shash[pos + asize] - shash[pos] * pow5[asize]) % MOD;
	} else {
		if(ss - pos < bsize){
			return false;
		}
		for(int i = 0; i < bsize; i++){
			if(s[i+bb] != s[i+pos]){
				return false;
			}
		}
		return true;
		//return bhash == (MOD2 + shash[pos + bsize] - shash[pos] * pow5[asize]) % MOD;
	}
}

bool check2(){
	ss = s.size();
	shash.resize(ss + 1, 0);
	pow5.resize(ss + 1, 1);
	for(int i = 0; i < ss; i++){
		pow5[i+1] = (pow5[i] * 5) % MOD;
		shash[i+1] = (shash[i] * 5 + s[i] + 1 - 'a') % MOD;
	}
	for(asize = 1; asize <= l; asize++){
		ahash = shash[asize];
		pos = asize;
		while(cmp(true)){
			pos += asize;
		}
		if(pos + l >= ss){
			cout << "2\n" << s.substr(0, asize) << "\n" << s.substr(pos, l);
			exit(0);
		}
		bb = pos;
		for(bsize = 1; bsize * 2 + bb <= ss && bsize <= l; bsize++){
			pos = bb + bsize;
			bhash = (shash[bb + bsize] - shash[bb] * pow5[bsize]) % MOD;
			bool xadd = true;
			while(pos < ss && xadd){
				xadd = false;
				if(cmp(true)){
					pos += asize;
					xadd = true;
				}
				if(cmp(false)){
					pos += bsize;
					xadd = true;
				}
			}
			if(xadd){
				cout << "2\n" << s.substr(0, asize) << "\n" << s.substr(bb, bsize);
				exit(0);
			}
		}
	}
	return false;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	bool used[3];
	fill(used, used + 3, false);
	cin >> l >> s;
	for(int i = 0; i < (int)s.size(); i++){
		used[s[i] - 'a'] = true;
		assert(s[i] >= 'a' && s[i] <= 'c');
	}
	int summ = int(used[0]) + int(used[1]) + int(used[2]);
	assert(summ > 0);
	check1();
	if(summ == 3){
		check2();
	}
	cout << summ << "\n";
	for(int i = 0; i < 3; i++){
		if(used[i]){
			cout << char(i + 'a') << "\n";
		}
	}
	return 0;
}