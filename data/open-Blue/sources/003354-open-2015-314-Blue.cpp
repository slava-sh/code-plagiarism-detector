/**
 * “¿Ÿ»Ã
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>


using namespace std;

int l;
string s;

bool try_1()
{
    for(int i = 1; i <= l; ++i)
    {
        if(s.length() % i != 0)
            continue;
        int j = 0;
        for(; j + i < s.length(); ++j)
        {
            if(s[j] != s[j + i])
                break;
        }
        if(j + i == s.length())
        {
            cout << 1 << endl;
            cout << s.substr(0, i) << endl;
            return true;
        }
    }
    return false;
}

bool go_2(const string& a, const string& b, bool st, int pos)
{
    bool exit_now = true;
    for(int x = 0; x * a.length() <= s.length(); ++x)
    {
        if((s.length() - x * a.length()) % b.length() == 0)
        {
            exit_now = false;
            break;
        }
    }
    if(exit_now)
        return false;
    if(pos == s.length())
    {
        if(st)
        {
            cout << 2 << endl;
            cout << a << endl;
            cout << b << endl;
        }
        return true;
    }
    if(rand() % 2)
    {
        if(pos + a.length() <= s.length())
        {
            if(s.substr(pos, a.length()) == a)
            {
                if(go_2(a, b, st, pos + a.length()))
                    return true;
            }
        }
        if(pos + b.length() <= s.length())
        {
            if(s.substr(pos, b.length()) == b)
            {
                if(go_2(a, b, st, pos + b.length()))
                    return true;
            }
        }
    }
    else
    {
        if(pos + b.length() <= s.length())
        {
            if(s.substr(pos, b.length()) == b)
            {
                if(go_2(a, b, st, pos + b.length()))
                    return true;
            }
        }
        if(pos + a.length() <= s.length())
        {
            if(s.substr(pos, a.length()) == a)
            {
                if(go_2(a, b, st, pos + a.length()))
                    return true;
            }
        }
    }

    return false;
}

bool go_1(const string& a, int b, bool st, int pos)
{
    bool exit_now = true;
    for(int x = 0; x * a.length() <= s.length(); ++x)
    {
        if((s.length() - x * a.length()) % b == 0)
        {
            exit_now = false;
            break;
        }
    }
    if(exit_now)
        return false;
    if(pos == s.length())
    {
        return true;
    }
    if(pos + a.length() <= s.length())
    {
        if(s.substr(pos, a.length()) == a)
        {
            if(go_1(a, b, st, pos + a.length()))
                return true;
        }
    }
    if(pos + b <= s.length())
    {
        return go_2(a, s.substr(pos, b), st, pos + b);
    }
    return false;
}

bool go_0(int a, int b, bool st)
{
    if(0 + a < s.length())
    {
        if(go_1(s.substr(0, a), b, st, a))
            return true;
    }
    if(0 + b < s.length())
    {
        if(go_1(s.substr(0, b), a, st, b))
            return true;
    }
    return false;
}

bool try_2()
{
    for(int i = 1; i <= l; ++i)
    {
        for(int j = i; j <= l; ++j)
        {
            if(go_0(i, j, false))
            {
                go_0(i, j, true);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> l;
    cin >> s;

    bool was[3];
    was[0] = was[1] = was[2] = false;
    for(auto c : s)
        was[c - 'a'] = true;

    int c = 0;
    c += was[0];
    c += was[1];
    c += was[2];

    if(c == 1)
    {
        cout << 1 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    if(try_1())
        return 0;

    if(c == 2)
    {
        cout << 2 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    if(try_2())
        return 0;

    if(c == 3)
    {
        cout << 3 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    return 0;
}
