#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;
int main()
{
    int n;
    int k ;
    string s , s1 , f , q;
    map<pair<string,string> ,bool > a;
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    cin >> n;
    while(n--)
    {
    cin >> s >> k;
    for(int i = 0 ; i < k ; i ++)
    {
    cin >> s1;
    a[pair<string,string>(s,s1)] = true;
    }
    }
    cin >> k;
    for(int i = 0 ; i < k ; i ++)
    {
            cin >> s;
            int l = -1;
            f = "";
            for(int i = 0 ; i <= 2 ; i ++){
                  l = -1;
                  f += s[i];
                  q = "";
                  for(int j = 1; j <= 2 ;j ++)
                  q += s[j+i];
                  for(int j = 0; j <= 2 ; j ++){
                  q += s[j+i+3];
                  if(a[pair<string,string>(f,q)]&& s[j+i+4] != '0'){                    
                                                      l = i + 3 + j;break;} 
                  }
                  
                  if(l != -1){
                       int t = 0;
                       bool tima = false;
                       cout << "+"<<f<<"("<<q<<")";
                       if((10-l)%2)
                       {for(++l; t < 3 ;t ++, l ++)
                        putchar(s[l]);
                        tima = true;
                        }else l++;
                        for(int t = l ; t < 11 ; t += 2)
                        {if(tima){putchar('-');tima = false;}
                                printf("%c%c",s[t],s[t+1]);
                        if(t + 2 < 11) putchar('-'); 
                        }
                        break;}
                  }
          if(l == -1)puts("Incorrect");
          else puts("");
          }
    

    getchar();getchar();
}


