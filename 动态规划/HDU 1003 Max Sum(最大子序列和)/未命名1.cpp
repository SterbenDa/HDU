#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int N=100000+10;
int dp[N];
int a[N];
int main(){
	int i,j,t,n,le,ri,big,re1,re2;
	scanf("%d",&t);
     for(j=1;j<=t;j++){
	    scanf("%d",&n);
	    scanf("%d",&a[1]);
	    big=dp[1]=a[1];
	    le=ri=re1=re2=1;
	    for(i=2;i<=n;i++){
	    	scanf("%d",&a[i]);
	    	if(dp[i-1]+a[i]>a[i]){
	    		dp[i]=dp[i-1]+a[i];
	    		ri++;
			}  		
			else{
				dp[i]=a[i];
				le=i;
				ri=i;
			}
			if(dp[i]>big)
			  {
			  	big=dp[i];
			  	re1=le;
			  	re2=ri;
			  }
		}
	       printf("Case %d:\n",j);
	       printf("%d %d %d\n",big,re1,re2);
	       if(j!=t)
	       printf("\n");
	}
	return 0;
}
