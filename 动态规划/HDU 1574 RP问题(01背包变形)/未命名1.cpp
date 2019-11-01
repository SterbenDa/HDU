/*
思路：01背包变形 
问题描述：有N件连续的事件，有些事件是RP值增加a，获益值减少c。
有些则相反。每件事件还有一个RP门槛b，RP值增加的事件RP得>=RP门槛，
RP值减少的事件则得RP<=RP门槛。满足上述条件不一定就会发生。
其中N<= 1000 ,a<=10,b<=10000,c<=10000;求这些事件的最大获益值，
 事件发生的顺序按照输入先后顺序先后发生，也就是说不可能先发生第i行的事件，
 然后再发生i – j行的事件。开始RP和获益值都为0；
 
算法：是DP题。一件事件发生与否只和当前RP有关，
所以想到存储到达某个事件是各个RP的最大获益。
不能开二维的数组（数据太大），只能开一个dp[20001];dp[j]表示RP为j - 10000; 
 另外还要一个标记数组，标记是否可以出现这个RP值；
*/
/* 
转载 
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
int dp[size];  //默认加了10000 
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
        dp[10000] = 0;  //相当于初始第一个 
        visited[10000] = true;  //初始0是可以达到的 
        for (i = 0; i < N; i++)  
        {  
            scanf("%d%d%d", &a, &b, &c);  
            if (a > 0)//a大于0 c是小于0 当RP要小于RP门槛 才能 
            {  
                for (j = b + 10000; j >= 0; j--) //RP门槛B，当前门槛j要小于等于b 
                {  
                    if (visited[j])  //当前人品j要可以达到 
                    {   
                        if (!visited[j + a]) //如果加了人品之前没达到，就初始化 
                        {  
                            dp[j + a] = dp[j] + c;  
                            visited[j + a] = true;  
                        }  
                        else   //否则就看要不要拿 
                        {  
                            dp[j + a] =   
                            max(dp[j + a], dp[j] + c);  
                        }  
                    }  
                }  
            }  
            else if (a < 0)  //a<0  c>0 当前人品j大于门槛人品b,才行   
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

