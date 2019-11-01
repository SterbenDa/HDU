#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std; 
const int N=2000000+20;
const int M=1000000+20;
int ha[N]; 
int main(){
    int a,b,c,d,i,j,sum,x;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
    	sum=0;
    	memset(ha,0,sizeof(ha));
    	if((a>0&&b>0&&c>0&d>0)||(a<0&&b<0&&c<0&d<0))
    	  {
    	  	printf("0\n");
    	  	continue;
		  }
		for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		 ha[a*i*i+b*j*j+M]++;
		 
		for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		   sum+=ha[-c*i*i-d*j*j+M];
		printf("%d\n",sum*16);
	}
	return 0;
}





/*  四循环改成三循环 还是超时 
#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <set>
using namespace std;
const int N=1000000+10; 
int a[N];
int main(){
    int a,b,c,d,i,j,k,z,sum,x;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
    	sum=0;
    	if((a>0&&b>0&&c>0&d>0)||(a<0&&b<0&&c<0&d<0))
    	  {
    	  	printf("0\n");
    	  	continue;
		  }
		for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		for(k=1;k<=100;k++){
		  x=sqrt((a*i*i+b*j*j+c*k*k)/(-d));
		  if(x>0&&x<=100&&a*i*i+b*j*j+c*k*k+d*x*x==0)
		    sum+=16;
		} 
		printf("%d\n",sum);
	}
	return 0;
}
*/
