#include <bits/stdc++.h>

using namespace std;

char s[100000];
int pi[100000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int l;
    cin >> l;
    cin >> s;
    int n = strlen(s);
    for(int p=1;p<=l;p++)
    {
        if(n % p)
            continue;
        bool b = 1;
        for(int i=p;i<n;i++)
        {
            if(s[i] != s[i - p])
            {
                b = 0;
                break;
            }
        }
        if(b)
        {
            cout << 1 << '\n';
            for(int i=0;i<p;i++)
            {
                cout << s[i];
            }
            return 0;
        }
    }
    cout << "2\na\nb";
    return 0;
}
