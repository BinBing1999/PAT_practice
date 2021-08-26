//1024 Palindromic Number
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
	long long n; int k;
	cin>>n>>k;
	string ss=to_string(n);
	string ss2;ss2=ss;reverse(ss2.begin(),ss2.end());
	int times=0;
	bool can_end=1;
	for(int i=0;i<ss.length()/2;i++)if(ss[i]!=ss2[i]){
			can_end=0;break;
		}
		if(can_end){
			cout<<ss<<endl;cout<<times;return 0;
		}
		can_end=1;
	int ii;
	for(ii=1;ii<=k;ii++){
		times++;can_end=1;
		const char* p2=ss2.data();
		const char* p=ss.data();
		long long num1 = atoll(p); 
		long long num2 = atoll(p2);
		num1+=num2;
		ss=to_string(num1);ss2=ss;reverse(ss2.begin(),ss2.end());
		for(int i=0;i<ss.length()/2;i++)if(ss[i]==ss2[i]){
			continue;
		}
		else {
			can_end=0;break;
		}
		if(can_end)break;
		
	}
	if(ii<=k){
		cout<<ss<<endl<<times;
	}
	else{
		cout<<ss<<endl<<k;
	}
	return 0;
}
