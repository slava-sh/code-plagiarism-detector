#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

int r[120][120],e[120],x[12],n,ch[120][120][12],m;
char z[12];
long long b,a;
void rab(int d,int st,int ra)
{
    int dl=0,t[12];
    while(d>0)
        t[dl++]=d%10,d/=10;
    r[st][ra]=dl;
    for(int i=0,j=dl-1; i<dl; i++,j--)
        ch[st][ra][i]=t[j];
}

void ouut(int ts,int tr,int ps)
{
    cout<<"+";
    for(int i=0; i<r[ts][0]; i++)
        cout<<ch[ts][0][i];
    cout<<"(";
    for(int i=0; i<r[ts][tr]; i++)
        cout<<ch[ts][tr][i];
    cout<<")";
    int oi=11-ps;
    if(oi==3)
    {
        cout<<x[8]<<x[9]<<x[10]<<endl;
        return;
    }
    if(oi==4)
    {
        cout<<x[7]<<x[8]<<"-"<<x[9]<<x[10]<<endl;
        return;
    }
    if(oi==5)
    {
        cout<<x[6]<<x[7]<<x[8]<<"-"<<x[9]<<x[10]<<endl;
        return;
    }
    if(oi==6)
    {
        cout<<x[5]<<x[6]<<"-"<<x[7]<<x[8]<<"-"<<x[9]<<x[10]<<endl;
        return;
    }
    if(oi==7)
    {
        cout<<x[4]<<x[5]<<x[6]<<"-"<<x[7]<<x[8]<<"-"<<x[9]<<x[10]<<endl;
        return;
    }
}

int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        rab(a,i,0);
        cin>>e[i];
        for(int j=1; j<=e[i]; j++)
        {
            cin>>b;
            rab(b,i,j);
        }
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<11; j++){
            cin>>z[j];
            x[j]=(int)(z[j]-48);
            }
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<r[j][0]; k++)
            {
                if(x[k]!=ch[j][0][k])goto as;
            }
            for(int l=1; l<=e[j]; l++)
            {
                for(int k=r[j][0],p=0; k<r[j][l]+r[j][0]; k++,p++)
                {
                    if(x[k]!=ch[j][l][p])
                        goto ad;
                }
                if(x[r[j][l]+r[j][0]]!=0)
                    ouut(j,l,r[j][l]+r[j][0]);
                else goto ad;
                goto ass;
            ad:;
            }
as:
            ;
        }
        cout<<"Incorrect\n";
ass:
        ;
    }
}
/*
2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/
