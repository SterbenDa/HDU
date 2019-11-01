//别人写的 
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,dp[23][23][23][23],a[23],b[23];

int dfs(int la,int ra,int lb,int rb,int sum)
{
    int maxn = 0;
    if(la>ra && lb>rb) return 0;  //没有数字了 
    if(dp[la][lb][ra][rb]) return dp[la][lb][ra][rb];  //之前的记录 
    if(la<=ra)
    {
    // 我选了一个值A 给对手的时候总值是sum-A 分治  自己对手拿的也就是他
	//本局拿的B sum-B给对手也就是我  因为每个人拿都是最优解 所以同个递归策略 
        maxn = max(maxn,sum-dfs(la+1,ra,lb,rb,sum-a[la]));
        maxn = max(maxn,sum-dfs(la,ra-1,lb,rb,sum-a[ra]));
    }
    if(lb<=rb)
    {
        maxn = max(maxn,sum-dfs(la,ra,lb+1,rb,sum-b[lb]));
        maxn = max(maxn,sum-dfs(la,ra,lb,rb-1,sum-b[rb]));
    }
    dp[la][lb][ra][rb] = maxn;
    return maxn;
}

int main()
{
    int t,i,j,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        for(i = 1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for(i = 1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            sum+=b[i];
        }
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(1,n,1,n,sum));  //我开始选的时候的状态 
    }

    return 0;
}













/*\ 自己写的  结构对了  思想不对   
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[30],b[30];
int dp[22][22][22][22];
//int atail,ahead,bhead,btail;
int dfs(int ahead,int atail,int bhead,int btail){
	if(dp[ahead][atail][bhead][btail])
	return dp[ahead][atail][bhead][btail];
	int ans=0;
	if(ahead>atail&&bhead>btail)
	 return 0;
	 if(ahead==atail&&bhead>btail)
	 return a[ahead];
	 if(ahead>atail&&bhead==btail)
	 return b[bhead];
		dp[ahead][atail][bhead][btail]=
		max(dfs(ahead+1,atail,bhead,btail)+a[ahead],
		max(dfs(ahead,atail-1,bhead,btail)+a[atail],
		max(dfs(ahead,atail,bhead+1,btail)+b[bhead],
		dfs(ahead,atail,bhead,btail-1)+b[btail])));

	return dp[ahead][atail][bhead][btail];
}
int main(){
	int t,n,sum,i;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			sum+=a[i]+b[i];
		}		
	//	atail=0,btail=0,ahead=n-1,bhead=n-1;
		memset(dp,0,sizeof(dp));
		printf("%d\n",max(dfs(1,n-1,0,n-1)+a[0],max(dfs(0,n-2,0,n-1)+a[n-1],
		max(dfs(0,n-1,1,n-1)+b[0],dfs(0,n-1,0,n-2)+b[n-1]))));
	}
	return 0;
}
*/
