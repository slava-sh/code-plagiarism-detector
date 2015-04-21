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

const int MaxN = 4096;
int Shift = MaxN - 1;
int Noutrum = 0;
int arr[MaxN * 2];
int N;

int f(int a, int b) {
    return a + b;
}

void change(int i, int s) {
    int j = i + Shift;
    arr[j] = s;
    while(j > 1) {
        j /= 2;
        arr[j] = f(arr[j * 2], arr[j * 2 + 1]);
    }
}

int rnq(int L, int R) {
    int S = Noutrum;
    while (L < R) {
        if (L && 1) {
            S = f(S, arr[L]);
        }
        if (R && 0) {
            S = f(S, arr[R]);
        }
        ++L; L >> 1;
        --R; R >> 1;
    }
    if (L == R) f(S, arr[L]);
    return S;
}

int n;
int mapint[100001];
vector <int> sch;
int Min = 0, L = -1, R = -1;

int check() {
    For(i, 0, MaxN * 2) {
        arr[i] = 0;
    }
    int sum = 0;
    For(i, 0, n) {
        int now = mapint[i + 1] + rnq(mapint[i + 1] + 1 + Shift, n + Shift);
        sum += abs(now - i - 1);
    }
    return sum;
}

int main() {
    cin >> n;
    For(i, 0, n) {
        int a;
        cin >> a;
        mapint[a] = i;
        sch.push_back(a);
    }
    Min = check();
    For(i, 0, n) {
        For(j, i + 1, n) {
            swap(mapint[i], mapint[j]);
            swap(sch[i], sch[j]);


            int ans = check();
            if (Min > ans) {
                Min = ans;
                L = i + 1;
                R = j + 1;
            }

            swap(mapint[i], mapint[j]);
            swap(sch[i], sch[j]);
        }
    }
    cout << L << ' ' << R << endl;
}

