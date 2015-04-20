#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int col1 = 0, col2 = 0, col3 = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if((a >= l1) && (a <= r1))
        {
            if((a >= l2) && (a <= r2))
                col3++;
            else
                col1++;
        }
        else if((a >= l2) && (a <= r2))
            col2++;
    }
    if(col3 >= m)
    {
        if(m % 2 == 0)
            cout << "Draw";
        else
            cout << "Petya";
    }
    else
    {
        int colp = (col3 + 1) / 2;
        int colv = col3 / 2;
        int col = col3;
        while(col < m)
        {
            if(col % 2 == 1)
                if(colv - (col3 / 2) < col2)
                    colv++;
            if(col % 2 == 0)
                if(colp - ((col3 + 1) / 2) < col1)
                    colp++;
            col++;
        }
        if(colp > colv)
            cout << "Petya";
        else if(colp < colv)
            cout << "Vasya";
        else
            cout << "Draw";
    }
    return 0;
}
