
/*���� ���˼·ÿ�ζ���sum������ ����ʵ���ϲ�һ��������sum  ��������2��
���Ȼ���ٺ�sum����*/
/* 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
//#define NUM 1e-6
using namespace std;
int a[6];
int n;
bool book[6];
bool dfs(int sum,int time){
	if(time==4){
		 if(24==sum)
	      return true;
	      return false;
	}	
	 int i,j;
	 for(i=0;i<4;i++)
	{
		if(book[i]==1)
		continue;
		book[i]=1;   
		if(dfs(sum+a[i],time+1))  return true;
	 	if(dfs(sum-a[i],time+1))  return true;
		if(dfs(sum*a[i],time+1))  return true;
	 	if(dfs(a[i]-sum,time+1))  return true;
	 	if(a[i]!=0&&sum%a[i]==0){
	 		if(dfs(sum/a[i],time+1))  return true;
		 } 	
	 	if(sum!=0&&a[i]%sum==0){
	 		if(dfs(a[i]/sum,time+1))  return true;
		 }	
		 book[i]=0;
	 }	  
	 return false; 
}
inline int hehe(char* c){
	if(c[0]=='A')
	return 1;
	else if(c[0]=='J')
	return 11;
	else if(c[0]=='Q')
	return 12;
	else if(c[0]=='K')
	return 13;
	else if(strlen(c)==2)
	return 10;
	else 
	return c[0]-'0';
}
int main(){
	int t,i;
	char c[5];
	while(scanf("%s",c)==1){
		a[0]=hehe(c);
		book[0]=0;
		for(i=1;i<4;i++)
		{
			scanf("%s",c);
			a[i]=hehe(c);
			book[i]=0;
		}
		bool ok=0;
		for(i=0;i<4;i++)
		{
			book[i]=1;
			if(dfs(a[i],1))
			{
				ok=1;
				break;
			}
			book[i]=0;
		}
		if(ok)
		printf("Yes\n");
		else
		 printf("No\n");
		
	}
	return 0;
}
*/




#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
//#define NUM 1e-6
using namespace std;
int a[6];
int n;
bool dfs(int x){
	if(x==3){
		 if(24==a[x])
	      return true;
	      return false;
	}	
	 int i,j;
	 for(i=x;i<4;i++)
	 for(j=i+1;j<4;j++){
	 	int le=a[i],ri=a[j];
	 	//���������� X��ָ�ڼ���  ����x=0 Ȼ��ѭ���ǵ�i=1,j=2
		 //����ᱣ�浽j=2���´εݹ���x+1  x=0û�����ᱻ���� ����ÿ��
		 //��a[x]��ֵ���浽a[i] 
	 	a[i]=a[x];   //???????????  ��ģ����˺ô����� 
	 	a[j]=le+ri;	   if(dfs(x+1))  return true;
	 	a[j]=le-ri; 	if(dfs(x+1))  return true;
		a[j]=le*ri;  	if(dfs(x+1))  return true;
	 	a[j]=ri-le;  	if(dfs(x+1))  return true;
	 	if(ri!=0&&le%ri==0){
	 		a[j]=le/ri;	if(dfs(x+1))  return true;
		 } 	
	 	if(le!=0&&ri%le==0){
	 		a[j]=ri/le;	if(dfs(x+1))  return true;
		 }	
		 a[i]=le;
		 a[j]=ri; 	
	 }	  
	 return false; 
}
inline int hehe(char* c){
	if(c[0]=='A')
	return 1;
	else if(c[0]=='J')
	return 11;
	else if(c[0]=='Q')
	return 12;
	else if(c[0]=='K')
	return 13;
	else if(strlen(c)==2)
	return 10;
	else 
	return c[0]-'0';
}
int main(){
	int t,i;
	char c[5];
	while(scanf("%s",c)==1){
		a[0]=hehe(c);
		for(i=1;i<4;i++)
		{
			scanf("%s",c);
			a[i]=hehe(c);
		}
		if(dfs(0))
		printf("Yes\n");
		else
		 printf("No\n");
		
	}
	return 0;
}


