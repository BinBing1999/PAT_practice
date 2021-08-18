//be_unique
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int ar[10003]={0};
set<int> SET;
vector<int> list;

//bool unique(int x){
//	bool f=1;
//	if(x<10)return f;
//	while(x>=10){
//		if(ar[x%10]!=1)f=0;
//		x/=10;
//	}
//	if(ar[x]!=1)f=0;
//	return f;
//}

int main(){
	int n;cin>>n;int t;
	
	for(int i=0;i<n;i++){
		cin>>t;list.push_back(t);
		ar[t]++;
	}
	for(int i=0;i<list.size();i++){
		if(ar[list[i]]==1){
			cout<<list[i];return 0;
		}
	}
//	for(set<int>::iterator it=SET.begin();it!=SET.end();it++){
//		if(ar[*it]==1){
//				cout<<*it;
//				return 0;
//			
//		}
//	}
	
	
	cout<<"None";
	return 0;
}
