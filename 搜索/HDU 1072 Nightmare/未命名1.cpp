#include <iostream>
#include <cstdio>
#include <queue> 
using namespace std;
const int N=10;
int map[N][N];
bool ok;
int n,m;
int book[N][N];
int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct Node{
	int x,y,step,bomb;
}tmp,node;
queue<Node> q;

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		ok=0;
		while(!q.empty()) q.pop();
 	    scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			book[i][j]=0;
			scanf("%d",&map[i][j]);
			if(map[i][j]==2){
				node.x=i;
				node.y=j;
				node.bomb=0;
				node.step=0;
			}
		}
		q.push(node);
		while(!q.empty()){
		    node=q.front();
			q.pop();
			if(node.bomb>=6)
			  continue;
			if(map[node.x][node.y]==3)
			  {
			  	ok=1;
			  	break;
			 }	
		 else if(map[node.x][node.y]==4)
			     node.bomb=0;		
	 for(i=0;i<4;i++){
		int a=node.x+step[i][0];
		int b=node.y+step[i][1];
		if(a<0||a>=n||b<0||b>=m||map[a][b]==0||book[node.x][node.y]>4)
		continue;
		 tmp.x=a;
		 tmp.y=b;
		 tmp.step=node.step+1;
		 tmp.bomb=node.bomb+1;
		book[a][b]++;
		 q.push(tmp);
	}	
}
		if(ok)
		printf("%d\n",node.step);
		else
		printf("-1\n");
	}
	return 0;
}
/*³¬Ê± 
#include <iostream>
#include <cstdio>
using namespace std;
const int N=10;
int map[N][N];
bool ok;
int n,m,small;
int book[N][N];
int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void dfs(int x,int y,int sum,int bomb){
	if(bomb>=6||sum>=small)
	return ;
	if(map[x][y]==3){
		ok=1;
		if(sum<small)
		small=sum;
		return;
	}
	if(map[x][y]==4)
		bomb=0;	  
	int i;
	for(i=0;i<4;i++){
		int a=x+step[i][0];
		int b=y+step[i][1];
		if(a<0||a>=n||b<0||b>=m||map[a][b]==0)
		continue;
		//book[a][b]++;
          dfs(a,b,sum+1,bomb+1);
		//book[a][b]--;
	}
}
int main(){
	int t,i,j,bx,by;
	scanf("%d",&t);
	while(t--){
		small=99999999;
		ok=0;
	    scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		for(j=0;j<m;j++){
		//	book[i][j]=0;
			scanf("%d",&map[i][j]);
			if(map[i][j]==2){
				bx=i;
				by=j;
			}
		}
	  // 	book[bx][by]++;
		dfs(bx,by,0,0);
		if(ok)
		printf("%d\n",small);
		else
		printf("-1\n");
	}
	return 0;
}
*/
