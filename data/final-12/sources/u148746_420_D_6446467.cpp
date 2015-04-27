#include <cstdio>
#include <algorithm>
#include <cstdlib>

struct Treap{
	int size,pri,num;
	Treap *l,*r;
	Treap(){}
	Treap(int n):size(1),pri(rand()),num(n),l(0),r(0){}
}space[1000000+1000],*Pspace;

int size(Treap *p)
{
	return p?p->size:0;
}

void push(Treap *p)
{
	if(!p)
	{
		p=0;
		return;
	}
	p->size=size(p->l)+size(p->r)+1;
}

Treap* merge(Treap *a,Treap *b)
{
/*printf("%d %d",a,b);
puts("~");*/
	if((!a)||(!b))
		return a?a:b;
//puts("Q");
	if(a->pri>b->pri)
	{
		a->r=merge(a->r,b);
//puts("A");
		push(a);
		return a;
	}
	else
	{
		b->l=merge(a,b->l);
/*puts("B");
printf("%d %d",a,b);*/
		push(b);
//puts("end?");
		return b;
	}
}

void split(Treap *t,Treap* &a,Treap* &b,int k)
{
	if(!t)
	{
		a=b=0;
		return;
	}
	if(size(t->l)>=k)
	{
		b=t;
		split(t->l,a,b->l,k);
		push(b);
	}
	else
	{
		a=t;
		split(t->r,a->r,b,k-size(t->l)-1);
		push(a);
	}
}

int x[1000000+1000],y[1000000+1000];
Treap* used[1000000+1000];
int num;

void ans(Treap *p)
{
	if(!p)
		return;
//printf("[%d %d %d]",p,p->l,p->r);
//system("pause");
	ans(p->l);
	if(p->num!=-1)
		printf("%d ",p->num);
	else
	{
		while(used[num])
			num++;
		printf("%d ",num);
		used[num]=p;
	}
	ans(p->r);
}

int main()
{
	srand(514);
	Pspace=space;
	Treap *root=0;
	bool yes=1;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		root=merge(root, new(Pspace++)Treap(-1) );
//puts(":)");
	for(int i=0;i<m;i++)
		scanf("%d%d",x+i,y+i);
	for(int i=m-1;i>=0;i--)
	{
		Treap *t1,*t2,*t3;
//puts("~");
		split(root,t1,t2,1);
//puts("!!!");
		if((t1->num!=-1 && t1->num!=x[i])||(used[x[i]]&&used[x[i]]!=t1))
		{
			yes=0;
			break;
		}
		t1->num=x[i];
		used[x[i]]=t1;
		if(y[i]==1)
		{
//printf("%d %d %d %d %d %d\n",t1,t1->l,t1->r,t2,t2->l,t2->r);
			root=merge(t1,t2);
//printf("%d %d %d\n",root,root->l,root->r);
//printf("%d %d\n",root->l->l,root->l->r);
			continue;
		}
		split(t2,t2,t3,y[i]-1);
		t1=merge(t2,t1);
		root=merge(t1,t3);
	}
	if(!yes)
		puts("-1");
	else
	{
		num=1;
		ans(root);
	}
	return 0;
}
