#include<iostream>
using namespace std;

bool sushu(int in){
    bool flag=1;
    for(int i=2;i<in;++i){
        if(in%i==0)flag=0;
        if(!flag)break;
    }
    return flag;
}

int main(){
    int m,n;
    cin>>m>>n;
    int count=1;
    for(int jj=m;jj<=n;jj++){
        if(sushu(jj)){
         if(count==10)cout<<jj<<endl;   
            else cout<<jj<<" ";
            count++;
    //     cout<<jj<<endl;
        }
        if(count>10)count=1;
    }
    return 0;
}
