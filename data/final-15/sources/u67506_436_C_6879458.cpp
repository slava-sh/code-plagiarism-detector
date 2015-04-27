#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include<vector>

/*
Во время запуска игры «Dungeons and Candies» требуется получить по сети от сервера описания k уровней игры. Каждое описание — карта клетчатого прямоугольного поля n × m, в клетках которого расположены конфеты (в каждой клетке находится не более одной конфеты). Пустая клетка обозначается символом «.», если же в клетке находится конфета, то она кодируется буквой латинского алфавита. Уровень может содержать одинаковые конфеты, в таком случае буквы в соответствующих клетках карты будут одинаковы.
*/

using namespace std;

int n, m, k, w;
string mas[1010];
int diff[1010][1010];
bool used[1010];
set< pair<int,int> > ss[1010];

int main()
{
    ios::sync_with_stdio(0);
    

cin >> n >> m >> k >> w;
    
    string s;
    for(int t = 0 ; t < k ; ++t)
    {
        mas[t] = "";
        for(int i = 0 ; i < n ; ++i)
        {
            cin >> s;
            mas[t] += s;
        }
    }

/*
При передачи по сети требуется минимизировать трафик — суммарный размер переданных данных. Уровни можно передавать в любом порядке. Существует два способа передать очередной уровень A:

Можно передать уровень A целиком. Этот способ требует передачи n·m байтов по сети.
Можно передать разницу между уровнем A и каким-то ранее переданным уровнем B, если такой существует; эта операция требует передачи dA, B·w байтов, где dA, B обозначает количество клеток поля, которые отличаются в A и B, а w — константа. Обратите внимание, что при вычислении dA, B сравниваются соответствующие друг другу клетки уровней A и B. При этом карты уровней нельзя преобразовывать, например, поворачивать или смещать относительно друг друга.
Ваша задача — найти способ передать все k уровней, минимизировав трафик.
*/
    int len = n*m;
    for(int i = 0 ; i < k ; ++i)
        for(int j = 0 ; j < i ; ++j)
        {
            diff[i][j] = 0;
            for(int l = len-1 ; l >= 0 ; --l)
                diff[i][j] += (mas[i][l] != mas[j][l]);
            
            diff[i][j] *= w;
            diff[j][i] = diff[i][j];
            
            ss[i].insert(make_pair(diff[i][j], j));
            ss[j].insert(make_pair(diff[i][j], i));
        }
    
    vector< pair<int,int> > ans;
    ans.push_back(make_pair(1, 0));
    used[0] = 1;
    for(int i = 0 ; i < k ; ++i)
    {
        ss[i].erase(make_pair(diff[i][0], 0));
        diff[i][0] = 99999999;
    }
    int sm = len;
    
    for(int tt = 0 ; tt < k-1 ; ++tt)
    {
        int p = -1, fr = -1, best = len;
        
        for(int i = 0 ; i < k ; ++i)
        if(used[i])
        if(ss[i].size() > 0)
        {
            if((*ss[i].begin()).first <= best)
            {
                best = (*ss[i].begin()).first;
                p = (*ss[i].begin()).second;
                fr = i;
            }
        }
        //cout << p << " " << fr << "\n";
        sm += best;
        if(fr == -1)
        {
            for(int i = 0 ; i < k ; ++i)
            if(!used[i])
                p = i;
            
            ans.push_back(make_pair(p+1, 0));
            used[p] = 1;
            for(int i = 0 ; i < k ; ++i)
            {
                ss[i].erase(make_pair(diff[i][p], p));
                diff[i][p] = 99999999;
            }
        }
        else
        {
            ans.push_back(make_pair(p+1, fr+1));
            used[p] = 1;
            for(int i = 0 ; i < k ; ++i)
            {
                ss[i].erase(make_pair(diff[i][p], p));
                diff[i][p] = 99999999;
            }
        }
    }

//trololo
    cout << sm << "\n";
    for(int i = 0 ; i < ans.size() ; ++i)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}
