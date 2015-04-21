#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

typedef struct my_treap * treap;

struct my_treap
{
	treap l,r;
	int mn,val,x,prior;
};

treap t[100100],tr1,tr2,buf,tr3;

int n,m,delta,x,y,c,INF,cases,d[100100],i,v,j,to,go,cur,qb,qe,q[10000100];
vector <pair <int,int> > edge[100100];
//set <pair<int,int> > s;

int mn(treap t)
{
	return t ? t->mn : INF;
}

void upd_mn(treap t)
{
	if (t)
	{
		t->mn=min(min(mn(t->l),mn(t->r)),t->val);
	}
	return;
}

void split(treap t,treap & l,treap & r,int key)
{
	if (!t)
	{
		l=r=NULL;
		return;
	}
	treap newTreap=NULL;
	if (t->x<=key)
	{
		if (!t->r)
			r=NULL;
		else
			split(t->r,newTreap,r,key);
		t->r=newTreap;
		l=t;
	}
	else
	{
		if (!t->l)
			l=NULL;
		else
			split(t->l,l,newTreap,key);
		t->l=newTreap;
		r=t;
	}
	upd_mn(l);
	upd_mn(r);
	return;
}

void merge(treap & t,treap l,treap r)
{
	if (!l)
	{
		t=r;
		return;
	}
	if (!r)
	{
		t=l;
		return;
	}
	treap newTreap=NULL;
	if (l->prior>r->prior)
	{
		merge(newTreap,l->r,r);
		l->r=newTreap;
		t=l;
	}
	else
	{
		merge(newTreap,l,r->l);
		r->l=newTreap;
		t=r;
	}
	upd_mn(t);
	return;
}

void del(treap & t)
{
	if (!t) return;
	del(t->l);
	del(t->r);
	delete(t);
	t=NULL;
	return;
}

void init()
{
	for (int i=1; i<=n; i++)
	{
		del(t[i]);
	}
	for (int i=1; i<=n; i++)
		d[i]=INF;
	return;
}

void insert(treap & t,int x)
{
	buf=new my_treap();
	buf->x=x;
	buf->val=cur;
	buf->prior=(rand()<<16)+rand();
	buf->l=NULL;
	buf->r=NULL;
	buf->mn=cur;
	merge(t,t,buf);
	return;
}

bool in_use(treap t,int key)
{
	if (!t) return false;
	if (t->x==key)
	{
		t->val=min(t->val,key);
		upd_mn(t);
		return true;
	}	
	if (t->x>key)
	{
		if (in_use(t->l,key))
		{
			upd_mn(t);
			return true;
		}
		else
			return false;
	}
	if (in_use(t->r,key))
	{
		upd_mn(t);
		return true;
	}
	else
		return false;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	srand(time(NULL));
	INF=(int)2e9;
	cin>>n>>m>>delta;
	while (m--)
	{
		cin>>x>>y>>c;
		edge[x].pb(mp(y,c));
		edge[y].pb(mp(x,c));
	}
	cin>>cases;
	while (cases--)
	{
		init();
		cin>>x>>y;
		
		d[x]=0;
		//s.insert(mp(d[x],x));
		q[0]=x;
		qb=0;
		qe=1;
		while (qb!=qe)
		{
			v=q[qb];
			qb++;
			for (j=0; j<edge[v].size(); j++)
			{
				to=edge[v][j].first;
				go=edge[v][j].second;
				split(t[v],t[v],tr2,go+delta);
				split(t[v],tr1,t[v],go-delta-1);
				if (t[v] || v==x)
				{	
					if (t[v])
						cur=t[v]->mn+1;					
					else
						cur=1;
					if (!in_use(t[to],go))
					{
						split(t[to],t[to],tr3,go);
						insert(t[to],go);
						merge(t[to],t[to],tr3);
						
						//s.erase(mp(d[to],to));						
						if (cur<=d[to])
						{														
							d[to]=cur;							
						}	
						//s.insert(mp(cur,to));						
						q[qe]=to;
						qe++;
					}
					
				}
				merge(t[v],tr1,t[v]);
				merge(t[v],t[v],tr2);
				
			}
		}
		if (d[y]!=INF)
			cout<<d[y]<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}



