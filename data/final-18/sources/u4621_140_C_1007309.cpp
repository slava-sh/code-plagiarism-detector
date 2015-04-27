// {{{
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)      (A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
using namespace std;
typedef long long ll;
// }}}

typedef pair<int,int> P;
int main(){
    int n;
    scanf("%d",&n);
    map<int,int> ns;
    for(int i=0;i<n;i++){
        int nn;
        scanf("%d",&nn);
        if(ns.find(nn)==ns.end()) ns[nn]=1;
        else ns[nn]++;
    }
    priority_queue<P,vector<P>,less<P> > pq;
    for(map<int,int>::iterator it=ns.begin();it!=ns.end();it++){
        pq.push(MP(it->second,it->first));
    }
    vector<vector<int> > ans;
    for(;;){
        if(pq.empty()) break;
        P fi=pq.top();
        pq.pop();
        if(fi.first-1>0) pq.push(MP(fi.first-1,fi.second));
        P se;
        if(pq.empty()) break;
        if(pq.top().second==fi.second){
            P tmp=pq.top();pq.pop();
            if(pq.empty()) break;
            se=pq.top();pq.pop();
            pq.push(tmp);
        }else{
            se=pq.top();pq.pop();
        }
        if(se.first-1>0) pq.push(MP(se.first-1,se.second));
        P th;
        if(pq.empty()) break;
        if(pq.top().second==fi.second||pq.top().second==se.second){
            P tmp=pq.top();pq.pop();
            if(pq.top().second==fi.second||pq.top().second==se.second){
                if(pq.empty()) break;
                P tmp2=pq.top();pq.pop();
                if(pq.empty()) break;
                th=pq.top();pq.pop();
                pq.push(tmp2);
                pq.push(tmp);
            }else{
                if(pq.empty()) break;
                th=pq.top();pq.pop();
                pq.push(tmp);
            }
        }else{
            th=pq.top();pq.pop();
        }
        if(th.first-1>0) pq.push(MP(th.first-1,th.second));
        vector<int> three(3);
        three[0]=fi.second;three[1]=se.second;three[2]=th.second;
        sort(ALL(three));
        reverse(ALL(three));
        ans.push_back(three);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
}
