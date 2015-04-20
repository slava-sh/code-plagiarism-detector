#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DL=2000;

int z[MAX_DL];

int arr[MAX_DL];

int typs,n;

bool dead[MAX_DL];

int antin(int a)
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
    for (int i=0;i<n;i++)
    {
        cin>>z[i];
        arr[i]=-1;
    }
    arr[0]=0;
    typs=1;
    for (int i=1;i<n;i++)
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
        for (int j=0;j<z[i];j++)
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
                int typ=arr[i+j];
                for (int i1=0;i<n;i++)
                {
                    if (arr[i1]==antin(typ))
                    {
                        arr[i1]=antin(arr[j]);
                    }
                }
                for (int i1=0;i<n;i++)
                {
                    if (arr[i1]==typ)
                    {
                        arr[i1]=arr[j];
                    }
                }
                dead[typ]=true;
            }
        }

        if (i+z[i]>=n)
        {
            continue;
        }

        //JABARDA
        int j=z[i];
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
                int typ=arr[i+j];
                for (int i1=0;i<n;i++)
                {
                    if (arr[i1]==antin(typ))
                    {
                        arr[i1]=arr[j];
                    }
                }
                for (int i1=0;i<n;i++)
                {
                    if (arr[i1]==typ)
                    {
                        arr[i1]=antin(arr[j]);
                    }
                }
                dead[typ]=true;
            }

    }

    int sum=1;
    for (int i=0;i<typs;i++)
    {
        if (!dead[i])
        {
            sum=(sum*2)%1000000007;
        }
    }
    cout<<sum;
    return 0;
}
