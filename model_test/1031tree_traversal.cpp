#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
//pre_order+in_order
node* construct_tree(vector<int> pre,vector<int> in){
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
         head->left = construct_tree(left_pre, left_in);
         head->right = construct_tree(right_pre, right_in);
         return head;
}

void preorder(node* t){
	if(t==NULL)return;
	cout<<t->data<<' ';
	preorder(t->left);
	preorder(t->right);
	
}

int main(){
	int n;
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
	tree_node=construct_tree(post_vec,in_vec);
	preorder(tree_node);
	return 0;
}
