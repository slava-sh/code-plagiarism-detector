#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int inf = 2 * 1e9;

int main()
{
    //freopen("input.txt", "r", stdin);
    long long a, b, n, i, k, j, x, y, k1, k2;
    bool up, down;
    long long y1, y2;
    cin >> a >> b >> n;
    vector< vector< pair<long long, long long> > > lom(n);
    vector< vector< long long > > koef1(n), koef2(n);
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
    //cout << endl;
    for (i = 0; i < n; i++)
        for (j = 1; j < lom[i].size() - 1; j++)
        {
            koef1[i].push_back(lom[i][j].second - lom[i][j - 1].second);
            koef2[i].push_back(lom[i][j].first - lom[i][j - 1].first);
        }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < koef1[i].size(); j++)
//            cout << koef1[i][j] << ' ' << koef2[i][j] <<  ' '<< koef1[i][j]/(double) koef2[i][j] << endl;
//    }
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
        {
            up = false;
            down = false;
            if (lom[i][0].second > lom[j][0].second) up = true;
            if (lom[i][0].second < lom[j][0].second) down = true;
            //cout << "| " << lom[i][0].second << ' ' << lom[j][0].second << " |\n";
            if (lom[i][lom[i].size() - 2].second > lom[j][lom[j].size() - 2].second) up = true;
            if (lom[i][lom[i].size() - 2].second < lom[j][lom[j].size() - 2].second) down = true;
            //cout << "| " << lom[i][lom[i].size() - 2].second << ' ' << lom[j][lom[j].size() - 2].second << " |\n";
            k1 = 1; k2 = 1;
            if (up && down) {cout << "No\n" << i + 1 << ' ' << j + 1 << endl; return 0;}
            while (k1 < lom[i].size() - 2 || k2 < lom[j].size() - 2)
            {
                //cout << "| " << lom[i][k1].first << ' ' << lom[i][k2].first << " |\n";
                if (lom[i][k1].first < lom[j][k2].first)
                    {
                        x = lom[i][k1].first;
                        y1 = lom[i][k1].second*koef2[j][k2-1];
                        k1++;
                        y2 = lom[j][k2 - 1].second * koef2[j][k2-1] + (x - lom[j][k2 -  1].first)*koef1[j][k2-1];
                        //cout <<  ' ' << y1/(double)koef2[j][k2-1] << ' ' << y2/(double)koef2[j][k2-1] << endl;
                    } else {
                        x = lom[j][k2].first;
                        y2 = lom[j][k2].second * koef2[i][k1-1];
                        k2++;
                        y1 = lom[i][k1 - 1].second * koef2[i][k1-1] + (x - lom[i][k1 -  1].first)*koef1[i][k1-1];
                        //cout <<  ' ' << y1/(double)koef2[i][k1-1] << ' ' << y2/(double)koef2[i][k1-1] << endl;
                    }
                //cout << y1 << ' ' << y2 << endl;
                if (y1 > y2) up = true;
                if (y1 < y2) down = true;
                if (up && down) {cout << "No\n" << i + 1 << ' ' << j + 1 << endl; return 0;}
            }
        }
    cout << "Yes" << endl;
    return 0;
}
