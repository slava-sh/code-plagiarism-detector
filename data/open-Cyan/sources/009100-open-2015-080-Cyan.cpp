#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define mp make_pair

struct Point
{
    double x, y;
};

struct Segment
{
    double x1, y1, x2, y2;
};

bool comp(Segment a, Segment b)
{
    return a.x1 < b.x1;
}

vector <double> todo;

struct Zep
{
    vector <Segment> v;
    int num;
    int l = 0;
    double t(double x)
    {
        while (v[l].x2<x) l++;
        while (v[l].x1>x) l--;
        Segment k = v[l];
        return k.y1 + (x-k.x1) * (k.y2 - k.y1) / (k.x2 - k.x1);
    }
    void in(int k)
    {
        num = k;
        int l;
        cin >> l;
        double xl, yl;
        for (int i=0; i<=l; i++)
        {
            double x, y;
            cin >> x >> y;
            if (i)
            {
                if (i<l) {todo.push_back(x-0.5);todo.push_back(x+0.5);}
                v.push_back({xl, yl, x, y});
            }
            xl = x, yl = y;
        }
    }
};



int main()
{
    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    Zep ar[n];
    for (int i=0; i<n; i++)
        ar[i].in(i+1);
    todo.push_back(a+0.5);
    todo.push_back(b-0.5);

    sort(todo.begin(), todo.end());
    vector <pair<double, int> > v[2];
    for (int i=0; i<todo.size(); i++)
    {
        v[i%2].clear();
        for (int j=0; j<n; j++)
            v[i%2].push_back(make_pair(ar[j].t(todo[i]), ar[j].num));
        sort(v[i%2].begin(), v[i%2].end());
        for (int i=0; i<n; i++)
        {
            if (v[0][i].second!=v[1][i].second && v[0][v[0][i].second].first != v[0][v[1][i].second].first && v[1][v[0][i].second].first != v[1][v[1][i].second].first)
            {
                cout << "No\n" << v[0][i].second << " " << v[1][i].second;
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
