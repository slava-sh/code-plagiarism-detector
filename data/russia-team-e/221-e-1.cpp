#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstddef>

#define INF 1<<30

using namespace std;

const int N = 111111;

int n, k;
char buff[N];

map<string, map<string, bool> > m;
const string errResult = "Incorrect";

vector<string> v;
vector< vector<string> > r;

string divideNum(string s)
{
    if (s.size() == 3)
        return s;
    if (s.size() == 4)
        return s.substr(0, 2) + "-" + s.substr(2, 2);
    if (s.size() == 5)
        return s.substr(0, 3) + "-" + s.substr(3, 2);
    if (s.size() == 6)
        return s.substr(0, 2) + "-" + s.substr(2, 2) + "-" + s.substr(4, 2);
    if (s.size() == 7)
        return s.substr(0, 3) + "-" + s.substr(3, 2) + "-" + s.substr(5, 2);
}

string process(string s)
{
    for(int i = 1; i<=3; i++)
    {
        for(int j = 3; j<=5; j++)
        {
            string cityCode = s.substr(0, i);
            if (cityCode[0] == '0')
                continue;
            string operatorCode = s.substr(i, j);
            if (operatorCode[0] == '0')
                continue;;

            int vi = lower_bound(v.begin(), v.end(), cityCode) - v.begin();
            if (vi >= v.size() || v[vi] != cityCode)
                continue;
            int ri = lower_bound(r[vi].begin(), r[vi].end(), operatorCode) - r[vi].begin();
            if (ri >= r[vi].size() || r[vi][ri] != operatorCode)
                continue;
            string num = divideNum(s.substr(i+j));
            if (num[0] == '0')
                continue;
            string res = "+" + cityCode + "(" + operatorCode + ")" + num;
            return res;
        }
    }
    return errResult;
}

int main()
{
    #define TASKNAME "numbers"

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d", &n);
    gets(buff);
    v.resize(n);
    r.resize(n);

    for(int i = 0; i<n; i++)
    {
        int k;
        scanf("%s %d", buff, &k);
        v[i] = buff;
        gets(buff);
        for(int j = 0; j<k; j++)
        {
            gets(buff);
            r[i].push_back(buff);
        }
    }

    for(int i = 0; i<v.size(); i++)
    {
        for(int j = i+1; j<v.size(); j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
                swap(r[i], r[j]);
            }
        }
    }

    for(int i = 0; i<r.size(); i++)
    {
        sort(r[i].begin(), r[i].end());
    }

    scanf("%d", &k);
    gets(buff);

    for(int i = 0; i<k; i++)
    {
        gets(buff);
        string s = buff;
        string res = process(s);
        printf("%s\n", res.c_str());
    }

    return 0;
}
