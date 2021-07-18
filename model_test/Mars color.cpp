#include<iostream>
using namespace std;
int main(){
	int array[3];
	cin>>array[0]>>array[1]>>array[2];
	char showout[7];
	showout[0]='#';
	int temp;
	for(int i=0;i<3;i++){
		temp=array[i]%13;
		switch(temp){
			case 0:showout[2*(i+1)]='0';break;
			case 1:showout[2*(i+1)]='1';break;
			case 2:showout[2*(i+1)]='2';break;
			case 3:showout[2*(i+1)]='3';break;
			case 4:showout[2*(i+1)]='4';break;
			case 5:showout[2*(i+1)]='5';break;
			case 6:showout[2*(i+1)]='6';break;
			case 7:showout[2*(i+1)]='7';break;
			case 8:showout[2*(i+1)]='8';break;
			case 9:showout[2*(i+1)]='9';break;
			case 10:showout[2*(i+1)]='A';break;
			case 11:showout[2*(i+1)]='B';break;
			case 12:showout[2*(i+1)]='C';break;
		}
		temp=(array[i]/13)%13;
		switch(temp){
			case 0:showout[2*(i+1)-1]='0';break;
			case 1:showout[2*(i+1)-1]='1';break;
			case 2:showout[2*(i+1)-1]='2';break;
			case 3:showout[2*(i+1)-1]='3';break;
			case 4:showout[2*(i+1)-1]='4';break;
			case 5:showout[2*(i+1)-1]='5';break;
			case 6:showout[2*(i+1)-1]='6';break;
			case 7:showout[2*(i+1)-1]='7';break;
			case 8:showout[2*(i+1)-1]='8';break;
			case 9:showout[2*(i+1)-1]='9';break;
			case 10:showout[2*(i+1)-1]='A';break;
			case 11:showout[2*(i+1)-1]='B';break;
			case 12:showout[2*(i+1)-1]='C';break;
		}
	}
	for(int i=0;i<7;i++)cout<<showout[i];
	return 0;
}
