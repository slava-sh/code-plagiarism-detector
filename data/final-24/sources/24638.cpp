#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

const ll INF = 1e9+9999;

ll n,m,T;
ll timer=0;

vector<vector<pair<ll,ll> > > g;
vector<ll> us;
vector<vector<ll> > d;

vector<int> p_f(string s)
{
    int n=(int)s.length();
    vector <int> pi(n);
    for(int i=1; i<n; i++)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j]) ++j;
        pi[i]=j;
    }
    return pi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int l;
    cin>>l;
    string s;
    cin>>s;
    int ans=2;
    for(int i=0; i<s.size(); i++)
    {
        for(int j=i+1; j<s.size(); j++)
        {
            if(j-i<l && s.size()%(j-i+1)==0)
            {
                //cout<<s.size()%(j-i+1)<<endl;
                string t;
                for(int q=i; q<=j; q++)
                {
                    t+=s[q];
                }
                int tr=1;
               // cout<<t<<endl;
                for(int k=0; k<(int)s.size(); k++)
                {

                    //cout<<t[k%t.size()]<<" "<<s[k]<<endl;
                        if(t[k%t.size()]!=s[k]) {tr=0;break;}
                }
                if(tr ){
                    cout<<1<<endl<<t<<endl;
                    return 0;
                }
            }
        }
    }
    int a=0,b=0;
    for(int i=0;i<s.size();i++)
        {if(s[i]=='a') a=1;
        if(s[i]=='b') b=1;}
    cout<<a+b<<endl;
    if(a) cout<<'a'<<endl;
    if(b) cout<<'b'<<endl;
    return 0;
}
