/*************************************************************************
Author: ziki
Created Time: 2012/1/4 23:16:01
File Name: C.cpp
Description: 
************************************************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>


using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define zero(a) memset(a, 0, sizeof(a))
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

int aa[100000][3];
struct S{
	int n;
	int c;
	bool operator < (const  S &b)const
	{
		return c<b.c;
	}
}s;


int main()
{
	int n;
	while(cin>>n)
	{
		map<int,int>st;
		for(int i=0; i<n;i++)
		{
			int a;
			cin>>a;
			st[a]++;
		}
		priority_queue<S> que;
		map<int,int>::iterator it;
		for(it = st.begin(); it!=st.end(); it++)
		{
			s.n = it->first;
			s.c = it->second;
			que.push(s);
		}
		int k=0;
		while(1)
		{
			if(que.size()<3)break;
			S b[3];
			for(int i=0; i<3; i++){
				b[i] = que.top();
				que.pop();
				//cout<<b[i].n<<' '<<b[i].c<<'#'<<endl;
				b[i].c--;
				aa[k][i] = b[i].n;
			}
			for(int i=0; i<3; i++){
				if(b[i].c>0)
					que.push(b[i]);
			}
			sort(aa[k],aa[k]+3);
			k++;
		}
		cout<<k<<endl;
		for(int i = 0; i<k; i++)
		{
			cout<<aa[i][2] << ' ' << aa[i][1] << ' ' << aa[i][0]<<endl;
		}
	}
	return 0;
}

