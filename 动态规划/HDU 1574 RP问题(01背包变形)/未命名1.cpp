/*
˼·��01�������� 
������������N���������¼�����Щ�¼���RPֵ����a������ֵ����c��
��Щ���෴��ÿ���¼�����һ��RP�ż�b��RPֵ���ӵ��¼�RP��>=RP�ż���
RPֵ���ٵ��¼����RP<=RP�ż�����������������һ���ͻᷢ����
����N<= 1000 ,a<=10,b<=10000,c<=10000;����Щ�¼���������ֵ��
 �¼�������˳���������Ⱥ�˳���Ⱥ�����Ҳ����˵�������ȷ�����i�е��¼���
 Ȼ���ٷ���i �C j�е��¼�����ʼRP�ͻ���ֵ��Ϊ0��
 
�㷨����DP�⡣һ���¼��������ֻ�͵�ǰRP�йأ�
�����뵽�洢����ĳ���¼��Ǹ���RP�������档
���ܿ���ά�����飨����̫�󣩣�ֻ�ܿ�һ��dp[20001];dp[j]��ʾRPΪj - 10000; 
 ���⻹Ҫһ��������飬����Ƿ���Գ������RPֵ��
*/
/* 
ת�� 
*/  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
#include<cstring>  
#include<vector>  
#include<algorithm>  
#include<string>  
#include<map>  
#include<bitset>  
#include<queue>  
using namespace std;  
const int size = 20001;  
int dp[size];  //Ĭ�ϼ���10000 
int T;  
int N;  
bool visited[size];  
int main()  
{  
    scanf("%d", &T);  
    while (T--)  
    {  
        scanf("%d", &N);  
        int a, b, c;  
        int i;  
        int j;  
        memset(dp, 0, sizeof(dp));  
        memset(visited, 0, sizeof(visited));  
        dp[10000] = 0;  //�൱�ڳ�ʼ��һ�� 
        visited[10000] = true;  //��ʼ0�ǿ��Դﵽ�� 
        for (i = 0; i < N; i++)  
        {  
            scanf("%d%d%d", &a, &b, &c);  
            if (a > 0)//a����0 c��С��0 ��RPҪС��RP�ż� ���� 
            {  
                for (j = b + 10000; j >= 0; j--) //RP�ż�B����ǰ�ż�jҪС�ڵ���b 
                {  
                    if (visited[j])  //��ǰ��ƷjҪ���Դﵽ 
                    {   
                        if (!visited[j + a]) //���������Ʒ֮ǰû�ﵽ���ͳ�ʼ�� 
                        {  
                            dp[j + a] = dp[j] + c;  
                            visited[j + a] = true;  
                        }  
                        else   //����Ϳ�Ҫ��Ҫ�� 
                        {  
                            dp[j + a] =   
                            max(dp[j + a], dp[j] + c);  
                        }  
                    }  
                }  
            }  
            else if (a < 0)  //a<0  c>0 ��ǰ��Ʒj�����ż���Ʒb,����   
            {  
                for (j = b + 10000; j < size; j++)  
                {  
                    if (visited[j])  
                    {  
                        if (!visited[j + a])  
                        {  
                            dp[j + a] = dp[j] + c;  
                            visited[j + a] = true;  
                        }  
                        else   
                        {  
                            dp[j + a] =   
                            max(dp[j + a], dp[j] + c);  
                        }  
                    }  
                }  
            }  
        }  
        int ans = 0;  
        for (i = 0; i < size; i++)  
        {  
            if (visited[i] && dp[i] > ans)  
            {  
                ans = dp[i];  
            }  
        }  
        printf("%d\n", ans);  
    }  
    return 0;  
}  

