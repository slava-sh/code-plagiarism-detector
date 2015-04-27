#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int64;

struct State
{
    int h, t, moves;
    State(){}
    State(int _h, int _t, int _moves)
        : h(_h), t(_t), moves(_moves)
    {
    }
    bool operator < (const State &s) const
    {
        return moves < s.moves;
    }
    bool operator > (const State &s) const
    {
        return moves > s.moves;
    }
};


priority_queue<State, vector<State>, greater<State> > q;
priority_queue<State, vector<State>, less<State> > q2;
int tab[410][410];
int R, n, m;
pair<int, int> xH[210], xT[210];

bool hasCycle(int h, int t)
{
    if (h + t > R)
        return false;
    int &x = tab[h][t];
    if (x == 2)
        return false;
    if (x == 1)
        return true;
    x = 1;
    for (int i = 1; i <= h && i <= n; ++i)
    {
        if (hasCycle(h - i + xH[i].first, t + xH[i].second))
            return true;
    }
    for (int i = 1; i <= t && i <= m; ++i)
    {
        if (hasCycle(h + xT[i].first, t - i + xT[i].second))
            return true;
    }
    x = 2;
    return false;
}


bool addState(int h, int t, int moves)
{
    bool res = tab[h][t] != 0;
    if (!res || tab[h][t] > moves)
    {
        tab[h][t] = moves;
        q.push(State(h, t, moves));
    }
    return res;
}

void addState2(int h, int t, int moves)
{
    if (tab[h][t] == 0 || tab[h][t] < moves)
    {
        tab[h][t] = moves;
        q2.push(State(h, t, moves));
    }
}

void main()
{
    //freopen("input.txt", "r", stdin);
    int h, t;
    cin >> h >> t >> R;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> xH[i].first >> xH[i].second;
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> xT[i].first >> xT[i].second;
    memset(tab, 0, sizeof tab);
    addState(h, t, 1);
    while (!q.empty())
    {
        State st = q.top(); q.pop();
        if (st.h + st.t > R)
            continue;
        if (tab[st.h][st.t] != st.moves)
            continue;
        for (int i = 1; i <= n && i <= st.h; ++i)
        {
            int nh = st.h - i + xH[i].first,
                nt = st.t + xH[i].second;
            addState(nh, nt, st.moves + 1);
        }
        for (int i = 1; i <= m && i <= st.t; ++i)
        {
            int nh = st.h + xT[i].first,
                nt = st.t - i + xT[i].second;
            addState(nh, nt, st.moves + 1);
        }
    }
    if (tab[0][0] != 0)
    {
        cout << "Ivan\n" << tab[0][0] - 1;
        return;
    }
    else
    {
        memset(tab, 0, sizeof tab);
        if (hasCycle(h, t))
        {
            cout << "Draw";
            return;
        }
    }
    
    int ans = 0;
    memset(tab, 0, sizeof tab);
    addState2(h, t, 1);
    while (!q2.empty())
    {
        State st = q2.top(); q2.pop();
        if (st.h + st.t > R)
        {
            ans = max(ans, st.moves);
            continue;
        }
        if (tab[st.h][st.t] != st.moves)
            continue;
        for (int i = 1; i <= n && i <= st.h; ++i)
        {
            int nh = st.h - i + xH[i].first,
                nt = st.t + xH[i].second;
            addState2(nh, nt, st.moves + 1);
        }
        for (int i = 1; i <= m && i <= st.t; ++i)
        {
            int nh = st.h + xT[i].first,
                nt = st.t - i + xT[i].second;
            addState2(nh, nt, st.moves + 1);
        }
    }
    cout << "Zmey\n" << ans - 1;
}