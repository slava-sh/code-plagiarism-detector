#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

const int INF = 1000 * 1000 * 1000 + 100;

int l[100000];
pair<int, int> bord[100000];
vector< pair<int, int> > ords;
set<int> appeared;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    else if(bord[a.second].second != bord[b.second].second)
        return bord[a.second].second > bord[b.second].second;
    else if(bord[a.second].first != bord[b.second].first)
        return bord[a.second].first > bord[b.second].first;
    else
        return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a,b,n;
    cin >> a >> b >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
        l[i]++;
        bord[i] = mp(INF, -INF);
        for(int j = 0; j < l[i]; j++)
        {
            int x,y;
            cin >> x >> y;
            ords.pb(mp(y, i));
            bord[i].first = min(bord[i].first, y);
            bord[i].second = min(bord[i].second, y);
        }
    }
    sort(ords.begin(), ords.end(), comp);

    int pol,cnt = 0;
    for(int i = 0; i < ords.size(); i++)
    {
        if(cnt && ords[i].second != pol)
        {
            cout << "No\n" << pol + 1 << ' ' << ords[i].second + 1 << '\n';
            return 0;
        }
        else
            pol = ords[i].second;
        cnt++;
        if(cnt == l[pol])
            cnt = 0;
    }
    cout << "Yes\n";

    return 0;
}
