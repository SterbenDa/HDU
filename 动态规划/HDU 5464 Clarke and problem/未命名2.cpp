/*01背包DP*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
using namespace std;
const int N=1000+10;
const int mod=1e9+7;
int num[N];
int p,n;
int dp[N][N];
int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;i++){
			scanf("%d",&num[i]);
			num[i]%=p;
			//这里被刘大哥指明...  处理负数的  将他变成整数 
			num[i]=(num[i]+p)%p;   
		}		  
	    for(i=1;i<=n;i++){   //枚举每个数拿还是不拿 
	    	for(j=0;j<p;j++){   //枚举余数 
	    	 //不拿  就是余数为j加上i-1余数为j的数量 
	    	   dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;   
			//拿就 是余数为拿后的加上前I-1余数为拿前的 
			dp[i][(j+num[i])%p]=(dp[i][(j+num[i])%p]+dp[i-1][j])%mod;
			}
		}
		printf("%d\n",dp[n][0]);
	}
    return 0;	
}





/*   暴搜超时 */
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N=1000+10;
const int mod=1000000000+7;
int num[N];
int p,n;
int re;
void dfs(int now,int sum){
	int i;
	if(sum%p==0)
	  {
	  	re++;
	  	re%=mod;
	  	return;
	  }
	else if(sum>p||now>=n)
	 return;	
	dfs(now+1,sum+num[now]);
	dfs(now+1,sum);
}
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		re=1;
		scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
		  scanf("%d",&num[i]);
		sort(num,num+n);
		dfs(0,0);
		printf("%d\n",re);
	}
    return 0;	
}
*/
