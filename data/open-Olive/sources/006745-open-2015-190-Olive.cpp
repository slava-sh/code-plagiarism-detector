#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>w(n);
    for(int i=0;i<n;i++)
        w[i]=v[i];
    int k=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            if(w[j]>w[j+1])
            {
                int f=w[j];
                w[j]=w[j+1];
                w[j+1]=f;
                k++;
            }
    int a=-1;
    int b=-1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(v[i]<v[j])
            {
                for(int g=0;g<n;g++)
                    w[g]=v[g];
                w[i]=v[j];
                w[j]=v[i];
                int p=0;
                for(int g=1;g<n;g++)
                    for(int q=0;q<n-g;q++)
                        if(w[q]>w[q+1])
                        {
                            p++;
                            int f=w[q];
                            w[q]=w[q+1];
                            w[q+1]=f;
                        }
                if(p<k)
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
