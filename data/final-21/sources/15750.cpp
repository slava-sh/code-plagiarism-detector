#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int n;
const int maxn = 100000;
string s;
int answer = 0;
vector<vector<long long int> > h;
vector<vector<long long int> > hr;
long long int pow_p[maxn];
const int p = 47;

bool isgood(int ind, int shift)
{
    int r = h[ind].size() / 2 + shift - 1;
    int l = shift;
    long long int h1, h2;
    if(l == 0)
    {
        h1 = h[ind][r];
    }
    else
    {
        h1 = h[ind][r] - h[ind][l - 1] * pow_p[r - l + 1];
    }
    r = h[ind].size() - shift - 1;
    l = h[ind].size() - shift - h[ind].size() / 2;
    if(l == 0)
    {
        h2 = hr[ind][r];
    }
    else
    {
        h2 = hr[ind][r] - hr[ind][l - 1] * pow_p[r - l + 1];
    }
    //cout << h1 << " " << h2 << endl;
    answer = shift;
    return (h1 == h2);
    //long long int h1 = ((h[ind][h[ind].size() - 1] - (h[ind][shift - 1]) * (int)pow(p, h[ind].size() - shift)) * (int)pow(p, shift) + h[ind][shift - 1]);
    //long long int h2 = (hr[ind][hr[ind].size() - shift] + (hr[ind][hr[ind].size() - 1] - hr[ind][hr[ind].size() - shift]) * (int)pow(p, hr[ind].size()));
    //int answer = shift;
    //return (h1 == h2);
    //answer = 10000;
    //return false;

}

int main()
{
    freopen("inventory.in", "r", stdin);
    freopen("inventory.out", "w", stdout);
    cin >> n;
    h.resize(n);
    hr.resize(n);
    pow_p[0] = 1;
    for(int i = 1; i < maxn; ++ i)
    {
        pow_p[i] = pow_p[i - 1] * p;
    }
    for(int i = 0; i < n; ++ i)
    {
        cin >> s;
        s += s;
        h[i].resize(s.size());
        h[i][0] = s[0];
        for(int j = 1; j < s.size(); ++ j)
        {
            h[i][j] = h[i][j - 1] * p + s[j];
        }
        reverse(s.begin(), s.end());
        hr[i].resize(s.size());
        hr[i][0] = s[0];
        for(int j = 1; j < s.size(); ++ j)
        {
            hr[i][j] = hr[i][j - 1] * p + s[j];
        }
    }
    //for(int i = 0; i < hr[0].size(); ++ i)
    //{
        //cout << hr[0][i] << " ";
    //}
    //cout << endl;
    int flag;
    for(int i = 0; i < n; ++ i)
    {
        flag = 0;
        for(int m = 0; m < h[i].size() / 2 + 1; ++ m)
        {
            if(isgood(i, m))
            {
                cout << answer << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << -1 << endl;
        }
    }
}
