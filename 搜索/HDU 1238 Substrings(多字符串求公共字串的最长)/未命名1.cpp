//�Ż� 
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
		for(i=ilen;re==0&&i>0;i--){   //ö���Ӵ�����
		   for(j=0;re==0&&j+i-1<ilen;j++){   //ö��ģ���ִ�����ʼ�� 
		for(k=0;k<n;k++){
			if(k==id)
			continue;
			ok=0;
			for(z=0;z+i-1<len[k];z++) {  //����ʼ 
			   for(zz=0;zz<i;zz++){
			   	   if(c[k][z+zz]!=c[id][j+zz])
			   	     break;
			   }
			   if(zz==i){
			   	ok=1;
			   	break;
			   }		  
		}	
		for(z=len[k]-1;!ok&&z-i+1>=0;z--) {  //���ҿ�ʼ 
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



/*��ѽ   ѭ���Ŵ���   ����AC�� 
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
		for(i=0;i<ilen;i++){  //ö��ģ���ַ������ַ���ʼλ��
		   for(j=ilen-i;i+j-1<ilen&&j>0;j--) {    //�Ӵ��ĳ��� 
		      for(k=0;k<n;k++){   //ö��ÿ���ַ��� 
		         if(k==id)
		        continue;
		      	  ok=0;
				for(z=0;z+j-1<len[k];z++){ //��ʼ��λ�� 
					for(zz=0;zz<j;zz++)  //ÿ���ַ��Ƚ� 
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
			  for(z=len[k]-1;!ok&&z-j+1>=0;z--){  //���ҿ�ʼ 
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
			  if(!ok)   //��һ������ ����Ӵ��Ͳ����� 
			  break;		  
		}
		if(k==n)
		{
		//���˺þ� ö�ٵ������ڳ��������� ��ɱ�������...���˹��� 
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
