#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:100000000")

#define mp make_pair
#define pb push_back 
#define ll long long
#define sz(x) (int)(x).size()

int a[200200];

int x[200200][2];

bool ok[200200];

int main()
{
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int m, k;
        scanf("%d %d", &m, &k);
        for(int i = 1; i <= k; i++) scanf("%d", &a[i]);
        int un = 0;
        bool f = false;
        int first = -1;
        for(int i = 0; i < m - 1; i++) {
            scanf("%d %d", &x[i][0], &x[i][1]);
        }
        for(int j = 1; j <= k; j++) ok[j] = false;
        for(int i = 0; i < m - 1; i++) {
            int t = x[i][0];
            int r = x[i][1];
            if(t != 0) {
                if(r == 0) { // получил t, которое и просил
                    a[t]--;
                    if(a[t] == 0) first = t;
                }
                else { // получил t нужного не было
                    if(first == -1) { 
                        for(int j = i; j < m - 1; j++) {
                            int tt = x[j][0];
                            int rr = x[j][1];
                            if(tt != 0) ok[tt] = true; // значит оно еще выдавалось
                        }
                        int mini = 1e9;
                        for(int j = 1; j <= k; j++) {
                            if(ok[j]) ok[j] = false;
                            else if(!ok[j] && a[j] <= un) ok[j] = true, mini = min(mini, a[j]), first = j;
                        }
                        un -= mini;
                    }
                    a[t]--;
                    if(a[t] == 0) first = t;
                }
            }
            else {
                if(r == 0) { // получил неизвестное, которое и просил
                    un++;
                }
                else { // получил неизвестный, нужного не было
                    if(first == -1) {
                        for(int j = i; j < m - 1; j++) {
                            int tt = x[j][0];
                            int rr = x[j][1];
                            if(tt != 0) ok[tt] = true; // значит оно еще выдавалось
                        }
                        int mini = 1e9;
                        for(int j = 1; j <= k; j++) {
                            if(ok[j]) ok[j] = false;
                            else if(!ok[j] && a[j] <= un) ok[j] = true, mini = min(mini, a[j]), first = j;
                        }
                        un -= mini;
                    }
                    un++;
                }
            }
        }
        for(int i = 1; i <= k; i++) {
            if(a[i] - un <= 0 || ok[i]) printf("Y");
            else printf("N");
        }
        printf("\n");
    }

    return 0;
}