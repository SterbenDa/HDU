//转载原文:http://blog.csdn.net/geniusluzh/article/details/8751274 
/*
题意自不必多说，那我们来看看题中相同关系的定义：互相为朋友关系或者是彼此都没有朋友关系，也就是说三人之间有三条边或者是有零条边都是称为相同关系的。
      已经给出了每个点的朋友的个数，也就是与该点相连的点的个数，我们设第i个点的朋友个数为p[i]。于是使用这样一种策略来选出三个点：首先我们选择i号节点，然后我们在p[i]个朋友中选一个；然后在剩余的人中选一个，也就是在n-1-p[i]的人中选一个人；这样子选的三个人有什么特点呢？
      我们看到从朋友中选了一个，保证了相同关系中三人无边的情况不会出现；然而在非朋友中选了一个，保证了相同关系中三条边的情况不会出现。也就说上面选三个点的策略保证排除了所有的相同关系的情况，所以对所有i的p[i]*(n-1-p[i])求和就是相同关系补集的元素个数。
      再者我们发现按上面的策略选的三个点，没种三点情况总会被重复选一次，于是需要把上面的结果除以2，显然这是没有问题的。
      知道了这些，结果就很简单了，其实我认为代码可以不贴。
*/
#include <iostream>  
#include <cstdio>  
using namespace std;  
  
int C(int n, int m)  
{  
    if(m > n)  
        return 0;  
    else if(m == n)  
        return 1;  
    else  
    {  
        int ans = 1;  
        for(int i=n-m+1; i<=n; i++)  
            ans *= i;  
        for(int i=1; i<=m; i++)  
            ans /= i;  
        return ans;  
    }  
}  
  
int main()  
{  
    int T, n;  
    int a, b;  
    scanf("%d", &T);  
    while(T--)  
    {  
        scanf("%d", &n);  
        a = b = 0;  
        int temp;  
        double ans = 0;  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d", &temp);  
            ans += (double)temp*(n-1-temp);  
        }  
        ans /= 2.0;  
        ans = ans/(double)(C(n, 3));  
        printf("%.3lf\n", 1-ans);  
    }  
    return 0;  
}  
/*个人理解分析
假设A B C
设A的朋友B，非朋友C 
对于A，选B朋友，非朋友C
可能的情况1:B的朋友A，非朋友C
对于B，选A朋友，非朋友C，这里重复了 所以要除以2 
*/













