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
const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    } 
    int now = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            ++now;
        }   
    }
    ++now;

    //cout << now << endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, type;
        cin >> x >> type;
        --x;
        if (x > 0 && x < n - 1) {
            if (arr[x - 1] == arr[x] && arr[x] == arr[x + 1]) {
                if (type != arr[x]) {
                     now += 2;
                }
            } else if (arr[x - 1] == arr[x] || arr[x + 1] == arr[x]) {
                if (type != arr[x + 1] && type != arr[x - 1]) {
                    ++now;
                }
            } else if (arr[x - 1] == arr[x + 1]) {
                if (type == arr[x - 1]) {
                    now -= 2;
                }
            } else {
                if (type == arr[x - 1] || arr[x + 1] == type) {
                    --now;
                }
            }
        } else if (x > 0) {
            if (arr[x - 1] == arr[x]) {
                if (type != arr[x]) {
                    ++now;
                }
            } else {
                if (type == arr[x - 1]) {
                    --now;
                }
            }
        } else if (x < n - 1) {
            if (arr[x + 1] == arr[x]) {
                if (type != arr[x]) {
                    ++now;
                }
            } else {
                if (type == arr[x + 1]) {
                    --now;
                }
            }
        }            
        cout << now << endl;
        arr[x] = type;
    }   


    return 0;
}