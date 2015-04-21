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
                if (i<l) todo.push_back(x);
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
    sort(todo.begin(), todo.end());
    for (int i=0; i<todo.size(); i++)
    {
        vector <pair<double, int> > v1, v2;
        for (int j=0; j<n; j++)
            v1.push_back(make_pair(ar[j].t(todo[i]-1), ar[j].num));
        for (int j=0; j<n; j++)
            v2.push_back(make_pair(ar[j].t(todo[i]+1), ar[j].num));
        stable_sort(v1.begin(), v1.end());
        stable_sort(v2.begin(), v2.end());
        for (int i=0; i<v1.size(); i++)
        {
            if (v1[i].second!=v2[i].second && v1[v1[i].second].first != v1[v2[i].second].first && v2[v1[i].second].first != v2[v2[i].second].first)
            {
                cout << "No\n" << v1[i].second << " " << v2[i].second;
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
