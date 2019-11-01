/*
分析：直接想到两次bfs然后扫一次求点最小 有个重点的地方！
就是那点必须是两个人都能走到的！！wa了2次 
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
const int N=200+5;
char map[N][N];
bool book[N][N];
short ok[N][N];
int re[N][N];
int n,m;
struct Node{
	int x,y,step;
}node,tmp;
queue<Node> q;
int step[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
inline void bfs(int bx,int by){
		memset(book,0,sizeof(book));
	while(!q.empty())  q.pop();	
		 node.x=bx;
		 node.y=by;
		 node.step=0;
		 q.push(node);
		 book[bx][by]=1;
	while(!q.empty()){
		node=q.front();
		q.pop();
		if(map[node.x][node.y]=='@'){
			 ok[node.x][node.y]++;
			re[node.x][node.y]+=node.step;
		}
		 
		   int i;
		for(i=0;i<4;i++){
			int a=node.x+step[i][0];
			int b=node.y+step[i][1];
			if(a<0||a>=n||b<0||b>=m||book[a][b]||map[a][b]=='#'
		/*	||map[a][b]=='M'||map[a][b]=='Y'*/)
			continue;
			book[a][b]=1;
			tmp.x=a;
			tmp.y=b;
			tmp.step=node.step+11;
			q.push(tmp);
		}
	}
}
int main(){
	int i,j,x1,y1,x2,y2;
	while(scanf("%d%d",&n,&m)==2){
		memset(re,0,sizeof(re));	
			memset(ok,0,sizeof(ok));	
		for(i=0;i<n;i++){
			 scanf("%s",map[i]);
			 for(j=0;j<m;j++){
			 	if(map[i][j]=='Y'){
			 		x1=i;
			 		y1=j;
				 }
				if(map[i][j]=='M'){
			 		x2=i;
			 		y2=j;
				 }
			 }
		}
		bfs(x1,y1);
		bfs(x2,y2);
		int small=99999999;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		  if(map[i][j]=='@'&&ok[i][j]==2&&small>re[i][j])
		     small=re[i][j];
		     printf("%d\n",small);
	}
	return 0;
}
