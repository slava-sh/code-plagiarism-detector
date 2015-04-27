#include <iostream>
using namespace std;
    int a[100003][2];
int main()
{
    int t;
    cin>>t;
    for (int l=1; l<=t; l++)
    {
    int m, k;
    cin>>m>>k;
    a[0][0]=0;
    for (int i=1; i<=k; i++)
    {
        cin>>a[i][0];
        a[i][1]=0;
    }
    int fl=1;
    for (int i=0; i<m-1; i++)
    {
        int t, r;
        if (fl)
        {
            cin>>t>>r;
            if (r==1)
            {
                for (int j=1; j<=k; j++)
                    if (a[j][0]<=(-a[0][0]))
                        a[j][1]=1;
                fl=0;
            }
            a[t][0]--;
            a[t][1]=0;
        }
        else
        {
            int t, r;
            cin>>t>>r;
            a[t][0]--;
            a[t][1]=0;
        }
    }
    int min=1000000;
    for (int i=1; i<=k; i++)
        if (a[i][1])
            if (a[i][0]<min)
                min=a[i][0];
    int kol;
    if (min==1000000)
        kol=-a[0][0];
    else
        kol=-a[0][0]-min;
    for (int i=1; i<=k; i++)
        if (a[i][1]||(a[i][0]<=kol))
            cout<<"Y";
        else 
            cout<<"N";
    cout<<endl;
    }
    return 0;
}