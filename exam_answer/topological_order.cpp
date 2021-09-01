//topological order
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int graph[1010][1010]={{0}};
bool vis[1010]={0};
int n,k;
vector<vector<int> > tests(110);
bool f=0;

void toppo(int line,int pos){
	if(f)return;
	if(pos>=tests[line].size())return;
	int p=tests[line][pos];
	vis[p]=1;
	for(int i=1;i<=n;i++){
		if(graph[p][i]==1&&vis[i])f=1;
	}
	if(pos<tests[line].size())toppo(line,pos+1);
	vis[p]=0;
}

int main(){
	cin>>n>>k;
	int c1,c2;
	for(int i=0;i<k;i++){
		cin>>c1>>c2;
		graph[c1][c2]=1;
	}
	int k2;
	cin>>k2;
	for(int i=0;i<k2;i++){
		for(int j=0;j<n;j++){
			cin>>c1;
			tests[i].push_back(c1);
		}
	}
	int t;
	for(int i=0;i<k2;i++){
		f=0;
		toppo(i,0);
		if(f){
			cout<<i;
			t=i+1;
			break;
		}
	}
	for(int i=t;i<k2;i++){
		f=0;
		toppo(i,0);
		if(f){
			cout<<" "<<i;
		}
	}
	return 0;
}
