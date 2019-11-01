//����д�� 
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,dp[23][23][23][23],a[23],b[23];

int dfs(int la,int ra,int lb,int rb,int sum)
{
    int maxn = 0;
    if(la>ra && lb>rb) return 0;  //û�������� 
    if(dp[la][lb][ra][rb]) return dp[la][lb][ra][rb];  //֮ǰ�ļ�¼ 
    if(la<=ra)
    {
    // ��ѡ��һ��ֵA �����ֵ�ʱ����ֵ��sum-A ����  �Լ������õ�Ҳ������
	//�����õ�B sum-B������Ҳ������  ��Ϊÿ�����ö������Ž� ����ͬ���ݹ���� 
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
        printf("%d\n",dfs(1,n,1,n,sum));  //�ҿ�ʼѡ��ʱ���״̬ 
    }

    return 0;
}













/*\ �Լ�д��  �ṹ����  ˼�벻��   
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
