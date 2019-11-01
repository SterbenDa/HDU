#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Range{
	int a,b;
}r[100+10];
bool cmp(Range x,Range y){
	if(x.b!=y.b)
	return x.b>y.b;
	else
	return x.a>=y.a;
}
int main(){
   int t,p,q,i;
   string s;
   while(scanf("%d",&t)==1){
   	  scanf("%d%d",&p,&q);
   	 for(i=0;i<t;i++){
   	 	 scanf("%d%d",&r[i].a,&r[i].b);
   	 	 getline(cin,s);
   	 	 if(r[i].a>r[i].b)
   	 	 swap(r[i].a,r[i].b);
		}  	 
   	  sort(r,r+t,cmp);
   	  for(i=0;i<t;i++){
   	  	  if(q>r[i].b) 	  	    
			   break; 				
		  else
		  	q=min(q,r[i].a-1);		  
		 }
		 if(q>=p)
		   printf("%d\n",q);
		 else
		  printf("Badly!\n");
   }
	return 0;
}
