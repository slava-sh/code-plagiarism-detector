#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define INF 99999999
#define MAX 100010
#define MOD 1000000007
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
struct NODE
{
    int flag ,x;
}nodes[MAX];

int n ,m;
char str[10];
int flag[MAX];
int no[MAX] ,num[MAX];

int main()
{
    int re;
    while(~scanf("%d%d",&n,&m))
    {
        mem(flag);
        mem(no);
        mem(num);
        int ss = n;
        for(int i = 0;i < m;i++)
        {
            scanf("%s%d",str,&re);
            if(!flag[re])
            {
                ss--;
            }
            flag[re] = 1;
            if(str[0]=='+')
            {
                nodes[i].flag = 1;
                nodes[i].x = re;
            }
            else
            {
                nodes[i].flag = 0;
                nodes[i].x = re;
            }
        }
        if(m==1)
        {
            printf("%d\n",n);
            for(int i = 1;i <= n;i++)
            {
                printf("%d ",i);
            }
            continue;
        }
        if(!nodes[0].flag)
        {
            int ans = nodes[0].x ,flag1 = 1;
            int cnt = 0;
            for(int i = 1;i < m;i++)
            {
                if(flag1==1)
                {
                    if(!nodes[i].flag)
                    {
                        if(!no[nodes[i].x])
                        {
                            ans = nodes[i].x;
                        }
                        else
                        {
                            num[nodes[i].x] = 0;
                            flag1 = 0;
                            cnt--;
                        }
                    }
                    else
                    {
                        if(nodes[i].x!=ans)
                        {
                            num[nodes[i].x] = 1;
                            no[nodes[i].x] = 1;
                            cnt++;
                            flag1 = 0;
                        }
                        else
                        {
                            flag1 = 2;
                        }
                    }
                }
                else if(flag1==2)
                {
                    if(!nodes[i].flag)
                    {
                        if(!no[nodes[i].x])
                        {
                            if(nodes[i].x==ans)
                            {
                                if(!cnt)
                                {
                                    flag1 = 1;
                                }
                                else
                                {
                                    flag1 = 0;
                                    num[ans] = 1;
                                    no[ans] = 1;
                                    cnt++;
                                }
                            }
                            else
                            {
                                flag1 = 0;
                                num[ans] = 1;
                                no[ans] = 1;
                                cnt++;
                            }
                        }
                        else
                        {
                            cnt--;
                            num[nodes[i].x] = 0;
                        }
                    }
                    else
                    {
                        no[nodes[i].x] = 1;
                        num[nodes[i].x] = 1;
                        cnt++;
                    }
                }
                else
                {
                    if(!nodes[i].flag && !cnt)
                    {
                        ans = nodes[i].x;
                        flag1 = 1;
                    }
                    else
                    {
                        if(nodes[i].flag)
                        {
                            num[nodes[i].x] = 1;
                            no[nodes[i].x] = 1;
                            cnt++;
                        }
                        else
                        {
                            if(num[nodes[i].x])
                            {
                                num[nodes[i].x] = 0;
                                cnt--;
                            }
                        }
                    }
                }
            }
            if(flag1)
            {
                flag[ans] = 0;
                ss++;
            }
        }
        else
        {
            int ans = nodes[0].x ,flag1 = 2;
            int cnt = 0;
            for(int i = 1;i < m;i++)
            {
                if(flag1==1)
                {
                    if(!nodes[i].flag)
                    {
                        if(!no[nodes[i].x])
                        {
                            ans = nodes[i].x;
                        }
                        else
                        {
                            num[nodes[i].x] = 0;
                            flag1 = 0;
                            cnt--;
                        }
                    }
                    else
                    {
                        if(nodes[i].x!=ans)
                        {
                            num[nodes[i].x] = 1;
                            no[nodes[i].x] = 1;
                            cnt++;
                            flag1 = 0;
                        }
                        else
                        {
                            flag1 = 2;
                        }
                    }
                }
                else if(flag1==2)
                {
                    if(!nodes[i].flag)
                    {
                        if(!no[nodes[i].x])
                        {
                            if(nodes[i].x==ans)
                            {
                                if(!cnt)
                                {
                                    flag1 = 1;
                                }
                                else
                                {
                                    flag1 = 0;
                                    num[ans] = 1;
                                    no[ans] = 1;
                                    cnt++;
                                }
                            }
                            else
                            {
                                flag1 = 0;
                                num[ans] = 1;
                                no[ans] = 1;
                                cnt++;
                            }
                        }
                        else
                        {
                            cnt--;
                            num[nodes[i].x] = 0;
                        }
                    }
                    else
                    {
                        no[nodes[i].x] = 1;
                        num[nodes[i].x] = 1;
                        cnt++;
                    }
                }
                else
                {
                    if(!nodes[i].flag && !cnt)
                    {
                        ans = nodes[i].x;
                        flag1 = 1;
                    }
                    else
                    {
                        if(nodes[i].flag)
                        {
                            num[nodes[i].x] = 1;
                            no[nodes[i].x] = 1;
                            cnt++;
                        }
                        else
                        {
                            if(num[nodes[i].x])
                            {
                                num[nodes[i].x] = 0;
                                cnt--;
                            }
                        }
                    }
                }
            }
            if(flag1)
            {
                ss++;
                flag[ans] = 0;
            }
        }
        printf("%d\n",ss);
        for(int i = 1;i <= n;i++)
        {
            if(!flag[i])
            {
                printf("%d ",i);
            }
        }
    }
    return 0;
}