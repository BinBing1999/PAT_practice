//1118 Birds in Forest
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int father[10010]={0};
int pics[10010]={0};
int root[10010]={0};
vector<int> group;

int get_root(int a){
	int x=a;
	while(x!=father[x])x=father[x];
	int z;
	while(a!=father[a]){
		z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

void unite(int a,int b){
	int fa=get_root(a);
	int fb=get_root(b);
	father[fa]=fb;
}
set<int> birds;

int main(){
	int n;cin>>n;
	int k;int temp;
	//initialization
	for(int i=0;i<=10010;i++)father[i]=i;
	//build forest
	for(int i=0;i<n;i++){
		cin>>k;
		for(int ii=1;ii<=k;ii++){
			cin>>temp;
			birds.insert(temp);
			if(pics[i]==0)
				pics[i]=temp;
			unite(temp,pics[i]);
		}
	}
	for(set<int>::iterator it=birds.begin();it!=birds.end();it++){
		root[get_root(*it)]++;
	}
	for(int i=0;i<10010;i++){
		if(root[i]!=0)group.push_back(root[i]);
	}
	cout<<group.size()<<" "<<birds.size()<<endl;
	int que;
	cin>>que;int c1,c2;
	for(int i=0;i<que;i++){
		cin>>c1>>c2;
		if(get_root(c1)==get_root(c2))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
