/*
 * 2012-01-04  Martin  <Martin@Martin-desktop>

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

namespace Geometry
{
	inline int Sig(long double X)
	{
		if (fabs(X) < 1e-10)
			return 0;
		return (X < 0) ? - 1 : 1;
	}

	inline long double Det(cmplxd A, cmplxd B)
	{
		return real(A) * imag(B) - real(B) * imag(A);
	}
	
	inline cmplxd CrossPoint(cmplxd A, cmplxd B, cmplxd C, cmplxd D)
	{
		double S1 = Det(B - A, C - A);
		double S2 = Det(D - A, B - A);
		return (C * S2 + D * S1) / (S1 + S2);
	}

	inline bool CompareXY(cmplxd A, cmplxd B)
	{
		return real(A) < real(B) || (real(A) == real(B) && imag(A) < imag(B));
	}
}

namespace Poor
{
	const int MaxiN = 100005;
	
	int N;
	int R[MaxiN], S[MaxiN], M[MaxiN], B[MaxiN];
	
	bool Check(int Item)
	{
		int i = 0;
		for (int j = 0; j < Item; ++ i, ++ j)
			S[j] = R[i];
		for (int j = 0; j < Item; ++ i, ++ j)
		{
			while (i < N && R[i] == S[j])
				++ i;
			if (i >= N)
				return 0;
			M[j] = R[i];
		}
		for (int j = 0; j < Item; ++ i, ++ j)
		{
			while (i < N && R[i] == M[j])
				++ i;
			if (i >= N)
				return 0;
			B[j] = R[i];
		}
		return 1;
	}
	
	void Run()
	{
		scanf("%d", &N);
		rep (i, N)
			scanf("%d", R + i);
		sort(R, R + N);
		int L = 0, R = N / 3;
		while (L < R)
		{
			int Mid = (L + R + 1) / 2;
			if (Check(Mid))
				L = Mid;
			else
				R = Mid - 1;
		}
		Check(L);
		printf("%d\n", L);
		rep (i, L)
			printf("%d %d %d\n", B[i], M[i], S[i]);
	}
}

int main()
{
	Poor::Run();
	return 0;
}
