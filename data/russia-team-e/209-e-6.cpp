#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mpow = 100057;

vector <pair<long long, int> > gos[4];
vector <long long> oper[101][6];

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
    return !!(s[used] - '0');
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
        gos[c.length()].push_back(make_pair(get_hash(c), i));
        for(int j = 0; j < k; ++j)
        {
            string t;
            cin >> t;
            oper[i][t.length()].push_back(get_hash(t));
        }
    }
    for(int i = 1; i <= 3; ++i)
        sort(gos[i].begin(), gos[i].end());
    for(int i = 0; i < n; ++i)
        for(int j = 3; j <= 5; ++j)
            sort(oper[i][j].begin(), oper[i][j].end());
    int m;
    cin >> m;
    //vector <long long> thash;
    for(int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        //get_hash(s, thash);
        long long lenghash = 0;
        int leng, lenop;
        bool pos;
        for(leng = 1; leng <= 3; ++leng)
        {
            lenghash *= mpow;
            lenghash += s[leng - 1] - '0';
            int left = 0, right = gos[leng].size();
            while(right - left > 1)
            {
                int m = (left + right) / 2;
                if(gos[leng][m].first <= lenghash)
                    left = m;
                else
                    right = m;
            }
            if(gos[leng].size() == 0)
            {
                pos = false;
                continue;
            }
            pos = (gos[leng][left].first == lenghash);
            if(!pos)
                continue;
            pos = false;
            int anspos = gos[leng][left].second;
            /*cout << endl << gos[leng][left] << " " << lenghash << endl;
            cout << "leng = " << leng << endl;
            cout << "anspos = " << anspos << endl;*/
            long long lenophash = 0;
            for(int i = 0; i < 2; ++i)
            {
                lenophash *= mpow;
                lenophash += s[leng + i] - '0';
            }
            for(lenop = 3; lenop <= 5; ++lenop)
            {
                if(lenop >= 3)
                    lenophash *= mpow;
                lenophash += s[lenop - 1 + leng] - '0';
                int left = 0, right = oper[anspos][lenop].size();
                while(right - left > 1)
                {
                    int m = (left + right) / 2;
                    if(oper[anspos][lenop][m] <= lenophash)
                        left = m;
                    else
                        right = m;
                }
                if(oper[anspos][lenop].size() == 0)
                {
                    pos = false;
                    continue;
                }
                if(oper[anspos][lenop][left] == lenophash && norm(s, leng + lenop) && !!(s[0] - '0') && !!(s[leng] - '0'))
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
