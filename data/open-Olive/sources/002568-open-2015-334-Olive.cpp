#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int a[1010], n;
int b[1010], kol;
int c[1010];

void mergesort(int l, int r) {
    if(l == r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int i = l, j = mid + 1, x = 0;
    while(i <= mid || j <= r) {
        if(i > mid) {
            c[x] = b[j];
            j++, x++;
            kol += (mid - i + 1);
        } else if(j > r) {
            c[x] = b[i];
            i++, x++;
        } else {
            if(b[i] < b[j]) {
                c[x] = b[i];
                i++, x++;
            } else {
                c[x] = b[j];
                j++, x++;
                kol += (mid - i + 1);
            }
        }
    }
    for(i = l; i <= r; i++)
        b[i] = c[i - l];
}

int main() {
    must;
    int i, ii, jj, ans, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    memcpy(b, a, sizeof(b));
    mergesort(1, n);
    ans = kol;
    ii = jj = -1;
    for(i = 1; i <= n; i++)
    for(j = i + 1; j <= n; j++) {
        memcpy(b, a, sizeof(b));
        swap(b[i], b[j]);
        kol = 0;
        mergesort(1, n);
        if(ans > kol) {
            ans = kol;
            ii = i; jj = j;
        }
    }
    cout << ii << ' ' << jj << "\n";
    return 0;
}

