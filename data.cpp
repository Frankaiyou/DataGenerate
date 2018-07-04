#include<ctime>
#include<cstdio>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;


int Rand(int l,int r){
	return (rand()*rand())%(r-l+1)+l;
}


int main(){
	int Now;cin>>Now;
	srand(time(NULL)+Now*Now*Now+Now*Now+Now*1000);
	/**************************/
	//To make a alone data.
	/*************************/
	return 0;
}
