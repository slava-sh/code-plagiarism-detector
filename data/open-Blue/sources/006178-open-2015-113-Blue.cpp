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
        {
            pi[i] = pi[pi[i] - 1];
        }
        if(!pi[i] && s[i] == s[0])
            pi[i]++;
    }
}

bool comp(int s1, int f1, int s2)
{
    for(int i=s1;i<f1;i++)
    {
        if(s[i] != s[i - s1 + s2])
            return 0;
    }
    return 1;
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
    pi[0] = 0;
    int p = (n - pi[n - 1]);
    if(n % p == 0 && p <= l)
    {
        cout << 1 << '\n';
        for(int i=0;i<p;i++)
        {
            cout << s[i];
        }
        return 0;
    }
    if(l >= n)
    {
        cout << 1 << '\n' << s;
        return 0;
    }
    bool hc = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'c')
        {
            hc = 1;
            break;
        }
    }
    if(!hc)
    {
        cout << "2\na\nb";
        return 0;
    }
    if((long long)n * l * l > 100000000)
    {
        cout << "3\na\nb\nc";
        return 0;
    }
    for(int i=1;i<=l;i++)
    {
        int s2 = i;
        for(;s2<n;s2+=i)
        {
            if(!comp(s2, s2 + i, 0))
                break;
        }
        if(s2 >= n)
            s2 -= i;
        for(int j=1;j<=l;j++)
        {
            int t = 0;
            while(t < n)
            {
                if(comp(t, t + i, 0))
                {
                    t += i;
                }
                else if(comp(t, t + j, s2))
                {
                    t += j;
                }
                else
                {
                    t = -1;
                    break;
                }
            }
            if(t == n)
            {
                cout << 2 << '\n';
                for(int i_=0;i_<i;i_++)
                {
                    cout << s[i_];
                }
                cout << '\n';
                for(int j_=s2;j_<s2+j;j_++)
                {
                    cout << s[j_];
                }
                return 0;
            }
        }
    }
    cout << "3\na\nb\nc";
    return 0;
}
