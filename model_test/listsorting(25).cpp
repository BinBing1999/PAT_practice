#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct node{
	int grade;
	string id;
	string name;
};

bool cmp1(node a,node b){
	
	return b.id>a.id;
}

bool cmp2(node a,node b){
	if(a.name==b.name)return b.id>a.id;
	else return a.name<b.name;
}

bool cmp3(node a,node b){
	if(a.grade==b.grade)return b.id>a.id;
	else return a.grade<b.grade;
}

int main(){
	int n,way;
	cin>>n>>way;
	int score;
	string name[n];
	string id[n];
	vector<node> vec(n);
	node tempnode;
	for(int i=0;i<n;i++){
		cin>>id[i]>>name[i]>>score;
		tempnode.grade=score;
		tempnode.id=id[i];
		tempnode.name=name[i];
		vec[i]=tempnode;
	}
	if(way==1){
		sort(vec.begin(),vec.end(),cmp1);
	}
	else if(way==2){
		sort(vec.begin(),vec.end(),cmp2);
	}
	else{
		sort(vec.begin(),vec.end(),cmp3);
	}
	for(int i=0;i<n;i++){
		tempnode=vec[i];
		cout<<tempnode.id<<" "<<tempnode.name<<" "<<tempnode.grade<<endl;
	}
	return 0;
}
