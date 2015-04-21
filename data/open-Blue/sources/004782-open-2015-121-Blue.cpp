#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void norm_s(string & s1, string & s2)
{
    if (s1.size() < s2.size()) swap(s1, s2);
    string tmp_s2 = "";
    bool is_good = false;
    while (!is_good)
    {
        for (int i = s2.size(); i < s1.size(); i++)
        {
            tmp_s2 += s1[i];
        }
        if (s2 + tmp_s2 == s1)
        {
            s1 = tmp_s2;
            if (s1.size() < s2.size()) swap(s1, s2);
        }
        else
        {
            is_good = true;
        }
    }
}

bool can_use(string s, string s1, string s2)
{
    int now_i = 0;
    string now_s = "";
    while (now_i < s.size() && now_s.size() < max(s1.size(), s2.size()))
    {
        now_s += s[now_i];
        now_i++;
        if (now_s == s1)
        {
            now_s = "";
        }
        else if (now_s == s2)
        {
            now_s = "";
        }
        //cout << now_s << endl;
    }
    //cout << s1 << " " << s2 << " " << now_s << endl;
    if (now_s.size() == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int L;
    cin >> L;
    string s;
    cin >> s;
    if (s.size() <= L)
    {
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    }
    string s1 = "";
    for (int i = 0; i < L; i++)
    {
        s1 += s[i];
        if (s.size() % s1.size() == 0)
        {
            string tmp = s1;
            while (tmp.size() < s.size())
            {
                tmp += s1;
            }
            if (tmp == s)
            {
                cout << 1 << endl;
                cout << s1 << endl;
                return 0;
            }
        }
    }
    if (s.size() <= L * 2)
    {
        cout << 2 << endl;
        for (int i = 0; i < L; i++)
        {
            cout << s[i];
        }
        cout << endl;
        for (int i = L; i < s.size(); i++)
        {
            cout << s[i];
        }
        cout << endl;
        return 0;
    }
    int ca = 0, cb = 0, cc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a') ca++;
        else if (s[i] == 'b') cb++;
        else cc++;
    }
    if (ca == 0 && cb == 0 || cb == 0 && cc == 0 || ca == 0 && cc == 0)
    {
        cout << 1 << endl;
        cout << s[0] << endl;
        return 0;
    }
    if (ca == 0)
    {
        cout << 2 << endl;
        cout << "b\nc" << endl;
        return 0;
    }
    if (cb == 0)
    {
        cout << 2 << endl;
        cout << "a\nc" << endl;
        return 0;
    }
    if (cc == 0)
    {
        cout << 2 << endl;
        cout << "a\nb" << endl;
        return 0;
    }
    s1 = "";
    string s2 = "";
    for (int i = 1; i < L; i++)
    {
        for (int j = i + 2; j < i + 1 + L; j++)
        {
            s1 = "";
            s2 = "";
            for (int k = 0; k <= i; k++)
            {
                s1 += s[k];
            }
            for (int k = i + 1; k <= j; k++)
            {
                s2 += s[k];
            }
            norm_s(s1, s2);
            //cout << s1 << " " << s2 << endl;
            if (can_use(s, s1, s2))
            {
                cout << 2 << endl;
                cout << s1 << "\n" << s2 << endl;
                return 0;
            }
        }
    }
    cout << 3 << endl;
    cout << "a\nb\nc" << endl;
    return 0;
}
