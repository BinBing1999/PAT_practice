//find prime in string
#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
bool is_prime(int a){
	if(a==1||a==0)return 0;
	for(int i=2;i*i<=a;i++)
		if(a%i==0)return 0;
	return 1;
}

int main(){
    string nums;
	int n,k;cin>>n>>k>>nums;
	//cin>>nums;
	//int len=nums.length();
	string stemp;
	for(int i=0;i<=n-k;i++){
		stemp=nums.substr(i,k);
		//const char* p=stemp.data();
        int jjj=stoi(stemp);
		if(is_prime(jjj)){
			cout<<stemp;return 0;//----------------------cout the string but not the int itself due to unknown reason 
		}
	}
	cout<<"404\n";
	return 0;
}
