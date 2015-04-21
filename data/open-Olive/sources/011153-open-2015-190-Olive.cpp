#include <iostream>
#include <vector>

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
    int k=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(v[i]<v[j])
                k++;
    int a=-1;
    int b=-1;
    int l=0;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>i+1)
        {
            int p=l;
            for(int j=i+1;j<n;j++)
                for(int g=0;g<j;g++)
                    if(v[g]>v[j])
                        p++;
            for(int j=i+1;j<n;j++)
                if(v[j]<j+1&&v[j]<v[i])
                {
                    int h=p;
                    for(int g=0;g<i;g++)
                        if(v[g]>v[j])
                            h++;
                    for(int g=0;g<j;g++)
                    {
                        if(v[g]>v[j])
                            h--;
                        if(v[g]>v[i])
                            h++;
                    }
                    if(h<k)
                    {
                        k=h;
                        a=i+1;
                        b=j+1;
                    }
                }
        }
        for(int g=0;g<i;g++)
            if(v[g]>v[i])
                l++;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
