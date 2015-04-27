#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(), (c).end()
using namespace std;

int h,w;
int s[1212][1212];
char b[1212][1212];

//[a,c] x [b,d]
inline int rect(int a, int b, int c, int d){
    return s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1];
}

inline bool cont(int a, int b, int c, int d){
    return rect(a,b,c,d) == (c-a+1) * (d-b+1);
}

int main(){
    scanf("%d%d",&h,&w);
    rep(i,h) scanf("%s",b[i+1]+1);

    int p,q; p = q = -1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(p == -1 && b[i][j] == 'X'){
                p = i; q = j;
            }
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1] + (b[i][j]=='X');
        }
    }

    int X = s[h][w];

    const int DM = 1145141919;
    int res = DM;

    for(int i = 0; p+i <= h; i++){
        for(int j = 0; q+j <= w; j++){
            //[p,p+i] x [q,q+j] area : (i+1)*(j+1)
            //printf("(%d,%d) -- (%d,%d) : %d == %d\n",p,q,p+i,q+j, rect(p,q,p+i,q+j), (i+1)*(j+1));
            if(!cont(p,q,p+i,q+j)) continue;

            int area = (i+1) * (j+1);
            if(area > res) continue;

            int cnt = area;

            int y = p, x = q;
            while(true){
                bool down = cont(y+1,x,y+1+i,x+j);
                bool right = cont(y,x+1,y+i,x+1+j);
                //printf("(%d,%d) [stamps : %d x %d] right: %d down: %d\n",y,x,i+1,j+1, right, down);
                if(!(down ^ right)) break;
                if(down){
                    y++;
                    cnt += j+1;
                } else if(right){
                    x++;
                    cnt += i+1;
                } else assert(false);
            }

            if(cnt == X) res = min(res, area);
        }
    }
    printf("%d\n",res == DM ? -1 : res);
}

