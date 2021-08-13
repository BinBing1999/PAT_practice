//prime factors

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime;
int amount[100000000]={0};

bool is_prime(int n){
	bool flag=1;
	int n2=sqrt(n)+1;
	for(int i=2;i<n2;i++){
		if(n%i==0)flag=0;
	}
	return flag;
}

void get_prime_factor(int n){
	int cnt=2;
	while(n!=1&&cnt<=n){
		if(is_prime(n)){
			prime.push_back(n);
			amount[n]++;
			return;
		}
		if(is_prime(cnt)&&n%cnt==0){
			prime.push_back(cnt);
			amount[cnt]++;
				n/=cnt;
			while(n%cnt==0){
				amount[cnt]++;
				n/=cnt;
			}
			cnt=2;
		}
		else cnt++;
	}
}

int main(){
	int n;
	cin>>n;
	if(is_prime(n)){
		cout<<n<<"="<<n;
		return 0;
	}
	get_prime_factor(n);
	cout<<n<<"="<<prime[0];
	if(amount[prime[0]]>1)cout<<"^"<<amount[prime[0]];
	for(int i=1;i<prime.size();i++){
		cout<<"*"<<prime[i];if(amount[prime[i]]>1)cout<<"^"<<amount[prime[i]];
	}
	return 0;
}
