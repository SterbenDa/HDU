/*
������������һ��offer ����1-P(������Ͷ��ѧУ���������)
���Ը��ʸĳ�ÿ��ѧУ��������ĸ��� ��1-P[i]��
Ȼ��01����ѡ�����ܶ��ѧУȥͶ  Ȼ��ѡ�񶼲������������С��
״̬����Ϊ��  dp[j]=min(dp[j],dp[j-cost[i]]*p[i]); 
���ö�� �����С��dp[i]  1-dp[i]����������һ��offer�ĸ��� 
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
            p[i]=1.0-f;     //��Ҫ�ĸ���  
        }
        for(i=0;i<=n;i++)
		  dp[i]=1.0;    //����ȡMin  ������������100% 
        dp[0]=1.0;    //Ǯ��û��  û��Ҫ�ĸ��ʿ϶�Ϊ1 
        for(i=0;i<m;i++){   //m��ѧУ 
        	for(j=n;j>=cost[i];j--){   
        	//������Ⲣ�����ͻ  ѡԽ���ѧУ ����Խ��
			//����ûofferӦ�ø�С 
        		   dp[j]=min(dp[j],dp[j-cost[i]]*p[i]); 
        		  // printf("%lf ",dp[j]);
			}
            // printf("\n");
		}        
        double re=1.0;   //�������ֵ 
        for(i=n;i>=0;i--)
            if(re>dp[i])
              re=dp[i];
              //�������%��ʽҪ����%% 
		printf("%.1lf%%\n",(1.0-re)*100.0);                   
        }     
    return 0;
}
