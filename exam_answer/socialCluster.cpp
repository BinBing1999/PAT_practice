//social cluster
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int father[1010]={0};
int course_appear[1010]={0};//------------use 0 as a symble of no one in this class
int root_chosen[1010]={0};
vector<int> the_root;
//vector<int> cluster_members; 

int get_root(int a){
	int x=a;//get_temp_root
	while(x!=father[x])x=father[x];//x is root now
	//then set all node's father to be root to reduce complexity
	while(a!=father[a]){
		int temp=a;
		a=father[a];
		father[temp]=x;
	}
	return x;
}


void unite(int a,int b){
	int fa=get_root(a);
	int fb=get_root(b);
	//no need if condition
	//if(fa!=fb)
	father[fa]=fb;//this generate bug, make line 53 using father[i] dont work
}

int main(){
	int n,k;//1~1000
	cin>>n;
	for(int i=1;i<=n;i++)father[i]=i;//initialization
	int temp;
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);//dont add " " at the end of :
		for(int ii=1;ii<=k;ii++){
			cin>>temp;
			if(course_appear[temp]==0){
				course_appear[temp]=i;//header in the course
			}
			unite(i,course_appear[temp]);// combination of the set by root combination
		}
	}
	for(int i=1;i<=n;i++){
		int j=get_root(i);root_chosen[j]++;//----------------------very important , must use get_root(i) instead of father[i] else get wrong
	}
	for(int i=1;i<=n;i++){
		if(root_chosen[i]!=0)the_root.push_back(root_chosen[i]);
	}
	sort(the_root.begin(),the_root.end());
	reverse(the_root.begin(),the_root.end());
	//root number is group number
	cout<<the_root.size()<<endl;
	for(int i=0;i<the_root.size();i++){
		cout<<the_root[i];
		if(i!=the_root.size()-1)cout<<" ";
	}
	return 0;
}
