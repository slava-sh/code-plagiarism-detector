#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#pragma comment(linker, "/STACK:100000000")
using namespace std;

const int MAXINT = 1000000010;
const long long MAXLL = 2e18;
const long long MODUL = 1000000007;



template <typename T>
inline T MIN(T a, T b)
{
	return (a < b ? a : b);
}

const double TL = 3;


bool tl;
inline void isTL()
{
	static int cou(1000);
	static double lost(0);
	if(!(--cou))
	{
		cou = 1000;
		if (clock() > (TL - 0.3) * CLOCKS_PER_SEC)
			tl = 1;
	}
}
long long best = MAXLL;
long long n, tmp;
map<long long, int> arr;
vector<long long> fact, win, part;
int k, si;
long long os;

void go(int ind)
{
	if(tl)
		return;
	if(ind == -1)
	{
		best = MIN(best, os);
		return;
	}
	isTL();
	if(os * part[ind] >= best)
		return;
	sort(win.begin(), win.end());
	vector<long long> wt = win;
	for(int i(0); i < k && !tl; ++i)
	{
		os /= wt[i] / 2 + 1;
		wt[i] *= fact[ind];
		os *= wt[i] / 2 + 1;
		if(os < 0)
			os = 1;
		go(ind - 1);
		os /= wt[i] / 2 + 1;
		wt[i] /= fact[ind];
		os *= wt[i] / 2 + 1;
	}
}

int main()
{
	tl = 0;
	cin >> n >> k;
	for(; !(n & 1) && k > 1; n >>= 1, --k);
	if(k == 1)
	{
		cout << n / 2 + (n & 1);
		return 0;
	};
	tmp = n;
	for(long long i(3); i * i <= tmp; ++i)
	for(; tmp % i == 0; fact.push_back(i), tmp /= i);
	if(tmp != 1)
		fact.push_back(tmp);
	si = fact.size();
	if(!si)
	{
		cout << 1;
		return 0;
	}
	if(k >= si)
	{
		long long ans = 1;
		for(int i(0); i < si; ++i)
			ans *= fact[i] / 2 + 1;
		cout << ans;
		return 0;
	}
	win.resize(k);
	for(int i(0); i < k; ++i)
		win[i] = 1;
	part.resize(si);
	part[0] = fact[0] - 1;
	for(int i(1); i < si; ++i)
		part[i] = part[i - 1] * (fact[i] - 1);
	os = 1;
	go(si - 1);
	cout << best;
	return 0;
}













