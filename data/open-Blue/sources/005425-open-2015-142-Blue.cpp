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
const int T = 5;

//int dp [MXN][MXN];

ull tpw [MXN];


int c [3];

char s [MXN];

int pi [MXN];

ull hsh [MXN];

char a2 [MXN];
char b2 [MXN];

void set2( char *a, int l, int r ){
    forn(i,l,r+1) a[i-l] = s[i];
}

int main()
{
//    freopen("input.txt", "r", stdin);    freopen("output.txt", "w", stdout);

    int l;
    cin>>l;
    scanf("%s", s);
    int n = strlen(s);    if(n<=l){
        printf("1\n%s", s);
        return 0;
    }

    rep(i,n){
        c[s[i]-'a']++;
    }

    // answer = 1
    if(n<=l){
        printf("1\n%s", s);
        return 0;
    }



    // short s
    if(n<=l){
        printf("1\n%s", s);
        return 0;
    }




    int q = 0;
    rep(j,3){
        if(c[j]>0) q++;
    }    if(n<=l){
        printf("1\n%s", s);
        return 0;
    }



    // s has a period

    forn(i,1,n){
        int q = pi[i-1];
        while(q>0 && s[q]!=s[i]) q = pi[q-1];
        pi[i] = q + (s[q]==s[i]);
       // printf("%d ", pi[i]);
    }
    if( n % (n - pi[n-1]) == 0 && n-pi[n-1] <= l){
        int ttt = n - pi[n-1];
        s[ttt] = 0;
        printf("1\n%s", s);
        return 0;
    }


    // answer = 2

    tpw[0] = 1;
    forn(i,1,MXN) tpw[i] = T*tpw[i-1];
    ull cur = 0;
    rep(i,n){
        hsh[i] = hsh[i-1] + (s[i]-'a') * tpw[i];

    }

    bool ok2 = false;
    rep(i,l){
        cur += (s[i]-'a') * tpw[i];
        int j = i+1;
        for(; j < n; j += i+1){
            if( hsh[j+i] - hsh[j-1] != cur*tpw[j-1]) break;
        }
        ull cur2 = 0;
        forn(k,j,n){
            if(k-j+1 > l ) break;

            cur2 += (s[k]-'a') * tpw[k-j];
            int tp = k+1;
            for(; tp < n;){
                if( hsh[tp+i] - hsh[tp-1] == cur*tpw[tp] ){
                    tp += i+1;
                }
                else if( hsh[tp+k-j] - hsh[tp-1] == cur2*tpw[tp] ){
                    tp += k-j+1;
                }
                else break;
            }
            if(tp==n){
                ok2 = true;
                set2(a2,0,i);
                set2(b2,j,k);
                break;
            }
        }
        if(ok2) break;
    }
    if(ok2){
        printf("2\n");
        printf("%s\n%s", a2, b2);
        return 0;
    }

   /* if(q==.2){
        printf("2\n");
        rep(i,3){
            if(c[i]>0)
                printf("%c\n", char('a'+i));
        }
        return 0;
    }*/





    // answer = 3

    printf("3\n");
    rep(i,3) printf("%c\n", char('a'+i));

    return 0;
}
