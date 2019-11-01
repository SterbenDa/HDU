/*
思路：最早结束时间，结构体排序，然后依次枚举 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=100+5;
struct Node{
	int l,r;
}node[N];
bool cmp(Node a,Node b){
	if(a.r==b.r) 
	  return a.l<b.l;
	  return a.r<b.r;
}
int main(){ 
    int n,i,re;
     while(cin>>n){
     	  re=1;
     	if(n==0)
     	  break;
     	  for(i=0;i<n;i++){
     	  	    cin>>node[i].l>>node[i].r;
		   }
		sort(node,node+n,cmp);
		
		int now=node[0].r;
		for(i=1;i<n;i++){
			if(node[i].l>=now){
				re++;
				now=node[i].r;
			}
		}
		cout<<re<<endl;
	 }
	return 0;
}


