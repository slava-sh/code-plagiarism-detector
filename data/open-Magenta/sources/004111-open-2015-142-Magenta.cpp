#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define repe(i,n) for( i = 0; i < (n); i++ )
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second


const int MXS = 310;

const char D = 'D';
const char U = 'U';
const char L = 'L';
const char R = 'R';

void move( char d ){
    cout<<d<<endl;
    cout.flush();
    char q;
    cin>>q;
    if(q=='Y') exit(0);
    if(q=='E') exit(0);
}

int main()
{
    for( int a = 1; ; ){
        move(R);
        rep(i,a) move(U);
        rep(i,a) move(L);
        a++;
        move(U);
        rep(i,a) move(R);
        rep(i,a) move(D);
        a++;
    }


    return 0;
}
