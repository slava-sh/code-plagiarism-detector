#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define mp make_pair

bool eq(double a, double b)
{
    return abs(a-b)<=0.0000001;
}

struct point
{
    double x, y;
    int type;
    int nz;
};

double a0, b0;


struct otr
{
    ll x1, y1, x2, y2;
    int t;
    double a, b, c;
    void dol()
    {
        a = y2 - y1;
        b = x1 - x2;
        c = -a*x1 - b*y1;
    }
    bool intrsct(otr o)
    {
        point p;
        if (x1 == a0 && o.x1 == a0) return 0;
        if (x2 == b0 && o.x2 == b0) return 0;

        if (eq(a*o.b-b*o.a,0)) return 0;
    //    cout << "!";
        p.x = - (c * o.b - o.c*b) / (a*o.b-b*o.a);
        p.y = (c * o.a - o.c*a) / (a*o.b-b*o.a);
        if (eq(a * o.x1 + b*o.y1+ c, 0)) return 0;
        if (eq(a * o.x2 + b*o.y2+ c, 0)) return 0;

    //    cout << "!";
        if (eq(o.a * x1 + o.b*y1+ o.c, 0)) { return 0;}
        if (eq(o.a * x2 + o.b*y2+ o.c, 0)) { return 0;}

   //     cout << "!";
    //    cout << p.x << " " << p.y << " ";
        if (eq(abs(x1-x2), abs(p.x-x1) + abs(p.x-x2)))
        if (eq(abs(y1-y2), abs(p.y-y1) + abs(p.y-y2)))
        if (eq(abs(o.x1-o.x2), abs(p.x-o.x1) + abs(p.x-o.x2)))
        if (eq(abs(o.y1-o.y2), abs(p.y-o.y1) + abs(p.y-o.y2))) return 1;
        return 0;
    }
};


bool cmp(otr a, otr b)
{
    return a.x1 < b.x1;
}

double yord(otr x, double k)
{
    return (x.c+x.a*k)/(-x.b);
}


int main()
{


    cin >> a0 >> b0;
    int n;
    cin >> n;
    vector <otr> pt;
    for (int i=0; i<n; i++)
    {
        int li;
        cin >> li;
        double lx=0.5, ly=0.5;
        for (int j=0; j<=li; j++)
        {
            double x, y;
            cin >> x >> y;

            if (j)
            {
                pt.push_back({lx, ly, x, y, i+1, 0, 0, 0});
                pt[pt.size()-1].dol();
            }
            lx = x;
            ly = y;
        }
    }
    sort(pt.begin(), pt.end(), cmp);
    otr lotr[n+1];
    int f = 0;
    vector<pair<double, int> > last[2];
    for (int i=0; i<pt.size(); i++)
    {
        otr t = pt[i];
        lotr[t.t-1] = t;

        if (pt[i].x1!=a0)
        {
            last[i%2].clear();
            for (int j=0; j<n; j++)
                last[i%2].push_back(make_pair(yord(lotr[j], pt[i].x1), j));
            sort(last[i%2].begin(), last[i%2].end());
            if (f) for (int j=0; j<n; j++)
                if (last[i%2][j].second != last[!(i%2)][j].second && last[i%2][j].first != last[!(i%2)][j].first)
            {
                cout << "No\n" <<last[i%2][j].second +1<< " " << last[!(i%2)][j].second+1;
                return 0;
            }
            f = 1;
        }
    }
    cout << "Yes";
}
