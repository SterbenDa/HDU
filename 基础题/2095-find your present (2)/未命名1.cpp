#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <map>
using namespace std;
map<int,int>  ma;  //记录标记 
int a[1000000+10];  //存数 

int main(){    
    int n,re;
    while(scanf("%d",&n)==1){
    	if(n==0)
    	  break;
    	  ma.clear();   
    	for(int i=0;i<n;i++){
          	scanf("%d",&a[i]);   
			ma[a[i]]++;      	
		}
    	  
    	for(int i=0;i<n;i++){
          	if(ma[a[i]]==1)
			  {
			   re=a[i];
			   break;  	
			}        	
		}
    	printf("%d\n",re);
	}
	return 0;
}


