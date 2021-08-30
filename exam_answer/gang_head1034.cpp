//gang head,  this is a graph with direction
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#define max_num 2040

using namespace std;
typedef map<string,int>::iterator iter;
int graph[max_num][max_num]={0};
bool visited[max_num]={0};
map<string,int> name_list;
string names[max_num];
int group=0;
vector<string> heads;
vector<int> members;
int temp1[max_num]={0};
int n,k;
int leng=0;int member=0;

void dfs(int past,int now){
	if(!visited[now])member++;//cout<<member<<" ";//----------------!
	leng+=graph[past][now];//cout<<leng<<endl;//leng still add!
	visited[now]=1;
	temp1[past]+=graph[past][now];
	temp1[now]+=graph[past][now];//
	graph[past][now]=0;
	for(int i=0;i<max_num;i++){
		if(graph[now][i]!=0)dfs(now,i);//
	}
}

int main(){
	cin>>n>>k;
	string c1,c2;int tim;int cnt=0;
	int s1,s2;
	for(int i=0;i<n;i++){
		cin>>c1>>c2>>tim;
		iter it;it=name_list.find(c1);
		if(it==name_list.end()){
			name_list.insert(pair<string,int>(c1,cnt));
			s1=cnt;cnt++;names[s1]=c1;
		}else{
			s1=it->second;
		}
		it=name_list.find(c2);
		if(it==name_list.end()){
			name_list.insert(pair<string,int>(c2,cnt));
			s2=cnt;cnt++;names[s2]=c2;
		}else{
			s2=it->second;
		}
		graph[s1][s2]=tim;
	}
	int m=-1,p=-1;//
	for(int i=0;i<max_num;i++){
		if(!visited[i]){
			dfs(i,i);
			if(leng>k&&member>2){
				group++;
				members.push_back(member);
				for(int j=0;j<max_num;j++){
					if(temp1[j]>m){
						m=temp1[j];p=j;
					}
				}
				heads.push_back(names[p]);
			}
			member=0;leng=0;
			for(int j=0;j<max_num;j++)temp1[j]=0;
			m=-1;p=-1;
		}
	}
	cout<<group<<endl;
	if(group>0)
	for(int i=0;i<group;i++){
		cout<<heads[i]<<" "<<members[i]<<endl;
	}
	return 0;
}
