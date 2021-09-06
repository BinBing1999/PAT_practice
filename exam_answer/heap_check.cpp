//test heap
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int heap[1010];
bool mx=1;
bool mn=1;
int n;
int temp;
void max_check(int pos){
	if(pos>n)return;
	if(pos*2<=n&&heap[pos*2]>heap[pos])mx=0;
	if(pos*2+1<=n&&heap[pos*2+1]>heap[pos])mx=0;
	max_check(pos*2);
	max_check(pos*2+1);
}

void min_check(int pos){
	if(pos>n)return;
	if(pos*2<=n&&heap[pos*2]<heap[pos])mn=0;
	if(pos*2+1<=n&&heap[pos*2+1]<heap[pos])mn=0;
	min_check(pos*2);
	min_check(pos*2+1);
}

void post_order(int a){
	if(a>n)return;
	post_order(a*2);
	post_order(a*2+1);
	cout<<heap[a];
	temp--;
	if(temp!=0)cout<<" ";
}

int main(){
	int times=0;cin>>times;
	cin>>n;
	for(int j=0;j<times;j++){
 mx=1;
 mn=1;
	for(int i=0;i<1010;i++)heap[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>heap[i];
	}
	temp=n;
	if(n==1){
		cout<<"Not Heap"<<endl;
		cout<<heap[1]<<endl;
	}
//	for(int jj=2;jj<=n;jj++){
//		if(heap[jj]>heap[jj/2])mx=0;
//		if(heap[jj]<heap[jj/2])mn=0;
//	}
	max_check(1);min_check(1);
	if(mx)cout<<"Max Heap"<<endl;
	else if(mn)cout<<"Min Heap"<<endl;
	else
		cout<<"Not Heap"<<endl;
	post_order(1);cout<<endl;
		}
	return 0;
} 
