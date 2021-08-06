//acute stroke 1004,DFS style
#include<iostream>
#include<cmath>
using namespace std;

struct node{
	//int count_flag;//not necessary
	int stroke_flag;
	 node(){
		//count_flag=0;
		stroke_flag=0;
	}
};
int cnt=0;
node matrix[60][1286][128];//z,x,y
int dx[6]={1,-1,0,0,0,0};int dy[6]={0,0,1,-1,0,0};int dz[6]={0,0,0,0,1,-1};//movement
int M,N,L,T;//input
void dfs(int x,int y,int z){
	cnt++;
	matrix[z][x][y].stroke_flag=0;
	int nx,ny,nz;
	for(int i=0;i<6;i++){
		nx=dx[i]+x;ny=dy[i]+y;nz=dz[i]+z;
		if((0<=nx&&nx<M)&&(0<=ny&&ny<N)&&(0<=nz&&nz<L)&&matrix[nz][nx][ny].stroke_flag==1){
			dfs(nx,ny,nz);
		}
	}	
}

int main(){
	cin>>M>>N>>L>>T;
	int volume=0;
	int test_flag;int temp;
	int sum=0;
	for(int i=0;i<L;i++){  //build 3-dimensional matrix for brain
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				cin>>matrix[i][j][k].stroke_flag;
			}		
		}
	}
	for(int i=0;i<L;i++){  //build 3-dimensional matrix for brain
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(matrix[i][j][k].stroke_flag==1){
					cnt=0;
					dfs(j,k,i);
					if(cnt>=T){
						sum+=cnt;
					}
				}
				//else skip
			}		
		}
	}
	cout<<sum;
	
	return 0;
}

/*BFS style
#include <bits/stdc++.h>
using namespace std;
int brain[1300][130][65];
int dx[6] = {1,-1,0,0,0,0},dy[6] = {0,0,1,-1,0,0},dz[6] = {0,0,0,0,1,-1};
int m,n,l,t;
struct position{
    int x,y,z;
    position(int x,int y,int z):x(x),y(y),z(z){}
};
int bfs(int x,int y,int z){
    int cnt = 0;
    queue<position> q;
    q.push(position(x,y,z));
    brain[x][y][z] = 0;
    while(!q.empty()){
        position pos = q.front();q.pop();
        cnt++;
        for(int i = 0;i < 6;i++){
            int nx = pos.x + dx[i],ny = pos.y + dy[i],nz = pos.z + dz[i];
            if((0 <= nx && nx < m) && (0 <= ny && ny < n) && (0 <= nz && nz < l) && brain[nx][ny][nz]){
                brain[nx][ny][nz] = 0;
                q.push(position(nx,ny,nz));
            }
        }
    }
    return cnt < t ? 0 : cnt;
}
int main() {
    scanf("%d %d %d %d",&m,&n,&l,&t);
    for(int z = 0;z < l;z++){
        for(int x = 0;x < m;x++){
            for(int y = 0;y < n;y++) scanf("%d",&brain[x][y][z]);
        }
    }
    int sum = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < l;k++) if(brain[i][j][k]) sum += bfs(i,j,k);
        }
    }
    printf("%d\n",sum);
    return 0;
}
*/

