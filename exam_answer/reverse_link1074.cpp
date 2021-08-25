//reverse link 1074
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int key,address,next;
	
	
};
node array[100010];
vector<node> list;
vector<node> reversed;
int main(){
	int head,n,k;cin>>head>>n>>k;
	if(head==-1){
		return 0;
	}
	int add,ky,nex;node t;
	for(int i=0;i<n;i++){
		cin>>add>>ky>>nex;
		array[add].address=add;
		array[add].key=ky;
		array[add].next=nex;
	}	
	while(head!=-1){
		t=array[head];list.push_back(t);
		head=array[head].next;
	}
	for(int i=0;i<list.size();){
		if(k<=list.size()-i){
			for(int j=i+k-1;j>=i;j--){
				reversed.push_back(list[j]);
			}
			i+=k;
		}
		else{
			for(int j=i;j<list.size();j++){
				reversed.push_back(list[j]);
			}
			break;//end it loop
		}
	}
	for(int i=0;i<reversed.size();i++){
		printf("%05d %d ",reversed[i].address,reversed[i].key);
		if(i!=reversed.size()-1)printf("%05d\n",reversed[i+1].address);
		else cout<<-1;
	}
	
	return 0;
}
