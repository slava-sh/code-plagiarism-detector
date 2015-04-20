#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mpow = 100057;

vector <string> gos[4], oper[6];

long long get_hash(string &s)
{
    long long ans = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        ans *= mpow;
        ans += s[i] - '0';
    }
    return ans;
}

bool norm(string &s, int used)
{
    int left = 11 - used;
    if(left == 7)
        return !!(s[4] - '0');
    if(left == 6)
        return !!(s[5] - '0');
    if(left == 5)
        return !!(s[6] - '0');
    if(left == 4)
        return !!(s[7] - '0');
    return !!(s[8] - '0');
}

int main()
{
    ifstream cin("numbers.in");
    ofstream cout("numbers.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string c;
        int k;
        cin >> c >> k;
        gos[c.length()].push_back(c);
        for(int j = 0; j < k; ++j)
        {
            string t;
            cin >> t;
            oper[t.length()].push_back(t);
        }
    }
    for(int i = 1; i <= 3; ++i)
        sort(gos[i].begin(), gos[i].end());
    for(int i = 3; i <= 5; ++i)
        sort(oper[i].begin(), oper[i].end());
    int m;
    cin >> m;
    //vector <long long> thash;
    for(int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        //get_hash(s, thash);
        string lenghash = "";
        int leng, lenop;
        bool pos;
        for(leng = 1; leng <= 3; ++leng)
        {
            lenghash += s[leng - 1];
            int left = 0, right = gos[leng].size();
            while(right - left > 1)
            {
                int m = (left + right) / 2;
                if(gos[leng][m] <= lenghash)
                    left = m;
                else
                    right = m;
            }
            if(gos[leng].size() == 0)
            {
                pos = false;
                continue;
            }
            pos = (gos[leng][left] == lenghash);
            if(!pos)
                continue;
            pos = false;
            string lenophash = "";
            for(int i = 0; i < 2; ++i)
                lenophash += s[leng + i];
            for(lenop = 3; lenop <= 5; ++lenop)
            {
                lenophash += s[lenop - 1 + leng];
                int left = 0, right = oper[lenop].size();
                while(right - left > 1)
                {
                    int m = (left + right) / 2;
                    if(oper[lenop][m] <= lenophash)
                        left = m;
                    else
                        right = m;
                }
                if(oper[lenop].size() == 0)
                {
                    pos = false;
                    continue;
                }
                if(oper[lenop][left] == lenophash && norm(s, leng + lenop) && !!(s[0] - '0') && !!(s[leng] - '0'))
                {
                    pos = true;
                    break;
                }
            }
            if(pos)
                break;
        }
        if(!pos)
        {
            cout << "Incorrect" << endl;
            continue;
        }
        cout << "+";
        for(int i = 0; i < leng; ++i)
            cout << s[i];
        cout << "(";
        for(int i = 0; i < lenop; ++i)
            cout << s[leng + i];
        cout << ")";
        int left = 11 - leng - lenop;
        int cpos = leng + lenop;
        int cnt = 0;
        if(left == 7)
        {
            for(int i = 0; i < left + 2; ++i)
            {
                if(i == 3 || i == 6)
                {
                    cout << "-";
                    cnt++;
                }
                else
                    cout << s[cpos + i - cnt];
            }
        }
        if(left == 6)
        {
            for(int i = 0; i < left + 2; ++i)
            {
                if(i == 2 || i == 5)
                {
                    cout << "-";
                    cnt++;
                }
                else
                    cout << s[cpos + i - cnt];
            }
        }
        if(left == 5)
        {
            for(int i = 0; i < left + 1; ++i)
            {
                if(i == 3)
                {
                    cout << "-";
                    cnt++;
                }
                else
                    cout << s[cpos + i - cnt];
            }
        }
        if(left == 4)
        {
            for(int i = 0; i < left + 1; ++i)
            {
                if(i == 2)
                {
                    cout << "-";
                    cnt++;
                }
                else
                    cout << s[cpos + i - cnt];
            }
        }
        if(left == 3)
        {
            for(int i = 0; i < left; ++i)
            {
                cout << s[cpos + i - cnt];
            }
        }
        cout << endl;
        /*for(int i = leng + lenop; i < s.length(); ++i)
            cout << s[i];
        cout << endl;*/
    }
    return 0;
}
