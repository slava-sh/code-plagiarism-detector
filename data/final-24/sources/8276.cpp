#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <set>
#include <cmath>
#include <queue>

#define MAXN 100005
#define mod 1000000007

using namespace std;
typedef long long ll;

set<string> st[1005][505];
vector<vector<long>> dp(1005, vector<long>(505, mod));

int main()
{
    long n, l, i, j, k;
    string s;
    cin>>l;
    cin>>s;
    n = s.size();
    if (n<=l) {
        cout<<"1\n"<<s;
        return 0;
    }
    for (i=1; i<=l; i++) {
        dp[i-1][i] = 1;
        st[i-1][i].insert(s.substr(0, i));
    }
    for (i=0; i<n; i++) {
        for (j=1; j<=min(l, i+1); j++) {
            for (k=1; k<=min(l, n-i-1); k++) {
                if (st[i][j].find(s.substr(i+1, k))!=st[i][j].end()) {
                    if (st[i][j].size()<dp[i+k][j]) {
                        st[i+k][j] = st[i][j];
                        dp[i+k][j] = dp[i][j];
                    }
                } else {
                    if (st[i][j].size()+1<dp[i+k][k]) {
                        st[i+k][k] = st[i][j];
                        dp[i+k][k] = dp[i][j]+1;
                        st[i+k][k].insert(s.substr(i+1, k));
                    }
                }
            }
        }
    }
    long a = 1;
    for (i=2; i<=l; i++) {
        if (st[n-1][i].size()<st[n-1][a].size()) {
            a = i;
        }
    }
    cout<<st[n-1][a].size()<<"\n";
    for (auto it: st[n-1][a]) {
        cout<<it<<"\n";
    }

    return 0;
}
