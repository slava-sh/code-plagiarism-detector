#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n, r, d[300001], l, j;
int main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    cin>>n>>r;
    for(int i=0;i<n;i++)
        cin>>d[i];
    j=n-1;
    for(int i=n-1;i>=0;)
    {
        if(j<0)
            break;
        if(d[i]-d[j--]>r)
        {
            l+=j+2;
            i--;
            j=i;
        }
    }
    cout<<l;
}
