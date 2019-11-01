/*
��Ŀ��˼�ǣ���N����ݣ�����A B Ҫ���A��B
��i����ݿ�������ki�㣬���ǲ���С��1�����n�����ܷ�B
˼·�������ǣ��ӵ�һ��ö���ϻ��£���˷���������У����޽� 
*/
#include<iostream>
#include <string.h>
using namespace std;
const int N=200+5;
const int INF=1000000000;
bool book[N];
int k[N];
int a,b,n,re;
void dfs(int now,int sum){
	if(now==b)
	{
		if(re>sum)
		  re=sum;
		return;
	}
	if(re<=sum)
	   return;
	int ne;
	ne=now+k[now];
	if(ne<=n){
		if(book[ne]==0){
		  book[ne]=1;
		  dfs(ne,sum+1);
		  book[ne]=0;
		}		
	}	  
	ne=now-k[now];
	if(ne>=1){
		if(book[ne]==0){
				book[ne]=1;
		dfs(ne,sum+1);
		book[ne]=0;
		}	
	}
}
int main()
{  
    while(cin>>n){
    	if(n==0)
    	 break;
    	cin>>a>>b;
    	memset(book,0,sizeof(book));
    	for(int i=1;i<=n;i++)
    	     cin>>k[i];
    	re=INF;
    	book[a]=1;
    	dfs(a,0);
    	if(re!=INF)
    	  cout<<re<<endl;
    	else
    	  cout<<-1<<endl;
	}
	return 0;
}


