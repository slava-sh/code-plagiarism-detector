#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MP make_pair
#define pii pair<int,int>
const int N = 333333;
int a[N], b[N], c[N];
map<pair<int,int>, int> mp;
int main() {
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        mp[MP(a[i], b[i])] ++;
        c[a[i]-1]++;
        c[b[i]-1]++;
    }
    long long cc = 0, cc2 = 0; 
    for(map<pii, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        int a = it->first.first;
        int b = it->first.second;
        if(c[a - 1] + c[b - 1] >= p && \
                c[a - 1] + c[b - 1] - it->second < p)
            cc++;
    }
    sort(c, c + n);
    for(int i = 1; i < n; i++) {
        int l = 0, r = i - 1;
        int best = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(c[mid] + c[i] >= p) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(~best) {
            cc2 += i - best;
        }
    }
    cout << cc2 - cc << endl;
    return 0;
}
