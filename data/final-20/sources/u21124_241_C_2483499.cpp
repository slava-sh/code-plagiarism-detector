#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int N = 105;
struct node{int l,r,val;
	node(){}
	node(int _l,int _r,int _v) :l(_l),r(_r),val(_v){}
} flr[N],cel[N];
const int W= (int)1e5;
const int H = 100;
int hl,hr,n;
int visf[N],visc[N];
long long crs(int x1,int y1,int x2,int y2){
	long long val = 1LL*x1*y2 - 1LL*x2*y1;
	if(val==0) return 0; else if(val>0) return 1; else return -1;
}
int chk(node num[],int len,int y,int h,int vis[]){
	int x1 = W, y1 = y - hl;
	for(int i = 0; i < len; i++){
		int x2 = num[i].l, x3 = num[i].r;
		if(crs(x1,y1,x2,h-hl)*crs(x1,y1,x3,h-hl)<=0) {
			if(vis[i]) return -1;
			vis[i] = 1;
			return num[i].val;
		}
	}
	return -1;
}
int main(){
	cin >> hl >> hr >> n;
	int la = 0, lb = 0;
	for(int i = 0; i < n; i++){
		int v,l,r; char ch[3];
		cin >> v>>ch>>l>>r;
		if(ch[0]=='F') flr[la++] = node(l,r,v);
		else cel[lb++] = node(l,r,v);
	}
	int ans = 0;
	for(int i = 1; i <= n;i ++){
		int h = -i*H ;
		if(~i&1) h += hr;
		else h += H - hr;
		int sum = 0,v;
		memset(visf,0,sizeof(visf));
		memset(visc,0,sizeof(visc));
		for(int j = 1; j <= i; j++) {
			if(j&1) {
				v = chk(flr,la,h,H - j*H,visf);
			} else v = chk(cel,lb,h,H-j*H,visc);
			if(v == -1) break;
			else sum += v;	
		}
		if(v == -1) continue;
		else ans = max(ans,sum);
	}
//	cout<<ans<<endl;
	for(int i = 1; i <= n; i++){
		int h = i*H;
		if(~i&1) h += hr;
		else h += H - hr;
		int sum = 0,v;
		memset(visf,0,sizeof(visf));
		memset(visc,0,sizeof(visc));
		for(int j = 1; j<= i; j++) {
			if(j&1) v = chk(cel,lb,h,j*H,visc);
			else v = chk(flr,la,h,j*H,visf);
			//cout<<"j: "<<j<<" "<<v<<endl;
			if(v == -1) break;
			else sum += v;
		}
		//cout<<sum<<endl;
		if(v == -1) continue;
		else ans = max(ans,sum);
	}
	cout << ans << endl;
}
