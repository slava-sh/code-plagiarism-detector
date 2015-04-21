#include <iostream>
#include <vector>

using namespace std;

const int inf = 2 * 1e9;

int main()
{
    int a, b, n, i, k, j, x, y, k1, k2;
    bool up, down;
    double y1, y2;
    cin >> a >> b >> n;
    vector< vector< pair<int, int> > > lom(n);
    vector< vector< double > > koef(n);
    for (i = 0; i < n; i++)
    {
        cin >> k;
        for (j =0; j < k + 1; j++)
        {
            cin >> x >> y;
            lom[i].emplace_back(x, y);
        }
        lom[i].emplace_back(inf, 0);
    }
    for (i = 0; i < n; i++)
        for (j = 1; j < lom[i].size() - 1; j++)
        {
            koef[i].push_back((lom[i][j].second - lom[i][j - 1].second)/(double)(lom[i][j].first - lom[i][j - 1].first));
        }
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
        {
            up = false;
            down = false;
            if (lom[i][0].second > lom[j][0].second) up = true;
            if (lom[i][0].second < lom[j][0].second) down = true;
            k1 = 1; k2 = 1;
            while (k1 < lom[i].size() - 1 || k2 < lom[j].size() - 1)
            {
                if (lom[i][k1].first < lom[i][k2].first)
                    {
                        x = lom[i][k1].first;
                        y1 = lom[i][k1].second;
                        k1++;
                        y2 = lom[j][k2 - 1].second + (x - lom[j][k2 -  1].first)*koef[j][k2-1];
                    } else {
                        x = lom[j][k2].first;
                        y2 = lom[j][k2].second;
                        k2++;
                        y1 = lom[i][k1 - 1].second + (x - lom[i][k1 -  1].first)*koef[i][k1-1];
                    }
                if (y1 > y2) up = true;
                if (y1 < y2) down = true;
                if (up && down) {cout << "No\n" << i + 1 << ' ' << j + 1 << endl; return 0;}
            }
        }
    cout << "Yes" << endl;
    return 0;
}
