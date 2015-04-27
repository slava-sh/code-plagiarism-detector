#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef long long ll;

ll dp[555][555];

ll mod;
int co[555];
string str;
int n,m;

int main() {

    cin>>n>>m>>mod;

    getline(cin, str);    

    for (int i=0;i<m;i++){
        getline(cin, str);    
        //cout<<str<<endl;
        for (int j=0;j<str.size();j++)
            if (str[j]=='1')
                co[j]++;
    }

    int k = n-m;

    ll res=0;
    dp[0][0]=1;
    ll sm=0;

    for (int i=0;i<=n;i++){
        if (i==n){
            res=dp[i][0]; 
            res%=mod;
        }
        else
        for (ll ones=0;ones<=n;ones++){
            if (sm>=ones) {



                dp[i][ones]%=mod;
                //cout<<i<<' '<<ones<<' '<<dp[i][ones]<<endl;
                if ( (sm-ones)%2 ) continue;
                ll twos = (sm - ones)/2;
                ll zeros = k-twos-ones;
                //cout<<zeros<<'-'<<ones<<'-'<<twos<<endl;
                //cout<<co[i]<<endl;

                if (co[i]==0){
                    if (zeros>0 && ones>0) dp[i+1][ones] += dp[i][ones]*zeros*ones;
                    if (ones>1) dp[i+1][ones-2] += dp[i][ones]*ones*(ones-1)/2LL;
                    if (zeros>1) dp[i+1][ones+2] += dp[i][ones]*zeros*(zeros-1)/2LL;
                } 

                if (co[i]==1){
                    if (zeros>0) dp[i+1][ones+1] += dp[i][ones]*zeros; 
                    if (ones>0) dp[i+1][ones-1] += dp[i][ones]*ones;
                }
                if (co[i]==2){
                    dp[i+1][ones]=dp[i][ones];
                }

            }
        }
        if (co[i]==0) sm+=2;
        if (co[i]==1) sm+=1;
    }

    cout<<res<<endl;
} 
