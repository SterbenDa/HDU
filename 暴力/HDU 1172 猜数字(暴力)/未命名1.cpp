#include<iostream>
#include <string.h>
using namespace std;
const int N=100+5;
struct Node{
	int num,x1,x2;  
}node[N];
int f1[10];  //���ÿ�����ֳ��ָ���������Ҫ��Int  
int re[4];   //��ǽ���������ֻ��һ���Ŷ� 
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
    	       for(a[3]=0;a[3]<10;a[3]++){	//��������  
			    	 	       
    	       	  for(i=0;i<n;i++){   //ö��ÿ����ʾ 
    	       	  	
    	       	  	memset(f1,0,sizeof(f1));   	   //���±�ǣ�Ϊ���ж�   
    	         	
				   f1[a[0]]++;	
				   f1[a[1]]++;	
				   f1[a[2]]++;	
				   f1[a[3]]++;	 
				   
    	       		int sum1=0;  //���������¶���  
					int sum2=0;  //����������λ�ö��� 
    	           	int tmp=node[i].num;
    	           for(j=3;j>=0;j--){
    	           	   if(f1[tmp%10])   //�Ե����ִ��ڲ� 
    	           	   {
    	           	   	sum1++;
    	           	   	f1[tmp%10]--;
					   }	
					   if(tmp%10==a[j])   //λ�öԲ� 
					     sum2++;				  
					   tmp/=10;
				   }	
				   	if(sum1==node[i].x1&&sum2==node[i].x2){   //���� �����ж� 
					   }			   						   
				    else   //���о��������������ǲ��е� 
					  break;
				} 
				if(i==n){   //���ж��� 
				   ok++;
				   for(j=0;j<4;j++)   //������ 
				     re[j]=a[j];
				}
				 
			}
			  if(ok==1)   //ֻ��һ���𰸲��� 
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


