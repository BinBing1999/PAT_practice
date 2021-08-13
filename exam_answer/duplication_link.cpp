#include<iostream>
#include<vector>
//#include<cmath>
#include<algorithm>
#include<cstdio>//!!!!!!!!!!!!!!!!!!!!uesful for more critical output requirement
using namespace std;
int key[100000]={0};
int head[100000]={0};
bool exist[100000]={0};
int pos=0; 

vector<int> linkone;
vector<int> linktwo;
vector<int> keyone;
vector<int> keytwo;


void shoW(int a){
	if(a<10)printf("0000%d",a);
	else if(a<100)printf("000%d",a);
	else if(a<1000)printf("00%d",a);
	else if(a<10000)printf("0%d",a);
	else 	printf("%d",a);
}

int main(){
	int add,k,nex;
	int N;
	cin>>add>>N;
	pos=add;
	for(int i=0;i<N;i++){
		cin>>add>>k>>nex;
		head[add]=nex;
		key[add]=k;
	}
	for(int i=0;i<N;i++){
		if(exist[abs(key[pos])]==1){
			keytwo.push_back(key[pos]);
			linktwo.push_back(pos);
		}else{
			keyone.push_back(key[pos]);
			linkone.push_back(pos);
			exist[abs(key[pos])]=1;
		}
		pos=head[pos];
	}
	for(int i=0;i<keyone.size();i++){
		shoW(linkone[i]);cout<<" "<<keyone[i]<<" ";
		if(i<keyone.size()-1){
			shoW(linkone[i+1]);
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	for(int i=0;i<keytwo.size();i++){
		shoW(linktwo[i]);cout<<" "<<keytwo[i]<<" ";
		if(i<keytwo.size()-1){
			shoW(linktwo[i+1]);
			cout<<endl;
		}
		else cout<<-1;
	}
	
	return 0;
}
