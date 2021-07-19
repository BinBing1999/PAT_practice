#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node{
	string account;
	string password;
};

int main(){
/////	string s1("hello,world!");
//s1.replace(6, 5, "girl");                       // £ºhello,girl.
//s1.replace(s1.size() - 1, 1, 1, '.');           // £ºhello,world.
//s1.replace(s1.begin(), s1.begin() + 5, "boy");  // £ºboy,girl.
	int n;
	int num_of_change=0;
	cin>>n;
	node temp;
	string ac[n];
	string pas[n];
	vector<node> vec(n);
	bool not_change=1;
	int position=0;
	int tempy;
	for(int i=0;i<n;i++){
		cin>>ac[i]>>pas[i];
		temp.account=ac[i];
		temp.password=pas[i];
		vec[i]=temp;
	}
	for(vector<node>::iterator it=vec.begin();it!=vec.end();it++){
		temp=*it;
		if(temp.password.find('1')!=string::npos){
			while(temp.password.find('1')!=string::npos){
				position=temp.password.find('1');
				temp.password.replace(position,1,"@");//to replace string, the char must be included by "" but not''
			}
		not_change=0;
		}
		if(temp.password.find('l')!=string::npos){
			while(temp.password.find('l')!=string::npos){
				position=temp.password.find('l');
				temp.password.replace(position,1,"L");
			}
		not_change=0;
		}
		if(temp.password.find('0')!=string::npos){
			while(temp.password.find('0')!=string::npos){
				position=temp.password.find('0');
				temp.password.replace(position,1,"%");
			}
		not_change=0;
		}
		if(temp.password.find('O')!=string::npos){
			while(temp.password.find('O')!=string::npos){
				position=temp.password.find('O');
				temp.password.replace(position,1,"o");
			}
		not_change=0;
		}
		if(not_change){
			vec.erase(it);
			it--;
		}
		if(!not_change){
			tempy=it-vec.begin();
			vec[tempy]=temp;
			num_of_change++;
		}
		not_change=1;//update
	}
	if(num_of_change>0){
		cout<<num_of_change<<endl;
	for(int i=0;i<num_of_change;i++){
		temp=vec[i];
		cout<<temp.account<<" "<<temp.password<<endl;
	}
	}
	else {
		if(n==1)cout<<"There is 1 account and no account is modified";
		else cout<<"There are "<<n<<" accounts and no account is modified";
	}
	return 0;
}
