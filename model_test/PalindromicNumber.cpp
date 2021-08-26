//1024 Palindromic Number
#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> record;
vector<int> tem;
void to_base(int n,int base){
	
	int tt;
	while (n>0){
		tt=n%base;tem.push_back(tt);
		n/=base;
	}
	record=tem;
	reverse(record.begin(),record.end());
}


int main(){
	int n;int base;
	cin>>n>>base;
	to_base(n,base);
	int mid=record.size()/2;
	bool f=1;
	for(int i=0;i<mid;i++){
		if(record[i]!=tem[i])f=0;
	}
	if(f)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=0;i<record.size();i++){
		cout<<record[i];
		if(i!=record.size()-1)cout<<" ";
	}
	return 0;
}


//string s;
//	cin>>s;
//	const char*p = s.data();
//	double f=atof(p);
//	cout<<f;
//	
