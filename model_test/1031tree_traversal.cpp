#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n;//num of key

struct node{
	int data;
	node* left;
	node* right;
};
//pre_order+in_order
node* pre_construct_tree(vector<int> pre,vector<int> in){
	vector<int> left_pre, left_in, right_pre, right_in;
    int pos = 0;
    int length = in.size();//to get the length of the vec-------------------------! 
    if (length == 0)return NULL;
    node* head =new node;
	head->data=pre[0];
        for (int i = 0; i < length; ++i) {
             if (pre[0] == in[i]) {
                 pos = i;
                 break;
             }
         }
         for (int i = 1; i < pos + 1; ++i) {
             left_pre.push_back(pre[i]);
             left_in.push_back(in[i-1]);
         }
         for (int i = pos + 1; i < length; ++i) {
             right_pre.push_back(pre[i]);
             right_in.push_back(in[i]);
         }
         head->left = pre_construct_tree(left_pre, left_in);
         head->right = pre_construct_tree(right_pre, right_in);
         return head;
}

node* post_construct_tree(vector<int> post,vector<int> in){
	vector<int> left_post, left_in, right_post, right_in;
    int length = in.size();//to get the length of the vec-------------------------! 
    int pos = length-1;
    if (length == 0)return NULL;
    node* head =new node;
	head->data=post[pos];
        for (int i = 0; i < length; ++i) {
             if (post[pos] == in[i]) {
                 pos = i;
                 break;
             }
         }
         for (int i = 1; i < pos + 1; ++i) {
             left_post.push_back(post[i-1]);
             left_in.push_back(in[i-1]);
         }
         for (int i = pos + 1; i < length; ++i) {
             right_post.push_back(post[i-1]);
             right_in.push_back(in[i]);
         }
         head->left = post_construct_tree(left_post, left_in);
         head->right = post_construct_tree(right_post, right_in);
         return head;
}

void preorder(node* t){
	if(t==NULL)return;
	cout<<t->data<<' ';
	preorder(t->left);
	preorder(t->right);
	
}

void levelorder(node* t){
	queue<node*> que;
	node* temp;
	que.push(t);
	while(!que.empty()){
		temp=que.front();
		que.pop();
		if(temp->left!=NULL)que.push(temp->left);
		if(temp->right!=NULL)que.push(temp->right);
		cout<<temp->data;
		n--;
		if(n==0)return;
		else cout<<" ";
	}
}

int main(){
	cin>>n;
	vector<int> post_vec(n);
	vector<int> in_vec(n);
	node* tree_node;
	for(int i=0;i<n;i++){
		cin>>post_vec[i];
	}
	for(int i=0;i<n;i++){
		cin>>in_vec[i];
	}
	//tree_node=pre_construct_tree(post_vec,in_vec);
	tree_node=post_construct_tree(post_vec,in_vec);
	levelorder(tree_node);
	return 0;
}

//
/*
int build(int L1, int R1, int L2, int R2){
    if(L1 > R1) return  0;
    int proot = post_order[R2], pos;
    for(int i=0;i<n;i++){
        if(in_order[i] == proot){
            pos = i;
            break;
        }
    }
    int l_num = pos - L1; //左子树的结点个数
    lch[proot] = build(L1, pos-1, L2, L2+l_num-1);
    rch[proot] = build(pos+1, R1, L2+l_num, R2-1);
    return proot;
}
*/
