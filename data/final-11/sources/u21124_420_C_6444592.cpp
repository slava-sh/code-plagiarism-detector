#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 3e5 + 5;
int Count[N];
vector<pair<int,int> > v;
bool cmp(int a,int b){return a > b;}
int main(){
    int n,p;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a > b) swap(a,b);
        v.push_back(make_pair(a,b));
        Count[a]++;
        Count[b]++;
    }
    long long ans = 0;
    sort(v.begin(),v.end());
    n = v.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt ++;
        if(i == n-1 || v[i] != v[i+1]){
            int a = v[i].first;
            int b = v[i].second;
            if(Count[a] + Count[b] >= p && Count[a] + Count[b] - cnt < p){
                    ans --;
            }
            cnt = 0;
        }
    }
    sort(Count + 1, Count + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        int c = Count[i];
        int l = i+1, r = n + 1;
        while(l < r){
            int mid = l + r >> 1;
            if(Count[mid] + c >= p) l = mid + 1;
            else r = mid;
        }
        ans += l - i - 1;
    }
    cout<< ans << endl;
}
