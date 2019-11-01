/*
�ο�˼·��ַ��http://www.cnblogs.com/jklongint/p/4579042.html 
˼·�� �޸��������ٵ�Ԫ��ʹ����������ϸ�������ȼ�������������Ԫ�ز��䣬
Ȼ���޸������Ԫ�ء�Ҳ���Ǵ���������ѡ�����������ʹ���������޸ĺ����γ�һ��
�����������С����LIS���񣬲������˸����ƣ����ǳ�������ѧʽ��������������ƣ�
a[i]-a[j]>=i-j��i>j��a[i],a[j]��LIS�����ξ���a[i]-i>=a[j]-j��
һ����Ȼ���뷨�Ͳ����ˣ���ԭ���������任��a[i]->a[i]-i��
Ȼ�������������ǽ����У���ô��ǽ�����������ĸ������ǲ������������
������n��ȥ���Ǵ𰸡�
*/
/*��ʱ�� 
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
		for(i=1;i<=n;i++){ //����ǽ������� 
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
