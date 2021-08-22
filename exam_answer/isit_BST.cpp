//is it a BST?
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//only two sequence can confirm one tree----------------!¡I 
int n;//total num of keys
struct node{
	int key=-1;
	node* left=NULL;
	node* right=NULL;
};
vector<int> keypre;
vector<int> keyin1;
vector<int> keyin2;
vector<int> test1;
vector<int> test2;

//void mid(node* r){
//	if(r==NULL)return ;
//	mid(r->left);
//	cout<<r->key<<" ";
//	mid(r->right);
//}

void post_order(node* r){
	if(r==NULL)return;
	post_order(r->left);
	post_order(r->right);
	cout<<r->key;
	n--;if(n!=0)cout<<" ";//----------------!
}

void pre_test(node* r){
	if(r==NULL)return;
	test1.push_back(r->key);
	pre_test(r->left);
	pre_test(r->right);
	 
}

void mid_test(node* r){
	if(r==NULL)return;
	mid_test(r->left);
	test2.push_back(r->key);
	mid_test(r->right);
}

node* buildtree_pre1(vector<int> pre,vector<int> in){//--more practice!
	node* head;int pos=0;//--------------------------!pos must have initial value
	int len=in.size();if(len==0)return NULL;
	if(pre.size()!=in.size())return NULL;
	head=new node;
	head->key=pre[0];
	vector<int> left_pre;vector<int> left_in;vector<int> right_pre;vector<int> right_in;
	for(int i=0;i<len;i++){
		if(pre[0]==in[i]){
			pos=i;break;//break once confirm------------------because there will be equal keys at the back, not stopping could cause no alignment--!
		}
	}
	for(int i=1;i<pos+1;i++){
		left_pre.push_back(pre[i]);
		left_in.push_back(in[i-1]);
	}
	for(int i=pos+1;i<len;i++){
		right_pre.push_back(pre[i]);
		right_in.push_back(in[i]);
	}
	head->left=buildtree_pre1(left_pre,left_in);
	head->right=buildtree_pre1(right_pre,right_in);
	return head;
}

node* buildtree_pre2(vector<int> pre,vector<int> in){//--more practice!
	node* head;int pos=0;
	int len=in.size();if(len==0)return NULL;
	if(pre.size()!=in.size())return NULL;
	head=new node;
	head->key=pre[0];
	vector<int> left_pre;vector<int> left_in;vector<int> right_pre;vector<int> right_in;
	for(int i=0;i<len;i++){
		if(pre[0]==in[i]){
			pos=i;//dont break until no equals one------------------because there will be equal keys at the front, not stopping could cause no alignment--!
		}
	}
	for(int i=1;i<pos+1;i++){
		left_pre.push_back(pre[i]);
		left_in.push_back(in[i-1]);
	}
	for(int i=pos+1;i<len;i++){
		right_pre.push_back(pre[i]);
		right_in.push_back(in[i]);
	}
	head->left=buildtree_pre2(left_pre,left_in);
	head->right=buildtree_pre2(right_pre,right_in);
	return head;
}


int main(){
	int t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;keypre.push_back(t);
	}
	keyin1=keypre;sort(keyin1.begin(),keyin1.end());//1~n
	keyin2=keyin1;reverse(keyin2.begin(),keyin2.end());//n~1
	node* root;
	root=buildtree_pre1(keypre,keyin1);//type1
	pre_test(root);
	mid_test(root);
	bool f=1;
	for(int i=0;i<test1.size();i++){
		if(test1[i]!=keypre[i])f=0;//-------------------------!
	}
	for(int i=0;i<test2.size();i++){
		if(test2[i]!=keyin1[i])f=0;//-------------------------!
	}
	//mid(root);
	if(f){
		cout<<"YES"<<endl;
		post_order(root);//cout<<endl<<"jj";
		return 0;
	}
	test1.clear();//-------------------------!
	test2.clear();
	f=1;//----
	root=buildtree_pre2(keypre,keyin2);//type2
	pre_test(root);
	mid_test(root);
	for(int i=0;i<test1.size();i++){
		if(test1[i]!=keypre[i])f=0;
	}
	for(int i=0;i<test2.size();i++){
		if(test2[i]!=keyin2[i])f=0;
	}
	if(f){
		cout<<"YES"<<endl;
		post_order(root);
		return 0;
	}
	//type3
	cout<<"NO";
	return 0;
}
