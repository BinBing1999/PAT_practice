//finding average 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
using namespace std;

int main(){
	int n;cin>>n;
	string stemp;bool f=0;bool dot=0;int tpoint=-1;
	double temp;
	double num=0;
	double sum=0;
	for(int i=0;i<n;i++){
		cin>>stemp;
		for(int j=0;j<stemp.length();j++){
			if(stemp[j]<'0'||stemp[j]>'9'){//
				if(stemp[j]=='.'){
					if(j==0||dot){
						f=1;break;	
					}
					else if(j==1&&stemp[j-1]=='-'){
						f=1;break;
					}
					else {
						dot=1;f=0;tpoint=j;
					}
				}
				else if(stemp[j]=='-'){
					if(j==0){
						if(stemp.length()==1){
							f=1;break;
						}
						else f=0;
					}
					
					else {
						f=1;break;
					}
				}
				else{
					f=1;break;
				}
			}
		}
		if(f)cout<<"ERROR: "<<stemp<<" is not a legal number"<<endl;
		else if(tpoint!=-1&&stemp.length()-tpoint-1>2||stemp.length()==0||stemp.length()-1==tpoint)cout<<"ERROR: "<<stemp<<" is not a legal number"<<endl;
		else{
			const char* p=stemp.data();
			temp=atof(p);
			if(temp>1000||temp<-1000){
				cout<<"ERROR: "<<stemp<<" is not a legal number"<<endl;
				f=1;
			}
			else{
				num++;sum+=temp;
			}
		}
		f=0;dot=0;tpoint=-1;
	}
	if(num==0)cout<<"The average of 0 numbers is Undefined";
	else printf("The average of %d numbers is %0.2f",(int)num,sum/num);
	return 0;
}


