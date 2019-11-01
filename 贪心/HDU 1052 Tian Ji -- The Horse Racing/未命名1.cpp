/*
思路：两组马排序，从大到小枚举王的马，扫描田忌的剩下的最大的马，
如果有马能赢，就赢他，否则拿最小的马输给他 
重点：如果出现快马相等，则不能直接比，应该让两边最小的马比，
若田忌最慢大于等于王的最慢，则KO他，若慢，则将田忌最慢的马输给王最快的马
如果不这样做 例如
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
    	for(i=t-1;i>=0;i--){     //枚举王的马 
    		if(a[ri]>b[i]){
    			re+=200;
    			ri--;
			}   		   
    		else if(a[ri]<b[i])
    		   re-=200;
    		else       
			//71 83 92
		    //	74 87 92  就错了
    		  ri--;
		}
		cout<<re<<endl;
	}
	return 0;
}
*/
//改正AC
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
    		  if(a[ari]>b[bri])   //田马最快比王马最快  田马赢了则KO 
    		  {
    		       re+=200;
				   ari--;
				   bri--;     	
			}
			 else if(a[ari]<b[bri]){  //田马最快比王马最快  田马输则用最慢的马来输 
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
				 	//最快与最慢都相等，则用田忌最慢PK掉齐王最快;  
				 	//判断田忌最慢的马是不是比王最快的马慢 是才输给他
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
