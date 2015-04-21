#include <iostream>
#include <cstdio>

using namespace std;

typedef long double ld;


struct pt{
    int x, y;
};

int get(pt a, pt b){

}

bool cw(pt a, pt b, pt c){
    ld xx = 1.0L * (b.x - a.x) * 1.0L * (c.y - a.y) / (b.y - a.y) + a.x;
    return c.x > xx;
}

bool intersect_easy(pt a1, pt b1, pt a2, pt b2){
    if(a2.x  >= b1.x || b2.x <= a1.x)
        return false;
    return true;
}

bool intersect_medium(pt a1, pt b1, pt a2, pt b2){
    if( (b1.x - a1.x) * 1LL * (a2.y - a1.y) == (a2.x - a1.x) * 1LL* (b1.y - a1.y) )
        return false;
    if( (b1.x - a1.x) * 1LL * (b2.y - a1.y) == (b2.x - a1.x) * 1LL* (b1.y - a1.y) )
        return false;
    return (cw(a1, a2, b1) && !cw(a1, b2, b1));
}

pt a[111][111];
int sz[111];

int main()
{
    int n;
    int l, r;
    scanf("%d%d", &l, &r);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &sz[i]);
        for(int j = 0; j <= sz[i]; ++j){
            scanf("%d%d", &a[i][j].x, &a[i][j].y);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            for(int l1 = 0; l1 < sz[i]; ++l1){
                for(int l2 = 0; l2 < sz[j]; ++l2){
                    if(intersect_easy(a[i][l1], a[i][l1 + 1], a[j][l2], a[j][l2 + 1]) && intersect_medium(a[i][l1], a[i][l1 + 1], a[j][l2], a[j][l2 + 1])){
                        puts("No");
                        printf("%d %d\n", i+1, j+1);
                        return 0;
                    }
                }
            }
        }
    }
    puts("Yes");
    return 0;
}
