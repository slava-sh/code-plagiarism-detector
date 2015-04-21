#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <cmath>

using namespace std;

vector<pair<long double, long double> > c[100010];
vector<int> por;
const long double eps = 1E-5;
long double A;

bool my_less(int i, int j)
{
    long double x = A;
    long double yy1, yy2;
    yy1 = c[i][0].second;
    yy2 = c[j][0].second;
    if (yy1 > yy2 + eps) return false;
    int pos1 = 1, pos2 = 1;
    while (pos1 < c[i].size() && pos2 < c[j].size())
    {
        long double x1, y1, x2, y2;
        x1 = c[i][pos1].first;
        y1 = c[i][pos1].second;
        x2 = c[j][pos2].first;
        y2 = c[j][pos2].second;
        long double x3, y3, x4, y4;
        x3 = c[i][pos1 - 1].first;
        y3 = c[i][pos1 - 1].second;
        x4 = c[j][pos2 - 1].first;
        y4 = c[j][pos2 - 1].second;

        if (abs(x1 - x2) < eps)
        {
            x = x1;
            pos1 += 1;
            pos2 += 1;
        }
        else
        {
            if (x1 < x2)
            {
                x = x1;
                pos1 += 1;
            }
            else
            {
                x = x2;
                pos2 += 1;
            }
        }

        yy1 = (x - x1) * (y1 - y3) / (x1 - x3) + y1;
        yy2 = (x - x2) * (y2 - y4) / (x2 - x4) + y2;
            //cout << x << ' ' << yy1 << ' ' << yy2 << '\n';

        if (yy1 > yy2 + eps)
        {
            return false;
        }
    }
    return true;
}

vector<int> lll;
vector<int> rrr;

void qsort(int l, int r)
{
    if (r - l > 1)
    {
        lll.clear();
        rrr.clear();
        int x = rand() % (r - l) + l;
        int xx = por[x];
        for (int i = l; i < r; ++i)
        {
            if (x == i) continue;
            if (my_less(por[i], por[x]))
            {
                lll.push_back(por[i]);
            }
            else
            {
                rrr.push_back(por[i]);
            }
        }
        int pos = l;
        for (int i = 0; i < lll.size(); ++i)
        {
            por[pos] = lll[i];
            pos += 1;
        }

        int aaa = pos;

        por[pos] = xx;
        pos += 1;

        for (int i = 0; i < rrr.size(); ++i)
        {
            por[pos] = rrr[i];
            pos += 1;
        }
        qsort(l, aaa);
        qsort(aaa + 1, r);
    }
}

int main()
{
    long double B;
    scanf("%llf %llf", &A, &B);
    //cin >> A >> B;
    int n;
    scanf("%d", &n);
    //cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int len;
        scanf("%d", &len);
        //cin >> len;
        len += 1;
        for (int j = 0; j < len; ++j)
        {
            long double x, y;
            scanf("%llf %llf", &x, &y);
            //cin >> x >> y;
            c[i].push_back(make_pair(x, y));
        }
        por.push_back(i);
    }
    //sort(por.begin(), por.end(), my_less);

    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (my_less(por[j], por[j + 1]) == false)
            {
                swap(por[j], por[j + 1]);
            }
        }
    }*/
    qsort(0, n);

    for (int pos = 1; pos < n; ++pos)
    {
        int i = por[pos];
        int j = por[pos - 1];
        long double x = A;
        long double yy1, yy2;
        yy1 = c[i][0].second;
        yy2 = c[j][0].second;
        if (yy1 < yy2 - eps)
        {
            cout << "No\n";
            cout<< i + 1 << ' ' << j + 1;
            return 0;
        }
        int pos1 = 1, pos2 = 1;
        while (pos1 < c[i].size() && pos2 < c[j].size())
        {
            long double x1, y1, x2, y2;
            x1 = c[i][pos1].first;
            y1 = c[i][pos1].second;
            x2 = c[j][pos2].first;
            y2 = c[j][pos2].second;
            long double x3, y3, x4, y4;
            x3 = c[i][pos1 - 1].first;
            y3 = c[i][pos1 - 1].second;
            x4 = c[j][pos2 - 1].first;
            y4 = c[j][pos2 - 1].second;

            if (abs(x1 - x2) < eps)
            {
                x = x1;
                pos1 += 1;
                pos2 += 1;
            }
            else
            {
                if (x1 < x2)
                {
                    x = x1;
                    pos1 += 1;
                }
                else
                {
                    x = x2;
                    pos2 += 1;
                }
            }

            yy1 = (x - x1) * (y1 - y3) / (x1 - x3) + y1;
            yy2 = (x - x2) * (y2 - y4) / (x2 - x4) + y2;

            //cout << x << ' ' << yy1 << ' ' << yy2 << '\n';

            if (yy1 < yy2 - eps)
            {
                cout << "No\n";
                cout<< i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }

    cout << "Yes";
    return 0;
}

