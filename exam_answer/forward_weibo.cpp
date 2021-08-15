//weibo graph search
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//numbered from 1 to N
int n,l;
vector<vector<int> > relation(1010);
bool vis[1010]={0};
int level=0;int follower=0;
void bfs(int start){
	queue<int> list;
	int q=start;
	int levCnt=relation[q].size();
	vis[q]=1;for(int i=0;i<relation[q].size();i++)list.push(relation[q][i]);//this place has one round
	while(!list.empty()){
		if(levCnt==0){
			level++;
			levCnt=list.size();//new round
		}
		if(vis[list.front()]){
			list.pop();
			levCnt--;
			continue;
		}
		q=list.front();vis[q]=1;
		if(level>l-1)return;
		follower++;
		for(int i=0;i<relation[q].size();i++)list.push(relation[q][i]);
		list.pop();levCnt--;
	}
}

int main(){
	cin>>n>>l;
	int temp,temp2;
	vector<int> query;
//	cout<<"size of relation is "<<relation[0].size()<<endl;
	for(int i=1;i<=n;i++){
		cin>>temp;
		for(int j=0;j<temp;j++){
			cin>>temp2;relation[temp2].push_back(i);//graph with direction
		}
	}
	cin>>temp;
	for(int i=0;i<temp;i++){
		cin>>temp2;query.push_back(temp2);
	}
	for(int i=0;i<query.size();i++){
		level=0;follower=0;for(int j=0;j<1010;j++)vis[j]=0;
		bfs(query[i]);
		cout<<follower;if(i!=query.size()-1)cout<<endl;
	}
	return 0;
}

