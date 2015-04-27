#include<cstdio>
#include<iostream>
long long const MAX=100005;
using namespace std;
bool isused[MAX];
long meals[MAX];
long food[MAX];
long lastuse[MAX];
bool angry[MAX];
int main()
{
    long t,m,k;
    long unknown,first,mi;
    scanf("%ld",&t);
    int temp;
    for(long g=0;g<t;++g)
        {
        first=-1;
        unknown=0;
        mi=0;
        scanf("%ld%ld",&m,&k);
        for(long i=1;i<=k;++i)
            {
                scanf("%ld",&meals[i]);
                lastuse[i]=-1;
                isused[i]=false;
            }
        for(long i=0;i<m-1;++i)
            {
                scanf("%ld%d",&food[i],&temp);
                if(temp==1){
                        angry[i]=true;
                        if(first==-1)first=i;
                        }
                else angry[i]=false;
                if(first==-1){
                    if(food[i]==0)++unknown;
                    else --meals[food[i]];
                }
            //    cout<<"i=="<<i<<" un=="<<unknown<<endl;
                lastuse[food[i]]=i;
            }
        if(first>=0)
            {

            for(int i=1;i<=k;i++)
                {
          //     printf("for i==%ld lastuse[i]==%ld meals[i]==%ld\n",i,lastuse[i],meals[i]);
                if(lastuse[i]<first&&unknown>=meals[i])
                    {
                    isused[i]=true;
                    if(unknown-meals[i]>mi)mi=unknown-meals[i];
                    }
                }
            unknown=mi;
            }
        if(first==-1)first=m;
        for(long i=first;i<m-1;++i)
            {
                if(food[i]!=0)
                    {
                        --meals[food[i]];
                    }
                else ++unknown;
            }
        for(long i=1;i<=k;++i)
            {

                if(unknown>=meals[i])isused[i]=true;
                if(isused[i]==true)printf("Y");
                else printf("N");
               // printf(" for i==%ld lastuse[i]==%ld meals[i]==%ld , unknown is %ld\n",i,lastuse[i],meals[i],unknown);
            }
        printf("\n");
        }
}