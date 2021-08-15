//binary search tree
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
	int key;
	int pos;
	node* left;node* right;
};
node* pointers[200];
vector<int> serial;
vector<int> record;//to remember which pos has which key

void midOrder(node* root){
	if(root==NULL){
		return;
	}
	midOrder(root->left);
	record.push_back(root->pos);
	midOrder(root->right);
}


void level_traverse(node* root){
	node* p=root;
	queue<node*> line;
	line.push(p);
	while(!line.empty()){
		p=line.front();
		line.pop();
		if(p->left!=NULL)line.push(p->left);
		if(p->right!=NULL)line.push(p->right);
		cout<<p->key;if(!line.empty())cout<<" ";
	}
}

int main(){
	int n,t;
	int l,r;
	cin>>n;
	for(int i=0;i<200;i++){
		pointers[i]=new node;
	} 
	for(int i=0;i<n;i++){
		cin>>l>>r;
		pointers[i]->pos=i;//
		if(l!=-1)pointers[i]->left=pointers[l];
		else pointers[i]->left=NULL;
		if(r!=-1)pointers[i]->right=pointers[r];
		else pointers[i]->right=NULL;
	}
	for(int i=0;i<n;i++){
		cin>>t;
		serial.push_back(t);
	}
	sort(serial.begin(),serial.end());
	//for(int i=0;i<serial.size();i++)cout<<serial[i]<<" ";
	//cout<<endl;
	midOrder(pointers[0]);
	for(int i=0;i<record.size();i++){
		t=record[i];
		pointers[t]->key=serial[i];
	}
	
	level_traverse(pointers[0]);
	
	return 0;
}
