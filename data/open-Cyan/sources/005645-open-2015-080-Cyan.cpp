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

            if (lx!=0.5)
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
    for (int i=0; i<pt.size(); i++)
    {
        otr t = pt[i];
        lotr[t.t] = t;
        for (int j=1; j<=n; j++)
        {
     //       cout << t.t << ": (" << t.x1 << ", " << t.y1 << ")-(" << t.x2 << ", " << t.y2 << "); "  << j << ": (" << lotr[j].x1 << ", " << lotr[j].y1 << ")-(" << lotr[j].x2 << ", " << lotr[j].y2 << ")\n";
            if (lotr[j].t<=n&&lotr[j].t>0&&j!=t.t&&t.intrsct(lotr[j]))
            {
                cout << "No\n";
                cout << t.t << " " << j;
                return 0;
            }
        }
    }
    cout << "Yes";
}
