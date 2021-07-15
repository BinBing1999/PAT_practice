#include<iostream>
#include<vector>

using namespace std;

void yuefen(long long&fenzi,long long&fenmu){
	for(int i=2;i<=fenzi;i++){
		if(fenzi%i==0&&fenmu%i==0){
			fenzi/=i;fenmu/=i;
			i--;
			continue;
		}
	}
	return;
}

void qiuzheng(long long&int_num,long long&fenzi,long long&fenmu){
	if(fenmu>fenzi)return;
	if(fenmu==fenzi){
		fenmu=0;
		fenzi=0;
		int_num++;
	}
	else{
		int_num=fenzi/fenmu;
		fenzi=fenzi%fenmu;
	}
	return;
}


int main(){
	int n;
	cin>>n;
	char temp;
	long long a,b;
	long long int_part=0;
	vector<long long> vec_fenzi(n);
	vector<long long> vec_fenmu(n);
	long long product=1;
	for(int i=0;i<n;i++){
		cin>>a>>temp>>b;
		vec_fenzi[i]=a;
		vec_fenmu[i]=b;  
		product*=b;
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=product/vec_fenmu[i]*vec_fenzi[i];//¤À¥À­n´À?¦¨product 
	}
	if(sum==0){
		cout<<0<<endl;
		return 0;
	}
	if(sum>0){
		qiuzheng(int_part,sum,product);
		yuefen(sum,product);
		if(int_part==0){
			cout<<sum<<"/"<<product;//no endl
			return 0;
		}
		else if(sum==0){
			cout<<int_part;
			return 0;
		}
		else{
			cout<<int_part<<" "<<sum<<"/"<<product;
			return 0;
		}
	} 
	else{
		long long tem=0-sum;
		qiuzheng(int_part,tem,product);
		yuefen(tem,product);
		if(int_part==0){
			sum=0-tem;
			cout<<sum<<"/"<<product;//no endl
			return 0;
		}
		else if(tem==0){
			int_part=0-int_part;
			cout<<int_part;
			return 0;
		}
		else{
			int_part=0-int_part;
			
			cout<<int_part<<" "<<tem<<"/"<<product;
			return 0;
		}
		
	}
	
	return 0;
}
