#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

int t[N], z[N], d[N];
char s[N];

int main()
{
    int l, n, u = 0, b;
    cin >> l;
    gets(s);
    n = strlen(s);
    l = min(l, n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++){
        z[i] = max(0, min(z[i - l], r - i));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    for (int i = 1; i <= l; i++){
        b = 0;
        while (b < n){
            if (z[b] >= i)
                b += i;
            else
                break;
        }
        if (b == n){
            cout << "1\n";
            for (int j = 0; j < i; j++)
                printf("%c", s[j]);
            return 0;
        }
    }
    for (int i = 1; i <= l; i++){
        b = 0;
        while (z[b] >= i)
            b += i;
        for (int j = 1; j <= l && b + j <= n; j++){
            u++;
            t[b] = n - b;
            for (int c = b + 1, l = b, r = b; c < n; c++){
                t[c] = max(0, min(t[c - l + b], r - c));
                while (c + t[c] < n && s[t[c] + b] == s[c + t[c]])
                    t[c]++;
                if (c + t[c] > r)
                    l = c, r = c + t[c];
            }
            d[b] = u;
            for (int c = b; c < n; c++)
                if (d[c] == u){
                    if (t[c] >= j)
                        d[c + j] = u;
                    if (z[c] >= i)
                        d[c + i] = u;
                }
            if (d[n] == u){
                cout << "2\n";
                for (int c = 0; c < i; c++)
                    printf("%c", s[c]);
                cout << endl;
                for (int c = 0; c < j; c++)
                    printf("%c", s[b + c]);
                return 0;
            }
        }
    }
    cout << "3\na\nb\nc\n";
    return 0;
}
