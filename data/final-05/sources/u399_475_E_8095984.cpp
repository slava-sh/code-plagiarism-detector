/*
 * 2014-10-05  Martin  <Martin@Martin-desktop>

 * 
 */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <locale>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <complex>
#include <valarray>

using namespace std;

template <class T> inline T checkmin(T &a, T b)
{
	return (a < b) ? a : a = b;
}

template <class T> inline T checkmax(T &a, T b)
{
	return (a > b) ? a : a = b;
}

template <class T> T GCD(T a, T b)
{
	if (a < 0)
		return GCD(- a, b);
	if (b < 0)
		return GCD(a, - b);
	return (a == 0) ? b : GCD(b % a, a);
}

template <class T> T LCM(T a, T b)
{
	if (a < 0)
		return LCM(- a, b);
	if (b < 0)
		return LCM(a, - b);
	return (a == 0 || b == 0) ? 0 : a / GCD(a, b) * b;
}

template <class T> inline T sqr(T X)
{
	return X * X;
}

#define tr(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); ++ i)
#define rep(i, n) for (int i = 0; i < n; ++ i)
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long
#define cmplxd complex <double>
#define pi 3.14159265358979323846264338327950288

namespace Poor
{
	const int MaxiN = 2005;
	const int ModNum = 1000000007;
	
	int N, M, Top, Ans;
	int Label[MaxiN], Stack[MaxiN], S[MaxiN], Pa[MaxiN], Size[MaxiN], F[MaxiN], G[MaxiN];
	bool Map[MaxiN][MaxiN], Map2[MaxiN][MaxiN], Bag[MaxiN];
	
	int Find(int X) {
		if (S[X] < 0)
			return X;
		S[X] = Find(S[X]);
		return S[X];
	}
	
	void Union(int X, int Y) {
		X = Find(X);
		Y = Find(Y);
		if (X == Y)
			return;
		if (S[X] < S[Y]) {
			S[X] += S[Y];
			S[Y] = X;
		}
		else {
			S[Y] += S[X];
			S[X] = Y;
		}
	}
	
	void DFS1(int Cur) {
		Label[Cur] = Cur;
		Stack[Top] = Cur;
		++ Top;
		rep (i, N)
			if (Map[Cur][i] && !Map2[Cur][i]) {
				Map2[Cur][i] = Map2[i][Cur] = true;
				if (Label[i] == - 1)
					DFS1(i);
				else {
					/// Circle!
					int t = Top;
					while (t > 0 && Stack[t - 1] != i) {
						-- t;
						Union(Label[Stack[t]], Label[i]);
					}
				}
			}
		-- Top;
	}
	
	void DFS2(int Cur) {
		Size[Cur] = - S[Cur];
		F[Cur] = 0;
		rep (i, N)
			if (Map2[Cur][i] && i != Cur && i != Pa[Cur]) {
				Pa[i] = Cur;
				DFS2(i);
				Size[Cur] += Size[i];
				F[Cur] += F[i];
			}
		F[Cur] += Size[Cur] * (- S[Cur]);
	}
	
	void DFS3(int Cur) {
		checkmax(Ans, F[Cur] + G[Cur]);
		rep (i, N)
			if (Pa[i] == Cur) {
				G[i] = G[Cur] - S[i] * (N - Size[i]) + F[Cur] - F[i] - (- S[Cur]) * Size[i];
				DFS3(i);
			}
	}
	
	void Run()
	{
		scanf("%d%d", &N, &M);
		memset(Map, 0, sizeof(Map));
		rep (i, M) {
			int U, V;
			scanf("%d%d", &U, &V);
			-- U, -- V;
			Map[U][V] = Map[V][U] = 1;
		}
		memset(Map2, 0, sizeof(Map2));
		Top = 0;
		fill(Label, Label + N, - 1);
		fill(S, S + N, - 1);
		DFS1(0);
		memset(Map2, 0, sizeof(Map2));
		rep (i, N)
			rep (j, N)
				if (Map[i][j])
					Map2[Find(i)][Find(j)] = 1;
		fill(Pa, Pa + N, - 1);
		int Root = Find(0);
		DFS2(Root);
		Ans = 0;
		G[Root] = 0;
		DFS3(Root);
		
		rep (i, N)
			if (Find(i) == i) {
				fill(Bag, Bag + N + 1, 0);
				Bag[0] = true;
				rep (j, N)
					if (j == Pa[i] || Pa[j] == i) {
						int g = 0;
						if (Pa[j] == i)
							g = Size[j];
						else
							g = N - Size[i];
						for (int k = N; k >= g; -- k)
							if (Bag[k - g])
								Bag[k] = true;
					}
				rep (k, N)
					if (Bag[k])
						checkmax(Ans, F[i] + G[i] + k * (N + S[i] - k));
			}
		
		cout << Ans << endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
	#endif
	Poor::Run();
	return 0;
}
