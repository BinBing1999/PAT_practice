#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

struct node{  //tree node for forest
	int name;
	node* head;
};

int main(){
	int n;
	double price, rate;
	cin>>n>>price>>rate;
	vector<int> data(n);
	int temp,temp2;
	node* root;
	root=new node;
	root->name=-1;
	root->head=NULL;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	vector<node*> node_list(n);
	node* tp;
	for(int i=0;i<n;i++){
		tp=new node;
		tp->name=i;
		node_list[i]=tp;
	}
	for(int i=0;i<n;i++){
		if(data[i]!=-1){
			tp=node_list[i];
			temp2=data[i];
			tp->head=node_list[temp2];
		}
		else{
			tp=node_list[i];//must use tempo variable to get the data from vector 
			tp->head=root;
		}
	}
	int len;int max_len=0;int max_len_pos=0;int total_count=0;
	for(int i=0;i<n;i++){
		tp=node_list[i];
		len=0;
		while(tp->head!=NULL){
			//cout<<tp->name<<" ";//
			tp=tp->head;
			len++;
		}
		if(len>max_len){
			max_len=len;
			max_len_pos=i;
			total_count=1;
		}
		else if(len==max_len)total_count++;
		//cout<<len<<" "<<max_len<<" "<<max_len_pos<<endl;//
	}
	double highest_price=price*pow(rate/100+1, max_len);
	cout<<fixed<<setprecision(2)<<highest_price;
	cout<<" ";
	cout<<total_count;
//	cout<<endl<<max_len;
	return 0;
}



