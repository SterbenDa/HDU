#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
int n,m;
const int N=10000+20;
int dp[N] ;
int dfs(int sum){
	if(dp[sum]!=-1)
	return dp[sum];
	if(sum+m>=n)
	return dp[sum]=1;
	int i;
	 for(i=1;i<=m;i++){
	 	 dp[sum+i]=dfs(sum+i);
	 	if(dp[sum+i]==0)  //�¼Ҳ�����һ����Ӯ  ���Ҿ�Ӯ�� 
            return true;
	 }	
    return dp[sum]=0;     //�¼Ҵ���һ����Ӯ ���Ҿ����� 
}
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
	  scanf("%d%d",&n,&m);	
	  if(dfs(0)==1)
	    printf("Grass\n");
	  else
	  printf("Rabbit\n");
	}
	return 0;
}
