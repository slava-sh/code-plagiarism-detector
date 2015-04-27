//solution by Wsl_F
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <cassert>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <complex>
#include <utility>
#include <climits>
#include <cctype>
#include <x86intrin.h>



using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

const int MaxN= 100*1000;

int a[MaxN+10];
int t[MaxN+10];
int r[MaxN+10];
int last[MaxN+10];

/*
    ����� ���������� ������� ������ �������� ���������� ������ �� ��� �������, ������� �������� ���� ���������.

    ������ �����, ������� ����� ����������� ������ ����, ��� ����� � ����������� ������� � ������ �������, ��� �������,
    ��� ������ ����� ������ �� ��������, ����� ������� ������������ ��������, ����� ��� ������ - i

    ��������� ���������� ������������ ������� �� ������� ������������ - sumBefore

    � ���������� ���� �������������� ������� - sum

    ��� ���� ���-�� j-�� ����� ����� ����������� �� ��������� ���������� ���������� � ����������, ��� �� �����������
    ���� �� ���� �� ����������: a[j]+a[i]<= sum   a[j]<=sumBefore

*/

void solve()
{
    int m,k;
     scanf("%d %d", &m, &k);//cin>>m>>k;
    for (int i= 1; i<=k; i++)
         scanf("%d", &a[i]);//cin>>a[i];

    for (int i=0; i<=k; i++)
        last[i]= 0;

    for (int i= 1; i<m; i++)
    {
        scanf("%d %d", &t[i],&r[i]);//cin>>t[i]>>r[i];
        last[t[i]]= i;
    }

    if (k==1)
    {
        printf("N\n");//cout<<"N"<<endl;
        return;
    }

    int firstFinished= 0;
    int sumBefore=0;
    for (int i= 1; i<m; i++)
        if (r[i]==1) { firstFinished= i; break; }
        else if (t[i]==0) sumBefore++;

    int sum= 0;
    for (int i= 1; i<m; i++)
    {
        if (t[i]==0) sum++;
        else a[t[i]]--;
    }

    sumBefore;
    if (firstFinished)
    {
        int finished;
        int j= 0;
        a[0]= INFINITY;
        for (int i= 1; i<=k; i++)
            if (last[i]<firstFinished && a[i]<a[j]) j= i;
        sum-= a[j];
    }

    for (int i= 1; i<=k; i++)
        if (a[i]<=sum || (a[i]<=sumBefore && last[i]<firstFinished)) printf("Y");//cout<<'Y';
        else printf("N");//cout<<'N';
    printf("\n");//cout<<endl;
}


int main()
{

 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);


 int numberOfTests;
 scanf("%d", &numberOfTests);//cin>>numberOfTests;
 for (int testCase= 0; testCase<numberOfTests; testCase++)
    solve();

 return 0;
}


