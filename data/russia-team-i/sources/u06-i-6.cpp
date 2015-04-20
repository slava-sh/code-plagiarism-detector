#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("sochi.in");
    ofstream  out("sochi.out");
    int n,d;
    long long S=0;
    int otb=0,ota=0;
    in>>n>>d;
    int endn = n;
    int a[n];
    for (int i=0;i<n;i++){
        in>>a[i];
        if(a[i] <d)
            {endn--;continue;}
        else if(a[i] < 3*d)
        {
            if(otb<ota && a[i]>otb) {
                if(otb>0)endn--;
                otb=a[i];
                continue;
                }else
            if(a[i]>ota) {
                    if(ota>0)endn--;
                    ota=a[i];
                    continue;
                    }else
                {endn--;continue;}
        }
        S+=a[i];
    }
    if(endn > 0){
        S+=ota + otb;
        S= S-(endn*d)-((endn-2)*d);
    }

    int z=0;
    for(int i=0;i<n;i++) if(z<a[i]) z=a[i];
    if(z>S) S=z;

    out<<S;
    return 0;
}
