//significant digit
#include<iostream>
#include<string>
//#include<algorithm>
#include<cstdio>
using namespace std;


int main(){
	int n;double a,b;
	cin>>n>>a>>b;
	int cnt=0;
	double tem_a=a,tem_b=b;
	//for(int i=0;i<0;i++)cout<<"hi";//-------------------------
	if(a==0||b==0){//----------------------0 problem !!!!
	if(a==b){
		cout<<"YES "<<"0.";for(int i=0;i<n;i++)cout<<"0";
		cout<<"*10^0";
		return 0;
	}
	else{
		if(a==0){
			if(tem_b>=1){
		while(tem_b>=1){
		cnt++;tem_b/=10;
		}
		for(int i=0;i<n;i++){
		tem_b*=10;
		}
	} 
	else{
		while(tem_b<1){
			tem_b*=10;cnt--;
		}
		tem_b/=10;
		for(int i=0;i<n;i++){
		tem_b*=10;
		}
	}
	int ans_b=(int) tem_b;
	string sb=to_string(ans_b);int lenB=sb.length();//----------------------	
			cout<<"NO "<<"0.";for(int i=0;i<n;i++)cout<<"0";
			cout<<"*10"<<"^"<<0<<" ";
			printf("0.%d",ans_b);for(int i=0;i<n-lenB;i++)cout<<"0";
			cout<<"*10"<<"^"<<cnt;
		}	
		else{//b==0
			if(tem_a>=1){
		while(tem_a>=1){
		cnt++;tem_a/=10;
		}
		for(int i=0;i<n;i++){
		tem_a*=10;
		}
	} 
	else{
		while(tem_a<1){
			tem_a*=10;cnt--;
		}
		tem_a/=10;
		for(int i=0;i<n;i++){
		tem_a*=10;
		}
	}
	int ans_a=(int) tem_a;
	string sa=to_string(ans_a);int lenA=sa.length();//----------------------	
			cout<<"NO ";printf("0.%d",ans_a);for(int i=0;i<n-lenA;i++)cout<<"0";
			cout<<"*10"<<"^"<<cnt<<" ";
			cout<<"0.";for(int i=0;i<n;i++)cout<<"0";
			cout<<"*10"<<"^"<<0<<" ";
			
			
		}
		return 0;
	}
	}
	
	if(tem_a>=1){
		while(tem_a>=1){
		tem_a/=10;cnt++;tem_b/=10;
		}
		for(int i=0;i<n;i++){
		tem_a*=10;tem_b*=10;
		}
	} 
	else{
		while(tem_a<1){
			tem_a*=10;cnt--;tem_b*=10;
		}
		tem_a/=10;cnt++;tem_b/=10;
		for(int i=0;i<n;i++){
		tem_a*=10;tem_b*=10;
		}
	}
	int ans_a=(int) tem_a;int ans_b=(int) tem_b;
	string sa=to_string(ans_a);int lenA=sa.length();
	string sb=to_string(ans_b);int lenB=sb.length();//----------------------
	if(ans_a==ans_b){
		
			cout<<"YES ";printf("0.%d",ans_a);for(int i=0;i<n-lenA;i++)cout<<"0";//-----------------------------
		
			cout<<"*10"<<"^"<<cnt;
		
		
		
	}
	else {
			cout<<"NO ";printf("0.%d",ans_a);for(int i=0;i<n-lenA;i++)cout<<"0";
		
			cout<<"*10"<<"^"<<cnt<<" ";
	
			printf("0.%d",ans_b);for(int i=0;i<n-lenB;i++)cout<<"0";
		
			cout<<"*10"<<"^"<<cnt;
		
		
	}
	return 0;
}
