#include <iostream>
#include <math.h>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n, k;
int arr[1000001][11];

int main() {
    cin >> n >> k;
    For(i, 0, n + 1) {
        For(q, 0, k + 1) {
            arr[i][q] = 1e6;
        }
    }
    arr[1][0] = 1;
    For(q, 1, k + 1) {
        For(i, 1, n + 1) {
            for(int j = sqrt(i); j > 0; --j) {
                if (i % j == 0) {
                    //cout << i << ' ' << j << ' ' << q << ' ' << arr[i][q] << endl;
                    arr[i][q] = min(arr[i][q], (j + 1) / 2 * arr[i / j][q - 1]);
                    //cout << i << ' ' << j << ' ' << q << ' ' << arr[i][q] << endl;
                    break;
                }
            }
            arr[i][q] = min(arr[i][q], (i + 1) / 2 * arr[1][q - 1]);
        }
    }
    cout << arr[n][k];
}
