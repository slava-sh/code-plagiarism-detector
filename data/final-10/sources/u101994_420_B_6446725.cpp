#include <bits/stdc++.h>
using namespace std;
#define FREP(b) for(int i=0;i<b;i++)
#define REP(a,b,c) for(int a=b;a<c;a++)
#define asd(x) cout << "Here for " << #x << " :" <<x << endl;
#define asdf(x, y)  cout << "Here FOR " << #x << " :" << x << " " << #y  << " :" << y << endl;
typedef pair<int,int> ii;
typedef long long LL;
int n,q;
struct query{
    char c;
    int id;
} Q[100008];

const int MAX = 100008;
int flag[100008];
int ans[MAX], ans2[MAX];
void setup(){
    int alive = 0;
    char c ; int id;
    for(int i = q-1; i >=0 ; i--){
        c = Q[i].c, id = Q[i].id;
        //    asdf(c, id);
        if(c == '-'){
            flag[id] = 1;
            alive++;
        }
        else{
            if(flag[id]) flag[id] = 0, alive --;
            //          asdf(i, alive);
            if(alive){
                ans[Q[i].id] = true;
            }
        }
        //        asd(alive);
    }

    for(int i = 0; i < n; i++) ans2[i] = true;


    memset(flag, 0, sizeof flag);
    alive = 0;
//    printf("ans .. -> %d", ans[0]);
    for(int i = 0; i < q; i++){
        c = Q[i].c, id = Q[i].id;
        if(c == '+') flag[id] = 1, alive++;
        if(c == '-' && flag[id]) flag[id] = 0, alive--;
        if(c == '+') if(i!=0 || ans[id]){
  //          cout << "here.. " << id << endl;
            ans2[id] = false;
        }
        if(c == '-'){
         //   asdf(id, alive);
            if(i == q-1){
                if(alive){
    //                cout << "here..3 " << id << endl;
                    ans2[id] = false;
                }
                continue;
            }
            if(Q[i+1].c == '+' && Q[i+1].id == id){
                if(ans[id]){
      //              cout << "here4.. " << id << endl;
                    ans2[id] = false;
                }
                else i++;
            }
            else{
        //        cout << "here.5. " << id << endl;
                ans2[id] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> q; 

    FREP(q){
        cin >> Q[i].c >> Q[i].id;
        Q[i].id--;
    }
    setup();
    int a = 0;
    for(int i = 0; i < n; i++){
        if(ans2[i]) a++;
    }
    cout << a << endl;
    for(int i = 0; i < n; i++) if(ans2[i]) cout << i+1 << " ";
    if(a) cout << endl;
    return 0;
}

