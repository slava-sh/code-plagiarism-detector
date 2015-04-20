#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <ctime>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#define ll long long
#define MAXN 100000
#define INF 100000000
#define pb push_back
#define pob pop_back
#define sz size()
#define eps 1e-6
#define fname "prizes"
#define pof pop_front
#define mp make_pair
#define pus empty()
using namespace std;
ll n,m;
int main ()
{
 freopen(fname".in","r",stdin);
 freopen(fname".out","w",stdout);
 cin>>n>>m;
 if (n==2 || m==2)
 {
 	cout<<0;
 	return 0;
 }
 if (n==1 && m>1)
 {
 	cout<<n/3;
 	return 0;
 }
 if (m==1 && n>1)
 {
 	cout<<m/3;
 	return 0;
 }
 if (n==1 && m==1)
 {
 	cout<<0;
 	return 0;
 }
 cout<<1;


 return 0;
}
