/*
˼·��ս��������Ȼ���ʼս����ö�ٵ�����ƥ�䣬ǰ��������ˣ�����
���ǿ�ʼ�Ƚ���һ�����֣�̰�ĵķ�������������һ�������ܸ�����һ����Ӯ 
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


