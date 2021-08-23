//1006signINand signOUT
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct student{
	string id;
	int in_time=0;
	int out_time=0;
};
vector<student> list;
vector<student> come;
vector<student> leave;

bool cmp_come(student a,student b){
	return  a.in_time<b.in_time;
}


bool cmp_leave(student a,student b){
	return  a.out_time>b.out_time  ;
}


int main(){
	int n;cin>>n;
	student T;
	list.resize(n,T);
	int timeIn,timeOut,h,m,s;string name;
	for(int i=0;i<n;i++){
		cin>>name;
		scanf("%d:%d:%d",&h,&m,&s);timeIn=3600*h+60*m+s;//cout<<"ok"<<endl;//--!1.standard of not using " " and "\n"  2. remember add & before variants
		scanf("%d:%d:%d",&h,&m,&s);timeOut=3600*h+60*m+s;
		list[i].id=name;list[i].in_time=timeIn;list[i].out_time=timeOut;
	}
	come=list;leave=list;
	sort(come.begin(),come.end(),cmp_come);
	sort(leave.begin(),leave.end(),cmp_leave);
	cout<<come[0].id<<" "<<leave[0].id;
	return 0;
}
