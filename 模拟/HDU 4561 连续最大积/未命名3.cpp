/*���ϴ���*/
#include<stdio.h>
int maxx(int a,int b)
{
  if(a>b)  return a;
  return b;    
}
int minn(int a,int b)
{
  if(a<b)  return a;
  return b;    
}
int main()
{
   int T,n,kk=0;
   int a[10005],b[10005];
   scanf("%d",&T);
   while(T--)
      {
         scanf("%d",&n);

         for(int i=0;i<n;i++)
           {
             scanf("%d",&a[i]);      
           }   
         a[n++]=0; 
         int count=0,l=0,flag=0,num=0,max=0;
         //count���ڼ�¼-2���ִ���
		 //flag���ڼ�¼���ֻ򲻳���-2����£����һ������+2�Ĵ�����β�ͣ� 
		  //num���ڼ�¼+2������ֱ��-2����֮��ĳ��� ��ͷ�� 
         for(int i=0;i<n;i++)
           {
             if(a[i]==-2) { count++; flag=0;}
             if(a[i]!=-2&&!count&&a[i]!=0)  num++;
             if(a[i]!=-2&&a[i]!=0) {flag++;}
             if(a[i]==0)   //����öεĻ� 
               {
               	//��Ϊż����-2����öγ��Ⱦ������� 
                 if(count%2==0)  max=maxx(i-l,max);
                 /*��Ϊ������-2����Ҫô��Ҫ��һ��-2��ҪôҪ 
                 ��ȡ������С��  minn(num,flag)
                 ����Ҫ��һ��-2�Ļ�����ôǰ��num�Ͳ�Ҫ��
				  Ҫ�Ļ��������һ��-2�Ͳ�Ҫ��β�;Ͳ�Ҫ��β����flag 
                 i-l��Ƭ�γ���	minn(num,flag)ͷβѡ�̵� 
				 ����һ��-2 ��1��			
				 */
                 else max=maxx(max,i-l-minn(num,flag)-1);
                 count=flag=num=0;
                 l=i+1;
                 //l��¼�¸�Ƭ�ε���ʼλ�� 
               } 
           }         
         printf("Case #%d: %d\n",++kk,max);         
      }    
}





/*
˼·������ʱ�����ݽ��д�����ǳ���2�Ĵ���  ���ۼƵ���-2�Ĵ��� 
   ������0��������һ��      
   ����������-2������2�� ��2
   ����������2�����ɼ���2
   
   ����ż��������-2�Σ���ȫ��������������
   ��������������-2�Σ���ȡ��һ�������ڶ�����ڶ��������һ�������ֵ
   
   ���Ƚ� 
*/
/*
��ûʵ�� 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int N=10000+10;
vector<int> ve[N];
int num[N];
int main(){
    int t,i,now,j,len,tmp,re,sum;
       scanf("%d",&t);
        for(now=1;now<=t;now++){
		     scanf("%d",&n);
		     len=0;
		     num[len]=0;
		     re=0;
		     for(i=0;i<n;i++){
		     	scanf("%d",&tmp);
		     	if(tmp<0)
			 }
       	  printf("Case #%d: %d\n",now,re); 	
	   }
	return 0;
}
*/

/*
�������ݹ���
����
7
-2 2 2 2 -2 -2 2 
�ҵ�˼·������-2�жϺ�����û-2���еĻ�����ͨ�����Ǹ���������
���ǻ�������ϵ���� 
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int N=10000+10;
int a[N];
int n,sum,re;
int main(){
    int t,i,now,j;
       scanf("%d",&t);
       for(now=1;now<=t;now++){
       	    sum=0;
       	    re=0;
       	     scanf("%d",&n);
       	     for(i=0;i<n;i++)
       	     scanf("%d",&a[i]);
	          for(i=0;i<n;i++){
	          	if(a[i]==0){
	          		if(re<sum)
	          		{
	          			re=sum;
	          			sum=0;
				}
				  }
				  else if(a[i]>0){
				    sum++;
				  }else{
				  	int tmp=0;
				  	bool ok=0;
				  	j=i+1;
				  	while(j<n){
				  		if(a[j]==0)
				  		  break;
				  		 else if(a[j]>0)
				  		   tmp++;
				  		else{
				  		    tmp+=2;
				  		    ok=1;
				  			break;
						  }
						j++;
					  }
					  if(ok){
					  	sum+=tmp;
					  	i=j;
					  }				     
					  else{
					  	 if(re<sum)         		
	          			re=sum;	  
	          			sum=0;
					  }				
				  }
			  }
			  if(re<sum)
	          	re=sum;
       	  printf("Case #%d: %d\n",now,re); 	
	   }
	return 0;
}
*/
