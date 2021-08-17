//sort with swap(0)
//tips : find the loops of these number, if the loops contain 0, then the times equals number of elements in this loop,else+2.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sequence;//preserve number
int sum=0;
int cnt=0;
bool visited[100005]={0};

int traverse(int a){
	int num=0;bool zero_exist=0;
	if(a==0)zero_exist=1;
	//num++;
	visited[a]=1;
	for(int i=sequence[a];i!=a;i=sequence[i]){
		visited[i]=1;
		if(i==0)zero_exist=1;
		num++;
	}
	if(zero_exist)return num;
	return num+2;
}

int main(){
	int n;cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(i!=temp)sequence.push_back(temp);else sequence.push_back(-1);
	}
	for(int i=0;i<sequence.size();i++){
		if(sequence[i]!=-1&&!visited[i]){
			cnt=traverse(i);
			sum+=cnt;
		}
	}
	cout<<sum;
	return 0;
}
