/*
˼·��ö�����-�յ�  ������-��С=���� && �������ֶ�����ͬ������� 
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <set> 
using namespace std;
int  a[10000+10];
int re[10000+10]; 
set<int> se;
int main()
{  
    int t=1,i,j,k,n,m;
     int big,small;
     while(scanf("%d%d",&n,&m)==2){
     	printf("Case #%d:\n",t++);
     	memset(re,0,sizeof(re));
     	for(i=0;i<n;i++)
     	   scanf("%d",&a[i]);
     	 
     	for(i=0;i<n;i++){ //��� 
     		se.clear();  //��ռ��� 
     		se.insert(a[i]);
     		big=a[i];
     		small=a[i];
     		re[1]++;
			for(j=i+1;j<n;j++){    //ö�ٳ��� 
				if(!se.count(a[j])){    
					se.insert(a[j]);
					if(a[j]>big)
					   big=a[j];
					if(a[j]<small)
					   small=a[j];
					if(big-small+1==se.size())
					   re[se.size()]++;
				}				   
				else  //������ֵ���� ��ôǰ�浽���ھͶ��ˣ�����ѡ����� 
					break;				
			}
		}
		for(i=0;i<m;i++){
			scanf("%d",&k);
			printf("%d\n",re[k]);
		} 
	 }
	return 0;
}


/*��ʱ 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set> 
using namespace std;
int  a[10000+10];
int re;
set<int> se;
int main()
{  
    int t=1,i,j,k,n,m,z;
     int big,small;
     while(scanf("%d%d",&n,&m)==2){
     	printf("Case #%d:\n",t++);
     	for(i=0;i<n;i++)
     	   scanf("%d",&a[i]);
     	for(i=0;i<m;i++){
     		scanf("%d",&k);
     		re=0;
     		for(j=0;j+k<=n;j++){
     			se.clear();
     			small=1000000000;
     			big=-99999999;
     			bool ok=1;
     			for(z=j;z<j+k;z++){
     				if(se.count(a[z])){
     					  ok=0;
     				      break;
					 }
					 if(a[z]>big)
					    big=a[z];
					if(a[z]<small)
					   small=a[z];
					   if(big-small+1>k)
					       {
					       	ok=0;
					       	break;
						   }
     				se.insert(a[z]);
				 }
				 if(ok&&big-small+1==k)
				  re++;
			 }
			 printf("%d\n",re);
		 }  	
	 }
	return 0;
}
*/

