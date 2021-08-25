//link_sorting
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int key;
	int address;
	int next;
};

node list_init[100010];
vector<node> list;

bool cmp(node a,node b){
	return a.key<b.key;
}


int main(){
	int n,head;cin>>n>>head;
	if(head==-1){
		cout<<0<<" "<<-1;return 0;
	}
	int addr,keykey,nex;
	node t;
	for(int i=0;i<n;i++){
		cin>>addr>>keykey>>nex;
		list_init[addr].address=addr;
		list_init[addr].key=keykey;
		list_init[addr].next=nex;
	}
	while(head!=-1){
		t=list_init[head];list.push_back(t);
		head=list_init[head].next;
	}
	if(list.size()==0){
		cout<<0<<" "<<-1;return 0;
	}
		
	sort(list.begin(),list.end(),cmp);
	for(int i=0;i<list.size();i++){
		if(i!=list.size()-1){
			list[i].next=list[i+1].address;
		}
		else list[i].next=-1;
	}
	printf("%d %05d",list.size(),list[0].address);
	cout<<endl;
	for(int i=0;i<list.size();i++){
		if(list[i].next!=-1)printf("%05d %d %05d",list[i].address,list[i].key,list[i].next);
		else printf("%05d %d %d",list[i].address,list[i].key,list[i].next);
		if(i!=list.size()-1)cout<<endl;
	}
	return 0;
}
