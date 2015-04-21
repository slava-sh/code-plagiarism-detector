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

bool compa(Segment a, Segment b)
{
    return a.x1 < b.x1;
}

vector <double> todo;

struct Zep
{
    vector <Segment> v;
    int num;
    int lo = 0;
    double t(double x)
    {
        while (v[lo].x2<x) lo++;
        while (v[lo].x1>x) lo--;
        Segment k = v[lo];
        return k.y1 + (x-k.x1) * (k.y2 - k.y1) / (k.x2 - k.x1);
    }
    void in(int k)
    {
        num = k;
        lo = 0;
        int l;
        cin >> l;
        double xl, yl;
        for (int i=0; i<=l; i++)
        {
            double x, y;
            cin >> x >> y;
            if (i)
            {
                if (i<l) {todo.push_back(x-0.1);todo.push_back(x+0.1);}
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
    todo.push_back(a+0.1);
    todo.push_back(b-0.1);

    sort(todo.begin(), todo.end());
    vector <pair<double, int> > v[todo.size()];
    for (int i=0; i<todo.size(); i++)
    {
      //  cout << i << todo[i] << "\n";
        v[i].clear();
        for (int j=0; j<n; j++)
            v[i].push_back(make_pair(ar[j].t(todo[i]), ar[j].num));
        stable_sort(v[i%2].begin(), v[i%2].end());
      //  cout << "!" << v[i%2].size();
        if (i)
        for (int k = 0; k<i; k++)
        for (int j=0; j<n; j++)
        {
      //      cout << "!" << j;
            if (v[i][j].second!=v[k][j].second && !(v[i][j+1].first != v[k][j].first && v[i][j+1].second == v[k][j].second) && !(v[i][j-1].first != v[k][j].first && v[i][j-1].second == v[k][j].second))
            {
         //       cout << i << " " << todo[i] << " " << v[0][j].first << " " << v[1][j].first;
                cout << "No\n" << v[i][j].second << " " << v[k][j].second;
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
