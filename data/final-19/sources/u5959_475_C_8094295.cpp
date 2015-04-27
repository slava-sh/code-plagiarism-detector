#include <iostream>
using namespace std;
int n, m;
char st[2009][2009];
int sum[2009][2009];
int cnt;
int ssum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 -1] + sum[x1 - 1][y1 - 1];
}
int check(int i, int j, int si, int sj, int sssum = 0)
{
    //cout << i <<" "<< j << " " << si<<" " << sj << " " <<  sssum  << " "<< sum[n][m]<<endl;
    if(ssum(i, j, i + si - 1, sj + j - 1) == si * sj)
    {
        //cout <<"asdfffff" << endl;
        if(ssum(i + 1, j, i + si, sj + j - 1) == si * sj && ssum(i, j + 1, i + si - 1, sj + j) == si * sj)
            {
                //cout << "if1" << endl;
                return 0;
            }
        else
            if(ssum(i + 1, j, i + si, sj + j - 1) == si * sj)
            {

                //cout << "if2" << endl;
                return check(i + 1, j, si, sj, sssum + sj);
            }
        else
            if(ssum(i, j + 1, i + si - 1, sj + j) == si * sj)
            {

                //cout << "if3" << endl;
                return check(i, j + 1, si, sj, sssum + si);
            }
        else
        {
            //cout << sssum + si*sj << " " << sum[n][m] << endl;
            return (sssum + si*sj == sum[n][m]);

        }

    }
    else
    {
        //cout << "asdf" << endl;
        return 0;
    }
}
int ccheck(int &x, int &y)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        if(st[i][j] =='X')
            return x = i, y = j;
}
int main()
{
    int fix, fiy;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> st[i] + 1;
    }
    ccheck(fix, fiy);
    for(int i = 1; i <= 2 * n; i++)
    {
        for(int j = 1; j <= 2 * m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (st[i][j] == 'X');
    }
    int ans = (n + 1) * (m + 1);
    //cout << ans << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {

            if(ans <= i * j)
                continue;

            if(check(fix, fiy, i, j))
            {
                ans = min(ans, i * j);
                //cout << ans << endl;
            }
            //if(ans == 2)
                //cout << i <<" " <<  j<< endl;
        }
    }
    if(ans == (n + 1) * (m + 1))
        ans = -1;
    cout << ans << endl;
}
