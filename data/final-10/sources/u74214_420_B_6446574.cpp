#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200000 + 200;

bool v[N];
int id[N];
char op[N];

int main() {
 //	freopen("in.txt", "r", stdin);
 //	freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int counter = 0;
    
    for(int i = 1; i <= m; i++) {
	
		cin>> op[i]>> id[i];
		
        if(!v[id[i]]) {
            v[id[i]] = true;
    
	        if(op[i] == '-') {
				counter ++;
            } 
        }
    
	}
    memset(v, false, sizeof(v));
    for(int i = 1; i <= m; i++) {
        if(op[i] == '-') {
			counter --;
            if(counter > 0) {
                v[id[i]] = true;
            } else if(i < m && id[i] != id[i + 1]) {
                v[id[i]] = true;
            }
        } else {
            if(counter > 0) {
                v[id[i]] = true;
            } else if(i > 1 && id[i] != id[i - 1]) {
                v[id[i]] = 1;
            }
            counter ++;
        }
    }
    int ret = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            ret++;
            ans.push_back(i);
        }
    }
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i ++)
		cout<<ans[i]<<' ';cout<<endl;
	/*
    printf("%d\n",ret);
    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            printf("%d ",i);
        }
    }
    if(ret > 0) puts("");*/
    return 0;
}
