#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;
string mas[1002][3];
pair<string,string> a[1002];
long long n;
int main()
{
    freopen("names.in", "r", stdin);
    freopen("names.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
    }
    int cnt = 0;

    for (int i = 0; i< n; i++)
    {
        for (int j = i+1 ;j < n;j++)
        {
            if (mas[i][0] == mas[j][0])
            {
                a[cnt] = make_pair(mas[i][2],mas[i][0] + " " + mas[i][1]);
                a[cnt+1] = make_pair(mas[j][2],mas[j][0] + " " + mas[j][1]);
                cnt+=2;
            }
            if (mas[i][0] == mas[j][1])
            {
                a[cnt] = make_pair(mas[i][2],mas[i][0]+ " " + mas[i][1]);
                a[cnt+1] = make_pair(mas[j][0],mas[j][1]+ " " + mas[j][2]);
                cnt+=2;
            }
            if (mas[i][1] == mas[j][0])
            {
                a[cnt] = make_pair(mas[i][0],mas[i][1] + " " + mas[i][2]);
                a[cnt+1] = make_pair(mas[j][2],mas[j][0] +" "+ mas[j][1]);
                cnt+=2;
            }
            if (mas[i][1] == mas[j][1])
            {
                a[cnt] = make_pair(mas[i][0],mas[i][1] + " " + mas[i][2]);
                a[cnt + 1] = make_pair(mas[j][0],mas[j][1] + " " + mas[j][2]);
                cnt+=2;
            }



         }
    }
    sort(a,a+n);
    for (int i = 0; i < n ;i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }
    return 0;
}
