/*
思路：结构体排序，然后扫描从大到小，选择第一个开始将递增
 先排序，然后选择第一个开始，不断的找到id递增序列，若出现递减的，
 则将他插入数组的开始，不断插入；
  第一次扫描完了，看看数组还有没，若有，则继续 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=10000;
bool book[N];
struct Node{
	int id,v;
}node[N],tmp;
bool cmp(Node a,Node b){
	if(a.v==b.v){
		return a.id<b.id;
	}
	return a.v>b.v;
}
int main(){ 
    int n,re,len;
    while(cin>>n){    	
    	re=0;
    	len=n;
    	for(int i=0;i<n;i++){
    		cin>>node[i].v;
    		node[i].id=i;
		}
		sort(node,node+n,cmp);
		
		while(len>0){
			int now=0;
			int l=0;
			tmp=node[now];
		   for(int i=1;i<len;i++){		
			    if(tmp.id>node[i].id)   
			    {
			    	node[l].id=node[i].id;
			    	node[l].v=node[i].v;
			    	l++;
				}else{
					tmp=node[i];
				}
		   }
		   len=l;
		   re++;
		}	
		cout<<re<<endl;
	}
	return 0;
}


