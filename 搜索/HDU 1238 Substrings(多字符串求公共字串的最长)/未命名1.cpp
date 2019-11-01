//优化 
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
const int N=100+10;
int n,id,re,ilen;
char c[N][N];
int len[N];
int main(){
	int t,i,small,j,k,z,zz;
	bool ok;
	scanf("%d",&t);
	while(t--){
		re=0;
		small=N;
		scanf("%d",&n);
		for(i=0;i<n;i++){
		   	scanf("%s",c[i]);
		   	len[i]=strlen(c[i]);
		   	if(len[i]<small)
		   	  {
		   	  	small=len[i];
		   	  	id=i;
			}
		}
		ilen=len[id];
		for(i=ilen;re==0&&i>0;i--){   //枚举子串长度
		   for(j=0;re==0&&j+i-1<ilen;j++){   //枚举模板字串的起始点 
		for(k=0;k<n;k++){
			if(k==id)
			continue;
			ok=0;
			for(z=0;z+i-1<len[k];z++) {  //从左开始 
			   for(zz=0;zz<i;zz++){
			   	   if(c[k][z+zz]!=c[id][j+zz])
			   	     break;
			   }
			   if(zz==i){
			   	ok=1;
			   	break;
			   }		  
		}	
		for(z=len[k]-1;!ok&&z-i+1>=0;z--) {  //从右开始 
			   for(zz=0;zz<i;zz++){
			   	   if(c[k][z-zz]!=c[id][j+zz])
			   	     break;
			   }
			   if(zz==i){
			   	ok=1;
			   	break;
			   }		  
		}
		  if(!ok)
		    break;	
		} 
		  if(k==n){
		  	re=i;
		  	break;
		  }		  
		} 	
} 
   	printf("%d\n",re);
}
	return 0;
}



/*哎呀   循环放错了   不过AC了 
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=100+10;
int n,id,re,ilen,rlen;
char c[N][N];
int len[N];
int main(){
	int t,i,small,j,k,z,zz;
	bool ok;
	scanf("%d",&t);
	while(t--){
		re=0;
		rlen=0;
		small=N;
		scanf("%d",&n);
		for(i=0;i<n;i++){
		   	scanf("%s",c[i]);
		   	len[i]=strlen(c[i]);
		   	if(len[i]<small)
		   	  {
		   	  	small=len[i];
		   	  	id=i;
			}
		}
		ilen=len[id];
		for(i=0;i<ilen;i++){  //枚举模板字符串的字符起始位置
		   for(j=ilen-i;i+j-1<ilen&&j>0;j--) {    //子串的长度 
		      for(k=0;k<n;k++){   //枚举每个字符串 
		         if(k==id)
		        continue;
		      	  ok=0;
				for(z=0;z+j-1<len[k];z++){ //左开始的位置 
					for(zz=0;zz<j;zz++)  //每个字符比较 
					{
					    if(c[k][z+zz]!=c[id][i+zz])
						break;	
					}			
				  if(zz==j)
				   {
				      ok=1;
					  break;	
				   }		    
			  }
			  for(z=len[k]-1;!ok&&z-j+1>=0;z--){  //从右开始 
			  		for(zz=0;zz<j;zz++)
					{
					   	if(c[k][z-zz]!=c[id][i+zz])
						break;	
					}   
				   if(zz==j)
				   {
				      ok=1;
					  break;	
				   }	
			  } 
			  if(!ok)   //有一个不行 这个子串就不行了 
			  break;		  
		}
		if(k==n)
		{
		//坑了好久 枚举的起点放在长度外面了 造成被更新了...日了狗了 
			re=max(re,j);  
			break;
		 } 
}
}  
      printf("%d\n",re); 
}
	return 0;
}
*/
