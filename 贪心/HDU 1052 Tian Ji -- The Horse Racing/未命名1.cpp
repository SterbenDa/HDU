/*
˼·�����������򣬴Ӵ�Сö��������ɨ����ɵ�ʣ�µ�������
���������Ӯ����Ӯ������������С��������� 
�ص㣺������ֿ�����ȣ�����ֱ�ӱȣ�Ӧ����������С����ȣ�
������������ڵ���������������KO����������������������������������
����������� ����
71 83 92
74 87 92 
*/
/*
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=1000+5;
int a[N],b[N];
int main(){ 
   int t,i,j,re;
    while(cin>>t){
    	  if(t==0)
    	    break;
    	re=0;
    	for(i=0;i<t;i++)
    	  cin>>a[i];
    	for(i=0;i<t;i++)
    	  cin>>b[i];
    	sort(a,a+t);
    	sort(b,b+t);
    	
    	int ri=t-1;
    	for(i=t-1;i>=0;i--){     //ö�������� 
    		if(a[ri]>b[i]){
    			re+=200;
    			ri--;
			}   		   
    		else if(a[ri]<b[i])
    		   re-=200;
    		else       
			//71 83 92
		    //	74 87 92  �ʹ���
    		  ri--;
		}
		cout<<re<<endl;
	}
	return 0;
}
*/
//����AC
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=1000+5;
int a[N],b[N];
int main(){ 
   int t,i,j,re;
    while(cin>>t){
    	  if(t==0)
    	    break;
    	re=0;
    	for(i=0;i<t;i++)
    	  cin>>a[i];
    	for(i=0;i<t;i++)
    	  cin>>b[i];
    	sort(a,a+t);
    	sort(b,b+t);
    	
    	int ale,ari,ble,bri;
		ale=ble=0;
		ari=bri=t-1; 
    	 
    	while(ale<=ari&&ble<=bri){
    		  if(a[ari]>b[bri])   //���������������  ����Ӯ����KO 
    		  {
    		       re+=200;
				   ari--;
				   bri--;     	
			}
			 else if(a[ari]<b[bri]){  //���������������  ���������������������� 
			 	  re-=200;
			 	    ale++;
			 	    bri--;			 	    
			 }
			 else{
			 	if(a[ale]>b[ble]){
			 		re+=200;
			 		ale++;
			 		ble++;
				 }
				 else if(a[ale]<b[ble]){
				 	re-=200;
				 	ale++;
				 	bri--;
				 }
				 else{       
				 	//�������������ȣ������������PK���������;  
				 	//�ж�������������ǲ��Ǳ����������� �ǲ������
					 if(a[ale]<b[bri])
					   re-=200;
					  ale++;
					  bri--; 
				 }
			 }
		} 
		cout<<re<<endl;
	}
	return 0;
} 
