/*ת�أ�
     ת�����������е����ʲ�Ϊ��������V�������������ܸ��ʡ���
ע�⣺��Ŀ�����ǵ��Ǳ�ץ�ĸ��ʣ���������Ҫ�����������ʣ���Ҫȥ��ץ�ĸ���pi�Ĳ� ����1-pi
ֻ�������ʲŻ���ڸ���������֮������ץ�ĸ��ʲ�����ڸ�����ץ�ĸ���֮���������ʵ�֪ʶ������˵����
״̬ת�Ʒ��̣�dp[j] = max ( dp[j], dp[j-cost[i]] * weight[i])..

*/ 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int N=100*100+10;
double dp[N]; //  ����iǮ�����ܸ���dp[i] 
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
        //    dp[0]=0.0;  �������  nֻ��n������ 
        }
        memset(dp,0,sizeof(dp)); 
        dp[0]=1.0;
        for(i=0;i<n;i++)
            for(j=sum;j>=cost[i];j--) 
                dp[j]=max(dp[j],dp[j-cost[i]]*(1.0-p[i]));
        /*    ע�������Ǵ��  01��������Ӻ���ǰ����  ��Ϊ������漰��ǰ���
        ��01����i״̬ʱ����i-1״̬�ƹ�����  �����ǰ��  ǰ���״̬�ͻ���i������i-1
         ������ʱ���Ҳ���i-1��״̬�� 
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
