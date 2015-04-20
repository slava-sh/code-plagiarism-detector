#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> reg[1222];
vector<int> kc[1222];
string s;

int main()
{
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;


    for(int i = 0; i < n; ++i)
    {
        int c, k;
        cin >> c >> k;
        reg[c].resize(k);
        kc[c].resize(k);
        for(int j = 0; j < k; ++j)
        {
            int tmp;
            cin >> tmp;
            reg[c][j] = tmp;
            kc[c][j] = 0;
            while(tmp > 0)
            {
                ++kc[c][j];
                tmp /= 10;
            }
        }
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> s;

//        cout << s << " ";

        if(s[0] == '0')
        {
            cout << "Incorrect\n";
            continue;
        }

        int r = 0;
        bool fnd = false;
        for(int r_len = 1; r_len < 4; ++r_len)
        {
            r = r*10 + ((int)s[r_len-1]-48);
//            cout << r << " ";

            for(int rn = 0; rn < reg[r].size(); ++rn)
            {
                int codecur = 0;
                for(int codel = 0; codel < kc[r][rn]; ++codel)
                    codecur = codecur*10 + ((int)s[r_len+codel]-48);

                if(codecur != reg[r][rn])
                    continue;

                int l = kc[r][rn] + r_len;

                if(s[l] == '0')
                {
                    continue;
                }

                int ll = 11 - l;
                fnd = true;

                cout << "+" << r << "(" << codecur << ")";

                switch(ll)
                {
                case 3:
                    cout << s.substr(l, 3);
                    break;
                case 4:
                    cout << s.substr(l, 2) << "-" << s.substr(l+2, 2);
                    break;
                case 5:
                    cout << s.substr(l, 3) << "-" << s.substr(l+3, 2);
                    break;
                case 6:
                    cout << s.substr(l, 2) << "-" << s.substr(l+2, 2) << "-" << s.substr(l+4, 2);
                    break;
                case 7:
                    cout << s.substr(l, 3) << "-" << s.substr(l+3, 2) << "-" << s.substr(l+5, 2);
                    break;
                }
                cout << "\n";

                break;
            }

            if(fnd)
                break;
        }

        if(!fnd)
            cout << "Incorrect\n";
    }


    return 0;
}
