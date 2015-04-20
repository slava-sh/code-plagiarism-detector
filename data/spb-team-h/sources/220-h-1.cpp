/* team 220.  */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
};

struct name
{
	string Str0, Str1, Str2;

	bool operator<( const name &N1 )
	{
		if (Str0 == N1.Str0)
			if (Str1 == N1.Str1)
				return Str2 < N1.Str2;
			else
				return Str1 < N1.Str1;

		return Str0 < N1.Str0;
	}
};

int main()
{
  freopen("names.in", "r", stdin);
  freopen("names.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<name> Strs(n);
  string Str0, Str1, Str2;

  for (int i = 0; i < n; i++)
	cin >> Strs[i].Str0 >> Strs[i].Str1 >> Strs[i].Str2;
  
  std::map <string, int> NameCnt;
  for (int i = 0; i < n; i++)
	  NameCnt[Strs[i].Str0]++,
	  NameCnt[Strs[i].Str1]++;

  for (std::map<string, int>::iterator It = NameCnt.begin();
	  It != NameCnt.end(); ++It)
  {
	  if ((*It).second > 1)
		  for (int j = 0; j < n; j++)
			  if (Strs[j].Str0 == (*It).first)
			  {
				swap(Strs[j].Str0, Strs[j].Str1);
				swap(Strs[j].Str0, Strs[j].Str2);
			  }
  }

  sort(Strs.begin(), Strs.end());
  for (int i = 0; i < n; i++)
	  std::cout << Strs[i].Str0 << " " << Strs[i].Str1 << " " << Strs[i].Str2 << endl;
  return 0;
}