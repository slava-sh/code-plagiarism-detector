#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int M = 110100;

int i, n, k, f[M];

bool check(long long s){
  long long v = 0, e = k; 
  for(int i =  1; i <= n; i++){
    if(e < s)return false;
    int t = max(f[i] - v, s);
    e -= t;
    v += t; 
  }
  return true;
}

int main(){
  freopen("fence.in", "r", stdin);
  freopen("fence.out", "w", stdout);
  scanf("%d %d", &n, &k);
  for(i = 1; i <= n; i++)scanf("%d", f + i);
  sort(f + 1, f + n + 1);
  int l = 0, r = f[1] + 1;
  while(r - l > 1){
    int mid = (l + r) / 2;
    if(check(mid))l = mid;
    else r = mid;
  }
  printf("%d\n", l);
}