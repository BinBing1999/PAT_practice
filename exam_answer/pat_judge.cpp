//pat judge
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct user{
	int id;
	bool question[6]={0};
	int score[6]={-1,-1,-1,-1,-1,-1};//--------------cannot use score[6]={-1} this does not work
	int total=-1;
	int perf_cnt=0;
	bool able_show=0;
};

int perfecT(user a){
	int cnt=0;
	for(int i=0;i<6;i++){
		if(a.question[i])cnt++;
	}
	return cnt;
}

int totalScore(user a){
	int sum=0;bool non_sub=1;
	for(int i=0;i<6;i++){
		if(a.score[i]!=-1){
			sum+=a.score[i];non_sub=0;
		}
	}
	if(!non_sub)return sum;
	else  return -1;
}

bool cmp(user a,user b){
	bool flag=0;
	if(a.total>b.total)flag=1;
	else if(a.total==b.total&&a.perf_cnt>b.perf_cnt)flag=1;
	else if(a.total==b.total&&a.perf_cnt==b.perf_cnt&&a.id<b.id)flag=1;
	return flag;
}

int main(){
	int n,k,m;
	cin>>n>>k>>m;
	vector<int>perfect_score(k);//------------------ 
	int temp;
	for(int i=0;i<k;i++){
		cin>>temp;
		perfect_score[i]=temp;
	}
	user tem;
	int ID,ques,mark;
	vector<user> list(n+1);
	for(int i=0;i<n+1;i++){
		list[i]=tem;list[i].id=i;
	}		
	
	
	for(int i=0;i<m;i++){
		cin>>ID>>ques>>mark;
		if(mark>-1)list[ID].able_show=1;
		if(mark==-1)mark=0;
		if(list[ID].score[ques]<mark)list[ID].score[ques]=mark;
		if(mark==perfect_score[ques-1])list[ID].question[ques]=1;
	}
	
			
	for(int i=1;i<list.size();i++){
		list[i].total=totalScore(list[i]);
		list[i].perf_cnt=perfecT(list[i]);
	}
	sort(list.begin(),list.end(),cmp);
	int rank=1;int rank_new=1;
	for(int i=0;i<list.size();i++){
		if(list[i].able_show){
			cout<<rank<<" ";printf("%05d",list[i].id);cout<<" "<<list[i].total;
			for(int j=1;j<=k;j++){
				if(list[i].score[j]!=-1)cout<<" "<<list[i].score[j];
				else cout<<" "<<"-";
			}cout<<endl;
		}
		rank_new++;
		if(list[i].total!=list[i+1].total&&i!=list.size()-1)rank=rank_new;
		
	}
	return 0;
}
