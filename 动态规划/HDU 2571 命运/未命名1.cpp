#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int N=20+5;
const int M=1000+5;
int n,m;
int num[N][M];
int dp[N][M];
//上面下来的，左边倍数来的 
inline int max(int a,int b){
	if(a>b) 
	return  a;
	return b;
}
int main(){
	int t,i,j,k,x,y,up,le;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&num[i][j]);
			dp[i][j]=0;
		}
		dp[1][1]=num[1][1];  //这里wa了 刚开始要赋值 
		for(i=1;i<=n;i++)
		  for(j=1;j<=m;j++){
		  	 if(i==1&&j==1)
		  	 continue;
		  	 x=i-1;// 上面的横坐标 
		  	 y=j;   
		  	 if(x<1)
		  	 	up=-99999999;
			 else		  	  
		  	 up=dp[x][y];
		  	 x=i;
		  	 y=j-1;
		  	  if(y<1)
		  	 	le=-99999999;
		  	   else
		  	  le=dp[x][y];
		  	for(k=1;k<j;k++){   //dp[1][1]赋值后 这里k<j 测试数据就过了 
		  		if(j%k==0)
		  		  le=max(le,dp[x][k]);
			  }
			  dp[i][j]=max(le,up)+num[i][j];
		  }	
		  /*for(i=1;i<=n;i++){
		  	for(j=1;j<=m;j++)
		    printf("%d ",dp[i][j]);
		    printf("\n");
		  }	  */
		  printf("%d\n",dp[n][m]);
	}
	return 0;
}
