/* team 220.  */

#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
  vec(double nx, double ny, double nz) :
	  x(nx), y(ny), z(nz)
  {
  }
};

int main()
{
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);

  int n;
  cin >> n;
  vector<int>Ar(n);

  int maxs = 0;
  for (int i = 0; i < n; i++)
  {
	  cin >> Ar[i];
	  if (Ar[i] > maxs)
		  maxs = Ar[i];
 }

  vector<int>Stolb(maxs);

  vector<vec>Res;

  for (int i = 0; i < n; i++)
  {
	  for (int j = 0; j < Ar[i]; j++)
		  if (Stolb[j] == 0)
		  {
			// std::cout << i + 1 << " " << j + 1 << endl;
			Stolb[j] = 1;
			Res.push_back(vec(i + 1, j + 1, 0));
			break;
		  }
  }

  std::cout << Res.size() << endl;

  for (int i = 0; i < int(Res.size()); i++)
	  std::cout << Res[i].x << " " << Res[i].y << endl;
  return 0;
}