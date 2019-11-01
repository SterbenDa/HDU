#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 16;
const int inf = 2147483647;
const int mod = 2009;
int main()
{
    int x,y,w,n,s,t;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n))
    {
        s=x/w+1;
        if(s==1)
            printf("%d\n",(n-1)*(x+y));
        else if(n%s==0)
        {
            t=n/s-1;
            printf("%d\n",t*(x+y)+(s-1)*w);
        }
        else
        {
            t=n/s;
            printf("%d\n",t*(x+y)+(n-t*s-1)*w);
        }
    }
    return 0;
}
