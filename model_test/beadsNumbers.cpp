//missing beads
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<string,int> shop;
string eva;

int main(){
	string temp;
	string temp2;
	
	int less=0;
	cin>>temp>>eva;
	for(int i=0;i<temp.length();i++){
		temp2=temp[i];
		map<string,int>::iterator iter;
		iter=shop.find(temp2);
		if(iter!=shop.end())iter->second++;
		else shop.insert(pair<string,int>(temp2,1));
	}
	for(int i=0;i<eva.length();i++){
		temp2=eva[i];
		map<string,int>::iterator iter;
		iter=shop.find(temp2);
		if(iter==shop.end()){
			less++;
		}
		else if(iter->second<1)less++;
		else{
			iter->second--;
		}
	}
	if(less>0)cout<<"No "<<less;
	else cout<<"Yes "<<temp.length()-eva.length();
	return 0;
}
