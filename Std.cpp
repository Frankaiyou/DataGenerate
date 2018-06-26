#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge
{
	int u,v,x;
} ed[1000010];
int head[1000010];
int mon[1000010];
int que[1000010];
int dis[1000010];
bool vis[1000010];
int cnt,h,t=1,n,m,b,l,r;
void add(int x,int y,int z)
{
	cnt++;
	ed[cnt].u=head[x];
	ed[cnt].v=y;
	ed[cnt].x=z;
	head[x]=cnt;
}
int spfa(int top)
{
	memset(vis,0,sizeof(vis));
	memset(dis,50,sizeof(dis));
	vis[1]=1,dis[1]=0,que[t]=1,h=0,t=1;
	while(h<t)
	{
		int temp=que[++h];
		if(mon[temp]>top)
			continue;
		for(int i=head[temp]; i; i=ed[i].u)
		{
			if(mon[ed[i].v]<=top&&dis[ed[i].v]>dis[temp]+ed[i].x)
			{
				dis[ed[i].v]=dis[temp]+ed[i].x;
				if(vis[ed[i].v]==0)
				{
					vis[ed[i].v]=1;
					que[++t]=ed[i].v;
				}
			}
		}
		vis[temp]=0;
	}
	return dis[n];
}
bool judge(int mid)
{
	spfa(mid);
	if(dis[n]>b)
		return 0;
	else
		return 1;
}
int main()
{
	cin>>n>>m>>b;
	for(int i=1; i<=n; i++)
		cin>>mon[i],r=max(r,mon[i]);
	l=max(mon[1],mon[n]);
	for(int i=1; i<=m; i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	spfa(r);
	if(dis[n]>=842150450||dis[n]>b)
	{
		cout<<"AFK";
		return 0;
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l;
	return 0;
}
