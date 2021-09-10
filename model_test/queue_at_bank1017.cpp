//queuing at bank
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	double in_minute=0;
	//double wait=0;
	double serve=0;
};
//node customer[10010];
queue<node> line;
vector<node> coss;
double window[110]={0};
//bool ok_use[110];
int n,k;
bool cmp(node a,node b){
	return a.in_minute<b.in_minute;
}


int main(){
	cin>>n>>k;
	double h,m,s;double minute;
	node temp;
	for(int i=0;i<n;i++){
		scanf("%lf:%lf:%lf",&h,&m,&s);
		cin>>temp.serve;
		//cout<<h<<" "<<m<<" "<<s<<" "<<endl;//
		minute=h*60.0+m+s/60.0;
		temp.in_minute=minute;
		coss.push_back(temp);
	}
	sort(coss.begin(),coss.end(),cmp);
	for(int i=0;i<coss.size();i++)line.push(coss[i]);
	double wait_time=0;bool f=0;
	for(int i=0;i<coss.size();i++){
		temp=line.front();
	//	cout<<temp.in_minute<<" ";
		int sml=window[0];int sml_pos=0;
		if(temp.in_minute<8*60){
		wait_time+=(8*60-temp.in_minute);//
		temp.in_minute=8*60.0;
	}
		if(temp.in_minute>17*60){
			n--;line.pop();//-------------!
			continue;
		}
		for(int ii=0;ii<k;ii++){
			if(window[ii]<=temp.in_minute){
				window[ii]=temp.in_minute;f=1;
				window[ii]=temp.in_minute+temp.serve;
				break;
			}
			else{
				if(window[ii]<=sml){
					sml=window[ii];sml_pos=ii;f=0;
				}
			}
		}
		if(!f){
			wait_time+=(sml-temp.in_minute);
			window[sml_pos]=window[sml_pos]+temp.serve;//----
		}
		cout<<wait_time<<endl;
		line.pop();//f=0;
	}
	printf("%.1f",wait_time/n);
	
	return 0;
}
