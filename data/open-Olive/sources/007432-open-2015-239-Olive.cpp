#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

using namespace std;

int n;
vector <int> arr;
int Min = 0, L = -2, R = -2;
int arr1[5001][5001];
int rra[5001][5001];

int main() {
    cin >> n;
    For(i, 0, n) {
        int a;
        cin >> a;
        arr.pb(a);
    }
    For(i, 0, n) {
        For(q, i + 1, n) {
            if (arr[i] < arr[q]) {
                arr1[i][q] = arr1[i][q - 1] + 1;
            }
            else{
                arr1[i][q] = arr1[i][q - 1] - 1;
            }
        }
    }
    For(i, 0, n) {
        for(int q = i - 1; q > -1; --q) {
            if (arr[i] > arr[q]) {
                rra[i][q] = rra[i][q + 1] + 1;
            }
            else{
                rra[i][q] = rra[i][q + 1] - 1;
            }
        }
    }
    For(a1, 0, n) {
        For(a2, a1 + 1, n) {
            if (arr[a1] > arr[a2]) {
                int ans = 0;
                ans += arr1[a1][a2 - 1];
                //cout << a1 + 1 << ' ' << a2 + 1 << ' ' << ans << endl;
                ans += rra[a2][a1];
                //cout << a1 + 1 << ' ' << a2 + 1 << ' ' << ans << endl;
                if (Min > ans) {
                    Min = ans;
                    L = a1;
                    R = a2;
                }
            }
        }
    }
    //cout << Min << endl;
    cout << L + 1 << ' ' << R + 1 << endl;
}

