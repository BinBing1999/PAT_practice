//shuffling mac
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int cards_order[55]={0};
vector<vector<int> >result(1);
int main(){
	int k;cin>>k;
	for(int i=1;i<=54;i++)cin>>cards_order[i];
	for(int i=0;i<=54;i++)result[0].push_back(i);//the initial states
	//cout<<"stae1"<<endl;
	for(int i=1;i<=k;i++){
		result.push_back(result[i-1]);
		for(int j=1;j<=54;j++)
				result[i][cards_order[j]]=result[i-1][j];
	}
	//cout<<"test"<<endl;//
	int gg=result.size();int tem;
	for(int i=1;i<=54;i++){
		tem=result[gg-1][i];
		if(tem<=13)if(tem==13) printf("S%d",13);else printf("S%d",tem%13);
		else if(tem<=26)if(tem==26)printf("H%d",13);else printf("H%d",tem%13);
		else if(tem<=39)if(tem==39)printf("C%d",13);else printf("C%d",tem%13);
		else if(tem<=52)if(tem==52)printf("D%d",13);else printf("D%d",tem%13);
		else printf("J%d",tem-52);
		if(i<54)cout<<" ";
	}
	
	return 0;
}
