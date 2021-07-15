#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct node{
	string name;
	string id;
	int grade;
	node(string na="",string ID="",int num=0){
		grade=num;
		name=na;
		id=ID;
	}
	~node(){}
};

bool cmp(const node& s1, const node& s2)
{
    return s1.grade > s2.grade; 
}

int main(){
	int n;
	cin>>n;
	node tempnode;
	vector<node> lists(n);
	bool out_none=1;
	string tempname;
	string tempid;
	int score;
	int grade1,grade2;
	
	for(int i=0;i<n;i++){
		cin>>tempname>>tempid>>score;
		tempnode.grade=score;
		tempnode.name=tempname;
		tempnode.id=tempid;
		lists[i]=tempnode;
		//cout<<lists[1].name<<" "<<lists[1].id<<endl;//for test
	}
	
	cin>>grade1>>grade2;
	sort(lists.begin(),lists.end(),cmp);
	
	//for(int i=0;i<n;i++){
	
	//	tempnode=lists[i];
	//	cout<<tempnode.name<<" "<<tempnode.id<<tempnode.grade<<endl;
	//}
	
	for(int i=0;i<n;i++){
			tempnode=lists[i];
			if(tempnode.grade>=grade1&&tempnode.grade<=grade2){
		cout<<tempnode.name<<" "<<tempnode.id<<endl;
		//cout<<tempnode.name<<" "<<tempnode.id<<" "<<tempnode.grade<<endl;//test
		out_none=0;
		}
	}
	if(out_none)cout<<"NONE";
	return 0;
}
