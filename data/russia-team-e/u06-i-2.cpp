#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("sochi.in");
    ofstream  out("sochi.out");
    int n,d,S=0;
    int otb=0,ota=0;
    in>>n>>d;
    int endn = n;
    int a[n];
    for (int i=0;i<n;i++){
        in>>a[i];
        if(a[i] <d)
            {endn--;continue;}
        else if(a[i] <= 3*d)
        {
            if(a[i]>otb) {
                if(otb>0)endn--;
                otb=a[i];
                continue;
                }else
            if(a[i]>ota) {
                    if(ota>0)endn--;
                    ota=a[i];
                    continue;
                    }else
                continue;
        }
        S+=a[i];
    }
    S+=ota + otb;
    S= S-(endn*d)-((endn-2)*d);

    /*
    int min,i,max,n,d,s=0;
    in>>n>>d;
    int a[n];
    for (i=0;i<n;i++) in>>a[i];
    min=a[0],max=a[0];
       for (i=1;i<n;i++)
        {
    if (a[i]<min && (a[i]-d>=d)) min=a[i];
    if (a[i]>max && (a[i]-d>=d))  max=a[i];
    }
    s+=min-2*d;s+=max-2*d;
    for (i=0;i<n;i++)
    {
        if (a[i]==min) continue; else if (a[i]-2*d>=d) s+=a[i]-2*d;
    }*/
    out<<S;
    return 0;
}
