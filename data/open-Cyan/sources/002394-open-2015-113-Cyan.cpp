#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-12;

int a, b;
int n;
pair<int, vector<pair<int, int> > > lines[100005];
set<int> coords;
int cur[100005];
long double avg[100005];
vector<pair<int, long double> > tt;

bool cmp(const pair<int, vector<pair<int, int> > > &a, const pair<int, vector<pair<int, int> > > &b)
{
    return avg[a.first-1] < avg[b.first-1];
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
        long double av = 0;
        for(int j=0;j<=k;j++)
        {
            int a, b;
            cin >> a >> b;
            lines[i].second.push_back(make_pair(a, b));
            coords.insert(a);
            if(j > 0)
            {
                av += ((long double)lines[i].second[j-1].second + b) / 2 * (a - lines[i].second[j-1].first);
            }
        }
        avg[i] = av;
    }
    sort(lines, lines + n, cmp);
    for(set<int>::iterator i = coords.begin();i!=coords.end();i++)
    {
        int x = *i;
        long double cy = -2e9, ty;
        tt.clear();
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
                long double ly = lines[j].second[cur[j]].second;
                long double ry = lines[j].second[cur[j] + 1].second;
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
