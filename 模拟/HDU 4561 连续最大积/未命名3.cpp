/*网上代码*/
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
         //count用于记录-2出现次数
		 //flag用于记录出现或不出现-2情况下，最后一次连续+2的次数（尾巴） 
		  //num用于记录+2出现且直到-2出现之间的长度 （头） 
         for(int i=0;i<n;i++)
           {
             if(a[i]==-2) { count++; flag=0;}
             if(a[i]!=-2&&!count&&a[i]!=0)  num++;
             if(a[i]!=-2&&a[i]!=0) {flag++;}
             if(a[i]==0)   //计算该段的积 
               {
               	//若为偶数个-2，则该段长度就是最大积 
                 if(count%2==0)  max=maxx(i-l,max);
                 /*若为奇数个-2，则要么不要第一个-2，要么要 
                 则取长度最小的  minn(num,flag)
                 代表不要第一个-2的话，那么前面num就不要了
				  要的话，那最后一个-2就不要，尾巴就不要，尾巴是flag 
                 i-l该片段长度	minn(num,flag)头尾选短的 
				 减掉一个-2 即1个			
				 */
                 else max=maxx(max,i-l-minn(num,flag)-1);
                 count=flag=num=0;
                 l=i+1;
                 //l记录下个片段的起始位置 
               } 
           }         
         printf("Case #%d: %d\n",++kk,max);         
      }    
}





/*
思路：输入时对数据进行处理，标记出现2的次数  并累计单独-2的次数 
   若出现0，则存入第一段      
   若出现连续-2，则变成2个 即2
   若出现连续2，则变成几个2
   
   对于偶数个单独-2段，则全部就是其连续积
   对于奇数个单独-2段，则取第一个到最后第二个或第二个到最后一个的最大值
   
   最后比较 
*/
/*
还没实现 
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
测试数据挂了
例如
7
-2 2 2 2 -2 -2 2 
我的思路是遇到-2判断后面有没-2，有的话就连通后面那个加起来，
但是会出现如上的情况 
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
