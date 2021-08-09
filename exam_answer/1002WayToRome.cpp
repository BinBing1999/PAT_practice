#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
using namespace std;
#define max_city 200//------------------------------------
//this algorithm cannot use when facing a big data set
int n,k;
int des_code;
int route[max_city][max_city]={0};
vector<string> cityname(max_city);//for one to one reference to int
int happiness[max_city]={0};
int routecost=0,result_routecost=10000;
int happy=0,result_happy=0;int tem_cnt=0;
int average_happy=0,result_average_happy=0;
int  num_of_least=0;
vector<int> path;
vector<int> result_path;
vector<bool>arrived(max_city);
/*
int find(string str[], string s,int size){
	int cnt=0;
	for(int i=0;i<size;i++)
	if(str[i]==s)cnt=i;
	return cnt;
}*/
//find(cityname,temp1,n) for find indexes
void DFS(int start, int cur,int dest){
	arrived[cur]=1;
	routecost+=route[start][cur];
	path.push_back(cur);
	
	if(cur==dest){
		happy=0;average_happy=0;tem_cnt=0;
		for(int i=1;i<path.size();i++){
			happy+=happiness[path[i]];
			tem_cnt++;
		}
		average_happy=happy/tem_cnt;
		//cout<<average_happy<<" "<<happy<<" "<<tem_cnt<<endl;
		if(routecost==result_routecost) num_of_least++;
		if(routecost!=result_routecost){
			if(routecost<result_routecost){
				result_routecost=routecost;
				result_path=path;
				result_happy=happy;
				result_average_happy=average_happy;
				num_of_least=0;
			}
		}
		else if(routecost==result_routecost&&happy>result_happy){ //add num of same routecost
				result_path=path; // no need to refresh the cost 
				result_happy=happy;
				result_average_happy=average_happy;
				//num_of_least++;
		}
		else if(routecost==result_routecost&&happy==result_happy&&average_happy>result_average_happy){
				result_path=path;
				result_happy=happy;
				result_average_happy=average_happy;
				//num_of_least++;
		}
		
	}
	else{
		for(int i=1;i<n;i++){
			if(route[cur][i]!=0&&!arrived[i]){
				DFS(cur,i,dest);
			}
		}
	}
	
	//go back
	arrived[cur]=0;
	routecost-=route[start][cur];
	path.pop_back();
}

int main(){
	string temp1,temp2;
	string des="ROM";
	int tem1,tem2;
	int cost;
	cin>>n>>k;
	cin>>cityname[0];
	happiness[0]=0;
	for(int i=1;i<n;i++){
		cin>>cityname[i];
		cin>>happiness[i];
		if(cityname[i]==des)des_code=i;
	}
	//cout<<des_code;//test----------------------------!
	for(int i=0;i<k;i++){
		cin>>temp1>>temp2>>cost;
		tem1=find(cityname.begin(),cityname.end(),temp1)-cityname.begin();
		tem2=find(cityname.begin(),cityname.end(),temp2)-cityname.begin();
		route[tem1][tem2]=cost;
		route[tem2][tem1]=cost;
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<route[i][j];
			if(j==n-1)cout<<endl;
			else cout<<" ";
		}
	}*/
	arrived.resize(200,0);// initialize
	DFS(0,0,des_code);
	
	//cout the figure
	cout<<++num_of_least<<" "<<result_routecost<<" "<<result_happy<<" ";//watch the number after point----------------
	cout<<result_average_happy<<endl;
	cout<<cityname[result_path[0]];
	for(int i=1;i<result_path.size();i++){
		cout<<"->"<<cityname[result_path[i]];
	}
	return 0;
}



