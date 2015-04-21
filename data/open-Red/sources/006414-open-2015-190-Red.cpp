#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int fabs(int a)
{
    if(a<0)
        a=0-a;
    return a;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n,m,d;
    fin>>n>>m>>d;
    vector<int>v(m);
    vector<vector<int> >w(m,vector<int>(3));
    for(int i=0;i<m;i++)
        fin>>w[i][0]>>w[i][1]>>w[i][2];
    int r;
    fin>>r;
    queue<int>q;
    while(r!=0)
    {
        r--;
        int a,b;
        fin>>a>>b;
        for(int i=0;i<m;i++)
            v[i]=0;
        int ind=0;
        for(int i=0;i<m;i++)
            if(w[i][0]==a)
            {
                v[i]++;
                q.push(w[i][1]);
                q.push(w[i][2]);
                if(w[i][1]==b)
                {
                    ind=1;
                    i=m;
                }
                q.push(1);
            }
            else
                if(w[i][1]==a)
                {
                    v[i]++;
                    q.push(w[i][0]);
                    q.push(w[i][2]);
                    if(w[i][0]==b)
                    {
                        ind=1;
                        i=m;
                    }
                    q.push(1);
                }
        while(!q.empty()&&ind==0)
        {
            int a1=q.front();
            q.pop();
            int a2=q.front();
            q.pop();
            int a3=q.front();
            q.pop();
            for(int i=0;i<m;i++)
                if(v[i]<=2&&w[i][0]==a1&&fabs(a2-w[i][2])<=d)
                {
                    v[i]++;
                    q.push(w[i][1]);
                    q.push(w[i][2]);
                    if(w[i][1]==b)
                    {
                        ind=a3+1;
                        i=m;
                    }
                    q.push(a3+1);
                }
                else
                    if(v[i]<=2&&w[i][1]==a1&&fabs(a2-w[i][2])<=d)
                    {
                        v[i]++;
                        q.push(w[i][0]);
                        q.push(w[i][2]);
                        if(w[i][0]==b)
                        {
                            ind=a3+1;
                            i=m;
                        }
                        q.push(a3+1);
                    }
        }
        while(!q.empty())
            q.pop();
        if(ind==0)
            fout<<"-1"<<endl;
        else
            fout<<ind<<endl;
    }
    return 0;
}
