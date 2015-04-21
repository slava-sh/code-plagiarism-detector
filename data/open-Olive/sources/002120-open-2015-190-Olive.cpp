#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k=0;
    int a=-1;
    int b=-1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int p=fabs(v[i]-i-1)-fabs(v[i]-j-1)+fabs(v[j]-j-1)-fabs(v[j]-i-1);
            if(p>k)
            {
                k=p;
                a=i+1;
                b=j+1;
            }
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
