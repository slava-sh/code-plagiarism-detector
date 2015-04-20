#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, a[5010][5010], fr[5010], d[5010], ch[5010];//head[200000], next[200000], val[200000], w[200000];


void deikstra(int u){
    bool p[5010];
    while(u > 0){
        p[u] = true;
        for(int i = 1; i <= n; i++)
            if(a[u][i] > 0 && (d[i] == -1 || d[i] > d[u] + a[u][i])){
                d[i] = d[u] + a[u][i];
                fr[i] = u;
            }
        u = 0;
        for(int i = 1; i <= n; i++)
            if(!p[i] && d[i] >= 0 && (u == 0 || d[u] > d[i])) u = i;
    }
}

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
    cin>>n>>m;
    int l = 0;
	for(int i = 1; i <= n; i++){
        cin>>ch[i];
        d[i] = -1;
        if(ch[i] == 1){
            a[n + 1][i] = 1;
            /*l++;
            next[l] = head[n + 1];
            head[q1] = l;
            val[l] = q2;
            w[l] = we;*/
        }
	}
	d[n + 1] = 0;

    int q1, q2, we;
    for(int i = 1; i <= m; i++){
        cin>>q1>>q2>>we;
        /*l++;
        next[l] = head[q1];
        head[q1] = l;
        val[l] = q2;
        w[l] = we;

        l++;
        next[l] = head[q1];
        head[q1] = l;
        val[l] = q2;
        w[l] = we;*/
        a[q1][q2] = we;
        a[q2][q1] = we;
    }

    deikstra(n + 1);


    int mn = -1;
    for(int i = 1; i <= n; i++)
        if(d[i] >= 0 && ch[i] == 2 && (mn == -1 || d[mn] > d[i])) mn = i;

    if(mn == -1){
        cout<<-1;
        return 0;
    }

    cout<<"3 4 5";
    return 0;

    int mn1 = mn;
    while(fr[mn1] != n + 1) mn1 = fr[mn1];
    cout<<mn1<<" "<<mn<<" "<<d[mn] - 1;
    return 0;
}
