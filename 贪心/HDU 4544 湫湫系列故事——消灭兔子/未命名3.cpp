/**
����˼·��
�����ӵ�Ѫ���Ӵ�С���򣬽�����ɱ�����Ӵ�С����
����ÿһ������Ѫ�������������ɱ������Ľ�ѹ�����ȶ��У�
���ȶ����Լ���д������ÿ���׳�����Ϊ��Ǯ��С��

����ÿֻ���ӣ������˺����ڵ�������Ѫ���Ͷ���ȥ����ǰ�Ĵ��ڵ�����Ҳ������
ÿ�������׳�һ��ͷ�������� 

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
     return a.qq>b.qq;      //С��qq�����棬���ȶ��еķ���Ҫд�� 
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
		
	    for(j=0,i=0;i<n;i++){      //ö���������� 
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
