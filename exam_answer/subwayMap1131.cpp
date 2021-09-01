//1131subway map
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
vector<int>lines;
set<int> finding;
int maps[10010][10010]={0};
bool vis[10010]={0};
vector<int> start;
vector<int> endd;
//
vector<int> path;
vector<int> final_path;
int station=0;int min_sta=10011;
int huan=0;int min_huan=10011; int lii=0;
int largest=-1;

void dfs(int past,int now,int dest){
	station++;                 //cout<<now<<endl;
	vis[now]=1;
	path.push_back(now);
	bool f=0;
	if(past==now)lii=maps[past][now];
	else{
		if(lii!=maps[past][now]){
			huan++;
			f=1;
			lii=maps[past][now];
		}
	}
	if(now==dest){
		if(station<min_sta){
			min_sta=station;
			final_path=path;
			min_huan=huan;
		}
		else{
			if(station==min_sta&&huan<min_huan){
				min_huan=huan;
				final_path=path;
			}
		}
	}
	else{
		for(int j=0;j<=largest;j++){
			if(maps[now][j]!=0&&!vis[j])dfs(now,j,dest);
		}
	}
	station--;
	vis[now]=0;
	path.pop_back();
	if(f)huan--;//
}


int main(){
	int n;cin>>n;
	int k;int temp;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>temp;lines.push_back(temp);finding.insert(temp);
		}
		for(int j=1;j<k;j++){
			maps[lines[j]][lines[j]]=i;maps[lines[j-1]][lines[j-1]]=i;
				maps[lines[j]][lines[j-1]]=i;
				maps[lines[j-1]][lines[j]]=i;
			
		}
		lines.clear();
	}
	//cout<<maps[3012][3010]<<"tt"<<endl;
	int uu;int c1,c2;
	set<int>::iterator it;it=finding.begin();
	while(it!=finding.end()){
		largest=*it;
		it++;
	}
	
	//cout<<"biggest  : "<<largest<<endl;//
	cin>>uu;
	for(int i=0;i<uu;i++){
		cin>>c1>>c2;
		start.push_back(c1);
		endd.push_back(c2);
	}
	int h,e,li;
	for(int i=0;i<uu;i++){
		dfs(start[i],start[i],endd[i]);
		cout<<min_sta-1<<endl;//-----------!
		li=maps[final_path[0]][final_path[1]];
		h=final_path[0];e=final_path[1];
		for(int jj=1;jj<final_path.size();jj++){
			if(maps[final_path[jj-1]][final_path[jj]]==li){
				e=final_path[jj];
				continue;
			}
			else{
				cout<<"Take Line#"<<li;printf(" from %04d to %04d.\n",h,e);
				li=maps[final_path[jj-1]][final_path[jj]];
				h=final_path[jj-1];
				e=final_path[jj];
			}
			
		}
		cout<<"Take Line#"<<li;printf(" from %04d to %04d.\n",h,e);
			//Take Line#3 from 3011 to 3013.
		min_sta=10010;
		final_path.clear();
		huan=0;min_huan=10011;
		lii=0; 
	}
	return 0;
}
