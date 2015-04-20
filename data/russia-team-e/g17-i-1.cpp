#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
long int i, n,  ans=0;
int d;
int main(){
    
    freopen("sochi.in","r", stdin);                                                                                    
    freopen("sochi.out","w", stdout);
    cin>>n>>d;
    int a[n];
    for(i=0; i<n; i++) cin>>a[i];
    
    ans=a[0];
    for(i=1; i<n; i++) 
             ans=ans+a[i]-2*d;
    cout<<ans;
    //system ("pause");
    return EXIT_SUCCESS;
}
