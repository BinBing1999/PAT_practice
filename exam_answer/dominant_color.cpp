//The Dominant Color (20)
#include<iostream>
//#include<algorithm>
#include<set>
#include<vector>
#include<map>

using namespace std;

int main(){
	set<int> SET;
	//int record[10000000]={0};
	map<int,int> mapRecord;
	int m,n;cin>>m>>n;
	int temp;int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>temp;cnt++;
			map<int,int>::iterator iter=mapRecord.find(temp);
			if(iter!=mapRecord.end())iter->second++;//-------------------!!!
			else mapRecord.insert(pair<int,int>(temp,1));
			SET.insert(temp);
		}
	}
	for(set<int>::iterator it=SET.begin();it!=SET.end();it++){
		if(mapRecord.find(*it)->second>cnt/2)cout<<*it;
	}
	
	return 0;
}
