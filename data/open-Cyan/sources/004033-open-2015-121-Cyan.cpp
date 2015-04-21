#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool is_good = true;

double e = 0.000001;

struct elem
{
    vector<pair<double, double> > points;
    int number;
    elem()
    {
        number = -1;
    }
};

bool mf(elem i, elem j)
{
    if (i.points[0].second - e <= j.points[0].second && i.points[i.points.size() - 1].second - e <= j.points[j.points.size() - 1].second)
    {
        return true;
    }
    else if (i.points[0].second + e >= j.points[0].second && i.points[i.points.size() - 1].second + e >= j.points[j.points.size() - 1].second)
    {
        return false;
    }
    else if (is_good)
    {
        //cout << i.points[0].second << " " << j.points[0].second << " " << i.points[i.points.size() - 1].second << " " << j.points[j.points.size() - 1].second << endl;
        is_good = false;
        cout << "No" << endl;
        cout << i.number << " " << j.number << endl;
    }
    return false;
}

int main()
{
    int A, B;
    cin >> A >> B;
    int N;
    cin >> N;
    vector<elem> v(N);
    for (int i = 0; i < N; i++) v[i].number = i + 1;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j <= l; j++)
        {
            int a, b;
            cin >> a >> b;
            v[i].points.push_back(make_pair(a, b));
        }
    }
    sort(v.begin(), v.end(), mf);
    if (!is_good) return 0;
    vector<int> tmp(N);
    for (int i = 0; i < N; i++) tmp[i] = 1;
    while (true)
    {
        double now_x = B;
        int now_ind = -1;
        for (int i = 0; i < N; i++)
        {
            if (now_x > v[i].points[tmp[i]].first)
            {
                now_x = v[i].points[tmp[i]].first;
                now_ind = i;
            }
        }
        if (now_x == B)
        {
            cout << "Yes" << endl;
            return 0;
        }
        vector<double> ans(N);
        ans[now_ind] = v[now_ind].points[tmp[now_ind]].second;
        //cout << "D" << endl;
        for (int i = 0; i < N; i++)
        {
            if (i != now_ind)
            {
                double x1 = v[i].points[tmp[i]].first;
                double x2 = v[i].points[tmp[i] - 1].first;
                double y1 = v[i].points[tmp[i]].second;
                double y2 = v[i].points[tmp[i] - 1].second;
                double y = (y2 * now_x - y1 * now_x + y1 * x2 - y2 * x1) / (x2 - x1);
                ans[i] = y;
            }
        }
        //cout << "D" << endl;
        for (int i = 1; i < N; i++)
        {
            if (ans[i] + e < ans[i - 1])
            {
                //cout << ans[i] << " " << ans[i - 1] << endl;
                cout << "No" << endl;
                cout << v[i].number << " " << v[i - 1].number << endl;
                return 0;
            }
        }
        //cout << now_ind << endl;
        tmp[now_ind]++;
    }
}
