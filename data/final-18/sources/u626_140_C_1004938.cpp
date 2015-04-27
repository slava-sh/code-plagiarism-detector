#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 
#include <map>  
#include <string>
#include <vector> 
#include <iostream>  
#include <sstream> 
#include <queue>
#include <algorithm>

using namespace std; 
 
long i,k,i2,i1,r,k1,j,m,l,n,i3,j10,j2,j3,a1,a2,v;  
long cas,s,c,t1,a,b,k2,d,t,ng,dmax,ta[1000010],b1;
long long zz,zzn;
char we[1000010];
pair<long,long> p1,p2,p3;
vector<pair<long,long> > vp,vp2;
vector<long> va;
priority_queue <pair<long,long> > pq;
#define SORT(a) 	sort(a.begin(),a.end())
#define CL(a,x)         memset(a,x,sizeof(a))
#define MP 		make_pair 
	


int main() {  
//	freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	//	int czas=clock(); 
	//pi=2*acos(0.0);
	 
	//while(1){
	cin>>n;
	va.clear();
	for(i=0;i<n;i++){
		cin>>k;
		va.push_back(k);
	}
	if(n<3)
		cout<<"0"<<endl;
	else {
		SORT(va);
		vp.clear();
		vp2.clear();
		i=0;
		p1=MP(va[0],1);
		p2=MP(-1,va[0]);
		//vp.push_back(p1);
		vp2.push_back(p2);
		i=1;
		while(i<n){
			if(va[i]==va[i-1]){
				//vp[vp.size()-1].second++;
				vp2[vp2.size()-1].first=vp2[vp2.size()-1].first-1;
			}
			else {
				p1=MP(va[i],1);
				p2=MP(-1,va[i]);
				//vp.push_back(p1);
				vp2.push_back(p2);
			}
			i++;
		}
		SORT(vp2);
		k=n/3;
		m=n;
		while(vp2[0].first<-k){
			i=0;
			a=0;
			while(vp2[i].first<-k&&i<vp2.size()){
				a+=-(vp2[i].first+k);
				vp2[i].first=-k;
				i++;
			}
			k=(m-a)/3;
			m-=a;
		}
		if(vp2.size()<3)
			cout<<"0"<<endl;
		else {
			cout<<k<<endl;
			for(i=0;i<vp2.size();i++){
				p1=MP(-vp2[i].first,vp2[i].second);
				//vp.push_back(p1);
				pq.push(p1);
			}
			
			while(!pq.empty()&&k>0){
			//for(i=vp.size()-1;i>=0&&k>0;i--){
				va.clear();
				p1=pq.top();
				va.push_back(p1.second);
				pq.pop();
				p2=pq.top();
				va.push_back(p2.second);
				pq.pop();
				p3=pq.top();
				va.push_back(p3.second);
				pq.pop();
				k--;
				if(p1.first>1){
					p1=MP(p1.first-1,p1.second);
					pq.push(p1);
				}
				if(p2.first>1){
					p2=MP(p2.first-1,p2.second);
					pq.push(p2);
				}
				if(p3.first>1){
					p3=MP(p3.first-1,p3.second);
					pq.push(p3);
				}
				SORT(va);
				cout<<va[2]<<" "<<va[1]<<" "<<va[0]<<endl;
			}

				
		}

	}


	//}
		
//	czas = clock() - czas;
//	printf("%lf\n",double(czas)/CLOCKS_PER_SEC);					

			
	return 0;

} 
