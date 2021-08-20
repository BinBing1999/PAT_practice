//hello world for u
#include<iostream>
#include<string>
using namespace std;


int main(){
	string s;
	string s2;
	cin>>s;
	int len=s.length();
	int k=0;int c;int b;
	for(int i=3;i<=len;i++){
		c=len+2-i;if(c%2==0){
			c/=2;if(c<=i&&c>k){
				k=c;b=i;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<k-1;i++){
		cout<<s[i];for(int j=0;j<b-2;j++)cout<<" ";cout<<s[len-i-1]<<endl;
		cnt++;
	}
	s2=s.substr(cnt,len-cnt*2);
	cout<<s2;
	
	return 0;
}
