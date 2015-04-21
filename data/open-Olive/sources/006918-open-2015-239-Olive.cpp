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
int lessr[15000];
int Min = 0, L = -2, R = -2;
int counter;

int check(int a1, int a2) {
    int ans = counter;
    For(i, a1 + 1, a2) {
        if (arr[a1] < arr[i]) {
            ++counter;
        }
        else {
            --counter;
        }
    }
    For(i, a1 + 1, a2) {
        if (arr[i] > arr[a2]) {
            --counter;
        }
        else {
            ++counter;
        }
    }
    counter += arr[a1] < arr[a2];
    swap(ans, counter);
    return ans;
}

int main() {
    cin >> n;
    For(i, 0, n) {
        int a;
        cin >> a;
        arr.pb(a);
    }
    For(i, 0, n) {
        For(j, i + 1, n) {
            lessr[i] += arr[i] > arr[j];
        }
        counter += lessr[i];
    }
    Min = check(0, 0);
    For(a1, 0, n) {
        For(a2, a1 + 1, n) {
            if (arr[a1] > arr[a2]) {
                int ans = counter;
                For(i, a1 + 1, a2) {
                    if (arr[a1] > arr[i]) {
                        --counter;
                    }
                    else {
                        ++counter;
                    }
                }
                For(i, a1 + 1, a2) {
                    if (arr[i] > arr[a2]) {
                        --counter;
                    }
                    else {
                        ++counter;
                    }
                }
                counter += arr[a1] < arr[a2];
                swap(ans, counter);
                //cout << a1 + 1 << ' ' << a2 + 1 << ' ' << ans << ' ' << endl;
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

