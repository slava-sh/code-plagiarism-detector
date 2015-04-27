#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <cstdlib>
#include <map>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int , int>
using namespace std;
const int N = int(3e5);
int n,a[N],m,k,t[N],r[N],b[N];
int pos,cnt,Min;
int T;
bool u[N];
int main () {
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<m;i++){
            scanf("%d%d",&t[i],&r[i]);
            if(t[i] > 0) b[t[i]]++;
        }
        pos = 0;
        cnt = 0;
        Min = int(1e9);
        for(int i=1;i<m;i++){
            if(r[i] > 0){
                if(!pos) {
                    for(int j=1;j<=k;j++){
                        if(b[j] == 0){
                            if(Min > a[j]){
                                Min = a[j];
                                pos = j;
                            }
                            if(a[j] <= cnt){
                                u[j] = 1;   
                            }
                        }   
                    }
                    u[pos] = 1;
                    cnt -= Min;
                }
            }
            if(t[i] == 0){
                cnt++;
            }
            else{
                a[t[i]]--;
                if(a[t[i]] == 0) pos = t[i];
            }
            b[t[i]]--;
        }
        for(int i=1;i<=k;i++){
            if(a[i] <= cnt){
                u[i] = 1;
            }
            if(u[i]){
                printf("Y");
            }
            else {
                printf("N");
            }
            u[i] = 0;
        }
        puts("");
        for(int i=1;i<m;i++){
            b[t[i]] = 0;
        }
    }
return 0;
}
