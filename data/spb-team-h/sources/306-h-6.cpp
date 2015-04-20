#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;
string mas[1002][3];
bool  fl;
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
        fl = 1;
        for (int j = 0 ; j < n;j++)
        {
            if(i != j)
            {



//cout << "i = " << i << " j = " << j << "\n";
            if ((mas[i][0] == mas[j][0]) && (fl))
            {
                a[i] = make_pair(mas[i][2],mas[i][0] + " " + mas[i][1]);
                cnt++;
                fl = 0;
            }
            if ((mas[i][0] == mas[j][1]) && fl)
            {
                a[i] = make_pair(mas[i][2], mas[i][0]+ " " + mas[i][1]);
                cnt++;
                fl = 0;
               //  cout << "ghfui " << a[i].first << " " << a[i].second << "\n";
           }
            if ((mas[i][1] == mas[j][0]) && fl)
            {
                a[i] = make_pair(mas[i][0], mas[i][1] + " " + mas[i][2]);
                cnt++;
                fl = 0;
               // cout << "ghdfjghjkdfui " << a[i].first << " " << a[i].second << "\n";

            }
            if ((mas[i][1] == mas[j][1]) && fl)
            {
                a[i] = make_pair(mas[i][0],mas[i][1] + " " + mas[i][2]);
                cnt++;
                fl = 0;
            }

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
