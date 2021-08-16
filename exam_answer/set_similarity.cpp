//set_similarity
#include<iostream>
#include<set>
#include<vector>
#include<iomanip>
using namespace std;
vector<set<int> > list;

void check(int a,int b){
	double similar=0;
	double same,total;
	if(list[b-1].size()<list[a-1].size()){
		for(set<int>::iterator it=list[b-1].begin();it!=list[b-1].end();it++){
			if(list[a-1].find(*it)!=list[a-1].end())same++;
		}
	}
	else{
		for(set<int>::iterator it=list[a-1].begin();it!=list[a-1].end();it++){
			if(list[b-1].find(*it)!=list[b-1].end())same++;
		}
	}
	total=list[a-1].size()+list[b-1].size();
	similar=same/(total-same);
	cout<<fixed<<setprecision(1)<<similar*100<<"%";
}

int main(){
	int n;
	cin>>n;
	vector<set<int> > q(n);
	int temp,temp2,temp3;
	for(int i=0;i<n;i++){
		cin>>temp;
		for(int j=0;j<temp;j++){
			cin>>temp2;
			q[i].insert(temp2);
		}
	}
	cin>>temp;
	vector<int> pp1;
	vector<int> pp2;
	for(int i=0;i<temp;i++){
		cin>>temp2>>temp3;
		pp1.push_back(temp2);
		pp2.push_back(temp3);
	}
	list=q;
	for(int i=0;i<temp;i++){
		temp2=pp1[i];temp3=pp2[i];
		check(temp2,temp3);if(i!=temp-1)cout<<endl;
	}
	return 0;
}
