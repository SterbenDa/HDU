/*
˼·����õļ�ǮΪ500*xi+2*yi ���Ի���������500*xi+2*yiԽ�������
������Ŀ��Χ(0<xi<1440),yi(0=<yi<=100)
����xi=2,yi=1��xj=1,yj=100  ʱ��ֻҪ��һ��1*500Ҳ�����100*2�� 
�������򷽷�Ϊʱ�����ȣ�������level 
������ͻ�����������  
ö��ÿһ������ɨ������Ӵ�С�����Ծ���������ۼƻ����������������������� 
*/
/*��ʱ����  ö�ٻ��������Ʋ��ԣ�Ҫ��level�����ǣ����Ӷȴ�����O(100)
���ö�ٻ��� O(n) 
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
bool cmp(Node a,Node b){    //���� 
   if(a.time==b.time)
       return a.level>b.level;
	return a.time>b.time;
} 
bool book[N];      //��ǻ��� 
int main(){ 
    int n,m,i,j,sum;
    long long re;  //Ҫ��long long 
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
		
		for(i=0;i<m;i++){  //ö��ÿһ������ 
		      int id=-1;   //��ǻ���λ�� 
			   int tmp=99999999;   //��ǻ���level ��ʼΪ��� ѡ��levelС�Ļ��� 
			for(j=0;j<n;j++){      
			//ö��ÿһ������ ������ ��Ҫѡ��ȼ���С�Ļ���ȥ��� 			  
				if(machine[j].time>=task[i].time) //����Ҫ�������� 
				  {
				  	//ע�� wa�˺ܾ� 
				  	//������Ҫд�����棬��Ϊ���������ʹ�û����ڵȼ�������
					//  �ͱ������ˣ�����û���ǵ� 
				  	if(machine[j].level>=task[i].level&&book[j]!=1
					  &&machine[j].level<=tmp){
					 id=j;   
				  	 tmp=machine[j].level;  
				}				  	  				  	
				  }
				  else   //�����������ǻ���ʱ�䲻�������������� ����Ų����� 
				  break; 
				   
			}
			if(id!=-1){  //�ҵ� 
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
bool cmp(Node a,Node b){    //���� 
   if(a.time==b.time)
       return a.level>b.level;
	return a.time>b.time;
} 
bool book[N];      //��ǻ��� 
int main(){ 
    int n,m,i,j,sum;
    long long re;  //Ҫ��long long 
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
		
		for(i=0,j=0;i<m;i++){  //ö��ÿһ������  
		//����ǰ������ʱ��Ļ����϶��������ʱ��Ļ�����ֻ�ǿ��ȼ��в��� 
		    while(j<n&&machine[j].time>=task[i].time){		
			//ö��ÿһ������ ������ ��Ҫѡ��ȼ���С�Ļ���ȥ��� 			  
				level[machine[j].level]++;  //������ʱ��Ļ����ĵȼ����
				j++;				   
			}
			for(int k=task[i].level;k<=100;k++){  
			//���������ʼ�ȼ�ö��  ���л������ڣ���������
			//��Ϊ֮ǰ�����ȥ����ʱ��Ļ����� 
				if(level[k]>0){
					level[k]--;
					re+=task[i].time*500+task[i].level*2;
					sum++; 
					break;  //���� 
				}
			}
		}		
		 printf("%d %lld\n",sum,re);
	}
	return 0;
}
