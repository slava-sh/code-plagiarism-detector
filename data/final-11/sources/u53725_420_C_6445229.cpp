#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std ;
const int N = 300200 ;

int x[N], y[N] ;
int n, p ;

int cnt[N] ;
int f[N] ;
int sum[N] ;
vector <int> l[N], r[N] ;

int main() {
    //freopen("input.txt", "r", stdin) ;
    scanf("%d %d", &n, &p) ;

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &x[i], &y[i]) ;
        cnt[x[i]]++ ;
        cnt[y[i]]++ ;
        l[x[i]].push_back(y[i]) ;
        r[y[i]].push_back(x[i]) ;
    }

    for (int i = 1; i <= n; ++i) {
        f[cnt[i]]++ ;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + f[i] ;
    }

    long long ans = 0 ;
    for (int i = 1; i <= n; ++i) {
        vector <int> :: iterator it1, it2 ;
        it1 = l[i].begin() ;
        it2 = r[i].begin() ;
        if(cnt[i] >= p) {
            ans += n - 1 ;
            continue ;
        }
        ans += sum[n] - sum[p - cnt[i] - 1] ;
        if (cnt[i] >= p - cnt[i])   ans-- ;
        for (it1 = l[i].begin(); it1 != l[i].end(); it1++){
            if(*it1 != i) {
                //cout << *it1 << endl ;
                if(cnt[*it1] + cnt[i] == p)
                    ans-- ;
                --cnt[*it1] ;
            }
        }

        for (it2 = r[i].begin(); it2 != r[i].end(); it2++) {
            if(*it2 != i) {
                //cout << *it2 << endl ;
                if (cnt[*it2] + cnt[i] == p )
                    ans-- ;
                --cnt[*it2] ;
            }
        }

        for (it1 = l[i].begin(); it1 != l[i].end(); it1++){
            if(*it1 != i) {
                ++cnt[*it1] ;
            }
        }

        for (it2 = r[i].begin(); it2 != r[i].end(); it2++) {
            if(*it2 != i) {
                ++cnt[*it2] ;
            }
        }

    }

    cout << (ans >> 1) << endl ;


    return 0 ;
}
