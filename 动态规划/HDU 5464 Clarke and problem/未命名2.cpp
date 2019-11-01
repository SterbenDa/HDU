/*01����DP*/
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
			//���ﱻ�����ָ��...  ��������  ����������� 
			num[i]=(num[i]+p)%p;   
		}		  
	    for(i=1;i<=n;i++){   //ö��ÿ�����û��ǲ��� 
	    	for(j=0;j<p;j++){   //ö������ 
	    	 //����  ��������Ϊj����i-1����Ϊj������ 
	    	   dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;   
			//�þ� ������Ϊ�ú�ļ���ǰI-1����Ϊ��ǰ�� 
			dp[i][(j+num[i])%p]=(dp[i][(j+num[i])%p]+dp[i-1][j])%mod;
			}
		}
		printf("%d\n",dp[n][0]);
	}
    return 0;	
}





/*   ���ѳ�ʱ */
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
