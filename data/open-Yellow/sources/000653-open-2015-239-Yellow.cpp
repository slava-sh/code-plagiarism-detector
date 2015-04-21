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
int arr[200000];
int counter;

int street(int a, int b, int c) {
    int sum = 0;
    int arr1[4];
    arr1[0] = 1e9 + 1;
    arr1[1] = a;
    arr1[2] = b;
    arr1[3] = c;
    For(i, 1, 4) {
        if (arr1[i - 1] != arr1[i]) {
            ++sum;
        }
    }
    return sum;
}

int main() {
    cin >> n;
    arr[0] = arr[n + 1] = 1e9 + 1;
    For(i, 1, n + 1) {
        cin >> arr[i];
        if (arr[i - 1] != arr[i]) {
            ++counter;
        }
    }
    cin >> k;
    For(i, 0, k) {
        int j, s;
        cin >> j >> s;
        counter += street(arr[j - 1], s, arr[j + 1]) - street(arr[j - 1], arr[j], arr[j + 1]);
        arr[j] = s;
        cout << counter << endl;
    }
}

