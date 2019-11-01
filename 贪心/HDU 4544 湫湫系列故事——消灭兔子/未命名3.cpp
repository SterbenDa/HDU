/**
解题思路：
将兔子的血量从大到小排序，将剑的杀伤力从大到小排序，
对于每一个兔子血量，将比他大的杀伤力大的剑压入优先队列，
优先队列自己重写，让它每次抛出的数为价钱最小的

对于每只兔子，满足伤害大于等于他的血量就丢进去，以前的大于的武器也在里面
每次若能抛出一个头，就满足 

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue> 
using namespace std;
const int N=100000+10;
struct Jian{
	int qq,di;
}jian[N];
int tuzi[N],n,m;
long long re;
bool cmp2(Jian a,Jian b){
    return a.di>b.di;
}
bool cmp1(int a,int b){
    return a>b;
}

bool operator < (Jian a,Jian b){
     return a.qq>b.qq;      //小的qq放上面，优先队列的符号要写反 
}
int main(){
	int i,j;
	while(scanf("%d%d",&n,&m)==2){
		priority_queue<Jian> q;
		for(i=0;i<n;i++)
		scanf("%d",&tuzi[i]) ;
			//cin>>tuzi[i];
				
		for(i=0;i<m;i++)
			scanf("%d",&jian[i].di);
		
		for(i=0;i<m;i++)
			scanf("%d",&jian[i].qq);
			
		if(m<n){
			cout<<"No"<<endl;
			continue;
		}
		
		sort(tuzi,tuzi+n,cmp1);
		sort(jian,jian+m,cmp2);
		
		re=0;
		bool ok=1;	
		
	    for(j=0,i=0;i<n;i++){      //枚举所有兔子 
	        while(j<m&&jian[j].di>=tuzi[i]){
	        	q.push(jian[j]);
	        	j++;
			}
			if(q.empty()){
				ok=0;
				break;
			}
			re+=q.top().qq;
			q.pop();
		}	     
		
		if(ok)
			cout<<re<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}
