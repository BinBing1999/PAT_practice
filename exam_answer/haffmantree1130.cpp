////haffman tree for polinomal expression
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	string key="";
	node* left=NULL;
	node* right=NULL;
};

node* tree[22];
string ss;
bool vis[30]={0};
node* r;

string middle(node* root){
	if(root==NULL)return "";
	string l1;string r1;string m1;string total;
	l1=middle(root->left);
	m1=root->key;
	r1=middle(root->right);
	total=l1+m1+r1;
	if(root==r)return total;
	if(total!=m1)return "("+total+")";//!=r
	return total;
}

int main(){
	int n;cin>>n;
	for(int i=0;i<=n;i++)tree[i]=new node;
	string k;
	int k1,k2;
	for(int i=1;i<=n;i++){
		cin>>k>>k1>>k2;
		tree[i]->key=k;
		if(k1!=-1){
			tree[i]->left=tree[k1];//----------------no problem
			vis[k1]=1;//-------------------------- find the root
		}
		if(k2!=-1){
			tree[i]->right=tree[k2];
			vis[k2]=1;
		}
	}
	for(int i=1;i<n;i++){
		if(!vis[i]){
			r=tree[i];//promise to have the exact root
			break;
		}
		
	}
	ss=middle(r);
	cout<<ss;
	return 0;
}

