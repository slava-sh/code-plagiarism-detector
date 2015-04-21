#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int
#define inf 1000000000000000000
#define Z 3001

struct st
{
	int t, v;
	bool l;
};

bool operator<(st a, st b)
{
	return a.t < b.t ||
		a.t == b.t && a.v < b.v ||
		a.t == b.t && a.v == b.v && a.l < b.l;
}

st getSt(int t, int v, bool l)
{
	st s;
	s.t = t;
	s.v = v;
	s.l = l;
	return s;
}

lint N, K, C, D;

vector<pair<lint, lint>> v;

lint t1[Z];
lint t2[Z];

map<st, lint> m;

lint g(int t, int f, bool l)
{
	
	if(t == 0 && f == K && l == 0)
		return 0;
	if(t == 0)
		return inf;
	if(f > K)
		return inf;
	
	st s;
	s.t = t;
	s.v = f;
	s.l = l;
	if(l == 1)
		m[s] = g(t, f, 0) + t2[t];
	if(m[s])
		return m[s];
	
	
	//...
	lint res = inf;
	lint D0 = D * (v[t - 1].second - v[t - 1].first);
	lint D1 = D * (v[t].first - v[t - 1].first);
	if(l == 0)
	{
		
		res = min(res, g(t - 1, f + 1, 0) + D0);
		res = min(res, g(t - 1, f, 1) + D0);
	}
	if(l == 1)
	{
		
		res = min(res, g(t - 1, f + 1, 0) + D1);
		res = min(res, g(t - 1, f, 1) + D1);
	}
	if(f == K - 1)
	{
	
		lint DC;
		if(l == 0)
			DC = D0;
		else
			DC = D1;
		//for(int i = 0; i <= K; i++)
		//	for(int j = 0; j < 2; j++)
		res = min(res, g(t - 1, 0, 0) + C + DC);
	}
	//...
	m[s] = res;
	return m[s];
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> K >> C >> D;
	for(int i = 0; i < N; i++)
	{
		lint a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	v.push_back(make_pair(v.back().second, v.back().second));
	st s;
	s.t = 0;
	s.v = K;
	s.l = 0;
	m[s] = 0;
	/*
	lint res = inf;

	for(int i = 0; i < K; i++)
		for(int j = 0; j < 2; j++)
	{
		res = min(res, g(N, i, j));
	}
	cout << res;*/
	

	for(int i = 0; i <= K; i++)
		for(int j = 0; j < 2; j++)
			m[getSt(0, i, j)] = inf;
	
	m[getSt(0, K, 0)] = 0;
	
	for(int i = 1; i <= N; i++)
	{
		t1[i] = D * (v[i - 1].second - v[i - 1].first);
		t2[i] = D * (v[i].first - v[i - 1].second);
	}
	for(int t = 1; t <= N; t++)
	{
		for(int f = 0; f <= K; f++)
		{
			lint res = inf;
			lint D0 = t1[t];
			//lint D1 = D * (v[t].first - v[t - 1].first);
			
				if(f < K)
				res = min(res, m[getSt(t - 1, f + 1, 0)] + D0);
				res = min(res, m[getSt(t - 1, f, 1)] + D0);
			
			
			if(f == K - 1)
			{
	
				res = min(res, m[getSt(t - 1, 0, 0)] + C + D0);
			}
			st s0 = getSt(t, f, 0);
			m[s0] = res;
			s0.l = 1;
			m[s0] = res + t2[t];
		}
	}
	lint res = inf;

	for(int i = 0; i < K; i++)
	{
		res = min(res, g(N, i, 0));
	}
	cout << res;

	fclose(stdin);
	fclose(stdout);
	return 0;
}