/* team 220.  */
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
};

int main()
{
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  int n, m;
  int count_p = 0, count_v = 0;
  cin >> n >> m;

  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  
  /*
  vector<int> S;
  for (int i = 0; i < n; i++)
  {
	int x;
	cin >> x;
	if (x > l1 && x < r1 || 
		x > l2 && x < r2)
			S.push_back(x);
  }

  SHOWAR(Ar, 10);
  */
  int qp = 0, qv = 0, q = 0;
  ;
  for (int i = 0; i < n; i++)
  {
	  int x;
	  cin >> x;
	  if (x >= l1 && x <= r1 &&
		  x >= l2 && x <= r2)
			  q++;
	  else if (x >= l1 && x <= r1)
		  qp++;
	  else if (x >= l2 && x <= r2)
		  qv++;
  }

  int m1 = int(m / 2.0 + 0.5),m2 = m - m1;
  int res1 = std::min(m1, int(q / 2.0 + 0.5)), res2 = min(m2, q - res1);

  if (m1 - res1 > 0)
	  res1 += min(m1 - res1, qp);
  if (m2 - res2 > 0)
	  res2 += min(m2 - res2, qv);
  if (res1 > res2)
	  cout << "Petya" << endl;
  else if (res2 > res1)
	  cout << "Vasya" << endl;
  else
	  cout << "Draw" << endl;
	
  return 0;
}