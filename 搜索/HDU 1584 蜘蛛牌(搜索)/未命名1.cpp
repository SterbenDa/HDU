/*
思路：做题时分类显示是搜索
1.但我感觉用贪心更好。更高效
10肯定不动，那么9动之前是8连上去还是9过去后再连呢，对于8后的7也是这样考虑
容易知道，一个数例如1，他要么去2默认的位置，要么去2变后的位置，只能这两种
于是就贪心就行了，但是这种做法不对，如果出现一个数i到i+1和i+2的距离相同，那么他
是先去i+1还是i+2呢，又分了情况

2.于是感觉用动态规划也能做
dp[i]=min(dp[i],abs(book[i]-book[j]))  j=[i+1,10];
但是发现不对，例如5 2 3 10 8 6 4 7 1 9
9去10肯定，按照状态方程，8是去10，那么问题来了，按照状态方程，7应该是去9的，
然而8是去10，所以不对 

3.日了狗了
 
*/

//转载网上代码： 
//思路：将所有状况进行一次DFS
#include <stdio.h>
#include <string.h>

int a[15],vis[15],ans;

int abs(int x)
{
    if(x<0)
    return -x;
    return x;
}

void dfs(int cnt,int sum)
{
    int i,j;
    if(sum>=ans)
    return ;
    if(cnt == 9)    //每次选择一个变换，9次结束 
    {
        ans = sum;
        return ;
    }
    for(i = 1;i<10;i++)   //第cnt次选择任意一张牌要叠上去 
    {
        if(!vis[i])   
        {
            vis[i] = 1;     //标记 
            for(j = i+1;j<=10;j++)    
			//选择要叠到哪张牌上 这里的意思是从i+1这张牌开始选
			//这张牌要没被移动过，如果被移动过，那么他就是去了更高牌的位置上 
            {
                if(!vis[j])   
                {
                    dfs(cnt+1,sum+abs(a[i]-a[j]));  //进入第cnt次选择 
                    break;     
			//所以只要找到一次，递归后就跳出，因为刚找到的这张牌是没移动过
			//你不能去下一个更大的牌，接不下去 
                }
            }
            vis[i] = 0; //回溯 
        }
    }
}

int main()
{
    int t,i,x;
    scanf("%d",&t);
    while(t--)
    {
        for(i = 1;i<=10;i++)
        {
            scanf("%d",&x);
            a[x] = i;//牌面为x的牌在第i个位置
        }
        memset(vis,0,sizeof(vis));
        ans = 10000000;
        dfs(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
/*
1
5 2 3 10 8 6 4 7 1 9
*/


