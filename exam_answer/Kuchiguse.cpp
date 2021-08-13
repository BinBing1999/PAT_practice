//Kuchiguse
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string suffix(string a, string b){
	string s="";
	bool flag=1;
	int cc=a.size()-1;int dd=b.size()-1;//remember to reduce one to get in the region of array
	string t;
	while(flag&&cc>=0&&dd>=0){
		if(a[cc]==b[dd]){//&&a[cc]!=' '
			t=a[cc];
			s.insert(0,t);
			flag=1;cc--;dd--;
		}else flag=0;
		
	}
	//cout<<s;
	return s;
}


int main(){
	int n;
	cin>>n;
	string list[n];
	string c_out="";
	string temp1,temp2;
	char test[258];
	cin.getline(test,257);//read one more time to clear stream
	for(int i=0;i<n;i++){
		cin.getline(test,257);
		temp1=test;
		list[i]=temp1;
	}
	
	
		temp1=list[0];
		temp2=list[1];
		c_out=suffix(temp1,temp2);
		if(c_out==""){
			cout<<"nai";
			return 0;
		}
	for(int i=2;i<n;i++){
		temp1=list[i];
		c_out=suffix(temp1,c_out);
		if(c_out==""){
			cout<<"nai";
			return 0;
		}
	}
	cout<<c_out;
	return 0;
} 
