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

const int MXN = 20100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;
const int MXD = 1000100;

//int dp [MXN][MXN];


int c [3];

char s [MXN];

int pi [MXN];

int main()
{
//    freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);

    int l;
    cin>>l;
    scanf("%s", s);
    int n = strlen(s);
    rep(i,n){
        c[s[i]-'a']++;
    }

    // answer = 1


    // short s
    if(n<=l){
        printf("1\n%s", s);
        return 0;
    }




    int q = 0;
    rep(j,3){
        if(c[j]>0) q++;
    }


    // s has a period

    forn(i,1,n){
        int q = pi[i-1];
        while(q>0 && s[q]!=s[i]) q = pi[q-1];
        pi[i] = q + (s[q]==s[i]);
       // printf("%d ", pi[i]);
    }
    if( n % (n - pi[n-1]) == 0 && n-pi[n-1] <= l){
        int t = n - pi[n-1];
        s[t] = 0;
        printf("1\n%s", s);
        return 0;
    }


    // answer = 2

    if(q==2){
        printf("2\n");
        rep(i,3){
            if(c[i]>0)
                printf("%c\n", char('a'+i));
        }
        return 0;
    }


    // answer = 3

    printf("3\n");
    rep(i,3) printf("%c\n", char('a'+i));

    return 0;
}
