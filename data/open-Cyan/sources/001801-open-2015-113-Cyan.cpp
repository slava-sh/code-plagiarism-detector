#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int a, b;
int n;
pair<int, vector<pair<int, int> > > lines[100005];
set<int> coords;
int cur[100005];

bool cmp(const pair<int, vector<pair<int, int> > > &a, const pair<int, vector<pair<int, int> > > &b)
{
    return a.second[0].second < b.second[0].second;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        lines[i].first = i+1;
        for(int j=0;j<=k;j++)
        {
            int a, b;
            cin >> a >> b;
            lines[i].second.push_back(make_pair(a, b));
            coords.insert(a);
        }
    }
    sort(lines, lines + n, cmp);
    for(set<int>::iterator i = coords.begin();i!=coords.end();i++)
    {
        int x = *i;
        double cy = -2e9, ty;

        for(int j=0;j<n;j++)
        {
            if(x == lines[j].second[cur[j] + 1].first)
            {
                cur[j]++;
                ty = lines[j].second[cur[j]].second;
            }
            else
            {
                int lx = lines[j].second[cur[j]].first;
                int rx = lines[j].second[cur[j] + 1].first;
                double ly = lines[j].second[cur[j]].second;
                double ry = lines[j].second[cur[j] + 1].second;
                ty = ((rx-x) * ly + (x-lx) * ry) / (rx-lx);
            }
            if(cy - ty > EPS)
            {
                cout << "No\n";
                cout << lines[j].first << ' ' << lines[j-1].first;
                return 0;
            }
            cy = ty;
        }
    }
    cout << "Yes";
    return 0;
}
