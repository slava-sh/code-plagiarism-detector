#include <bits/stdc++.h>

using namespace std;

char s[100000];
int pi[100000];

void calc_pi()
{
    pi[0] = 0;
    for(int i=1;s[i];i++)
    {
        pi[i] = pi[i - 1] + 1;
        while(pi[i] && s[i] != s[pi[i] - 1])
            pi[i] = pi[pi[i] - 1];
        if(!pi[i] && s[i] == s[pi[i]])
            pi[i]++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int l;
    cin >> l;
    cin >> s;
    int n = strlen(s);
    calc_pi();
    int p = (n - pi[n - 1]);
    if(p <= l)
    {
        cout << 1 << '\n';
        for(int i=0;i<p;i++)
        {
            cout << s[i];
        }
        return 0;
    }

    cout << "2\na\nb";
    return 0;
}
