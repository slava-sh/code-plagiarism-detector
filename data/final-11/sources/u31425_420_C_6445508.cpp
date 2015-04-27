#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 300200
using namespace std ;

int x, y;
int n, p;
int cnt[MAXN];
int f[MAXN];
int sum[MAXN];
vector <int> l[MAXN], r[MAXN];

int main(){
    cin >> n >> p ;
    for (int i = 0; i < n; ++i){
        scanf("%d%d", &x, &y);
        cnt[x]++;
        cnt[y]++;
        l[x].push_back(y);
        r[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        f[cnt[i]]++;
    }
    for (int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + f[i];
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
