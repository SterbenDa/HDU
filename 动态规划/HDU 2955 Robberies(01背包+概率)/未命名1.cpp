/*转载！
     转成以所有银行的总资产为背包容量V。。求最大的逃跑概率。。
注意：题目给我们的是被抓的概率，，而我们要求最大的逃跑率，需要去被抓的概率pi的补 ，即1-pi
只有逃跑率才会等于各个逃跑率之积，被抓的概率不会等于各个被抓的概率之积，，概率的知识，不多说。。
状态转移方程：dp[j] = max ( dp[j], dp[j-cost[i]] * weight[i])..

*/ 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int N=100*100+10;
double dp[N]; //  拿了i钱的逃跑概率dp[i] 
int sum;
int cost[100+5];
double p[100+5];
int n;
double f;
int main(){
     int t,i,j;
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%lf%d",&f,&n);
        for(i=0;i<n;i++){
            scanf("%d%lf",&cost[i],&p[i]);
            sum+=cost[i];
        //    dp[0]=0.0;  这里错了  n只是n家银行 
        }
        memset(dp,0,sizeof(dp)); 
        dp[0]=1.0;
        for(i=0;i<n;i++)
            for(j=sum;j>=cost[i];j--) 
                dp[j]=max(dp[j],dp[j-cost[i]]*(1.0-p[i]));
        /*    注释这里是错的  01背包必须从后往前更新  因为后面会涉及到前面的
        而01背包i状态时根据i-1状态推过来的  如果从前推  前面的状态就会变成i而不是i-1
         到后面时就找不到i-1的状态了 
        for(j=0;j<=sum;j++){   
                if(j>=cost[i])          
                else
                 continue;                
            }  */   
        for(i=sum;i>=0;i--){
            if(dp[i]>1.0-f){
              printf("%d\n",i);
                break;
            }
        }     
    }
    return 0;
}
