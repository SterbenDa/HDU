/*
思路： 
很明显dfs超时 手贱还要敲完  回溯很没效率
BFS可以只走一次  n*m的步数最多  
枚举4个状态做4次队列 
*/
/*超时的dfs 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=100+5;
bool book[N][N];
bool ok;
int n,m,k;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  //上下左右  0123
int sx,sy,ex,ey;
char map[N][N];
void dfs(int last,int turn,int x,int y){
	 if(turn>k)
	   return;
	 if(ok)
	  return;
	 if(x==ex&&y==ey)
	 {
	 	ok=1;
	 	return;
	 }	 
	 for(int i=0;i<4;i++){
	 	int a=x+step[i][0];
	 	int b=y+step[i][1];
	 	if(a<0||b<0||a>=n||b>=m||book[a][b]||map[a][b]=='*')
	 	  continue;
	 	  book[a][b]=1;
	 	  if(i!=last)
	 	    dfs(i,turn+1,a,b);
	 	   else
	 	     dfs(i,turn,a,b);
	 	if(ok)
	 	      return;
	 	  book[a][b]=0;
	 }
} 
int main(){ 
    int t,i,j;
    scanf("%d",&t);
    while(t--){
    	 ok=0;
    	memset(book,0,sizeof(book));
    	scanf("%d%d",&n,&m);
    	for(i=0;i<n;i++)
    	     scanf("%s",map[i]);
    	     
    	 //  for(i=1;i<=n;i++){
    	 //    	 for(j=1;j<=m;j++)
    	 //    	  printf("%c",map[i][j]);
    	 //    	  printf("\n");
		//	 }
    	  	  
    	scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
    	
    	sx--;
    	sy--;
    	ex--;
		ey--;
		 
		book[sx][sy]=1;
		for(i=0;i<4;i++)   //枚举起始朝向 
		{
			dfs(i,0,sx,sy);
			if(ok)
			 break;
		} 			
		if(ok)
		  printf("yes\n");
		else
		 printf("no\n");
	}
	return 0;
}
*/
/*   爆内存 
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int N=100+5;
bool book[N][N];
bool ok;
int n,m,k;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  //上下左右  0123
int sx,sy,ex,ey;
char map[N][N];
struct Node{
	int x,y,turn,last;
}node,tmp;
queue<Node> q;
int main(){ 
    int t,i,j;
    scanf("%d",&t);
    while(t--){
    	 ok=0;
    	scanf("%d%d",&n,&m);
    	for(i=0;i<n;i++)
    	     scanf("%s",map[i]);
    	         	  	  
    	scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
    	
    	sx--;
    	sy--;
    	ex--;
		ey--;
	
		for(i=0;i<4;i++)   //枚举起始朝向 
		{
			while(!q.empty())  q.pop();
		//	memset(book,0,sizeof(book));
			book[sx][sy]=1;
			node.x=sx;
			node.y=sy;
			node.last=i;
			node.turn=0;
			q.push(node);
			
			while(!q.empty()){
				tmp=q.front();
				q.pop();
				
				if(tmp.x==ex&&tmp.y==ey&&tmp.turn<=k)
					  {
					  	ok=1;
					  	break;
					  }
					  
				for(j=0;j<4;j++) {
					int a=tmp.x+step[j][0];
					int b=tmp.y+step[j][1];
					if(a<0||b<0||a>=n||b>=m||map[a][b]=='*')
					  continue;
				//	book[a][b]=1;
					
					 node.x=a;
					 node.y=b;
					 node.last=j;
					 if(j==tmp.last)					  	 
					  	  node.turn=tmp.turn;			
					  else					  	 
					  	 node.turn=tmp.turn+1;
					  if(node.turn>k)
					    continue;
					q.push(node);
				}
				
			}
		  if(ok)
		   break;
		} 			
		if(ok)
		  printf("yes\n");
		else
		 printf("no\n");
	}
	return 0;
}
*/
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int N=100+5;
bool book[N][N];
bool ok;
int n,m,k;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  //上下左右  0123
int sx,sy,ex,ey;
char map[N][N];
struct Node{
	short x,y,turn,last;
}node,tmp;
queue<Node> q;
int main(){ 
    int t,i,j;
    scanf("%d",&t);
    while(t--){
    	 ok=0;
    	scanf("%d%d",&n,&m);
    	for(i=0;i<n;i++)
    	     scanf("%s",map[i]);
    	         	  	  
    	scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
    	
    	sx--;
    	sy--;
    	ex--;
		ey--;
	
	
			while(!q.empty())  q.pop();
	
			node.x=sx;
			node.y=sy;
			node.last=-1;
			node.turn=0;
			q.push(node);
			
			while(!q.empty()){
				tmp=q.front();
				q.pop();
				
				if(tmp.x==ex&&tmp.y==ey&&tmp.turn<=k)
					  {
					  	ok=1;
					  	break;
					  }
					  
				for(j=0;j<4;j++) {
					int a=tmp.x+step[j][0];
					int b=tmp.y+step[j][1];
					if(a<0||b<0||a>=n||b>=m||map[a][b]=='*')
					  continue;
							
					 node.x=a;
					 node.y=b;
					 node.last=j;
					 if(tmp.last==-1||j==tmp.last){   //起始位置过来的 或 方向一样 
					 	node.turn=tmp.turn;	
					 }						
					 else					  	 
					  	 node.turn=tmp.turn+1;
					  	 
					  if(node.turn>k)
					    continue;
					    
					q.push(node);
				}
				
			}
		 
					
		if(ok)
		  printf("yes\n");
		else
		 printf("no\n");
	}
	return 0;
}
