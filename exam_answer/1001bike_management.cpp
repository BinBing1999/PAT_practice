#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define station_max_num 500
int temp=100;
int time_cnt=0,result_time=1000;
int outBikes=0,inBikes=0,result_in=0,result_out=0;
int adjacent_matrix[station_max_num+1][station_max_num+1]={0};//to store the path value
int c,n,sp,m;
vector<int> bike_num; 


vector<int>road;//to record the road
vector<int>result_road;//to record the road
vector<bool> arrived(station_max_num);//record which nodes have been arrived

void dfs(int start, int current_index, int dest)
{
    arrived[current_index] = 1;
    road.push_back(current_index);
    time_cnt += adjacent_matrix[start][current_index];
  //cout<<time_cnt<<" ";
  //cout<<road[road.size()-1]<<" ";
  //cout<<result_road[result_road.size()-1]<<" ";
    if(current_index == dest) {   // condition to limit iteration
        outBikes=0,inBikes=0;;
        for(int i=1; i<road.size(); i++) { // not containing bike number from node 0
            if(bike_num[road[i]] > c/2) {  //bike number more than half of capacity
                inBikes += bike_num[road[i]] -c/2;  //take back number
            } 
			else {
                if((c/2 - bike_num[road[i]]) < inBikes) {
                    inBikes -= (c/2 - bike_num[road[i]]);//compensation
                } 
				else {
                    outBikes += (c/2 - bike_num[road[i]]) - inBikes;
                    inBikes = 0; // all have been compensated
                }
            }
        }
        if(time_cnt != result_time) {
            if(time_cnt < result_time) {
                result_time=time_cnt;
                result_road=road;
                result_in=inBikes;
                result_out=outBikes;
            }
        } else if(outBikes != result_out) {
            if(outBikes < result_out) {
                result_road = road;
                result_out = outBikes;
                result_in = inBikes;
            }
        } else if(inBikes < result_in) {
            result_road = road;
            result_out = outBikes;
            result_in = inBikes;
        }
    } 
	else { //ain't the destination
        for(int i=1; i<=n; i++) {
            if(adjacent_matrix[current_index][i] != 0 && arrived[i]!=1) {
                dfs(current_index, i, dest);
            }
        }
    }
 
    // go back
    arrived[current_index] = 0;
    road.pop_back();
    time_cnt -= adjacent_matrix[start][current_index];
}


int main(){
	cin>>c>>n>>sp>>m;
	bike_num.push_back(temp);//the bike number in PBMC,a default value to avoid error
	arrived[0]=0;
	int si,sj,tij;
	for(int i=1;i<=n;i++){
		cin>>temp;
		bike_num.push_back(temp);
		arrived[i]=0;
	}
	//cout<<bike_num.size()<<endl;
	for(int i=1;i<=m;i++){
		cin>>si>>sj>>tij;
		adjacent_matrix[si][sj]=tij;
		adjacent_matrix[sj][si]=tij;
	}
	/*
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<adjacent_matrix[i][j];
			if(j!=3)cout<<" ";
			else cout<<endl;
		}
	}
	*/
	dfs(0,0,sp);
	//if(result_road.empty())cout<<"result empty"<<endl;
	//if(road.empty())cout<<"process empty"<<endl;
	cout<<result_out<<" "<<"0";
	for(int i=1;i<result_road.size();i++){
		cout<<"->"<<result_road[i];
	}cout<<" "<<result_in;
	
	return 0;
}
