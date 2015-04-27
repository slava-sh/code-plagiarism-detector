#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

int leng;
string s;

int z[20000];

void cnt_z()
{
    int l = 0, r = 0;
    for(int i = 1; i < s.size(); i++)
    {
        z[i] = 0;
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < s.size() && s[ z[i] ] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

bool try1()
{
    int res = s.size();

    for(int i = 1; i < s.size(); i++)
        if(i + z[i] == s.size() && s.size() % i == 0)
        {
            res = i;
            break;
        }

    if(res <= leng)
    {
        cout << "1\n" << s.substr(0, res);
        return 1;
    }
    else
        return 0;
}

int z2[20000];

void cnt_z2(int start)
{
    memset(z2, 0, sizeof(z2));
    int l = start, r = start;
    for(int i = start + 1; i < s.size(); i++)
    {
        z2[i] = 0;
        if(i <= r)
            z2[i] = min(r - i + 1, z2[start + i - l]);
        while(i + z2[i] < s.size() && s[ start + z2[i] ] == s[i + z2[i]])
            z2[i]++;
        if(i + z2[i] - 1 > r)
        {
            l = i;
            r = i + z2[i] - 1;
        }
    }
}

bool used[100000];

bool check(int leng1, int leng2)
{
    memset(used, 0, sizeof(used));
    queue<int> q;
    used[0] = 1;
    q.push(0);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        if(v == s.size())
            return 1;
        if(z[v] >= leng1 && !used[v + leng1])
        {
            used[v + leng1] = 1;
            q.push(v + leng1);
        }
        if(z2[v] >= leng2 && !used[v + leng2])
        {
            used[v + leng2] = 1;
            q.push(v + leng2);
        }
    }
    return 0;
}

bool try2()
{
//    bool lett[3] = {0, 0, 0};
//    for(int i = 0; i < s.size(); i++)
//        lett[ s[i] - 'a' ] = 1;
//    if(lett[0] && lett[1] && lett[2])
//        return 0;
//    else
//    {
//        cout << "2\n";
//        for(int i = 0; i < 3; i++)
//            if(lett[i])
//                cout << (char)(i + 'a') << '\n';
//        return 1;
//    }
    for(int leng1 = 1; leng1 <= leng; leng1++)
    {
        int start = leng1;
        while(z[start] >= leng1)
            start += leng1;
            cnt_z2(start);
            for(int leng2 = 1; leng2 <= leng && start + leng2 - 1 < s.size(); leng2++)
            {
                z[0] = leng1;
                z2[start] = leng2;
                if(check(leng1, leng2))
                {
                    cout << "2\n" << s.substr(0, leng1) << '\n' << s.substr(start, leng2);
                    return 1;
                }
            }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> leng >> s;

    cnt_z();
    if(try1())
        return 0;
    else if(try2())
        return 0;
    else
        cout << "3\na\nb\nc\n";

    return 0;
}
