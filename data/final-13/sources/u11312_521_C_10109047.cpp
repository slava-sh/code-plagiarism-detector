#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <algorithm>
#include <functional>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) (((a)>0)-((a)<0))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926535897932384626433832795)
#define INF (2147483647)
#define LLINF (9223372036854775807LL)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}

inline LL Cnk(int _n, int _k)
{ // {{{
	LL _r = 1;
	int _t = max(_k, _n-_k);
	for(int _i=_t+1; _i <= _n; ++_i)
	{
		_r *= _i;
		_r /= _i - _t;
	}
	return _r;
} // }}}

inline LL gcdex(LL _a, LL _b, LL &_x, LL &_y)
{ // {{{
	LL _r, _q, _x0, _y0, _x1, _y1;
	_y1=_x=_x0=1;
	_x1=_y=_y0=0;
	while(_b!=0){
		_q = _a/_b;
		_r = _a-_q*_b;
		if(_r!=0){
			_x = _x0-_q*_x1;
			_y = _y0-_q*_y1;
			_x0 = _x1; _y0 = _y1;
			_x1 = _x; _y1 = _y;
		}
		_a = _b; _b = _r;
	}
	if(_a<0) {_a=-_a; _x=-_x; _y=-_y;}
	return _a;
} // }}}

inline LL inverse(LL _n, LL _m)
{ // {{{
	LL _x, _y;
	LL _g = gcdex(_n, _m, _x, _y);
	if(_g != 1) return -1;
	else return (_x % _m + _m) % _m;
} // }}}

int main()
{
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	int m[100500], ms[100500];
	char s[100500];
	scanf("%s", &s);
	for(int i=0; i<n; ++i){
		m[i] = s[i]-'0';
		if(!i) ms[i] = m[i];
		else ms[i] = (ms[i-1]+m[i])%MOD;
	}
	LL ck=1, ck1=1, p=1, a=n-k;
	LL pi = inverse(10, MOD);
	while(a>1) p=(p*10)%MOD, a--;
	LL res = 0;
	for(int i=k, n1=k; i<n; ++i, ++n1){
		res = (res + (ck1 * (i ? ms[i-1] : 0) % MOD + ck * m[i] % MOD ) % MOD * p % MOD) % MOD;
		//cout << res << " " << p << " " << ck << " " << ck1 << endl;
		p = (p*pi)%MOD;

		ck = ck * (n1+1) % MOD * inverse(n1+1-k, MOD) % MOD;
		ck1= ck1* n1 % MOD * inverse(n1+1-k, MOD) % MOD;

	}
	cout << res;
	return 0;
}

int cpp4cf_main()
{
	freopen("C.cpp","r",stdin);

	char s[99];
	bool f;

	while(true) {
		cin>>s;
		if(cin.eof()) break;
		if(strstr(s,"/*")) {
			cin>>s;
			if(strstr(s,"Test")) {
				cin>>s;
				if(strstr(s,"on")) {
					cout<<"Output: ";
					cpp4cf_main();
					cout<<"\nAnswer: ";
					f = false;
					while(true) {
						cin>>s;
						if(strstr(s,"*/")) break;
						if(strstr(s,"//")) {
							if(f) cout<<endl;
							else f = true;
						}else cout<<s<<" ";
					}
					cout<<"\n\n";
				}
			}
		}
	}

	return 0;
}

