#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct FIO
{
  std::string N, Sn, O;
  bool Normal;

  FIO(std::string Str, std::string Str1, std::string Str2) : N(Str), Sn(Str1), O(Str2), Normal(false)
  {

  }

  bool operator<( FIO &A2 )
  {
    return N < A2.N;
  }
};

void main(void)
{
  std::vector<FIO> V;
  int n = 0;
  FILE *InF, *OutF;

  InF = fopen("names.in", "rt");
  OutF = fopen("names.out", "wt");

  fscanf(InF, "%d", &n);

  for (int i = 0; i < n; i++)
  {
    char Str[3][20];

    fscanf(InF, "%s ", Str[0]);
    fscanf(InF, "%s ", Str[1]);
    fscanf(InF, "%s ", Str[2]);

    V.push_back(FIO(std::string(Str[0]), std::string(Str[1]), std::string(Str[2])));
    for (int j = 0; j < i; j++)
    {
      if (V[j].Normal == true)
        continue;

      if (V[i].Sn == V[j].N)
      {
        std::swap(V[j].N, V[j].Sn);
        std::swap(V[j].N, V[j].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
      else if (V[i].N == V[j].N)
      {
        std::swap(V[i].N, V[i].Sn);
        std::swap(V[i].N, V[i].O);
        std::swap(V[j].N, V[j].Sn);
        std::swap(V[j].N, V[j].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
      else if (V[i].N == V[j].Sn)
      {
        std::swap(V[i].N, V[i].Sn);
        std::swap(V[i].N, V[i].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (V[i].Normal == true)
      continue;
    for (int j = 0; j < n; j++)
    {
      if (j == i)
        continue;

      if (V[i].Sn == V[j].N)
      {
        std::swap(V[j].N, V[j].Sn);
        std::swap(V[j].N, V[j].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
      else if (V[i].N == V[j].N)
      {
        std::swap(V[i].N, V[i].Sn);
        std::swap(V[i].N, V[i].O); 
        std::swap(V[j].N, V[j].Sn);
        std::swap(V[j].N, V[j].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
      else if (V[i].N == V[j].Sn)
      {
        std::swap(V[i].N, V[i].Sn);
        std::swap(V[i].N, V[i].O);
        V[j].Normal = true;
        V[i].Normal = true;
        break;
      }
    } 
  }

  std::sort(V.begin(), V.end());

  for (int i = 0; i < n; i++)
    fprintf(OutF, "%s %s %s\n", V[i].N.data(), V[i].Sn.data(), V[i].O.data());

  fclose(OutF);
  fclose(InF);
}