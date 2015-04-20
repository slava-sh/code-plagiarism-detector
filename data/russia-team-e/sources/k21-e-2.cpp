#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <deque>

#define goo(i,k,n) for(int i=k;i<n;i++)
#define go(i,n) goo(i,0,n)
#define ll long long
#define f first
#define s second

using namespace std;
ll m, n, k;
string str, ss,c,  numb[10005];
pair<string, int> st[10005];

int main(){
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	cin>>n;
	go(i,n){
		cin>>c>>k;
		go(j,k){
			cin>>ss;
			st[m].f = (c+ss);
			st[m].s =c.size();
			m++;
		}
	}
	ll nn;
	cin>>nn;
	go(i,nn){
		cin>>str;
		bool trrr=0;
		go(j,m){
			bool tr=0;
			string h=st[j].f;
			ll w=h.size();
			go(ii, w)
				if(h[ii]!=str[ii]){
					tr=1;
					break;
				}
			
			if(!tr){
				bool trr=0;
				if(str[w] != '0'){
					string p="+";
					for(int q=0;q<st[j].s;q++)
						p+=h[q];
					p+='(';
					for(int q=st[j].s;q<w;q++)
						p+=h[q];
					p+=')';
					ll len=11-w;
					if(len == 3)
						for(int q=w;q<11;q++)
							p+=(str[q]);
					if(len == 4){
						for(int q=w; q<w+2;q++)
							p+=str[q];
						p+='-';
						for(int q=w+2;q<11;q++)	
							p+=str[q];
					}
					if(len == 5){
						for(int q=w; q<w+3;q++)
							p+=str[q];
						p+='-';
						for(int q=w+3;q<11;q++)	
							p+=str[q];						
					}
					if(len == 6){
						for(int q=w; q<w+2;q++)
							p+=str[q];
						p+='-';
						for(int q=w+2;q<w+4;q++)	
							p+=str[q];
						p+='-';
						for(int q=w+4;q<11;q++)
							p+=str[q];				
					}
					if(len == 7){
						for(int q=w; q<w+3;q++)
							p+=str[q];
						p+='-';
						for(int q=w+3;q<w+5;q++)	
							p+=str[q];
						p+='-';
						for(int q=w+5;q<11;q++)
							p+=str[q];				
					}
					cout<<p<<"\n";
					cout.flush();
					trr=1;
					trrr=1;
					break;					
					
				}
				if(!trr){
					cout<<"Incorrect\n";
					cout.flush();
					trrr=1;
				}

			}
		}
		if(!trrr){
			cout<<"Incorrect\n";
			cout.flush();
		}
			
	}



	return 0;
}




