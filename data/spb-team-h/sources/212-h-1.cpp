#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

struct people
{
    string s1, s2, s3;
    bool operator <(people const &a)const
    {
        return s1 < a.s1;
    }
};

people mas[1010];
string s1[1010], s2[1010], s3[1010];

int main()
{
    freopen("names.in", "r", stdin);
    freopen("names.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s1[i] >> s2[i] >> s3[i];
    }
    for(int i = 0; i < n; i++)
    {
        bool d = 0;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                if(s1[i] == s1[j])
                {
                    d = 1;
                    break;
                }
                else if(s1[i] == s2[j])
                {
                    d = 1;
                    break;
                }
                else if(s2[i] == s1[j])
                {
                    break;
                }
            }
        }
        if(d)
        {
            mas[i].s1 = s3[i];
            mas[i].s2 = s1[i];
            mas[i].s3 = s2[i];
        }
        else
        {
            mas[i].s1 = s1[i];
            mas[i].s2 = s2[i];
            mas[i].s3 = s3[i];
        }
    }
    sort(mas, mas + n);
    for(int i = 0; i < n; i++)
    {
        cout << mas[i].s1 << " " << mas[i].s2 << " " << mas[i].s3 << "\n";
    }
    return 0;
}
