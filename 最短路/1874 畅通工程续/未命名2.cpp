#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int M=1000*2+10;
const int N=200+10;
const int INF=1000000000;
int w[M],from[M],to[M];
int dis[N],book[N];
int main(){
	int n,i,t,a,b,k,m;
	while(scanf("%d%d",&n,&m)==2){
		for(i=0;i<2*m;i++){
			scanf("%d%d%d",&a,&b,&t);
	    	from[i]=a;
	    	to[i]=b;
	    	w[i]=t;
	    	i++;
	    	from[i]=b;
	    	to[i]=a;
	    	w[i]=t;
		}	
		scanf("%d%d",&a,&b);	
		for(i=0;i<n;i++)
		  dis[i]=INF;
		dis[a]=0;
		//bellman-ford
		for(k=0;k<=n-1;k++){
			for(i=0;i<n;i++)
			 book[i]=dis[i];
			
			 for(i=0;i<2*m;i++)
			 	if(dis[to[i]]>dis[from[i]]+w[i])
			 	  dis[to[i]]=dis[from[i]]+w[i];
			 	 
			 bool check=0;			 	  
				   for(i=0;i<n;i++)
			 	    if(book[i]!=dis[i]){
			 	    	check=1;
			 	    	break;
					 }
					 if(check==0)
					 break;
		}
		bool flag=0;
		 for(i=0;i<m;i++){
		 	if(dis[to[i]]>dis[from[i]]+w[i])
		 	  {
		 	  	flag=1;
		 	  	break;
			   }
		 }
		if(dis[b]==INF||flag)
		 printf("-1\n");
		 else
		  printf("%d\n",dis[b]);
	}
	return 0;
}
