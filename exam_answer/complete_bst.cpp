//complete binary search tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
	int key=-1;
	node* left=NULL;
	node* right=NULL;
};

vector<int> list;
node* record[2020];
vector<int> record2;
int n;

void level_traversal(node* root){
	queue<node*> que;
	que.push(root);
	node* point;
	while(!que.empty()){
		point=que.front();
		if(point->left!=NULL)que.push(point->left);
		if(point->right!=NULL)que.push(point->right);
		cout<<point->key;
		que.pop();if(!que.empty())cout<<" ";
	}
}
void middle(node* root){
	if(root==NULL)return;
	middle(root->left);
	record2.push_back(root->key);
	middle(root->right);
}

void build_bst(){
	int cnt=1;
	int tem;
	queue<int> que;
	que.push(cnt);
	while(cnt<=n){
		tem=que.front();
		record[tem]->key=tem;
		if(tem*2<=n){
			record[tem]->left=record[tem*2];
			que.push(tem*2);
		}
		if(tem*2+1<=n){
			record[tem]->right=record[tem*2+1];
			que.push(tem*2+1);
		}
		que.pop();cnt++;
	}
}

int main(){
	cin>>n;
	int temp;
	for(int i=0;i<2020;i++)record[i]=new node;
	for(int i=0;i<n;i++){
		cin>>temp;
		list.push_back(temp);
	}
	sort(list.begin(),list.end());
	build_bst();
	middle(record[1]);
	for(int i=0;i<record2.size();i++){
		record[record2[i]]->key=list[i];
	}
	level_traversal(record[1]);
	return 0;
}
