#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#define pb push_back
#define mp make_pair
#define SS(a,b) scanf("%d%d",&a,&b);
#define S(a) scanf("%d",&a);
#define SSL(a,b) scanf("%lld%lld",&a,&b);
#define SL(a) scanf("%lld",&a);
#define SSS(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({ll t;scanf("%lld",&t);t;})
#define MAXN 500000
#define MAYA KRISHNAN
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
#define INPUT freopen("input.txt","r",stdin);
#define OUTPUT freopen("output.txt","w",stdout);
#define disvec(v) { for(int vec_index=0;vec_index<v.size();vec_index++) cout<<v[vec_index]<<" "; cout<<endl;}
using namespace std;
typedef  long long LL;
typedef  long long ll;
struct node{
    int cnt;
    int num;
    node(int a,int b){
        cnt=a,num=b;    
    }
};
bool operator <(const node &a , const node & b){
    return a.cnt<b.cnt;
}
map<int,int>M;
vector<int>get[100000];
int main(){
    int n=GI;
    REP(i,n){
        int x=GI;
        M[x]++;
    }
    set<pair<int,int> >s;
    map<int,int>::iterator mit;
    set<pair<int,int> >::iterator sit;
    for(mit=M.begin();mit!=M.end();mit++){
        s.insert(mp(-(mit->second),mit->first));
    }
//  cout<<s.size()<<endl;
    
    int index=-1;
    while(s.size()>=3){
    /*  for(sit=s.begin();sit!=s.end();sit++)
            cout<<(*sit).first<<" "<<(*sit).second<<endl;
        cout<<endl;*/
        pair<int,int> temp[3];
        REP(i,3){
            sit=s.begin();
            temp[i]=*sit;
            s.erase(sit);
        }
        vector<int>t;
        index++;
        REP(i,3){
            get[index].pb(temp[i].second);
        //  cout<<temp[i].second<<" ";
            temp[i].first++;
            if(temp[i].first<0)
                s.insert(temp[i]);
        }
//      cout<<endl;
    }
    cout<<index+1<<endl;
    REP(i,index+1){
        sort(get[i].rbegin(),get[i].rend());
        REP(j,3)
            cout<<get[i][j]<<" ";
        cout<<endl;
    }
    GI;
    return 0;
}
