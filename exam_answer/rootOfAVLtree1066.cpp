//building AVL tree
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct node{
	int key;
	node* left=NULL;
	node* right=NULL;
	int height=0;
};

node* root=NULL;

int mx(int a,int b){
	if(a>b)return a;
	else return b;
}

int height(node* p){
	if(p==NULL)return 0;
	else return p->height;
}


void LL(node* &p){
	node* p1=p->left;//future root
	p->left=p1->right;
	p1->right=p;
	p->height=mx(height(p->left),height(p->right))+1;
	p1->height=mx(height(p1->left),height(p))+1;
	p=p1;
}

void RR(node* &p){
	node* p1=p->right;//future root
	p->right=p1->left;
	p1->left=p;
	p->height=mx(height(p->left),height(p->right))+1;
	p1->height=mx(height(p1->right),height(p))+1;
	p=p1;
}

void LR(node* &p){
	RR(p->left);
	LL(p);
}

void RL(node* &p){
	LL(p->right);
	RR(p);
}

void insert(int k,node* &r){//remember using & for configure the root itself  ,not value pass
	if(r==NULL){
		r=new node;
		r->key=k;r->height=1;//cout<<"new"<<" ";
	}
	else if(k<r->key){
		insert(k,r->left);//cout<<"left"<<" ";
		if(height(r->left)-height(r->right)>=2){//!!!!---!!!//---! non balance deal
			if(k<r->left->key)LL(r);
			else LR(r);
		}
	}
	else{//when>= insert to right side
		insert(k,r->right);//cout<<"right ";
		if(height(r->right)-height(r->left)>=2){//!!!-!!!!//--!
			if(k>r->right->key)RR(r);
			else RL(r);
		}
	}
	r->height=mx(height(r->left),height(r->right))+1; // uusing cursive way to adjust all height
}

int main(){
	int n;cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		insert(temp,root);		
	}
	cout<<root->key;
	return 0;
}
