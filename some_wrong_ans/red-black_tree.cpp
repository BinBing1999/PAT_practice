//Is It A Red-Black Tree
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define maxy 40

struct node{
	int key=-1;
	node* left=NULL;
	node* right=NULL;
	bool red_black=0;//0 is black
};

vector<int> pre;
vector<int> mid;
bool red[maxy]={0};
node* root=NULL;
int cnt_black=0;
bool temp_f=0;
int cc=0;

void cleantree(node* r){
		if(r==NULL)return;
		cleantree(r->left);
		cleantree(r->right);
	delete r;r=NULL;
}

void clean(){
	for(int i=0;i<maxy;i++)red[i]=0;
	pre.clear();mid.clear();
	cleantree(root);
}

node* buildtree(vector<int> pred,vector<int> midd){
	int pos=0;
	if(midd.size()<=0)return NULL;
	for(int i=0;i<midd.size();i++){
		if(midd[i]==pred[0]){
			pos=i;break;//!!!
		}
	}
	node* head=new node;
	head->key=pred[0];
	if(red[pred[0]])head->red_black=1;
	vector<int>left_pre;vector<int>left_mid;
	vector<int>right_pre;vector<int>right_mid;
	for(int i=1;i<=pos;i++){
		left_pre.push_back(pred[i]);
		left_mid.push_back(midd[i-1]);
	}
	for(int i=pos+1;i<midd.size();i++){
		right_pre.push_back(pred[i]);
		right_mid.push_back(midd[i]);
	}
	head->left=buildtree(left_pre,left_mid);
	head->right=buildtree(right_pre,right_mid);
	return head;
}

void traverse(node* r){
	if(r==NULL){
		if(cnt_black==0)cnt_black=cc;
		else if(cnt_black!=cc)temp_f=1;
		else {
		}
		return;
	}
	if(!r->red_black)cc++;
	if(r->red_black){
		if(r->left->red_black||r->right->red_black)temp_f=1;
		if(r->left==NULL&&r->right!=NULL||r->left!=NULL&&r->right==NULL)temp_f=1;
	}
	traverse(r->left);
	traverse(r->right);
	
}


bool testtree(node* r){
	traverse(r);
	bool f=temp_f;
	temp_f=0;
	cnt_black=0;
	cc=0;
	if(f)return 0;
	else return 1;
}




int main(){
	int n;
	cin>>n;
	vector<bool> ans;
	int k,temp;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>temp;
			pre.push_back(abs(temp));
			if(temp<0)red[abs(temp)]=1;
		}
		mid=pre;sort(mid.begin(),mid.end());
		root=buildtree(pre,mid);
		bool f=testtree(root);
		if(red[pre[0]])f=0;
		ans.push_back(f);
		clean();
	}
	for(int i=0;i<ans.size();i++){
		if(ans[i])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
