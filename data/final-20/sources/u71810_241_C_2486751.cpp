#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define E 0.0001

int cnt[2];
struct MirrorData{
    int val;
    int left;
    int right;
}mir[2][120];

int hl, hr, n, ans;

void ReadData (void){
    char str[10];
    cin >> hl >> hr >> n;
    int a, b, c, f;
    cnt[0] = cnt[1] = 0;
    for (int i=1 ;i<=n ;i++){
        scanf ("%d%s%d%d",&a,str,&b,&c);
        f = (str[0] == 'F');
        cnt[f]++;
        mir[f][cnt[f]].val = a;
        mir[f][cnt[f]].left = b;
        mir[f][cnt[f]].right = c;
    }
    //Sort
    for (int t=0 ;t<=1 ;t++){
        for (int i=1 ;i<=n ;i++){
            for (int j=1 ;j<i ;j++){
                if (mir[t][j].left < mir[t][j+1].left){
                    swap (mir[t][j], mir[t][j+1]);
                }
            }
        }
    }
    return ;
}
int TwoSearch (int cl, int cr, int oppo, int wall){
    int h1, h2;
    h1 = hl + 100*cl;
    if (oppo)
        h2 = (100-hr) + 100*cr;
    else
        h2 = hr + 100*cr;
    double hh = 1.0*h1/(h1+h2)*100000;
    //printf ("%d,%d,%lf\n",h1,h2,hh);
    for (int i=1 ;i<=cnt[wall] ;i++){
        if (mir[wall][i].left <= hh+E && hh-E <= mir[wall][i].right)
            return i;
    }
    return -1;
}
void ManageData (int k){
    int temp, loc, wall;
    int lastloc[2];
    bool fff;
    for (int i=1 ;i<=n ;i++){
        //printf ("%d\n",i);
        temp = 0, lastloc[0] = lastloc[1] = -1, fff = true;
        for (int j=1 ;j<=i ;j++){
            wall = k^(j%2);
            loc = TwoSearch (j-1, i-j, 1-i%2, wall);
            //printf ("%d(%d:%d,%d)\n",loc,mir[wall][loc].val,mir[wall][loc].left,mir[wall][loc].right);
            if (loc == -1 || lastloc[wall^1] == loc){
                fff = false;
                break;
            }
            temp += mir[wall][loc].val;
            lastloc[wall^1] = loc;
        }
        if (fff)
            ans = max (ans, temp);
    }
    return ;
}
int main (){
    ans = 0;
    ReadData ();
    ManageData(0);
    hl = 100-hl;hr = 100-hr;
    ManageData(1);
    cout << ans << endl;
    return 0;
}
