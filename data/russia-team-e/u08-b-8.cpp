#include <stdio.h>
#include <iostream>
using namespace std;
long long d[100000000];
int d1[100000000];
long long r,n;
long long s,c;
void rek(long long kly){
	
if((s-d[kly])>r) c=c+1;
if(kly<n)rek(kly+1);
}
int main()
{
	
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
	/*freopen("che.in","w", stdout);
	cout<<300000<<" "<<2<<endl;
	for(register int i=2; i<600000; i+=2)cout<<i<<" ";
	*/
		return 0;
}