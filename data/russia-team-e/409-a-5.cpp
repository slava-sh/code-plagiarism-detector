#include <iostream>
#include <fstream>
using namespace std;

const long long MAX_DL=2000;

long long z[MAX_DL];

long long arr[MAX_DL];

long long typs,n;

bool dead[MAX_DL];

long long antin(long long a)
{
    if (a%2==0)
    {
        return a+1;
    }
    else
    {
        return a-1;
    }
}

int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    cin>>n;
    for (long long i=0;i<n;i++)
    {
        cin>>z[i];
        arr[i]=-1;
    }
    if (z[0]!=0)
    {
        cout<<0;
        return 0;
    }
    arr[0]=0;
    typs=1;
    for (long long i=1;i<n;i++)
    {
        if (z[i]==-1)
        {
            if (arr[i]==-1)
            {
                arr[i]=typs*2;
                typs++;
            }
            continue;
        }
        if (z[i]>n-i)
        {
            cout<<0;
            return 0;
        }
        for (long long j=0;j<z[i];j++)
        {
            if (arr[i+j]==-1 || arr[i+j]==arr[j])
            {
                arr[i+j]=arr[j];
            }
            else if (arr[i+j]==antin(arr[j]))
            {
                cout<<0;
                return 0;
            }
            else
            {
                long long typ=arr[i+j];
                for (long long i1=0;i1<n;i1++)
                {
                    if (arr[i1]==antin(typ))
                    {
                        arr[i1]=antin(arr[j]);
                    }
                }
                for (long long i1=0;i1<n;i1++)
                {
                    if (arr[i1]==typ)
                    {
                        arr[i1]=arr[j];
                    }
                }
                dead[typ/2]=true;
            }
        }

        if (i+z[i]>=n)
        {
            continue;
        }

        //JABARDA
        long long j=z[i];
            if (arr[i+j]==-1 || arr[i+j]==antin(arr[j]))
            {
                arr[i+j]=antin(arr[j]);
            }
            else if (arr[i+j]==arr[j])
            {
                cout<<0;
                return 0;
            }
            else
            {
                long long typ=arr[i+j];
                for (long long i1=0;i1<n;i1++)
                {
                    if (arr[i1]==antin(typ))
                    {
                        arr[i1]=arr[j];
                    }
                }
                for (long long i1=0;i1<n;i1++)
                {
                    if (arr[i1]==typ)
                    {
                        arr[i1]=antin(arr[j]);
                    }
                }
                dead[typ/2]=true;
            }

    }

    long long sum=1;
    for (long long i=0;i<typs;i++)
    {
        if (!dead[i])
        {
            sum=(sum*2)%1000000007;
        }
    }
    cout<<sum;
    return 0;
}
