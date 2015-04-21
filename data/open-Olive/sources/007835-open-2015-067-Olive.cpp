#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const int MAXN = 1e6 + 6, bd = 20, bdv = 1 << bd;

int n;
int inp[MAXN];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {        
        scanf("%d", &inp[i]);        
    }
    
    pair <int, pii > ans = mapa(0, mapa(-1, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (inp[i] < inp[j]) {
                continue;
            }   
            int num = 0;
            for (int k = i + 1; k < j; ++k) {
                if (inp[k] < inp[i] && inp[k] > inp[j]) {
                    ++num;
                }
            }
            ans = max(ans, mapa(num, mapa(i, j)));
        }
    }   
    
    if (ans.ff == 0) {
        printf("-1 -1\n");
    } else {
        //cout << ans.ss.ff + 1 << " " << ans.ss.ss + 1 << endl;
        printf("%d %d\n", ans.ss.ff + 1, ans.ss.ss + 1);
    }

    return 0;
}
