#include<cstdio>
#include<set>
#include<vector>
using namespace std;
char a[100001];
int b[100001];
int init[100001];
bool on[100001];
int data;
int n,m;
int end;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		while(a[i]!='+'&&a[i]!='-'){
			scanf("%c",a+i);
		}
		scanf("%d",b+i);
		if(init[b[i]]==0){
			init[b[i]]=(a[i]=='+'?-1:1);
		}
	}
	int cnt=0;
	set<int> st;
	for(int i=1;i<=n;i++){
		if(init[i]==1){
			on[i]=true;
			st.insert(i);
			cnt++;
		}
	}
	if(cnt==0){
		on[b[0]]=true;
	}
	for(int i=0;i<m;i++){
		if(a[i]=='+'){
			cnt++;
			st.insert(b[i]);
			on[b[i]]&=true;
			if(cnt==1){
				
				if(end!=0 && end!=b[i]){
					on[end]=on[b[i]]=false;
				}
			}
		}else{
			cnt--;
			st.erase(b[i]);
			if(cnt!=0) on[b[i]]=false;
		}
		if(cnt==0) end=b[i];
	}
	vector<int> put;
	for(int i=1;i<=n;i++){
		if(on[i]||init[i]==0){
			put.push_back(i);
		}
	}
	printf("%d\n",put.size());
	int sz=put.size();
	for(int i=0;i<sz;i++){
		printf("%d ",put[i]);
	}
	return 0;
}