#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pr(a) cout<<#a<<" = "<<(a)<<endl
#define cin(n) int (n); scanf("%d", &(n))
#define cin2(n,m) int (n),(m); scanf("%d%d",&(n),&(m))
#define sz(a) int((a).size())
#define all(a) a.begin(),a.end()
#define loop(x,a,b) for(int (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define prc(a) tr(a, it) cout<<*(it)<<" "; cout<<endl
#define pra(a,n) for(int i=0; i<(n); i++) printf("%d ",((a)[i])); printf("\n")
#define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cout<<a[i][j]<<" "; cout<<endl; } cout<<endl; 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) scanf("%d",&((a)[i])) 
#define vin(a,n) vector<int> (a); (a).resize((n)); for(int i=0; i<(n); i++) scanf("%d",&((a)[i])) 
#define md 1000000007

int es[1000],ee[1000],tt[1000];

int n,m,k,w;

int V;
char a[1001][11][11];
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}


int printMST(int parent[], int n2, int** graph)
{
    n2 = k;
    int sm = 0;
   for (int i = 1; i < V; i++){
      es[i] =  parent[i],ee[i] = i;
     if( graph[i][parent[i]]*w > n*m+w)
     {
        es[i] = -1;
        sm += n*m+w;
     }
     else
     {
        sm += graph[i][parent[i]]*w;
     }
    }

    cout<<sm+m*n+w-k*w<<endl;
}

void primMST(int** graph)
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     printMST(parent, V, graph);
}

int dif(int x,int y)
{

    int cnt = 0;
    rep(i,n)
        rep(j,m)
            if (a[x][i][j] == a[y][i][j])
                cnt += 1;
    return n*m-cnt+1;
}

int main()
{   
    rep(i,1000)
    {
        es[i] = -1;
        ee[i] = 0;
        tt[i] = 0;
    }
    scanf("%d%d%d%d",&n,&m,&k,&w);
    V = k;
    
    rep(i,k)
        rep(j,n)
            rep(l,m)
                cin>>a[i][j][l];

    int** da;
    da = (int**)calloc(k,sizeof(int*));
    rep(i,k)
        da[i] = (int*)calloc(k,sizeof(int));
    rep(i,k)
        rep(j,i)
            da[i][j] = da[j][i] = dif(i,j);

     primMST(da);

     int ct = 0;

     rep(i,k)
     {
        if(es[i] == -1)
        {
            printf("%d %d\n",ee[i]+1,es[i]+1);
            tt[i] = 1;
            ct += 1;
        }
     }
    while(ct < k)
    {
        rep(i,k)
        {
            if(tt[es[i]] == 1 and tt[i] == 0)
            {
                printf("%d %d\n",ee[i]+1,es[i]+1);
                tt[i] = 1;
                ct += 1;
        }
        }
    }

    return 0;
}

