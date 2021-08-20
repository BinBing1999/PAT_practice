//hash of course and students
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<string,vector<int> > note;
typedef map<string,vector<int> >::iterator iter;

int main(){
	int n,k;cin>>n>>k;
	string name;
	int temp;int course;
	vector<int> t;//-------
	vector<string> list;
	for(int i=0;i<k;i++){
		cin>>course>>temp;
		for(int j=0;j<temp;j++){
			cin>>name;
			iter it;
			it=note.find(name);
			if(it!=note.end()){
				it->second.push_back(course);
			}
			else{
				t.push_back(course);
				note.insert(pair<string,vector<int> >(name,t));
				t.clear();
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>name;list.push_back(name);
	}
	//int z;
	for(int i=0;i<list.size();i++){
		cout<<list[i]<<" ";
		iter it;it=note.find(list[i]);
		cout<<it->second.size()	;
		t=it->second;
		sort(t.begin(),t.end());
		//if(t.size()!=0)cout<<t[0];
		for(int j=0;j<t.size();j++)cout<<" "<<t[j];
		if(i!=list.size())cout<<endl;
		t.clear();
	}
	
	
	return 0;
}
