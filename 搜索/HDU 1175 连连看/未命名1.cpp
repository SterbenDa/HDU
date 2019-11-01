#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
const int N=1000+10;
int map[N][N];
bool book[N][N];
int n,m;
int xx1,xx2,yy1,yy2;
int step[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//               0об    1ср    2ио   3вЬ 
bool ok;
void dfs(int x,int y,int sum,int last){
	if(sum>2||ok)
	    return;
	if(x==xx2&&y==yy2){
		ok=1;
		return;
	}
	int i;
	for(i=0;i<4;i++){
		int a=x+step[i][0];
		int b=y+step[i][1];
	  if(a<1||a>n||b<1||b>m||book[a][b]==1)
		continue;
	   if((a!=xx2||b!=yy2)&&map[a][b]!=0)
	   continue;
		book[a][b]=1;
		if(last==i||last==-1)			
			dfs(a,b,sum,i);
		else
		   dfs(a,b,sum+1,i);    	
		if(ok==1)
		return;
     	book[a][b]=0;
	}
}
int main(){
	int i,j,t;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
		break;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
		scanf("%d",&t);
		while(t--){
			ok=0;
			memset(book,0,sizeof(book));
			scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
		if(map[xx1][yy1]!=map[xx2][yy2]||map[xx1][yy1]==0||map[xx2][yy2]==0){
				printf("NO\n");
				continue;
			}
			book[xx1][yy1]=1;
			dfs(xx1,yy1,0,-1);
			if(ok)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}
