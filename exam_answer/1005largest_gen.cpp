#include<iostream>
#include<vector>
using namespace std;
#define max_n 100

int levelnum[max_n]={0};
int max_level=1,max_num=0;//initializing 
int n,m;
vector<vector<int> > tree_node(max_n);//must initialize with max_n, else no space
void dfs(int root,int level){
	levelnum[level]++;//add num in this coming level
    if(levelnum[level]>max_num){               //update latest max_num
        max_num=levelnum[level];
        max_level=level;
    }
    for(int i=0;i<tree_node[root].size();i++)       //traversing this node's children
        dfs(tree_node[root][i],level+1);	//the core
}

int main(){
	
	cin>>n>>m;
	int father,child,num_child;
	//cout<<n<<" "<<m<<endl;
	
	for(int i=0;i<m;i++){
		cin>>father>>num_child;
		for(int j=0;j<num_child;j++){
			cin>>child;
			tree_node[father].push_back(child);
		}
	}
	dfs(1,1);
	cout<<max_num<<" "<<max_level;
	return 0;
}
