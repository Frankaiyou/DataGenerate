#include<algorithm>
#include<cstdio>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<windows.h>
#define N 1000
using namespace std;

struct File{
	string str,name,type;
	File(){}
	File(string n,string t){name=n,type=t,str=name+type;}
	void input(){
		string temp;
		cin>>temp;cin>>temp;
		bool flag=0;
		for(int i=0;i<temp.size();++i)
			if(temp[i]=='.')
				name=temp.substr(0,i),type=temp.substr(i,temp.size()-i),flag=true;
		if(!flag){name=temp;type=".cpp";}
		str=name+type;
	}
};

File data,Std,Infile,Outfile,Tempfile;
int Size;

void Compile(File file){
	string Mingling;
	Mingling="g++ "+file.str+" -O2 -o "+file.name;
	cout<<Mingling<<endl;
	system(Mingling.c_str());
}
void RunProgram(File n,File in,File out){
	string Ml=n.name+" >"+out.str+" <"+in.str;
	cout<<Ml<<endl;
	system(Ml.c_str());
}
void init(){
	data.input(),Std.input();
	Infile.input(),Outfile.input(),Tempfile.input();
	Compile(data);Compile(Std);
	srand(time(NULL));
	string t;cin>>t;cin>>Size;
}

int Rand(){
	return rand()*rand();
}

void Make(){
	string id;File ouf,inf;
	for(int s=1;s<=Size;++s){
		ofstream temput(Tempfile.str.c_str());
		temput<<(rand()%N+N*(s-1));
		temput.close();
		id=to_string(s);
		ouf=File(Outfile.name+id,Outfile.type);
		inf=File(Infile.name+id,Infile.type);
		RunProgram(data,Tempfile,inf);
		RunProgram(Std,inf,ouf);
	}
}

int main(){
	freopen("settings.txt","r",stdin);
	init(),Make();
	return 0;
}
