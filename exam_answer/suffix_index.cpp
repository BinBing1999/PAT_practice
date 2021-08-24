//common suffix index
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int link[100010]={0};
string ram[100010];
vector<int> l1;
vector<int> l2;

int main(){
	int head1,head2;cin>>head1>>head2;
	int n;cin>>n; int temp1,temp2;string s;
	for(int i=0;i<n;i++){
		cin>>temp1>>s>>temp2; //
		ram[temp1]=s;
		link[temp1]=temp2;
		}
	while(head1!=-1){
		l1.push_back(head1);head1=link[head1];
	}
	while(head2!=-1){
		l2.push_back(head2);head2=link[head2];
	}
	if(l1.size()==0||l2.size()==0){
		cout<<-1;return 0;
	}
	for(int i=l1.size()/12*5;i<l1.size();i++){
		if(find(l2.begin(),l2.end(),l1[i])!=l2.end()){
			printf("%05d",l1[i]);return 0;
		}
	}
	cout<<-1;
	return 0;
}
