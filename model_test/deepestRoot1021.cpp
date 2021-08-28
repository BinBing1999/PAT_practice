//deepest root
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> >graph(10010);
bool vis[10010]={0};
bool lop[10010]={0};
vector<int> road;
bool loop=0;
int mx_lev=0;
int level=0;
set<int> list;
set<int> in_loop;

void dfs(int past,int now){
	vis[now]=1; //cout<<now<<" trv ";//---
	level++;
	road.push_back(now);
	if(level>mx_lev){
		list.clear();
		mx_lev=level;
		list.insert(road[0]);
	}
	if(level==mx_lev){ // no problem
		list.insert(road[0]);
	}
	for(int i=1;i<graph[now].size();i++){
		if(!vis[graph[now][i]])dfs(now,graph[now][i]);
		else {
			if(graph[now][i]==past)continue;
			loop=1;
			lop[graph[now][i]]=1;
			for(int i=road.size()-1;road[i]!=graph[now][i]&&i>=0;i--){
			if(!lop[road[i]])in_loop.insert(road[i]);//-----
			lop[road[i]]=1;
			}
		}
	}
	road.pop_back();
	level--;
	vis[now]=0;
}

int main(){
	int n;cin>>n;
	int c1,c2;
	for(int i=1;i<=n;i++)graph[i].push_back(i);
	for(int i=0;i<n-1;i++){
		cin>>c1>>c2;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	for(int i=1;i<=n;i++)if(!lop[i])dfs(i,i);
	if(loop){
		cout<<"Error: "<<in_loop.size()<<" components";
//		for(set<int> ::iterator it=in_loop.begin();it!=in_loop.end();it++)
//			cout<<*it<<endl;
	}
	else{
		for(set<int> ::iterator it=list.begin();it!=list.end();it++)
			cout<<*it<<endl;
	}
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N=1e4+5;

int n;
vector<int> g[N],book;
int f[N],cnt;
int mdepth,vis[N];

void Init(){
    for(int i=1;i<=n;i++)
        f[i]=i;
    cnt=n;
}

int Find(int a){
    return f[a]==a? a:f[a]=Find(f[a]);
}

void dfs(int u,int depth){
    mdepth=max(depth,mdepth);
    vis[u]=depth;
    for(int i=0;i<(int)g[u].size();i++)
        if(vis[g[u][i]]==0)
            dfs(g[u][i],depth+1);
}

int main(){
    scanf("%d",&n);
    Init();

    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);

        int ru=Find(u),rv=Find(v);
        if(ru!=rv){
            f[ru]=rv;
            cnt--;
        }

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(cnt!=1) printf("Error: %d components\n",cnt);
    else{
        memset(vis,0,sizeof(vis));
        mdepth=0;
        dfs(1,1);
        for(int i=1;i<=n;i++)
            if(vis[i]==mdepth)
                book.push_back(i);

        memset(vis,0,sizeof(vis));
        mdepth=0;
        dfs(book[0],1);
        for(int i=1;i<=n;i++)
            if(vis[i]==mdepth)
                book.push_back(i);

        sort(book.begin(),book.end());
        for(int i=0;i<(int)book.size();i++)
            if(!i||book[i]!=book[i-1])
                printf("%d\n",book[i]);
    }

    return 0;
}

————————————————
版权声明：本文为CSDN博主「艾_Mi杰」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Ai_Mijie/article/details/113198602
*/

