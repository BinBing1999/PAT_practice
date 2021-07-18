#include<iostream>
#include<string>
using namespace std;

struct node{
	int data;
struct	node* left;
struct	node* right;
}; 

int n;

void postorder(node* t){
	if(t==NULL)return;
	postorder(t->left);
	postorder(t->right);
	cout<<t->data;
	n--;//to avoid space at the end
	if(n!=0)cout<<" ";
}

int main(){
	node* stack[40];//less than 31 nodes
	int top=0;
	cin>>n;
	int datas;
	node* root;
	node* temp1;
	node* temp2;
	string s[2*n];
	for(int i=0;i<2*n;i++){
		cin>>s[i];
		if(s[i]=="Push"){
			cin>>datas;
			if(i==0){//root problem
				root=new node;
				root->data=datas;
				root->left=NULL;
			    root->right=NULL;
			    stack[top]=root;
			    temp1=root;top++;
			}
			else{//not root 
				temp2=new node;
				temp2->data=datas;
				temp2->left=NULL;
				temp2->right=NULL;
				stack[top]=temp2;
				if(temp1->left==NULL)temp1->left=temp2;
				else temp1->right=temp2;
				temp1=temp2;top++;
			}
		}
		
		else{//pop
		top--;
			temp1=stack[top];
		}
	}
	
	postorder(root);
	return 0;
}
