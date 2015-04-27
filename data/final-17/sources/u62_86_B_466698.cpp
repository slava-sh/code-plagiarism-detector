#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int n , m;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
char mark[1002][1002];
int deg[1002][1002];

int z;
int listx[101];
int listy[101];
bool ban[11];
bool solved[1001][1001];

bool isdigi(char c)
{
    return '0' <= c && c <= '9';
}

void solve(int x , int y)
{
    if(solved[x][y])return;
    solved[x][y] = true;
    z ++;
    listx[z] = x;
    listy[z] = y;
    for(int f = 0 ; f < 4 ; f++)
        if(mark[x + dx[f]][y + dy[f]] == '.')
        {
            deg[x + dx[f]][y + dy[f]] --;
            if(deg[x + dx[f]][y + dy[f]] == 0)
                solve(x + dx[f] , y + dy[f]);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m)
    {
        for(int i = 0 ; i <= n + 1 ; i++)
            for(int j = 0 ; j <= m + 1 ; j++)
                mark[i][j] = '#' , deg[i][j] = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            string s;
            cin >> s;
            s = " " + s;
            for(int j = 1 ; j <= m ; j++)
                mark[i][j] = s[j];
        }
        bool havedeg0 = false;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                if(mark[i][j] == '.')
                {
                    for(int f = 0 ; f < 4 ; f++)
                        if(mark[i+dx[f]][j+dy[f]] == '.')
                            deg[i][j] ++;
                    if(deg[i][j] == 0)
                        havedeg0 = true;
                }
        if(havedeg0)
            cout << "-1" << endl;
        else
        {
            memset(solved , 0 , sizeof(solved));
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= m ; j++)
                    if(mark[i][j] == '.')
                    {
                        z = 0;
                        if(mark[i][j+1] == '.')
                        {
                            solve(i , j);
                            solve(i , j+1);
                        }
                        else
                        {
                            solve(i , j);
                            solve(i+1 , j);
                        }
                        memset(ban , 0 , sizeof(ban));
                        for(int k = 1 ; k <= z ; k++)
                            for(int f = 0 ; f < 4 ; f++)
                                if(isdigi(mark[listx[k]+dx[f]][listy[k]+dy[f]]))
                                    ban[mark[listx[k]+dx[f]][listy[k]+dy[f]] - '0'] = true;
                        int now = 0;
                        while(ban[now])
                            now ++;
                        for(int k = 1 ; k <= z ; k++)
                            mark[listx[k]][listy[k]] = char(now + '0');
                        
                    }
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= m ; j++)
                {
                    cout << mark[i][j];
                    if(j == m)
                        cout << endl;
                }
        }
    }
    return 0;
}

/*
5 5
.....
.....
.....
.....
.....

*/
