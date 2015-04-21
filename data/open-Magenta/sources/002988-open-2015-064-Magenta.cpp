#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxS = 6500;
const int delta = 30;

vector<pair<int, int> > v[maxS];
int X = 1, Y = 1;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void print(string s) {
    cout << s << "\n";
    cout.flush();
    cin >> s;
    if (s == "Y") exit(0);
    if (s == "E") exit(0);
    //cerr << X << " " << Y << "\n";
}

void go(int & x, int & y, int xx, int yy) {
    while (x < xx) {
        print("R");
        x++;
    }
    while (x > xx) {
        print("L");
        x--;
    }
    while (y < yy) {
        print("U");
        y++;
    }
    while (y > yy) {
        print("D");
        y--;
    }
}

void GO(vector<pair<int, int> > & z) {
    for (size_t i = 0; i < z.size(); i++) {
        go(X, Y, z[i].first, z[i].second);
    }
}

int calc(vector<pair<int, int> > a) {
    int res = 0;
    pair<int, int> cur = make_pair(X, Y);
    for (size_t i = 0; i < a.size(); i++) {
        res += dist(cur, a[i]);
        cur = a[i];
    }
    return res;
}

void upd(vector<pair<int, int> > & to, vector<pair<int, int> > & x) {
    int vto = calc(to);
    int vx = calc(x);
    if (vx < vto) to = x;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    for (int i = 1; i < maxS; i++)
        for (int j = 1; i * j < maxS; j++)
            v[i * j].push_back(make_pair(i, j));

    for (int s = 1, d = 2; ; s += d) {
        vector<pair<int, int> > z;
        for (int i = s; i < s + d; i++) {
            for (size_t it = 0; it < v[i].size(); it++)
                z.push_back(v[i][it]);
        }
        vector<pair<int, int> > best;
        sort(z.begin(), z.end());
        best = z;
        /*bool fl = true;
        int cnt = 0;
        for (size_t i = 0; i < z.size(); i++) {
            if (i == 0 || z[i].first == z[i - 1].first) cnt++;
            else {
                if (fl) reverse(z.begin() + i - cnt, z.begin() + i);
                fl ^= true;
            }
        }
        if (cnt != 0) {
            reverse(z.end() - cnt, z.end());
        }
        upd(best, z);
        sort(z.begin(), z.end());
        fl = false;
        cnt = 0;
        for (size_t i = 0; i < z.size(); i++) {
            if (i == 0 || z[i].first == z[i - 1].first) cnt++;
            else {
                if (fl) reverse(z.begin() + i - cnt, z.begin() + i);
                fl ^= true;
            }
        }
        if (cnt != 0) {
            reverse(z.end() - cnt, z.end());
        }
        upd(best, z);
        sort(z.begin(), z.end());
        reverse(z.begin(), z.end());
        fl = true;
        cnt = 0;
        for (size_t i = 0; i < z.size(); i++) {
            if (i == 0 || z[i].first == z[i - 1].first) cnt++;
            else {
                if (fl) reverse(z.begin() + i - cnt, z.begin() + i);
                fl ^= true;
            }
        }
        if (cnt != 0) {
            reverse(z.end() - cnt, z.end());
        }
        upd(best, z);
        sort(z.begin(), z.end());
        reverse(z.begin(), z.end());
        fl = false;
        cnt = 0;
        for (size_t i = 0; i < z.size(); i++) {
            if (i == 0 || z[i].first == z[i - 1].first) cnt++;
            else {
                if (fl) reverse(z.begin() + i - cnt, z.begin() + i);
                fl ^= true;
            }
        }
        if (cnt != 0) {
            reverse(z.end() - cnt, z.end());
        }
        upd(best, z);*/
        GO(best);
        d += 3;
    }

    return 0;
}
