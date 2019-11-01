#include<iostream>
#include <string.h>
using namespace std;
const int N=100+5;
struct Node{
	int num,x1,x2;  
}node[N];
int f1[10];  //标记每个数字出现个数，这里要用Int  
int re[4];   //标记结果，若结果只有一个才对 
int main()
{  
    int n;
    int a[4],i,j;
    int  ok;
    while(cin>>n){
    	if(n==0)
    	   break;
    	ok=0; 
    	for(i=0;i<n;i++)
    	   cin>>node[i].num>>node[i].x1>>node[i].x2;
    	   
    	for(a[0]=0;a[0]<10;a[0]++)
    	  for(a[1]=0;a[1]<10;a[1]++)
    	    for(a[2]=0;a[2]<10;a[2]++)
    	       for(a[3]=0;a[3]<10;a[3]++){	//暴力四重  
			    	 	       
    	       	  for(i=0;i<n;i++){   //枚举每个提示 
    	       	  	
    	       	  	memset(f1,0,sizeof(f1));   	   //重新标记，为了判断   
    	         	
				   f1[a[0]]++;	
				   f1[a[1]]++;	
				   f1[a[2]]++;	
				   f1[a[3]]++;	 
				   
    	       		int sum1=0;  //看几个数猜对了  
					int sum2=0;  //看几个数的位置对了 
    	           	int tmp=node[i].num;
    	           for(j=3;j>=0;j--){
    	           	   if(f1[tmp%10])   //对的数字存在不 
    	           	   {
    	           	   	sum1++;
    	           	   	f1[tmp%10]--;
					   }	
					   if(tmp%10==a[j])   //位置对不 
					     sum2++;				  
					   tmp/=10;
				   }	
				   	if(sum1==node[i].x1&&sum2==node[i].x2){   //可以 继续判断 
					   }			   						   
				    else   //不行就跳出，这个组合是不行的 
					  break;
				} 
				if(i==n){   //所有都行 
				   ok++;
				   for(j=0;j<4;j++)   //保存结果 
				     re[j]=a[j];
				}
				 
			}
			  if(ok==1)   //只有一个答案才行 
			  {
			  	for(i=0;i<4;i++)
			  	  cout<<re[i];
			  	  cout<<endl;
			  }
			   else
			   cout<<"Not sure"<<endl;   	
	}
	return 0;
}


