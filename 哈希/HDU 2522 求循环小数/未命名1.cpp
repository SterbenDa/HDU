#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
const int N=1000000+10;
bool book[N];
int len,a[N];
bool flag;
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	if(n<0)
	 {
	 	n=n*(-1);
	 	flag=0;
	 }
	 else
	   flag=1;
	   
	   if(n==1)
	   {
	   	if(flag)
	   	 printf("1\n");
	   	 else
	   	  printf("-1\n");
	   }
		len=0;
		memset(book,0,sizeof(book));
		int now=1;
		while(now!=0&&book[now]==0){
			book[now]=1;		
			if(now>=n){
				a[len++]=now/n;
				now%=n;
			}
			else
				a[len++]=0;
				
			now*=10;							  		
		}
		if(flag)
		printf("0.");
		else
		  printf("-0.");
		for(i=1;i<len;i++)
		  printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
