//1003 Emergency (25)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int people[510]={0};
int road[510][510]={0};
bool vis[510]={0};
int shortest_num=0;int leng=0;int shortest=100000000;
int max_rescue=0;int res=0;

void dfs(int past,int now,int dest){
	vis[now]=1;
	leng+=road[past][now];
	res+=people[now];
	if(now==dest){//reached
		if(leng<shortest){
			shortest=leng;max_rescue=res;shortest_num=1;
		}
		else if(leng==shortest){
			shortest_num++;
			if(res>max_rescue)max_rescue=res;
		}
		else{
		}
	}
	else{
		for(int i=0;i<510;i++){
			if(road[now][i]!=0&&!vis[i]){
				dfs(now,i,dest);	
			}
		}
	}
	vis[now]=0;
	leng-=road[past][now];
	res-=people[now];
}



int main(){
	int n,m,c1,c2;
	cin>>n>>m>>c1>>c2;
	int temp1,temp2;int L;
	for(int i=0;i<n;i++){
		cin>>people[i];
	}
	for(int i=0;i<m;i++){
		cin>>temp1>>temp2>>L;
		road[temp1][temp2]=L;
		road[temp2][temp1]=L; 
	}
	dfs(c1,c1,c2);
	cout<<shortest_num<<" "<<max_rescue;
	return 0;
}

