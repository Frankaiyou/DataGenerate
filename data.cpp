#include<ctime>
#include<cstdio>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstdlib>
#define M 1000005
#define N 1000
using namespace std;

int n,m,b,up;
int f[M];
int Rand(int l,int r){
	return (rand()*rand())%(r-l+1)+l;
}
int find(int s){
	return f[s]==s?s:f[s]=find(f[s]);
}

void gouzao(){
	printf("%d %d %d\n",n,m,b);
	for(int i=1;i<=n;++i)
		printf("%d\n",n-i);
	int sz=0;
	for(int i=1,j=1;i<=m;++i,++j){
		if(j==n)j=1,++sz;
		printf("%d %d %d\n",j,j+1,(j+sz*n+1)%53);
	}
}

int main(){
	int Now;cin>>Now;
	srand(time(NULL)+Now*Now*Now+Now*Now+Now*1000);
	/**************************/
	if(Now<5*N)n=Rand(190,200),m=Rand(9900,10000),b=Rand(101,200),up=50;
	else if(Now<6*N){n=Rand(190,200),m=Rand(9900,10000),b=Rand(101,200),up=50;gouzao();return 0;}
	else if(Now<7*N)n=Rand(9000,10000),m=Rand(2*n,50000),b=Rand(9999000,10000000),up=1000000000;
	else if(Now<8*N)n=10000,m=50000,b=Rand(9999000,10000000),up=10000000;
	else n=10000,m=Rand(3*n,50000),b=Rand(9999000,10000000),up=100000;
	printf("%d %d %d\n",n,m,b);
	for(int i=1;i<=n;++i)printf("%d\n",Rand(1,up));
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<n-1;++i){
		int u=Rand(1,n),v=Rand(1,n);
		while(find(u)==find(v))u=Rand(1,n),v=Rand(1,n);
		f[find(u)]=find(v),printf("%d %d %d\n",u,v,Rand(1,up));
	}
	for(int i=n;i<=m;++i)
		printf("%d %d %d\n",Rand(1,n),Rand(1,n),Rand(1,up));
	return 0;
	/*************************/
	return 0;
}
