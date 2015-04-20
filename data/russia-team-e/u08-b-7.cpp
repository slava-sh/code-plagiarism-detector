#include <stdio.h>
#include <iostream>
using namespace std;
int d[100000000];
int d1[100000000];
int r,n;
int s,c;
void rek(int kly){
	int answer;
if((s-d[kly])>r) c=c+1;
if(kly<n)rek(kly+1);
}
int main()
{
	int ans;
s=c=0;
	freopen("che.in","r", stdin);
	freopen("che.out","w", stdout);
	scanf("%d %d", &n, &r);


	for(int i=n; i>=1; i--){
		 scanf("%d",&d[i]);
	}

	for(register int i=1; i<n; i++){
		s=d[i];
		
		rek(i+1);
		
		}
		printf("%d", c);

		return 0;
}