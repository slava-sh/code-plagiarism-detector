#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n;
int S[100011];
int x[100011];
int lowbit(int x){return x & (-x);}
int LEN = 100000;
vector <int> which[100001];
vector <int> ansA , ansB , ansC;

void modify(int pos , int d)
{
    if(pos <= 0)return;
    while(pos <= LEN)
    {
        S[pos] += d;
        pos += lowbit(pos);
    }
}

int s(int pos)
{
    int ret = 0;
    while(pos)
    {
        ret += S[pos];
        pos -= lowbit(pos);
    }
    return ret;
}

int last()
{
    if(s(LEN) == 0)return -1;
    int L = 0 , R = LEN , M;
    while(R - L > 1)
    {
        M = (L + R) >> 1;
        if(s(M) == s(LEN))
            R = M;
        else
            L = M;
    }
    return R;
}

int main()
{
    ios :: sync_with_stdio(false);
    while(cin >> n)
    {
        ansA.clear() , ansB.clear() , ansC.clear();
        for(int i = 0 ; i <= LEN ; i++)
            which[i].clear();
        int ans = 0;
        for(int i = 1 ; i <= n ; i++)
            cin >> x[i];
        sort(x + 1 , x + 1 + n);
        memset(S , 0 , sizeof(S));
        x[n+1] = -1;
        int cnt = 1;
        for(int i = 2 ; i <= n + 1 ; i++)
            if(x[i] != x[i-1])
            {
                which[cnt].push_back(x[i-1]);
                modify(cnt , 1);
                cnt = 1;
            }
            else
                cnt ++;
        while(true)
        {
            int a = last();
            modify(a , -1);
            int b = last();
            modify(b , -1);
            int c = last();
            modify(c , -1);
            if(a < 0 || b < 0 || c < 0)
                break;
            cnt ++;
            modify(a - 1 , 1);
            modify(b - 1 , 1);
            modify(c - 1 , 1);
            int A = which[a][which[a].size()-1];
            which[a].pop_back();
            int B = which[b][which[b].size()-1];
            which[b].pop_back();
            int C = which[c][which[c].size()-1];
            which[c].pop_back();
            which[a-1].push_back(A);
            which[b-1].push_back(B);
            which[c-1].push_back(C);
            if(A < B)swap(A , B);
            if(B < C)swap(B , C);
            if(A < B)swap(A , B);
            if(B < C)swap(B , C);
            if(A < B)swap(A , B);
            if(B < C)swap(B , C);
            
            ansA.push_back(A);
            ansB.push_back(B);
            ansC.push_back(C);
            ans ++;
        }
        cout << ans << endl;
        for(int i = 1 ; i <= ans ; i++)
            cout << ansA[i-1] << " " << ansB[i-1] << " " << ansC[i-1] << endl;
    }
    return 0;
}
