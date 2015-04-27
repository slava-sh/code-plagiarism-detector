#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

int mark[1002][1002];
int area[1002][1002]; // 1 is usable
char res[1002][1002];
int total_area;
int fy, fx;
int n, m;

void fill_area(vector<pair<int, int> > P)
{
  int sz = P.size();
  int unusable[10] = {0};
  for (int i=0; i<sz; i++) {
    int y = P[i].first, x = P[i].second;
    area[y][x] = 0;
    if (res[y-1][x]>='0' && res[y-1][x]<='9') unusable[res[y-1][x]-'0'] = 1;
    if (res[y+1][x]>='0' && res[y+1][x]<='9') unusable[res[y+1][x]-'0'] = 1;
    if (res[y][x-1]>='0' && res[y][x-1]<='9') unusable[res[y][x-1]-'0'] = 1;
    if (res[y][x+1]>='0' && res[y][x+1]<='9') unusable[res[y][x+1]-'0'] = 1;
    total_area --;
  }
  int target = 0;
  while (unusable[target]) target ++;
  for (int i=0; i<sz; i++) {
    int y = P[i].first, x = P[i].second;
    res[y][x] = '0' + target;
  }
  while (fy>0 && !area[fy][fx]) {
    fx --;
    if (fx == 0) { fx = m; fy --; }
  }
}

int main()
{
  cin >> n >> m;
  for (int i=0; i<=m+1; i++)
    res[0][i] = res[n+1][i] = '#';

  for (int i=0; i<n; i++) {
    char temp[1001];
    scanf("%s", temp);
    res[i][0] = res[i][m+1] = '#';
    strcpy(res[i+1]+1, temp);
    for (int j=0; j<m; j++)
      if (temp[j] == '.') area[i+1][j+1] = 1, total_area ++, fy=i+1, fx=j+1;
  }

  int no_answer = 0;
  queue<pair<int, int> > Q;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      if (area[i][j]) {
        int cnt = area[i-1][j] + area[i+1][j] + area[i][j-1] + area[i][j+1];
        if (cnt == 0) no_answer = 1;
        if (cnt == 1) {
          mark[i][j] = 1;
          Q.push(pair<int, int>(i, j));
        }
      }
  if (no_answer) {
    printf("-1\n");
    return 0;
  }
 
  while (total_area) {

  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    if (!area[now.first][now.second]) continue;
    pair<int, int> next = now;
    if (area[now.first+1][now.second]) next.first ++;
    else if (area[now.first-1][now.second]) next.first --;
    else if (area[now.first][now.second+1]) next.second ++;
    else next.second --;
    vector<pair<int, int> > P;
    P.push_back(pair<int, int>(next.first, next.second));
    if (mark[next.first-1][next.second]) P.push_back(pair<int, int>(next.first-1, next.second));
    if (mark[next.first+1][next.second]) P.push_back(pair<int, int>(next.first+1, next.second));
    if (mark[next.first][next.second-1]) P.push_back(pair<int, int>(next.first, next.second-1));
    if (mark[next.first][next.second+1]) P.push_back(pair<int, int>(next.first, next.second+1));
    fill_area(P);

    for (int i=max(1, next.first-2); i<=min(n, next.first+2); i++)
      for (int j=max(1, next.second-2); j<=min(m, next.second+2); j++) {
        if (!area[i][j]) continue;
        int cnt = area[i-1][j] + area[i+1][j] + area[i][j-1] + area[i][j+1];
        if (cnt == 1 && !mark[i][j]) {
          mark[i][j] = 1;
          Q.push(pair<int, int>(i, j));
        }
      }
  }
  if (!total_area) break;

  vector<pair<int, int> > P;
  P.push_back(pair<int, int>(fy, fx));
  P.push_back(pair<int, int>(fy, fx-1));
  int my = fy, mx = fx;
  fill_area(P);
    for (int i=max(1, my-2); i<=min(n, my+2); i++)
      for (int j=max(1, mx-2); j<=min(m, mx+2); j++) {
        if (!area[i][j]) continue;
        int cnt = area[i-1][j] + area[i+1][j] + area[i][j-1] + area[i][j+1];
        if (cnt == 1 && !mark[i][j]) {
          mark[i][j] = 1;
          Q.push(pair<int, int>(i, j));
        }
      }
  }

  for (int i=1; i<=n; i++) {
    res[i][m+1] = 0;
    printf("%s\n", res[i]+1);
  }

  return 0;
}
