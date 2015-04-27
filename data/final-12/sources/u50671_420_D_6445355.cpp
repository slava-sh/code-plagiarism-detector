#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

const int N = int (2e6) + 50;
int ls[N], rs[N], s[N], value[N];
int node, root;
void init() {
    node = root = s[0] = 0;
}
void Right_Rotate (int &t) {
    int k = ls[t];
    ls[t] = rs[k];
    rs[k] = t;
    s[k] = s[t];
    s[t] = s[ls[t]] + s[rs[t]] + 1;
    t = k;
}
void Left_Rotate (int &t) {
    int k = rs[t];
    rs[t] = ls[k];
    ls[k] = t;
    s[k] = s[t];
    s[t] = s[ls[t]] + s[rs[t]] + 1;
    t = k;
}
void Maintain (int &t, bool flag) {
    if (flag)
        if (s[rs[rs[t]]] > s[ls[t]])
            Left_Rotate (t);
        else if (s[ls[rs[t]]] > s[ls[t]])
            Right_Rotate (rs[t]), Left_Rotate (t);
        else return ;
    else if (s[ls[ls[t]]] > s[rs[t]])
        Right_Rotate (t);
    else if (s[rs[ls[t]]] > s[rs[t]])
        Left_Rotate (ls[t]), Right_Rotate (t);
    else return ;
    Maintain (ls[t], 0);
    Maintain (rs[t], 1);
    Maintain (t, 0);
    Maintain (t, 1);
}
void Insert (int &t, int val) {
    if (t) {
        ++s[t];
        if (val < value[t]) Insert (ls[t], val);
        else Insert (rs[t], val);
        Maintain (t, val >= value[t]);
    } else {
        s[t = ++node] = 1;
        value[t] = val;
        ls[t] = rs[t] = 0;
    }
}
int Delete (int &t, int val) {
    --s[t];
    if (val == value[t] || val < value[t] && !ls[t] || val > value[t] && !rs[t]) {
        int tmp = value[t];
        if (!ls[t] || !rs[t]) t = ls[t] + rs[t];
        else value[t] = Delete (ls[t], value[t] + 1);
        return tmp;
    } else if (val < value[t]) return Delete (ls[t], val);
    else return Delete (rs[t], val);
}
int Pred (int t, int val) {
    if (!t) return val;
    if (val <= value[t]) return Pred (ls[t], val);
    else {
        int tmp = Pred (rs[t], val);
        return tmp == val ? value[t] : tmp;
    }
}
int Succ (int t, int val) {
    if (!t) return val;
    if (val >= value[t]) return Succ (rs[t], val);
    else {
        int tmp = Succ (ls[t], val);
        return tmp == val ? value[t] : tmp;
    }
}
int Find (int t, int val) {
    while (t && val != value[t])
        t = val < value[t] ? Find (ls[t], val) : Find (rs[t], val);
    return t;
}
int Rank (int t, int val) {
    if (!t) return 1;
    if (val <= value[t]) return Rank (ls[t], val);
    else return s[ls[t]] + 1 + Rank (rs[t], val);
}
int Select (int t, int k) {
    if (k == s[ls[t]] + 1) return value[t];
    if (k <= s[ls[t]]) return Select (ls[t], k);
    else return Select (rs[t], k - 1 - s[ls[t]]);
}

int Pos[N], n, m, Assigned[N], Dt[N << 1];
queue<int> S;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        Dt[i + N] = i;
        Insert (root, i);
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf ("%d%d", &a, &b);
        int rt = Select (root, b);
        int p = Dt[rt + N];
        if ( (Assigned[a] && Assigned[a] != p) || (Pos[p] && Pos[p] != a) ) {
            puts ("-1");
            return 0;
        }
        Dt[N - i] = p;
        Assigned[a] = p;
        Pos[p] = a;
        Delete (root, rt);
        Insert (root, -i);
    }
    for (int i = 1; i <= n; ++i)
        if (!Assigned[i]) S.push (i);

    for (int i = 1; i <= n; ++i) {
        if (!Pos[i]) {
            Pos[i] = S.front();
            S.pop();
        }
        printf ("%d%c", Pos[i], " \n"[i == n]);
    }
    return 0;
}

