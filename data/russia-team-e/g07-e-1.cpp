#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>

#define LL long long

using namespace std;

string rets(LL p)
 {
  string ret;
  ret.clear();
  while (p > 0) ret+=('0'+p%10),p/=10;
  reverse(ret.begin(),ret.end());
  return ret; 
 }

LL reti(string p,int sta,int en)
 {
  LL ret=0;
  for (int i=sta;i<=en;i++)
   ret=ret*10+p[i]-'0';
  return ret;
 }

vector <LL> g[2000];
LL n,c,i,k,m,o,e,ne,pe,a,j;
bool may;
string s;

bool search(LL sta,LL whi)
 {
  int l=0;
  int r=g[sta].size()-1;
  int M=0;
  while (l+1 < r)
   {
    M=(l+r)/2;
    if (g[sta][M] == whi) return true;
    if (g[sta][M] > whi) r=M-1;
    if (g[sta][M] < whi) l=M+1;
   }
  if (l < g[sta].size() && g[sta][l] == whi) return true;
  if (r >= 0 && g[sta][r] == whi) return true;
  return false;
 }

void print(string s,int l)
 {
  if (s.size() -l == 3)
   {
    for (int i=l;i<s.size();i++)
     cout<<s[i];
    cout<<endl;
    return;
   }
  if (s.size()- l == 4)
   {
    for (int i=l;i<l+2;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+2;i<s.size();i++) cout<<s[i];
    cout<<endl;
    return ;
   }
  if (s.size()-l == 5)
   {
    for (int i=l;i<l+3;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+3;i<s.size();i++) cout<<s[i];
    cout<<endl;
    return ;
   }
  if (s.size()-l == 6)
   {
    for (int i=l;i<l+2;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+2;i<l+4;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+4;i<s.size();i++) cout<<s[i];
    cout<<endl;
    return ;
   }
  if (s.size()-l == 7)
   {
    for (int i=l;i<l+3;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+3;i<l+5;i++) cout<<s[i];
    cout<<"-";
    for (int i=l+5;i<s.size();i++) cout<<s[i];
    cout<<endl;
    return ;
   }
 }

main ()
 {
  freopen("numbers.in","r",stdin);
  freopen("numbers.out","w",stdout);
 cin>>n;
 for (i=1;i<=n;i++)
  {
   cin>>c>>k;
   for (j=1;j<=k;j++)
    {
     cin>>a;
     g[c].push_back(a);
    }
  }
  for (i=1;i<=999;i++)
   sort(g[i].begin(),g[i].end());
  cin>>m;
  while (m--)
   {
    cin>>s;
    may=false;
    for (o=0;o<=2;o++)
     if (!may && s[0] != '0' && s[o+1] != '0')
     {
      ne=reti(s,0,o);
      if (g[ne].size() == 0) continue;
      for (e=o+3;e<=o+5;e++)
       if (s[e+1] != '0' && !may) 
        {
         pe=reti(s,o+1,e);
         if (!may && search(ne,pe))
          {
           cout<<"+"<<ne<<"("<<pe<<")";
           print(s,e+1);
           may=true;
          }
        }
     }
    if (!may) cout<<"Incorrect"<<endl;
   }
 }
     
