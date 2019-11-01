/*
思路：战斗力排序，然后初始战斗力枚举到最大的匹配，前面的无视了，渣渣
于是开始比较下一个对手，贪心的法则是升到和他一样，若能搞掉最后一个就赢 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e+4+100;
long long zhan[N];
int main()
{  
    int n,t;
    long long my,k,m;
    bool ok;
    scanf("%d",&t);
    for(int th=1;th<=t;th++){
        scanf("%d%lld%lld",&n,&m,&k);
        ok=1;
		for(int i=0;i<n;i++)
           scanf("%lld",&zhan[i]);
        sort(zhan,zhan+n);
        int now=0;
		while(now<n&&zhan[now]<=m){
			my=zhan[now];
			now++;
		}
		if(now==0)
		{
			ok=0;
			goto AC; 
		}
		now--;		
		for(int i=now+1;i<n;i++){
			if(k+my>=zhan[i]){
				my=zhan[i];
				if(k>0)
				k--;
			}
			else
			{
				ok=0;
				break;
			}
		}
		AC:
		printf("Case #%d:\n",th);
		if(ok)
	    	printf("why am I so diao?\n");
		else
		  printf("madan!\n");
	}
	return 0;
}


