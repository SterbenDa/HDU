/*
#include<iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int N=30000+10;
//bool map[N][N];    //去除重复 
vector<int> ve[N];    //标记该点去向 
int book[N];   //入度累计 
bool flag[N];   //标记是否完成 
priority_queue<int,vector<int>,greater<int> > q;
queue<int> tmp;
int main() 
{ 
    int t,n,m;
    int a,b;
    scanf("%d",&t);
    while(t--){
    //	memset(map,0,sizeof(map));
    	memset(book,0,sizeof(book));
    	memset(flag,0,sizeof(flag));
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    	    ve[i].clear();		
    	for(int i=0;i<m;i++){
    	    scanf("%d%d",&a,&b);
    	   // if(!map[a][b]){
    	    ve[a].push_back(b);
			book[b]++;
		//	map[a][b]=1;
		//	}	    	
		}
		for(int i=1;i<=n;i++){
			if(book[i]==0){
				q.push(i);
				flag[i]=1;
			}			  
		}
		while(!q.empty()){   
			for(int i=0;i<q.size();i++){
			  int now=q.top();
			  q.pop();
			  printf("%d ",now);
			  for(int j=0;j<ve[now].size();j++){
			  	   book[ve[now][j]]--;
			  	   if(book[ve[now][j]]==0&&flag[ve[now][j]]==0){
			  	   	tmp.push(ve[now][j]);
			  	   	flag[ve[now][j]]=1;
					 }
			  	    
			  }
			}			
			while(!tmp.empty()){   //临时存放，防止进去优先队列被混淆 
				int now=tmp.front();
				q.push(now);
				flag[now]=1;
				tmp.pop();												
			}			
		}
		printf("\n");
	}
    return 0;
}
*/

/*用数组优化*/
/*
#include<iostream>
#include <algorithm> 
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int N=30000+10;
//bool map[N][N];    //去除重复 
vector<int> ve[N];    //标记该点去向 
int book[N];   //入度累计 
bool flag[N];   //标记是否完成 
int array[N];
int len,now;
int main() 
{ 
    int t,n,m;
    int a,b;
    scanf("%d",&t);
    while(t--){
    	len=0;
    	now=0;
    //	memset(map,0,sizeof(map));
    	memset(book,0,sizeof(book));
   	memset(flag,0,sizeof(flag));
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    	    ve[i].clear();		
    	for(int i=0;i<m;i++){
    	    scanf("%d%d",&a,&b);
    	  //  if(!map[a][b]){
    	    ve[a].push_back(b);
			book[b]++;
		//	map[a][b]=1;
		//	}	    	
		}
		for(int i=1;i<=n;i++){
			if(book[i]==0){
			  array[len++]=i;
				flag[i]=1;
			}			  
		}		
	    while(1){
	    	sort(array+now,array+len);
	    	int tmp=len;
	    	for(;now<tmp;now++){
	    		printf("%d ",array[now]);
	    		for(int i=0;i<ve[array[now]].size();i++){
	    			  book[ve[array[now]][i]]--;
	    			  if(book[ve[array[now]][i]]==0&&flag[ve[array[now]][i]]==0)
	    			  {
	    			  	array[len++]=ve[array[now]][i];
	    			  	flag[ve[array[now]][i]]=1;
						}  
				}
			}
			if(tmp==len)   //没更新 
			  break;
		}
		printf("\n");
	}
    return 0;
}
*/
