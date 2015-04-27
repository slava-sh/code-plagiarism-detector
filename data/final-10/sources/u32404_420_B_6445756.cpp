#include <iostream>
using namespace std;

const int maxN = 100100;

int n, m, ind, bal, cnt, minBal;
char ch;
pair <int, int> mas[maxN];
bool bad[maxN], used[maxN];
int cntPlus[maxN], last[maxN];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> ch >> ind;
        mas[i] = make_pair((ch == '+' ? 1 : -1), ind);
        if (!used[mas[i].second] && mas[i].first == -1)
        {
            minBal++;
        }
        used[mas[i].second] = true;
    }

    bal = minBal;
    
    cntPlus[0] = bal;
    for (int i = 1; i <= m; i++)
    {
        cntPlus[i] = cntPlus[i - 1] + (mas[i].first == 1);
    }
    for (int i = 1; i <= n; i++)
    {
        last[i] = -1;
    }

    for (int i = 1; i <= m; i++)
    {
        bal += mas[i].first;
        if (mas[i].first == -1)
        {
            if (bal != 0)
                bad[mas[i].second] = true;
            last[mas[i].second] = i;
        }       
        if (mas[i].first == 1)
        {
            if (cntPlus[i - 1] - (last[mas[i].second] == -1 ? 0 : cntPlus[last[mas[i].second]]) > 0)
            {
                bad[mas[i].second] = true;
            }
            last[mas[i].second] = m;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[i] != -1 && cntPlus[m] - cntPlus[last[i]] > 0)
        {
            bad[i] = true;
        }
        if (!bad[i])
            cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (!bad[i])
            cout << i << " ";
    }

    return 0;
}