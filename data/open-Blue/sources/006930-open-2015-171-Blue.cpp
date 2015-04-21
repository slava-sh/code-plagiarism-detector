#include <iostream>
#include <vector>

using namespace std;

bool test(string &s, int pos, string &st)
{
    int i;
    i = 0;
    //cout << ' ' << pos << endl;
    if (pos + st.size() > s.size()) return false;
    //cout << ' ' << s.substr(pos, st.size()) << ' ' << st<<endl;
    if (st != s.substr(pos, st.size())) return false;
    return true;
}

int main()
{
    string s, s1, s2;
    bool fl = false, fl1;
    int l, i, j, k, pos, pos1;
    cin >> l;
    cin >> s;
    for (j = 1; j <= l; j++)
    {
        fl1 = true;
        if (s.size() % j != 0) continue;
        for (i = j + 1; i < s.size(); i++)
        {
            if (s[i] != s[i % j]) {fl1 = false; break;}
        }
        if (fl1) {cout<< 1 << endl << s.substr(0, j); return 0;}
    }
    s1 = "";
    for (j = 1; j <= l; j++)
    {
        fl = false;
        fl1 = true;
        pos = 0;
        s1 = s1 + s[j - 1];
        s2 = "";
        for (i = 0; i < s.size(); i++)
        {
            if (i >= pos + j) pos+=j;
            if (s[i] != s1[i % j])
            {
                s2 = "";
                pos1 = pos;
                for (k = 1; k <= l; k++)
                {
                    fl = false;
                    pos = pos1;
                    s2 = s2 + s[k + pos-1];
                    //cout << s1  << ' ' << s2 << ' ' << pos << ' ' << k + pos-1 <<endl;
                    while (pos < s.size())
                    {
                        if (test(s, pos, s1)) {pos+=s1.size(); continue;}
                        else
                        if (test(s, pos, s2)) {pos+=s2.size(); continue;}
                        else{
                        fl = true;
                        break;}
                    }
                    if (!fl) {cout << 2 << endl << s1 << endl << s2; return 0;}
                }
                break;
            }
        }
    }
    return 0;
}
