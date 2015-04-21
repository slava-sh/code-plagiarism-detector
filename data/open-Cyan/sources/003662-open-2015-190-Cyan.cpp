#include <iostream>
#include <vector>

using namespace std;

struct ch
{
    int a,b;
};

int main()
{
    int k,f,n;
    cin>>k>>f>>n;
    vector<vector<ch> >v(n,vector<ch>(401));
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        for(int j=0;j<=l;j++)
            cin>>v[i][j].a>>v[i][j].b;
    }
    int ind=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            int a=0;
            int b=0;
            int x=0;
            if(v[i][0].b>v[j][0].b)
                x=1;
            else
                if(v[i][0].b<v[j][0].b)
                    x=2;
            int t=k;
            while(ind==0&&v[i][a].a!=f&&v[j][b].a!=f)
            {
                if(v[i][a+1].a>v[j][b+1].a)
                {
                    b++;
                    t=v[j][b].a;
                }
                else
                    if(v[i][a+1].a<v[j][b+1].a)
                    {
                        a++;
                        t=v[i][a].a;
                    }
                    else
                    {
                        t=v[i][a].a;
                        a++;
                        b++;
                    }
                int y=0;
                if(v[i][a].a==v[j][b].a)
                {
                    if(v[i][a].b>v[j][b].b)
                        y=1;
                    else
                        if(v[i][a].b<v[j][b].b)
                            y=2;
                }
                else
                    if(v[i][a].a==t)
                    {
                        long long q=v[i][a].b-v[j][b].b;
                        q=q*(v[j][b+1].a-v[j][b].a);
                        long long w=v[j][b+1].b-v[j][b].b;
                        w=w*(v[i][a].a-v[j][b].a);
                        if(q>w)
                            y=1;
                        else
                            if(q<w)
                                y=2;
                    }
                    else
                    {
                        long long q=v[j][b].b-v[i][a].b;
                        q=q*(v[i][a+1].a-v[i][a].a);
                        long long w=v[i][a+1].b-v[i][a].b;
                        w=w*(v[j][b].a-v[i][a].a);
                        if(q>w)
                            y=2;
                        else
                            if(q<w)
                                y=1;
                    }
                if(x==1)
                {
                    if(y==2)
                        ind=1;
                }
                else
                    if(x==2)
                    {
                        if(y==1)
                            ind=1;
                    }
                    else
                        x=y;
            }
            if(ind==1)
            {
                k=i;
                f=j;
            }
        }
    if(ind==1)
        cout<<"No"<<endl<<k+1<<" "<<f+1<<endl;
    else
        cout<<"Yes";
    return 0;
}
