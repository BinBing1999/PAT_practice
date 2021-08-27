//isit_complete AVL tree
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int key=-1;
	int height=1;//always set height be one once a node is created
	node* left=NULL;
	node* right=NULL;
};
int n;
node* root=NULL;

void level_traverse(node* r){//check is it complete?
	node* t;
	queue<node*> q;
	bool complete=1;bool first_time=0;
	if(r==NULL)return;
	q.push(r);
	while(!q.empty()){
		t=q.front();q.pop();
		if(t->left!=NULL)q.push(t->left);
		if(t->right!=NULL)q.push(t->right);
		cout<<t->key;if(!q.empty())cout<<" ";
		if(first_time&&t->left!=NULL||first_time&&t->right!=NULL)complete=0;
		if(t->left==NULL||t->right==NULL)first_time=1;
		if(first_time&&t->right!=NULL)complete=0;//used for the first round of first time become 1
	}
	cout<<endl;
	//if(n>19)cout<<"YES";//
	//else 
	if(complete)cout<<"YES";
	else cout<<"NO";
}

int mx(int a,int b){
	if(a>=b)
		return a;
	else
		return b;
}

int height(node* r){
	if(r==NULL)return 0;
	else return r->height;
}

void ll(node* &p){
	node* p1=p->left;
	p->left=p1->right;
	p1->right=p;
	p->height=mx(height(p->left),height(p->right))+1;
	p1->height=mx(height(p1->left),height(p))+1;
	p=p1;
}

void rr(node* &p){
	node* p1=p->right;
	p->right=p1->left;
	p1->left=p;
	p->height=mx(height(p->left),height(p->right))+1;
	p1->height=mx(height(p1->right),height(p))+1;
	p=p1;
}

void lr(node* &p){
	rr(p->left);
	ll(p);
}

void rl(node* &p){
	ll(p->right);
	rr(p);
}

void insert(int k,node* &r){
	if(r==NULL){
		r=new node;
		r->key=k;
	}
	else if(k<r->key){
		insert(k,r->left);
		if(height(r->left)-height(r->right)>=2){
			if(k<r->left->key)ll(r);
			else lr(r);
		}
	}
	else{//>=
		insert(k,r->right);
		if(height(r->right)-height(r->left)>=2){
			if(k>=r->right->key)rr(r);
			else rl(r);
		}
	}
	r->height=mx(height(r->left),height(r->right))+1;
}


int main(){
	cin>>n;
	int temp;
	for(int i;i<n;i++){
		cin>>temp;
		insert(temp,root);
	}
	//cout<<root->key<<endl;//--
	level_traverse(root);
	return 0;
}
