#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

#define sd(a) scanf("%d",&a)

#define pd(a) printf("%d\n",(a))

#define LL long long

int t[2050][2050];

int pos[1050][1050],n;


void build1(int node,int si,int sj,int parent,int row)

{

	if(si==sj)

	{

		t[parent][node]=0;

		pos[row][si]=parent*10000+node;

		return;

	}

	build1(node*2,si,(si+sj)/2,parent,row);

	build1(node*2+1,(si+sj)/2+1,sj,parent,row);

	t[parent][node]=0;

}

void build(int node,int si,int sj)

{

	int i;

	if(si==sj)

	{

	build1(1,0,n-1,node,si);

		return;

	}

	build(node*2,si,(si+sj)/2);

	build(node*2+1,(si+sj)/2+1,sj);

	int lim=pow(2,1+ceil(log2(n)));

	for(i=1;i<=2000;++i)

		t[node][i]=0;

}

void update1(int node,int parent,int diff)

{

	if(node)

	{

		t[parent][node]+=diff;

		update1(node>>1,parent,diff);

	}

}

void update(int node,int child,int diff)

{

	if(node)

	{

		t[node][child]+=diff;

		update1(child>>1,node,diff);

		update(node>>1,child,diff);

	}

}

int query1(int node,int si,int sj,int st,int en,int parent)

{

	if(si>en||sj<st)

		return 0;

	if(si>=st&&sj<=en)

	{

		return t[parent][node];

	}

	return (query1(node*2,si,(si+sj)/2,st,en,parent)+query1(node*2+1,(si+sj)/2+1,sj,st,en,parent));

}

int query(int node,int si,int sj,int st,int en,int cols,int cole)
{

	if(si>en||sj<st)

		return 0;

	if(si>=st&&sj<=en)

	{

		return query1(1,0,n-1,cols,cole,node);

	}

	return query(node*2,si,(si+sj)/2,st,en,cols,cole)+query(node*2+1,(si+sj)/2+1,sj,st,en,cols,cole);

}

int main()
{

	int test,x,y,x1,y1,num,hash,diff,x2,y2;

	char s[5];

	sd(test);

	while(test--)

	{

		sd(n);

		build(1,0,n-1);

		while(true)

		{

			scanf("%s",&s);

			if(s[1]=='E')

			{

				scanf("%d %d %d",&x,&y,&num);

				hash=pos[x][y];

				x1=hash/10000;

				y1=hash%10000;

				diff=num-t[x1][y1];

				t[x1][y1]=num;

				update1(y1>>1,x1,diff);

				update(x1>>1,y1,diff);

			}

			else if(s[1]=='U')

			{

				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

				printf("%d\n",query(1,0,n-1,x1,x2,y1,y2));

			}

			else

			{

				printf("\n");

				break;

			}

		}

	}

}
