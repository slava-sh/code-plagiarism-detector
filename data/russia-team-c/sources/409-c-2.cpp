#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool was[210000];

int v0,u0,n;

vector< int > way;

vector< int > edges[210000];

int fmax[210000];
int fmax1[210000];
int arr[210000];

bool DFS(int v)
{
    was[v]=true;
    way.push_back(v);
    if (v==u0)
    {
        return true;
    }
    for (int i=0;i<edges[v].size();i++)
    {
        int po=edges[v][i];
        if (!was[po])
        {
            if (DFS(po))
            {
                return true;
            }
        }
    }
    was[v]=false;
    way.pop_back();
    return false;
}

int  DFS1(int v)
{
    was[v]=true;
    int maxx=0;
    for (int i=0;i<edges[v].size();i++)
    {
        int po=edges[v][i];
        if (!was[po])
        {
            maxx=max(maxx,DFS1(po));
        }
    }
    return maxx+1;
}


int main()
{
    freopen("dwarfs.in", "r", stdin);
    freopen("dwarfs.out", "w", stdout);
    scanf("%d",&n);
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    scanf("%d %d",&v0,&u0);
    DFS(v0);
    int ws=way.size();
    for (int i=0;i<ws;i++)
    {
        arr[i]=DFS1(way[i]);
      //  cout<<arr[i]<<" ";
    }
    fmax[ws-1]=arr[ws-1];
    for (int i=ws-2;i>=0;i--)
    {
        fmax[i]=max(fmax[i+1],arr[i]+ws-i-1);
    }
    fmax1[0]=arr[0];
    for (int i=1;i<ws;i++)
    {
        fmax1[i]=max(fmax1[i-1],arr[i]+i);
    }
    int maxx=min(fmax1[0],fmax[1]);
    //cout<<maxx<<" "<<fmax1[0]<<" "<<fmax[1];
    for (int i=1;i<ws-1;i++)
    {
        maxx=max(min(fmax1[i],fmax[i+1]),maxx);
    }
    printf("%d",maxx);
    return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

18
1 2
2 3
3 4
4 5
1 6
1 7
2 8
2 9
8 10
8 11
3 12
12 13
13 14
14 15
5 16
16 17
17 18
1 5
*/
