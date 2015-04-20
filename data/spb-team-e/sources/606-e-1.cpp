#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    set <int> v;
    set <int> p;
    set <int> c;
    int l1, r1, l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (l1 <= x && r1 >= x)
        {
            p.insert(i);
        }
        if (l2 <= x && r2 >= x)
        {
            v.insert(i);
        }
        if (p.count(i) == v.count(i) && p.count(i) == 1)
        {
            c.insert(i);
        }
    }
    int vc = 0, pc = 0;
    for (int i = 0; i < m; i++)
    {
        if (!c.empty())
        {
            int x = *c.begin();
            c.erase(x);
            v.erase(x);
            p.erase(x);
            if (i % 2 == 0)
                pc++;
            else
                vc++;
        }
        else
        {
            if (!p.empty() && i%2==0)
            {
                p.erase(*p.begin());
                pc++;
            }
            if (!v.empty() && i%2==1)
            {
                v.erase(*v.begin());
                vc++;
            }
        }
    }
    if (vc > pc)
        cout << "Vasya";
    else if (vc < pc)
        cout << "Petya";
    else
        cout << "Draw";
    return 0;
}
