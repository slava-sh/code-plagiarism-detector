#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;
int a[1001],n;
vector < pair<int,int> > mas;

int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin >> n;
    for (int i =1; i<n;i++)
    {
        cin >> a[i];
    }
    int x = 0;
    int cnt = 0;
    for (int i = 1; i < n+1; i++)
    {
        if  (a[i] > x)
        {
           cnt++;
           x++;
           pair <int,int> b = make_pair(x,i);
           mas.push_back(b);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < cnt ;i++ )
    {
        cout << mas[i].first << " " << mas[i].second << "\n";
    }
    return 0;
}
