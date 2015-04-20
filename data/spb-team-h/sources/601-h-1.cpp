#include <stdio.h>
#include <iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map <string, int> m;

struct fio {
  string f;
  string i;
  string o;
};

bool comp (fio a, fio b)
{
  return a.f < b.f;
}

fio per[1001];

int main ()
{
  freopen("names.in", "r", stdin);
  freopen("names.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> per[i].f;
    cin >> per[i].i;
    cin >> per[i].o;
    m[per[i].f]++;
    m[per[i].i]++;
    m[per[i].o]++;
  }

  for (int i = 0; i < n; i++)
  {
    if (m[per[i].f] > 1)
    {
      string fam, im, ot;
      fam = per[i].o;
      im = per[i].f;
      ot = per[i].i;
      per[i].f = fam;
      per[i].i = im;
      per[i].o = ot;
    }
  }
                         
  sort(per, per + n, comp);

  for (int i = 0; i < n; i++)
    cout << per[i].f << " " << per[i].i << " " << per[i].o << endl;
  return 0;
}