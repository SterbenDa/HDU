/*
参考思路网址：http://www.cnblogs.com/jklongint/p/4579042.html 
思路： 修改数量最少的元素使得这个数列严格递增，等价于让数量最多的元素不变，
然后修改其余的元素。也就是从序列里面选尽量多的数，使得其它数修改后能形成一个
单调递增序列。这跟LIS很像，不过多了个限制，我们尝试用数学式子来描述这个限制，
a[i]-a[j]>=i-j，i>j，a[i],a[j]∈LIS，变形就是a[i]-i>=a[j]-j。
一种自然的想法就产生了，将原序列做个变换，a[i]->a[i]-i，
然后对新序列求最长非降序列，那么最长非降序列里的数的个数就是不变的数的最大个
数，用n减去就是答案。
*/
/*超时了 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath> 
#include<algorithm>
using namespace std ;
const int maxn = 100010 ;
int a[maxn];
int dp[maxn];
int main()
{
    int now,t,i,j,n,re;
    scanf("%d",&t);
    for(now=1;now<=t;now++){
    	re=-99999999;
    	scanf("%d",&n);
    	for(i=1;i<=n;i++){
    		scanf("%d",&a[i]);
    		a[i]-=i;
    		dp[i]=1;
		}
		for(i=1;i<=n;i++){ //求最长非降子序列 
			for(j=1;j<i;j++){
			    if(a[i]>=a[j])
				  dp[i]=max(dp[j]+1,dp[i]);			
			} 
			if(dp[i]>re)
			  re=dp[i];
		}
    	printf("Case #%d:\n",now);
    	printf("%d\n",n-re);
	}
    return  0;
}*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
int dp[123456], n, a[123456];
 
int LIS(int *from, int *to) {
    dp[0] = -1e9;
    for (int i = 1; i <= n; i ++) dp[i] = 1e9;
    int ans = 0;
    for (int *pint = from; pint < to; pint ++) {
        int pos = upper_bound(dp, dp + n, *pint) - dp - 1;
        dp[pos + 1] = min(dp[pos + 1], *pint);
        ans = max(ans, pos + 1);
    }
    return ans;
}
int main() {
    int T, cas = 0;
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            scanf("%d", a + i);
            a[i] -= i;
        }
        printf("Case #%d:\n%d\n", ++ cas, n - LIS(a, a + n));
    }
    return 0;
}
