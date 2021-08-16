//calculation of 2^64 integer

#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	long double a,b,c;
	bool ans[10000]={0};
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a+b>c){
			ans[i]=1;
		}
		else{
			ans[i]=0;
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i]){
			cout<<"Case #"<<i+1<<": true";
			if(i!=n-1)cout<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": false";
			if(i!=n-1)cout<<endl;
		}
	}
	
	return 0;
}
