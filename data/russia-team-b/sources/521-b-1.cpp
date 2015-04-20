// *** ADDED BY HEADER FIXUP ***
#include <cstdio>
#include<fstream>
// *** END ***
// *** ADDED BY HEADER FIXUP ***
#include <vector>
// *** END ***
#include <iostream>

using namespace std;

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);

    int n,r;
    cin>>n>>r;
    int x1= 0;
    vector<int> dist(n);
    for(int i = 0;i<n;++i){
        cin>>dist[i];
    }
    int ans = 0;
    for(int i =0;i<n;++i){
        while(x1<n&&dist[x1]<=dist[i]+r) ++x1;
        ans+=n-x1;
    }
    cout<<ans;
}
