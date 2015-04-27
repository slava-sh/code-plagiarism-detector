#include <cstdio> 
#include <iostream>
#include <cstring>
using namespace std;

const int p = 23917;
const int MAX = int(1e6);

unsigned long long has[MAX], has_last[MAX], pw[MAX]; 

unsigned long long len_has(int l, int r)
{
  if ( l == 0)
    return has[r];
  return has[r] - has[l - 1] * pw[r - l + 1];
}

unsigned long long len_has_last(int l, int r)
{
  
  if ( l == 0)
    return has_last[r];
  return has_last[r] - has_last[l - 1] * pw[r - l + 1];
}

char s[2 * int(1e5)];
int main()
{
  int n;
  freopen("inventory.in", "r", stdin);
  freopen("inventory.out", "w", stdout);
  pw[0] = 1;
  for ( int i = 1; i < int(1e5) * 2; i++)
    pw[i] = pw[i - 1] * p;
   
  cin >> n;
  for ( int ll = 0; ll < n; ll++)
  {
    gets(s);
    int o = strlen(s);
    for ( int i = 0; i < o; i++)
      s[i + o] = s[i];
    has[0] = s[0];
    for ( int i = 1; i < 2 * o; i++) 
      has[i] = has[i - 1] * p + s[i];
    has_last[0] = s[2 * o - 1];
    for ( int i = 1; i < o * 2; i++)
      has_last[i] = has_last[i - 1] * p + s[o * 2 - 1 - i];
    int flag = 0;
    for ( int i = 0; i < o + 1; i++)
    {
      if ( len_has( i, i + o - 1) == len_has_last( o - i, 2 * o - 1 - i ))
      {
        cout << i << endl; 
        flag = 1;
        break;
      }
    }
    if ( flag == 0)
      cout << "-1\n";
  }
  return 0;
}
