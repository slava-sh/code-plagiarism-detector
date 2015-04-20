#include <iostream>
#include <stdio.h>

using namespace std;

int n,r;
int sk[300002];
long long rez;

int main()
{
freopen("che.in","r",stdin);
freopen("che.out","w+",stdout);

int kr,la;
sk[n+1]=0;
scanf("%d %d",&n,&r);
for (kr=1;kr<=n;kr++)scanf("%d",&sk[kr]);

    rez=0;
    kr=1;la=1;
    while (kr<=n){
        while (la<=n && sk[la]-sk[kr]<=r){
            la++;
        }
        if (la>n)break;
        else
            {
               rez+=(n-la+1);
            }
        kr++;
    }

printf("%lld",rez);
}
