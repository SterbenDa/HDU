/*
思路：获得的价钱为500*xi+2*yi 所以获利最大就是500*xi+2*yi越大的任务
由于题目范围(0<xi<1440),yi(0=<yi<=100)
假设xi=2,yi=1与xj=1,yj=100  时间只要多一，1*500也会大于100*2； 
所以排序方法为时间优先，再排序level 
对任务和机器进行排序  
枚举每一个任务，扫描机器从大到小，可以就完成他，累计获利，并标记这个机器被搞了 
*/
/*超时！！  枚举机器的姿势不对！要用level数组标记，复杂度大大减少O(100)
如果枚举机器 O(n) 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=100000+10;
struct Node{
	int time,level;
}machine[N],task[N];
bool cmp(Node a,Node b){    //排序 
   if(a.time==b.time)
       return a.level>b.level;
	return a.time>b.time;
} 
bool book[N];      //标记机器 
int main(){ 
    int n,m,i,j,sum;
    long long re;  //要用long long 
    while(scanf("%d%d",&n,&m)==2){
    	re=0;
    	sum=0;
    	for(i=0;i<n;i++)
    	{
		  book[i]=0;
		  scanf("%d%d",&machine[i].time,&machine[i].level);
		  //cin>>machine[i].time>>machine[i].level;
		} 
    	     	  
    	for(i=0;i<m;i++)    
		 scanf("%d%d",&task[i].time,&task[i].level);		
    	 //  cin>>task[i].time>>task[i].level;
		
		sort(machine,machine+n,cmp);
		sort(task,task+m,cmp);
		
		for(i=0;i<m;i++){  //枚举每一个任务 
		      int id=-1;   //标记机器位置 
			   int tmp=99999999;   //标记机器level 初始为最大 选择level小的机器 
			for(j=0;j<n;j++){      
			//枚举每一个机器 若可以 还要选择等级最小的机器去完成 			  
				if(machine[j].time>=task[i].time) //这里要放在外面 
				  {
				  	//注意 wa了很久 
				  	//此条件要写在里面，因为如果机器被使用或由于等级不够，
					//  就被跳出了，后面没考虑到 
				  	if(machine[j].level>=task[i].level&&book[j]!=1
					  &&machine[j].level<=tmp){
					 id=j;   
				  	 tmp=machine[j].level;  
				}				  	  				  	
				  }
				  else   //跳出的条件是机器时间不足以完成这个任务 后面才不考虑 
				  break; 
				   
			}
			if(id!=-1){  //找到 
				book[id]=1;
				sum++;
				re+=task[i].time*500+task[i].level*2;
			}
		}
		//cout<<sum<<" "<<re<<endl;
		 printf("%d %d\n",sum,re);
	}
	return 0;
}
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=100000+10;
struct Node{
	int time,level;
}machine[N],task[N];
bool cmp(Node a,Node b){    //排序 
   if(a.time==b.time)
       return a.level>b.level;
	return a.time>b.time;
} 
bool book[N];      //标记机器 
int main(){ 
    int n,m,i,j,sum;
    long long re;  //要用long long 
    while(scanf("%d%d",&n,&m)==2){
    	re=0;
    	sum=0;
    	for(i=0;i<n;i++)
    	{
		  book[i]=0;
		  scanf("%d%d",&machine[i].time,&machine[i].level);
		  //cin>>machine[i].time>>machine[i].level;
		} 
    	     	  
    	for(i=0;i<m;i++)    
		 scanf("%d%d",&task[i].time,&task[i].level);		
    	 //  cin>>task[i].time>>task[i].level;
		
		sort(machine,machine+n,cmp);
		sort(task,task+m,cmp);
		
		int level[105]={0};
		
		for(i=0,j=0;i<m;i++){  //枚举每一个任务  
		//满足前面任务时间的机器肯定满足后面时间的机器，只是看等级行不行 
		    while(j<n&&machine[j].time>=task[i].time){		
			//枚举每一个机器 若可以 还要选择等级最小的机器去完成 			  
				level[machine[j].level]++;  //将满足时间的机器的等级标记
				j++;				   
			}
			for(int k=task[i].level;k<=100;k++){  
			//将任务的起始等级枚举  若有机器存在，则可以完成
			//因为之前加入进去满足时间的机器了 
				if(level[k]>0){
					level[k]--;
					re+=task[i].time*500+task[i].level*2;
					sum++; 
					break;  //跳出 
				}
			}
		}		
		 printf("%d %lld\n",sum,re);
	}
	return 0;
}
