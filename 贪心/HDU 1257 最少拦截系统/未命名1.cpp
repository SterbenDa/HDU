/*
˼·���ṹ������Ȼ��ɨ��Ӵ�С��ѡ���һ����ʼ������
 ������Ȼ��ѡ���һ����ʼ�����ϵ��ҵ�id�������У������ֵݼ��ģ�
 ������������Ŀ�ʼ�����ϲ��룻
  ��һ��ɨ�����ˣ��������黹��û�����У������ 
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


