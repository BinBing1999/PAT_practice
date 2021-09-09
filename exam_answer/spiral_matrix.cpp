//1105 Spiral Matrix
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int> list;
int matrix[2000][2000]={{0}};

int main(){
	int n;cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		//cout<<temp<<" ";
		list.push_back(temp);
	}
	sort(list.begin(),list.end());
	//reverse(list.begin(),list.end());//large to small
	int m,nn;
	if(sqrt(n)*sqrt(n)==n)m=sqrt(n);
	else for(m=sqrt(n)+1;m<=n;m++)if(n%m==0)break;
	nn=n/m;//get size m*nn of matrix
	int u=1,v=nn,p=1,q=m;
	int cnt=n-1;
	int e=1,f=1;//row, column
	while(cnt>=0){
		if(cnt==0){
			matrix[e][f]=list[cnt];
			break;
		}
		while(cnt>=0&&f<v){
			matrix[e][f++]=list[cnt--];
		
		}
		while(cnt>=0&&e<q){
			matrix[e++][f]=list[cnt--];
			
		}
		while(cnt>=0&&f>u){
			matrix[e][f--]=list[cnt--];
			
		}
		while(cnt>=0&&e>p){
			matrix[e--][f]=list[cnt--];
		
		}
		u++;v--;p++;q--;
		e++;f++;
	}
	//cout<<cnt<<endl;
	for(int ii=1;ii<=m;ii++){
		for(int jj=1;jj<=nn;jj++){
			cout<<matrix[ii][jj];
			if(jj!=nn)cout<<" ";else cout<<endl;
		}
	}
	return 0;
}
