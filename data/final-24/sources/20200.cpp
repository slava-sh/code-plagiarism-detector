#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
          
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int l, n;
  cin >> l;
  string s;
  cin >> s;
  n = s.size();
  int flaga = 0, flagb = 0, flagc = 0;

  if (l >= n)
  {
    cout << "1" << endl;
    cout << s << endl;
    return 0;
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a')
      flaga = 1;
    if (s[i] == 'b')
      flagb = 1;
    if (s[i] == 'c')
      flagc = 1;
  }


  if ((l <= 10 && n <= 100) || (flaga == 1 && flagb == 1 && flagc == 0 && l <= 500 && n <= 1000))
  {
  
    for (int i = 1; i <= l; i++)
    {
      int flag = 0;
      string s1 = "";
      if (n % i == 0)
      {
        for (int j = 0; j < i; j++)
          s1 += s[j];
        for (int k = 0; k < n / i - 1; k++)
        {
          string s2 = "";
          for (int j = (k + 1) * i; j < (k + 1) * i + i; j++)
          {
            s2 += s[j];
            //cout << j << " " << n << endl;
          }
          if (s1 != s2)
          {
            flag = 1;
          }        
        }
        if (flag == 0)
        {
          cout << "1" << endl;
          cout << s1 << endl;
          return 0;
        }
      }     
    }

    cout << "2" << endl;
    cout << "a" << endl << "b" << endl;
  }
  else if (flagb == 1 && flagc == 1 && flaga == 0 && l <= 500 && n <= 1000)
  {
    for (int i = 1; i <= l; i++)
    {
      int flag = 0;
      string s1 = "";
      if (n % i == 0)
      {
        for (int j = 0; j < i; j++)
          s1 += s[j];
        for (int k = 0; k < n / i - 1; k++)
        {
          string s2 = "";
          for (int j = (k + 1) * i; j < (k + 1) * i + i; j++)
          {
            s2 += s[j];
            //cout << j << " " << n << endl;
          }
          if (s1 != s2)
          {
            flag = 1;
          }        
        }
        if (flag == 0)
        {
          cout << "1" << endl;
          cout << s1 << endl;
          return 0;
        }
      }     
    }

    cout << "2" << endl;
    cout << "b" << endl << "c" << endl;
  }
  else if (flaga == 1 && flagc == 1 && flagb == 0 && l <= 500 && n <= 1000)
  {
     for (int i = 1; i <= l; i++)
    {
      int flag = 0;
      string s1 = "";
      if (n % i == 0)
      {
        for (int j = 0; j < i; j++)
          s1 += s[j];
        for (int k = 0; k < n / i - 1; k++)
        {
          string s2 = "";
          for (int j = (k + 1) * i; j < (k + 1) * i + i; j++)
          {
            s2 += s[j];
            //cout << j << " " << n << endl;
          }
          if (s1 != s2)
          {
            flag = 1;
          }        
        }
        if (flag == 0)
        {
          cout << "1" << endl;
          cout << s1 << endl;
          return 0;
        }
      }       
    }

    cout << "2" << endl << "a" << endl << "c" << endl;
  }  
  else
  {
    if (flaga == 1 && flagb == 1 && flagc == 1)
      cout << "3" << endl << "a" << endl << "b" << endl << "c" << endl;
    else if (flaga == 1 && flagb == 0 && flagc == 0)      
      cout << "1" << endl << "a" << endl;
    else if (flagb == 1 && flaga == 0 && flagc == 0)      
      cout << "1" << endl << "b" << endl;
    else if (flagc == 1 && flagb == 0 && flaga == 0)      
      cout << "1" << endl << "c" << endl;
    else if (flaga == 1 && flagb == 1 && flagc == 0)
      cout << "2" << endl << "a" << endl << "b" << endl;
    else if (flaga == 1 && flagc == 1 && flagb == 0)
      cout << "2" << endl << "a" << endl << "c" << endl;
    else if (flagb == 1 && flagc == 1 && flaga == 0)
      cout << "2" << endl << "b" << endl << "c" << endl;  
  }
         
  return 0;
}
