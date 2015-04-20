#include<iostream>
#include<fstream>
using namespace std;
long long int n, r, d[99999999], l;
int main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    cin>>n>>r;
    for(int i=0;i<n;i++)
        cin>>d[i];
    for(int i=0;i<n;i++){

        for(int j=n-1;j>=0;j--){
            if(i>=j)
                break;
            if(d[j]-d[i]>r)
            l++;}}
    cout<<l;
}
