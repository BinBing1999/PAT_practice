//shortest_road
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> record;
int total=0;
int len(int a,int b){
	int sum=0;
	int pos1=a-1;int pos2=b-1;
	if(pos1<pos2){
		for(int i=pos1;i<pos2;i++)sum+=record[i];
	}
	else{
		for(int i=pos2;i<pos1;i++)sum+=record[i];
	}
	if(sum>total-sum)return total-sum;
	return sum;
}


int main(){
	int n;cin>>n;
	int temp;int temp2;
	
	int chang=0;
	//vector<int> inverse_record;
	vector<int> one;
	vector<int> two;
	for(int i=0;i<n;i++){
		cin>>temp;
		total+=temp;
		record.push_back(temp);
	}
	//inverse_record=record;
	//reverse(inverse_record.begin(),inverse_record.end());
	int k;cin>>k;
	for(int j=0;j<k;j++){
		cin>>temp>>temp2;
		one.push_back(temp);two.push_back(temp2);
	}
	for(int i=0;i<k;i++){
		chang=len(one[i],two[i]);cout<<chang;
		if(i!=k-1)cout<<endl;
	}
	
	return 0;
}
