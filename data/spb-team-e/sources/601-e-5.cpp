#include <stdio.h>
#include <iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main ()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  int n, m, l1, r1, l2, r2, p = 0, v = 0, flag = 0, ob = 0, sump = 0, sumv = 0;
  cin >> n >> m >> l1 >> r1 >> l2 >> r2;

  for(int i = 0; i < n; i++)
  {
    int st;
    cin >> st;
    if(st <= r1 && st >= l1)
      p++;
    if(st <= r2 && st >= l2)
      v++;
    if(st <= r2 && st >= l2 && st <= r1 && st >= l1)
      ob++;
  }

  int flagp = 1, flagv = 1;

  for (int i = 0; i < m; i++)
  {
    if (flagp == 0 && flagv == 0)
    {
      if (sump > sumv)
        cout << "Petya";
      else if (sumv > sump)
        cout << "Vasya";
      else
        cout << "Draw";
      return 0;
    }

    if (flag == 0)
    {
      if (ob > 0)
      {
        sump++;
        ob--;
        p--;
        v--;
        flag = 1;
      }
      else if (p > 0)
      {
        sump++;
        p--;
        flag = 1;
      }
      else
      {
        flagp = 0;
        flag = 1;
      }
    }
    else
    {
      if (ob > 0)
      {
        sumv++;
        ob--;
        v--;
        p--;
        flag = 0;
      }
      else if (v > 0)
      {
        sumv++;
        v--;
        flag = 0;
      }
      else
      {
        flagv = 0;
        flag = 0;
      }
    }
  }

  if (sump > sumv)
        cout << "Petya";
      else if (sumv > sump)
        cout << "Vasya";
      else
        cout << "Draw";
  
  return 0;
}
