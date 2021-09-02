//hash_table collision solution
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> HashTable(10010);//initial are zero
//if non-only-positive input, we have to correct all 0 to -1; 
int n,m,sizeinit;int sizes;

bool is_prime(int b){
	for(int i=2;i*i<=b;i++){
		if(b%i==0)return 0;
	}
	return 1;
}

int least_prime(int a){
	int ans=a;
	while(!is_prime(ans))ans+=1;
	return ans;
}

void ins(int a){
	int pos;
	bool f=0;
		for(int i=0;i<sizes;i++){
			pos=a+i*i;
			if(HashTable[(pos)%sizes]==0){//----------------------loop insertion!
				HashTable[(pos)%sizes]=a;
				f=1;
				break;
			}
		}
	if(!f) cout<<a<<" cannot be inserted."<<endl;
}

int check(int a){
	int pos= a;
	int cnt=0;
	if(HashTable[pos%sizes]==a){
		cnt++;
	}
	else{
		cnt++;
		for(int i=1;i<=sizes;i++){
			if(HashTable[(pos+i*i)%sizes]==a||HashTable[(pos+i*i)%sizes]==0){//---------------------
				cnt++;break;
			}
			cnt++;
		}
	}
	return cnt;
}

vector<int> insertion;
vector<int>checker;

int main(){
	cin>>sizeinit;
	cin>>n>>m;
	sizes=least_prime(sizeinit);
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		insertion.push_back(temp);
	}
	double ccnntt=0;
	for(int i=0;i<m;i++){
		cin>>temp;
		if(temp>0)checker.push_back(temp);
		
	}
	for(int i=0;i<insertion.size();i++)ins(insertion[i]);
	for(int i=0;i<checker.size();i++)ccnntt+=(double)check(checker[i]);
	if(m==0)printf("%0.1f",ccnntt);
	else printf("%0.1f",ccnntt/((double)m));
	return 0;
}
