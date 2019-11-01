#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=100000+5;
int pre[N];
inline int find(int x){
	int sum=0;
	while(pre[x]!=x){
		 x=pre[x];
		 sum++;
	}	 
	return sum;
}
int main(){ 
    int n,m,i,a,b;
    while(scanf("%d%d",&n,&m)==2){
    	 if(n==0&&m==0)
    	   break;
    	   memset(pre,0,sizeof(int)*(n+1));
    	  for(i=0;i<n-1;i++)
    	   {
    	   	  scanf("%d%d",&a,&b);
    	   	  pre[b]=a;
		   }
		   while(m--){
		   	  scanf("%d%d",&a,&b);
		   	  int lxh=find(a);
              int pfz=find(b);
		   	  if(lxh<=pfz)
		   	     printf("lxh\n");
		   	  else
		   	     printf("pfz\n");
		   }
	}
	return 0;
}
