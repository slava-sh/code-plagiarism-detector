#include <bits/stdc++.h>
using namespace std;

bool appear[100010];

bool on[100010];
int _time[100010];

bool bad[100010];

struct event{ int z,id; };

vector<event> in;
vector<event> comp;

int main() {
    int n,m;
    scanf("%d%d\n",&n,&m);

    char c; int d;
    vector<int> prv;
    for(int i = 0; i < m; i++){
        scanf("%c %d\n",&c,&d); d--;
        appear[d] = true;
        if(c == '-'){
            if(!on[d]) prv.push_back(d);
            on[d] = false;
        }
        if(c == '+'){
            on[d] = true;
            _time[d] = i;
        }
        in.push_back({c == '+' ? 1 : -1, d});
    }

    for(auto it = prv.rbegin(); it != prv.rend(); it++){
        comp.push_back({1,*it});
    }

    for(auto pp : in){
        comp.push_back(pp);
    }

    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        if(on[i]){
            vp.push_back({-_time[i],i});
        }
    }
 //           comp.push_back({-1,i});
    sort(begin(vp),end(vp));
    for(int i = 0; i < vp.size(); i++){
        comp.push_back({-1,vp[i].second});
    }

    int cnt = 0;
    vector<int> ap;
    int leader = -1;
    for(auto pp : comp){
        //cout << pp.z << " " << pp.id+1 << endl;
        if(pp.z == 1){
            if(cnt != 0) bad[pp.id] = true;
            cnt++;
        } else {
            cnt--;
            if(cnt != 0) bad[pp.id] = true;
            if(cnt == 0){
                if(leader >= 0 && pp.id != leader){
                    leader = -2;
                } else if(leader == -1){
                    leader = pp.id;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!appear[i]) ans++;
        else if(!bad[i] && i == leader) ans++;
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(!appear[i] ||(!bad[i] && i == leader)) printf("%d ",i+1);
    }
    puts("");
}
