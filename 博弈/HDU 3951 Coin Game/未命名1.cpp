/*
��ת��������
 ���⣺��N��Ӳ��Χ��һȦ��������ÿ��ֻ��ȡ������1~K��Ӳ�ҡ�
 ��������û�б�ʤ���ԡ�
�ⷨ����K==1�����ֻ��N����ż�йء�
     ��K>=2�����N<=K����ô����Ȼ���ֱ�ʤ��
             ��N>Kʱ������һ����ȡ���꣬��ʣ��M����
   	���M<=K�����һ��ȫ��ȡ�꣬���ֱ�ʤ��
	��M>K������ʱM>=3��K>=2��
	��ô���־Ϳ�����ʣ�µ�һ����ȡ�м�������Ȼ���Ժ�ͶԳ�ȡ��
	��һ����ʤ�����д�ʱ���ֱ�ʤ��
*/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t,i,n,k,now;
	scanf("%d",&t);
       for(now=1;now<=t;now++){ 
		scanf("%d%d",&n,&k);
		printf("Case %d: ",now);
		if(k==1){
			if(n%2==1)
			printf("first\n");	
			else
			printf("second\n");	
		}
		else{
          if(k>=n)
			printf("first\n");		
		 else
		printf("second\n");	
	}
	}
	return 0;
} 









