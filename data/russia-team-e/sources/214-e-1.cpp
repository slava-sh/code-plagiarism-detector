#include <iostream>
#include<set>
#include<string>
#include<cstdio>

using namespace std;
#define m_p make_pair
bool flag ;
bool proof(string s1, string s2, char ch)
{
    return s1[0] != '0' && s2[0] != '0' && ch != '0';
}
void ct(string s,int x, int y)
{
    flag = true;
    int i;
    cout << "+";
    for(i = 0; i < x; i++)
        cout << s[i];
    cout << "(";
    for(i = x; i < y + x; i++)
        cout << s[i];
    cout << ")";
    int len = s.size() - x  - y;
    if(len == 3)
    {
        cout << s[x + y]  << s[x + y + 1] ;
        cout << s[x + y + 2];
    }
    if(len == 4)
    {
        cout << s[x + y]  << s[x + y + 1] << "-";
        cout << s[x + y + 2]  << s[x + y + 3];
    }
    if(len == 5)
    {
        cout << s[x + y]  << s[x + y + 1];
        cout << s[x + y + 2]  << "-" << s[x + y + 3] << s[x + y + 4];
    }
    if(len == 6)
    {
        cout << s[x + y]  << s[x + y + 1] << "-";
        cout << s[x + y + 2]  <<  s[x + y + 3] << "-" <<s[x + y + 4] << s[x + y + 5];
    }
    if(len == 7)
    {
        cout << s[x + y]  << s[x + y + 1] << s[x + y + 2]  <<"-";
        cout <<  s[x + y + 3]  <<s[x + y + 4] << "-"<< s[x + y + 5] << s[x + y + 6];
    }
    cout << endl;
    return;
}
set<pair<string, string> > se;
int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n, i, k, m, j;
    string st, stt, s, s1, s2, s3;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> st >> m;
        for(j = 0; j < m; j++)
        {
            cin >> stt;
            se.insert(m_p(st, stt));
        }
    }
    cin >> k;
    for(i = 0; i < k; i++)
    {
        flag = false;
        cin >> s;
        s1 = s[0];
        s2 = s[1];
        s2 += s[2];
        s2 += s[3];
        if(se.find(m_p(s1, s2)) != se.end() && proof(s1, s2, s[4]))
        {
            ct(s, 1, 3);
        }

        s1 = s[0];
        s2 = s[1];
        s2 += s[2];
        s2 += s[3];
        s2 += s[4];

        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[5]))
        {
            ct(s, 1, 4);
        }
        s1 = s[0];
        s2 = s[1];
        s2 += s[2];
        s2 += s[3];
        s2 += s[4];
        s2 += s[5];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[6]))
            ct(s, 1, 5);

        s1 = s[0];
        s1 += s[1];
        s2 = s[2];
        s2 += s[3];
        s2 += s[4];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[5]))
            ct(s, 2, 3);
        s1 = s[0];
        s1 += s[1];
        s2 = s[2];
        s2 += s[3];
        s2 += s[4];
        s2 += s[5];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[6]))
            ct(s, 2, 4);
        s1 = s[0];
        s1 += s[1];
        s2 = s[2];
        s2 += s[3];
        s2 += s[4];
        s2 += s[5];
        s2 += s[6];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[7]))
            ct(s, 2, 5);

        s1 = s[0];
        s1 += s[1];
        s1 += s[2];
        s2 = s[3];
        s2 += s[4];
        s2 += s[5];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[6]))
            ct(s, 3, 3);
        s1 = s[0];
        s1 += s[1];
        s1 += s[2];
        s2 = s[3];
        s2 += s[4];
        s2 += s[5];
        s2 += s[6];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[7]))
            ct(s, 3, 4);
        s1 = s[0];
        s1 += s[1];
        s1 += s[2];
        s2 = s[3];
        s2 += s[4];
        s2 += s[5];
        s2 += s[6];
        s2 += s[7];
        if(se.find(m_p(s1, s2)) != se.end()&& proof(s1, s2, s[8]))
            ct(s, 3, 5);
        if(!flag)
            cout << "Incorrect" << endl;
    }
    return 0;
}
