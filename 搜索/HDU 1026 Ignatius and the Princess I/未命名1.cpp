//要队列优先  因为每个点并不是1   所以wa了  
//我的第一次这种做法是为了记录路径  用STL队列保存路径感觉好麻烦 
//改进后AC 用数组加快排模拟优先队列 
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=100+5;
int map[N][N];
int n,m,goal;
bool ok;
int route[N*N];
bool book[N][N];
struct Node{
	int x,y;
	int last;
	int step;
}node,tmp;
Node q[N*N];
int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool cmp(Node a,Node b){
	return a.step<=b.step;
}
int main(){
	int i,j,head,tail;
	char c[N];
	while(scanf("%d%d",&n,&m)==2){
		head=0;
		tail=0;
		ok=0;
		for(i=0;i<n;i++){
			scanf("%s",c);
			for(j=0;j<m;j++){
				book[i][j]=0;
			  if(c[j]=='.')
			    map[i][j]=1;
			  else if(c[j]>='1'&&c[j]<='9')
			    map[i][j]=c[j]-'0'+1;
			    else
			    map[i][j]=-1;
			}			  
		}
		book[0][0]=1;
		node.last=0;
		node.x=0;
		node.y=0;
		node.step=0;
		q[tail++]=node;
		while(head<tail){
			sort(q+head,q+tail,cmp);
			tmp=q[head];
			if(tmp.x==n-1&&tmp.y==m-1)
			  {
			  	ok=1;
			  	goal=head;
				  		  			  	
			  }
		for(i=0;i<4;i++){
		   int a=tmp.x+step[i][0];
		   int b=tmp.y+step[i][1];
		 if(a<0||a>=n||b<0||b>=m||map[a][b]==-1||book[a][b]==1)
		  continue;
	    	book[a][b]=1;
	    	  node.x=a;
	    	  node.y=b;
	    	  node.last=head;
	    	  node.step=tmp.step+map[a][b];
	    	  q[tail++]=node;
		}
		// book[tmp.x][tmp.y]=0;
		head++;
	    }
	   if(ok)
	   {
printf("It takes %d seconds to reach the target position, let me show you the way.\n"
,q[goal].step);
           i=0,j=goal;
           while(j!=0){  //处理路径 
           	route[i++]=j;
           	j=q[j].last;
		   }
		    route[i]=0;   //路径最开始是head=0 
		for(j=1;i>=0;i--,j++){
			int a=q[route[i]].x;
			int b=q[route[i]].y;
			if(map[a][b]>1){
				while(map[a][b]>1){
				   printf("%ds:FIGHT AT (%d,%d)\n",j,a,b);
				   j++;
				   map[a][b]--;
				}
			}
			if(i>0)
		printf("%ds:(%d,%d)->(%d,%d)\n",j,a,b,q[route[i-1]].x,q[route[i-1]].y);				  
		 }       
	   }
	   else
	   	printf("God please help our poor hero.\n");
	   	printf("FINISH\n");
	}
	return 0;
}

