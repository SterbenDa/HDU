/*
分析：至少拿一个offer 就是1-P(有能力投的学校都不给你进)
所以概率改成每个学校不给你进的概率 即1-P[i]；
然后01背包选尽可能多的学校去投  然后选择都不给你进概率最小的
状态方程为：  dp[j]=min(dp[j],dp[j-cost[i]]*p[i]); 
最后枚举 求出最小的dp[i]  1-dp[i]就是至少拿一个offer的概率 
*/ 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int N=100*100+10;
double dp[N];  
int cost[N];
double p[N];
int n,m;
double f;
int main(){
    int t,i,j;
   while(scanf("%d%d",&n,&m)==2){
   	if(n==0&&m==0)
   	    break;
        for(i=0;i<m;i++){
            scanf("%d%lf",&cost[i],&f);
            p[i]=1.0-f;     //不要的概率  
        }
        for(i=0;i<=n;i++)
		  dp[i]=1.0;    //下面取Min  所以这里设置100% 
        dp[0]=1.0;    //钱都没有  没人要的概率肯定为1 
        for(i=0;i<m;i++){   //m个学校 
        	for(j=n;j>=cost[i];j--){   
        	//这里理解并不会冲突  选越多的学校 机会越多
			//即都没offer应该更小 
        		   dp[j]=min(dp[j],dp[j-cost[i]]*p[i]); 
        		  // printf("%lf ",dp[j]);
			}
            // printf("\n");
		}        
        double re=1.0;   //设置最大值 
        for(i=n;i>=0;i--)
            if(re>dp[i])
              re=dp[i];
              //这里输出%格式要两个%% 
		printf("%.1lf%%\n",(1.0-re)*100.0);                   
        }     
    return 0;
}
